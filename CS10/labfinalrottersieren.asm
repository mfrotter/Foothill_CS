# the null-terminated string must be defined in data segment
.data
yourname1: .space 64 #array to store 1st name
yourname2: .space 64 #array to store 2nd name
yourname3: .space 64 
yourname4: .space 64
yourname5: .space 64
yourname6: .space 64
yourname7: .space 64
yourname8: .space 64

.text
		li $t3, 8
		li $t4, 0
	main:

		bge $t4, $t3, end
		
		la $t0, yourname1 #initialize matrix array
		la $t2, yourname2
		la $t5, yourname3
		la $t6, yourname4
		la $t7, yourname5
		la $t8, yourname6
		la $t9, yourname7
		la $s1, yourname8
		
		lw $t1, 0($t0)
		lw $t1, 4($t0)		
		lw $t1, 8($t0)
		lw $t1, 12($t0)
			
		lw $t1, 0($t2)
		lw $t1, 4($t2)		
		lw $t1, 8($t2)
		lw $t1, 12($t2)
				
		lw $t1, 0($t5)
		lw $t1, 4($t5)		
		lw $t1, 8($t5)
		lw $t1, 12($t5)
			
		lw $t1, 0($t6)
		lw $t1, 4($t6)		
		lw $t1, 8($t6)
		lw $t1, 12($t6)
		
		lw $t1, 0($t7)
		lw $t1, 4($t7)		
		lw $t1, 8($t7)
		lw $t1, 12($t7)
			
		lw $t1, 0($t8)
		lw $t1, 4($t8)		
		lw $t1, 8($t8)
		lw $t1, 12($t8)
				
		lw $t1, 0($t9)
		lw $t1, 4($t9)		
		lw $t1, 8($t9)
		lw $t1, 12($t9)
			
		lw $t1, 0($s1)
		lw $t1, 4($s1)		
		lw $t1, 8($s1)
		lw $t1, 12($s1)
		
		addi $t4, $t4, 4
		jal main
	end:
			
		#end of program
		li $v0, 10
		syscall
		
	