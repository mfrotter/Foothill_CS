#Lab 2 Program

li $v0,4 #load service number for string print in $v0
la $a0, prompt_string # load address of string to be printed into $a0
syscall


la $a0, answer #tell syscall where the buffer is
li $a1, 25 #tell syscall how big the buffer is
li $v0,8 # read a string
move $t1,$a0 # save string in temp 1 (t1)
syscall # read value goes into v0

la $t2, output
loop1:   
bge $t0, 96, looppt2 #check end condition, i < 24
li, $t4, 0
j loop2 #jump to inner loop to evaluate tuple

endloop1:
addi $t0, $t0, 12 #12 instead of 4 because of tuple
addi $t2, $t2, 4 #advance pointer of output array
j loop1

loop2:
bge $t4, 12, endloop1 #tuple so 4*3 = 12
lb $t3, 0($t1) #load char from answer array
addi $t3, $t3, -48 #Convert ascci to int by subtracting by 48
beq $t4, 0, TENS #first char [0] is TENS
beq $t4, 4, ONES #second char [4] is ONES
beq $t4, 8, SPACES #third char [8] is a SPACE

TENS:
sll $t5, $t3, 3 #sll = 2^3 = 8
sll $t6, $t3, 1 #2^1 = 2
add $t7, $t6, $t5  #add together to make 10 = 2 + 8
j endif

ONES:
add $t7, $t7, $t3 #just add together since place
j endif

SPACES:
sw $t7, 0($t2) #when space is detected, store the integer
li $t7, 0 #reset temp value for next tuple
j endif

endif:
addi $t4, $t4, 4 #advances inner loop by 1
addi $t1, $t1, 1 #advances pointer by 1 (its 1 because we are working with chars)
j loop2

looppt2: #reset temp registers and load addresses of arrays we are working with
li $t0, 0
li $t5, 0
la $t2, output
la $t1, vprime
la $t4, vcheck

loop3:
bge $t0, 32, loop3pt2 #check end condition, i < 8
li $v0, 5 #read an integer
syscall
sw $v0, 0($t1) #store input into vprime
addi $t0, $t0, 4 #advance loop by 1
addi $t1, $t1, 4 #advance pointer by 1
j loop3

loop3pt2:
la $t1, vprime #reload address for vprime

loop4:
bge $t5, 32, loop5pre #check end condition, i < 8
lw $t3, 0($t2) #load integer from output[i] 
lw $t6, 0($t1) #load integer from vprime[i]
sub $t7, $t3, $t6
sw $t7, 0($t4) #store subtraction into vcheck
addi $t5, $t5, 4 #advance loop and pointers
addi $t2, $t2, 4
addi $t1, $t1, 4
addi $t4, $t4, 4
j loop4


loop5pre:
li $t0, 0
li $t5, 0
la $t4, vcheck

loop5:
bge $t0, 32, end #check end condition, i < 8
lw $t3, 0($t4) #load integer from vcheck[i]
add $t5, $t5, $t3 #add integers as loaded in
addi $t0, $t0, 4 #advance i and pointer
addi $t4, $t4, 4
j loop5

end:
li $v0,4 #load service number for string print
la $a0, result_string #load address of string to be printed into $a0
syscall

li $v0, 1 #print an integer
move $a0, $t5 #integer to print goes in $a0, prints final result from sum of vcheck
syscall


# the null-terminated string must be defined in data segment
.data
answer: .space 28 #will hold up to 24 characters for string, plus null character
output: .space 32 #array to store integers
vprime: .space 32 #vprime array 
vcheck: .space 32 #vcheck array
prompt_string: .asciiz "Please input a 1x8 vector of two-digit integers (For example, '11 04 20 22 37 03 88 42 ')"
result_string: .asciiz "Check result: "