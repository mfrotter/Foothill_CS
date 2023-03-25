# the null-terminated string must be defined in data segment
.data
M: .word 0, 9, 2, 7, 3, 8, 4, 5, 8, 9, 1, 3, 4, 6, 2, 0, 5, 6, 0, 7, 3, 8, 4, 1, 3, 0, 2, 4, 6, 9, 1, 7, 5, 4, 6, 8, 1, 3, 9, 2, 6, 0, 1, 5, 4, 2, 3, 9, 8, 5, 4, 7, 1, 9, 2, 0, 3, 1, 5, 2, 6, 9, 7, 8 #array to store 8x8 matrix
M2: .word 9, 3, 2, 7, 8, 5, 1, 0, 4, 1, 0, 8, 2, 3, 9, 6, 1, 6, 8, 4, 5, 9, 2, 3, 9, 1, 5, 8, 3, 7, 4, 0, 8, 9, 3, 7, 0, 5, 1, 2, 6, 2, 8, 7, 4, 5, 0, 1, 9, 8, 2, 1, 6, 3, 5, 7, 5, 1, 4, 6, 9, 8, 0, 3 #store 2nd array
Mresult: .space 256 #results from array


.text

	main:	
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
		
	matrixMultiply:
		addi $sp, $sp, -4 #creating space on stack to save RA to main
		sw $ra, 4($sp)
		#c[i][j] = a[i][k]+b[k][j]
		la $v1, Mresult
		li $t6, 0 # initiliaze temp address for c[i][j]
		li $t0, 0 # initiliaze temp address for a[i][k] and b[k][j]
		
		li $t7, 0 # initialize temp register for value of c[i][j]
		li $t8, 0 # initialize temp register for value of b[k][j]
		li $t9, 0 # initialize temp register for value of a[i][k]
	
		li $t4, 8 # row size / loop end
		li $t5, 4 # block siz
		li $t1, 0 #si=0, initialize 1st for loop	
		L1:	li $t2, 0 #sj=0, initialize 2nd for loop
		L2:	li $t3, 0 #sk=0, initialize 3rd for loop
		L3:	jal doBlock
			
			#increment sk and loop back if not sk + block size
			addu $t3, $t3, $t5 # sk = sk + block size
			bne $t3, $t4, L3 # if (sk != 8) go to L3
			
			#increment index variables of middle and outermost loops with + block size
			addu $t2, $t2, $t5 #sj = sj  + block size
			bne $t2, $t4, L2 # if (sj != 8) go to L2
			addu $t1, $t1, $t5 #si = si + block size
			bne $t1, $t4, L1 # if (si != 8) go to L1
			
		lw $ra, 4($sp) #restoring main $ra
		addi $sp, $sp, 4 #deallocating stack after done using
		jr $ra
		
	doBlock:
		add $s4, $t1, $t5 #s4 = si + block size
		add $s5, $t2, $t5 #s5 = sj + block size
		add $s6, $t3, $t5 #s6 = sk + block size
		move $s1, $t1  #i = si
		L1b:	move $s2, $t2 #j = sj
		L2b:	move $s3, $t3 #k = sk
			#starting with c[i][j]
			sll $t6, $s1, 3 #t6 = i * 2^3(size of row of c)
			addu $t6, $t6, $s2 # t6 = i * size(row) + j
			sll $t6, $t6, 2 #t6 = byte offset of [i][j], int is 4 bytes
			addu $t6, $v1, $t6 #t6 = byte address of c[i][j]
			lw $t7, 0($t6) #access address at $t6 for c[i][j[
		L3b:	#next we do b[k][j]
			sll $t0, $s3, 3 #t0 = k * 2^3(size of row of b)
			addu $t0, $t0, $s2 # t0 = k * size(row) + j
			sll $t0, $t0, 2 #t0 = byte offset of [k][j]
			addu $t0, $a3, $t0 #t0 = byte address of b[k][j]
			lw $t8, 0($t0)  #access address at $t0 for b[k][j]
			
			#finally we do a[i][k]
			sll $t0, $s1, 3 #t0 = i * 2^3(size of row of a)
			addu $t0, $t0, $s3 # t0 = k * size(row) + k
			sll $t0, $t0, 2 #t0 = byte offset of [i][k]
			addu $t0, $a1, $t0 #t0 = byte address of a[i][k]		
			lw $t9, 0($t0) #access address at $t0 for a[i][k]
			
			#start arithmetic
			mul $t8, $t9, $t8 # $t8 = a[i][j] * b[k][j]
			add $t7, $t7, $t8 # $t7 = c[i][j] + $t8
		
			addiu $s3, $s3, 1 #k = k + 1
			bne $s3, $s6, L3b # if (k != sk + block size) go to L3b
			sw $t7, 0($t6) #store into t6 for algorithm

			addiu $s2, $s2, 1 #j = j  + 1
			bne $s2, $s5, L2b # if (j != sj + block size) go to L2b
			addiu $s1, $s1, 1 #i = i + 1
			bne $s1, $s4, L1b # if (i != si + block size) go to L1b

		jr $ra

	readResults:
			li $a2, 0 #restart row counter
			li $t6, 0 #set outerloop i = 0
			li $t0, 36 #set register for branch compare i < 9

			
			readResultsOuterLoop:
				li $t4, 0 #restart inner loop
				addi $t6, $t6, 4 #outerloop i++
				
				li $v0 11  # syscall 11: print a character based on its ASCII value
    				li $a0 10  # ASCII value of a newline is "10"
    				syscall
				
				bge, $t6, $t0, endResultsRead #iterating until i < 9 because we i++ prior to starting loop
				addi $a2,$a2, 1 #increment row# counter
				
				
				readResultsInnerLoop:
					li $t5, 32 #set register for compare for i<8
					bge, $t4, $t5, readResultsOuterLoop #i < 8 to iterate through 1 row of 8 elements
					lw, $t2, 0($a1)
					
					li $v0, 1 #load service number to print integer from results array
					move $a0,$t2
					syscall
					
					# print space, 32 is ASCII code for space
					li $a0, 32
					li $v0, 11  # syscall number for printing character
					syscall
					
					#iterate pointer and i in inner loop
					addi $t4, $t4, 4
					addi $a1, $a1, 4
					j readResultsInnerLoop
				
			endResultsRead:
				jr $ra
		
