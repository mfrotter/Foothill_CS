# the null-terminated string must be defined in data segment
.data
answer: .space 16 #will hold up to 12 characters for string, plus null character
output: .space 16 #array to store integers
M: .space 64 #array to store all 4 output matrices
M2: .space 64 #store 2nd array
Mresult: .space 64 #results from array
Mresult2: .space 64
prompt_string1: .asciiz "Row "
prompt_string2: .asciiz ": "
sum_string: .asciiz "Sum: "
parity_string: .asciiz "Parity: "
newline: .asciiz "\n"
space: .asciiz " "

.text

	main:
		la $s1, M #initialize matrix array
		
		#call readAndStore #1
		jal readAndStoreFourTimes
		
		li $v0,4 #load service number for string print in $v0
		la $a0, newline # load address of string to be printed into $a0
		syscall
		
		la $s1, M #reinitialize address of M to store into $a1
		la $a3, M2 #intialize 1st matrix to store
		move $a0, $s1
		
		#store #1 into separate matrix
		jal storeFirst
		
	
		#call readAndStore #2
		jal readAndStoreFourTimes
		
			
		la $a1, M #reinitiliaze address of M and M2 for matrix multiply
		la $a3, M2
		
		#matrix 1 is in $a1 and matrix 2 is in $a3, now time to multiply them	
		jal matrixMultiply
		
		la $v1, Mresult #create a new array to store result
		move $a1,$v1 #store results vector into a1 to read it
		
		#read and print the resulting matrix
		jal readResults

	end:
			
		#end of program
		li $v0, 10
		syscall
		
	readAndStoreFourTimes:
		li $t6, 0
		li $a2, 0
		addi $sp, $sp, -4 #creating space on stack to save RA to main
		sw $ra, 4($sp)
		
		readStoreLoop:
			li $s0, 16 #set register for compare for i<4
			bge, $t6, $s0, endReadAndStore
		
			addi $a2,$a2, 1 #increment row# counter
	
			#Nested Procedure
			jal vectorRead #read vector input
		
			la $v1, output
			move $a1,$v1 #store output into a1 to use for storVector
		
			#Nested Procedure
			jal storeVector #store results from vectorRead to matrix M
			
			addi $t6, $t6, 4 #iterate i++
			j readStoreLoop
		
		endReadAndStore:
			lw $ra, 4($sp) #restoring main $ra
			addi $sp, $sp, 4 #deallocating stack after done using
			jr $ra

	
	vectorRead:
	
		#Prompt for Row Input
		li $v0,4 #load service number for string print in $v0
		la $a0, prompt_string1 # load address of string to be printed into $a0
		syscall

		li $v0,1 #load service number for integer print in $v0
		move $a0,$a2 #print row number counter
		syscall


		li $v0,4 #load service number for string print in $v0
		la $a0, prompt_string2 # load address of string to be printed into $a0
		syscall

		
		la $a0, answer #tell syscall where the buffer is
		li $a1, 10 #tell syscall how big the buffer is
		li $v0, 8 # read a string
		move $t1,$a0 # save string in temp 1 (t1)
		syscall # read value goes into v0

		la $v1, output #reset address for output
		li $t0, 0 #set outerloop i = 0
		
		#Commence conversion from ascii to int using two loops
		
		conversionOuterLoop:
			li $t9, 32 #set register for branch compare at i < 8
			bge $t0, $t9, endOfVectorRead #check end condition, i < 8, length of string
			li, $t4, 0 #reset loop2 i
			
			conversionInnerLoop:
				li $t5, 8 #set register for branch compare at i < 2
				bge $t4, $t5, endOuterLoop #double so 4*2 = 8
				li, $t8, 0 # compare for ifOnes
				li, $t7, 4 # compare for spaces
				lb $t3, 0($t1) #load char from answer array
				andi $t3, $t3, 15 #convert ascii to int by masking with 15
				beq $t4, $t8, ifOnes #first char [0] is ONES 
				beq $t4, $t7, endif #second char [4] is a SPACE

			ifOnes:
				sw $t3, 0($v1) #after ones, can store char into array
			
			endif:
				addi $t4, $t4, 4 #advances inner loop by 1
				addi $t1, $t1, 1 #advances pointer by 1 (its 1 because we are working with chars)
				j conversionInnerLoop
		
		endOuterLoop:
			addi $t0, $t0, 8 #12 instead of 4 because of tuple
			addi $v1, $v1, 4 #advance pointer of output array
			j conversionOuterLoop
				
		endOfVectorRead:	
			jr $ra



	storeVector:
		li $t2, 0 #reset temp registers
		li $t3, 0
		
		storeLoop:
			li $s0, 16 #set register for compare for i<4
			bge $t2, $s0, endStoreLoop #i < 4 for storing the 4 ints
			lw $t3, 0($a1) #load output from readVector
			sw $t3, 0($s1) #store output into M matrix
			addi $a1, $a1, 4 #increment i and pointers
			addi $s1, $s1, 4
			addi $t2, $t2, 4
			j storeLoop
		
		endStoreLoop:
			jr $ra
			
	storeFirst:
		li $t0, 0 #set i=0 for loop
		
		storeFirstLoop:
			li $t7, 64 #branch compare i < 16
			bge $t0, $t7, endStoreFirst #iterate through all 16 integers i < 16
			lw $t2, 0($a0) #load first matrix info
			sw $t2, 0($a3) #store first matrix into second matrix to re-use readAndStoreFourTimes procedure
			addi $t0, $t0, 4 #increment pointers and i
			addi $s1, $s1, 4
			addi $a3, $a3, 4
			j storeFirstLoop
		
		endStoreFirst:
			jr $ra
		
	matrixMultiply:
		#c[i][j] = a[i][k]+b[k][j]
		la $v1, Mresult
		li $t6, 0 # initiliaze temp address for c[i][j]
		li $t0, 0 # initiliaze temp address for a[i][k] and b[k][j]
		
		li $t7, 0 # initialize temp register for value of c[i][j]
		li $t8, 0 # initialize temp register for value of b[k][j]
		li $t9, 0 # initialize temp register for value of a[i][k]
		li $s2, 0
		li $s3, 0
		li $s4, 0
		li $v0, 0
		
	
		li $t4, 4 # row size / loop end
		li $t1, 0 #i=0, initialize 1st for loop	
		L1:	li $t2, 0 #j=0, initialize 2nd for loop
		L2:	li $t3, 0 #k=0, initialize 3rd for loop
		L3:	#starting with c[i][j]
			sll $t6, $t1, 2 #t6 = i * 2^2(size of row of c)
			addu $t6, $t6, $t2 # t6 = i * size(row) + j
			sll $t6, $t6, 2 #t6 = byte offset of [i][j], int is 4 bytes
			addu $t6, $v1, $t6 #t6 = byte address of c[i][j]
	
			#next we do b[k][j]
			sll $t0, $t3, 2 #t0 = k * 2^2(size of row of b)
			addu $t0, $t0, $t2 # t0 = k * size(row) + j
			sll $t0, $t0, 2 #t0 = byte offset of [k][j]
			addu $t0, $a3, $t0 #t0 = byte address of b[k][j]
			lw $t8, 0($t0)  #access address at $t0
			lw $s2, 16($t0) #loop unroll, offset by 16 because we need next row not next column
			lw $s5, 32($t0) 
			lw $v0, 48($t0)
			
			#finally we do a[i][k]
			sll $t0, $t1, 2 #t0 = i * 2^2(size of row of a)
			addu $t0, $t0, $t3 # t0 = k * size(row) + k
			sll $t0, $t0, 2 #t0 = byte offset of [i][k]
			addu $t0, $a1, $t0 #t0 = byte address of a[i][k]		
			lw $t9, 0($t0) #access address at $t0
			lw $s3, 4($t0) #loop unroll
			lw $s6, 8($t0)
			lw $k0, 12($t0)
			
			#start arithmetic
			mul $t8, $t9, $t8 # $t8 = a[i][j] * b[k][j]
			add $t7, $t7, $t8 # $t7 = c[i][j] + $t8
			mul $s2, $s3, $s2 # same as above
			add $s4, $s4, $s2 # same as above
			mul $s5, $s6, $s5 # same as above
			add $s7, $s7, $s5 # same as above
			mul $v0, $k0, $v0 # same as above
			add $k1, $k1, $v0 # same as above
			
			#increment k and loop back if not 4
			addiu $t3, $t3, 4 # k = k + 4 #changed 1 to 4 since we are unrolling three times
			bne $t3, $t4, L3 # if (k != 4) go to L3 (loop unroll once)
			add $t7, $t7, $s7
			add $t7, $t7, $k1
			add $t7, $t7, $s4
			sw $t7, 0($v1) #store into v1 for results
			addi $v1, $v1, 4 #<-----------------
			li $t7, 0
			li $s4, 0
			li $s7, 0
			li $k1, 0
			
			#increment index variables of middle and outermost loops
			addiu $t2, $t2, 1 #j = j  + 1
			bne $t2, $t4, L2 # if (j != 4) go to L2
			addiu $t1, $t1, 1 #i = i + 1
			bne $t1, $t4, L1 # if (i != 4) go to L1
			
		jr $ra

	readResults:
			li $a2, 0 #restart row counter
			li $t6, 0 #set outerloop i = 0
			li $t0, 20 #set register for branch compare i < 5

			
			readResultsOuterLoop:
				li $t4, 0 #restart inner loop
				addi $t6, $t6, 4 #outerloop i++
				
				#print a newline after each row
				li $v0, 4 #load service number for string print
				la $a0, newline
				syscall
				
				bge, $t6, $t0, endResultsRead #iterating until i < 5 because we i++ prior to starting loop
				addi $a2,$a2, 1 #increment row# counter
				
				#print "Row X: "
				li $v0,4 #load service number for string print in $v0
				la $a0, prompt_string1 # load address of string to be printed into $a0
				syscall
				
				li $v0,1 #load service number for integer print in $v0
				move $a0,$a2 #print row number counter
				syscall
				
				li $v0,4 #load service number for string print in $v0
				la $a0, prompt_string2 # load address of string to be printed into $a0
				syscall
				
				readResultsInnerLoop:
					li $s0, 16 #set register for compare for i<4
					bge, $t4, $s0, readResultsOuterLoop #i < 4 to iterate through 1 row of 4 elements
					lw, $t2, 0($a1)
					
					li $v0, 1 #load service number to print integer from results array
					move $a0,$t2
					syscall
					
					li $v0, 4 #load service number for string print
					la $a0, space # print a space
					syscall
					
					#iterate pointer and i in inner loop
					addi $t4, $t4, 4
					addi $a1, $a1, 4
					j readResultsInnerLoop
				
			endResultsRead:
				jr $ra
		
