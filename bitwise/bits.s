# Read the following instructions carefully
# You will provide your solution to this part of the project by
# editing the collection of functions in this source file.
#
# Some rules from Project 2 are still in effect for your assembly code here:
#  1. No global variables are allowed
#  2. You may not define or call any additional functions in this file
#  3. You may not use any floating-point assembly instructions
# You may assume that your machine:
#  1. Uses two's complement, 32-bit representations of integers.

# isZero - returns 1 if x == 0, and 0 otherwise
#   Argument 1: x
#   Examples: isZero(5) = 0, isZero(0) = 1
#   Rating: 1
.global isZero
isZero:
    testl %edi, %edi      # Test if x is zero
    setz %al              # Set AL register to 1 if zero, otherwise 0
    movzbl %al, %eax      # Zero-extend AL to EAX
    ret

# bitNor - ~(x|y)
#   Argument 1: x
#   Argument 2: y
#   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
#   Rating: 1
.global bitNor
bitNor:
    orl %esi, %edi        # Compute x|y
    notl %edi             # Compute ~(x|y)
    movl %edi, %eax       # Return result
    ret

# distinctNegation - returns 1 if x != -x.
#     and 0 otherwise
#   Argument 1: x
#   Rating: 2
.global distinctNegation
distinctNegation:
    negl %edi             # Compute -x
    cmpl %edi, %eax       # Compare x and -x
    setne %al             # Set AL to 1 if they're not equal, otherwise 0
    movzbl %al, %eax      # Zero-extend AL to EAX
    ret

# dividePower2 - Compute x/(2^n), for 0 <= n <= 30
#  Round toward zero
#   Argument 1: x
#   Argument 2: n
#   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
#   Rating: 2
.global dividePower2
dividePower2:
    movl %edi, %eax       # Copy x to eax
    testl %edi, %edi      # Test if x is negative
    js .negative          # If negative, jump to negative label
    movl %esi, %ecx       # Move n to ecx for positive x
    sarl %cl, %eax        # Arithmetic shift right by n positions for positive x
    ret
.negative:
    addl $1, %edi         # Add 1 to x if x is odd (i.e., its least significant bit is set)
    andl $1, %edi         # Check if x was odd (negative and odd means the LSB is set)
    addl %edi, %eax       # Add 0 if x was even, 1 if x was odd
    movl %esi, %ecx       # Move n to ecx
    sarl %cl, %eax        # Arithmetic shift right by n positions
    ret
# getByte - Extract byte n from word x
#   Argument 1: x
#   Argument 2: n
#   Bytes numbered from 0 (least significant) to 3 (most significant)
#   Examples: getByte(0x12345678,1) = 0x56
#   Rating: 2
.global getByte
getByte:
    shll $3, %esi        # Multiply n by 8 to get byte offset
    movl %edi, %eax      # Move x to eax
    shrl %cl, %eax       # Shift right by byte offset
    andl $0xFF, %eax     # Mask out everything but least significant byte
    ret

# isPositive - return 1 if x > 0, return 0 otherwise
#   Argument 1: x
#   Example: isPositive(-1) = 0.
#   Rating: 2
.global isPositive
isPositive:
    testl %edi, %edi      # Test if x is positive
    setg %al              # Set AL to 1 if greater, otherwise 0
    movzbl %al, %eax      # Zero-extend AL to EAX
    ret

# floatNegate - Return bit-level equivalent of expression -f for
#   floating point argument f.
#   Both the argument and result are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representations of
#   single-precision floating point values.
#   When argument is NaN, return argument.
#   Argument 1: f
#   Rating: 2
.global floatNegate
floatNegate:
    movl %edi, %eax               # Move f to eax
    andl $0x7FFFFFFF, %eax        # Mask out the sign bit
    cmpl $0x7F800000, %eax        # Compare with +INF (exponent all 1s, fraction 0)
    je .returnInput               # If f is +INF, simply return the input
    movl %edi, %eax               # Move f to eax again
    xorl $0x80000000, %eax        # Flip the sign bit
    ret

.returnInput:
    movl %edi, %eax               # Move f to eax
    ret

# isLessOrEqual - if x <= y  then return 1, else return 0
#   Argument 1: x
#   Argument 2: y
#   Example: isLessOrEqual(4,5) = 1.
#   Rating: 3
.global isLessOrEqual
isLessOrEqual:
    cmpl %esi, %edi       # Compare x with y
    setle %al             # Set AL to 1 if x <= y, otherwise 0
    movzbl %al, %eax      # Zero-extend AL to EAX
    ret

# bitMask - Generate a mask consisting of all 1's between
#   lowbit and highbit
#   Argument 1: highbit
#   Argument 2: lowbit
#   Examples: bitMask(5,3) = 0x38
#   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
#   If lowbit > highbit, then mask should be all 0's
#   Rating: 3
.global bitMask
bitMask:
    cmpl %esi, %edi               # Check if lowbit > highbit
    jg .allZeros                 # If so, return 0
    movl $1, %eax                # Start with a single bit at position 0
    movl %esi, %ecx              # Move lowbit to ecx
    sall %cl, %eax               # Shift to lowbit position
    movl %edi, %ecx              # Move highbit to ecx
    subl %esi, %ecx              # Find the difference between highbit and lowbit
    addl $1, %ecx                # Add 1 to create a mask of 1s of the required length
    decl %eax                    # Decrement to create a mask starting from position 0
    sall %cl, %eax               # Shift to the highbit position
    ret

.allZeros:
    xorl %eax, %eax               # Return 0
    ret

# addOK - Determine if can compute x+y without overflow
#   Argument 1: x
#   Argument 2: y
#   Example: addOK(0x80000000,0x80000000) = 0,
#            addOK(0x80000000,0x70000000) = 1,
#   Rating: 3
.global addOK
addOK:
    addl %esi, %edi       # Add x and y
    # Check for overflow
    jo .overflow
    movl $1, %eax         # No overflow, return 1
    ret

.overflow:
    xorl %eax, %eax       # Overflow occurred, return 0
    ret


# floatScale64 - Return bit-level equivalent of expression 64*f for
#   floating point argument f.
#   Both the argument and result are passed as unsigned int's, but
#   they are to be interpreted as the bit-level representation of
#   single-precision floating point values.
#   When argument is NaN, return argument
#   Argument 1: f
#   Rating: 4
.global floatScale64
floatScale64:
    movl $2, %eax
    ret

# floatPower2 - Return bit-level equivalent of the expression 2.0^x
#   (2.0 raised to the power x) for any 32-bit integer x.
#
#   The unsigned value that is returned should have the identical bit
#   representation as the single-precision floating-point number 2.0^x.
#   If the result is too small to be represented as a denorm, return
#   0. If too large, return +INF.
#
#   Argument 1: x
#   Rating: 4
.global floatPower2
floatPower2:
     # Adding bias of 127 to the exponent
    addl $127, %edi

    # Check if result is too small
    cmpl $-126, %edi
    jl .too_small

    # Check if result is too large
    cmpl $128, %edi
    jg .too_large

    # Shift to position the exponent
    sall $23, %edi
    movl %edi, %eax
    ret

.too_small:
    xorl %eax, %eax  # Clearing EAX for 0
    ret

.too_large:
    movl $0x7F800000, %eax  # +INF in IEEE 754 representation
    ret