# base-Converter
Its a simple base conversion program written in c++ for understanding the conversion done at the backend.
For understanding what are base conversions lets first of all understand some of the fundamental concepts.

## What  is Number System?

A number system is a way of representing numbers using a set of symbols. The most commonly used number system is the decimal system, which uses the symbols 0 to 9 to represent numbers. In a decimal system, the value of a digit is determined by its position within the number. For example, in the number "123", the digit "1" represents 100, the digit "2" represents 20, and the digit "3" represents 3.

Other number systems include binary, octal, and hexadecimal, which use 2, 8, and 16 symbols respectively to represent numbers. These systems are commonly used in computer science and engineering because they are more convenient for computers to work with than the decimal system.

### There are several types of number systems, including:

**Binary**: a base-2 number system, where only 0 and 1 are used.

**Decimal**: a base-10 number system, where 0 to 9 digits are used.

**Octal**: a base-8 number system, where only 0 to 7 digits are used.

**Hexadecimal**: a base-16 number system, where 0 to 9 digits and A to F letters are used.
 and there are many other but we will be dealing with this 4 types.
 
 ## What is base conversion? 
Base conversion is the process of converting a number from one number system to another number system. For example, converting a decimal number (base-10) to binary (base-2) or hexadecimal (base-16). The process involves determining the place value of each digit in the original number and expressing it in terms of the new base system. The new representation will have a different set of digits and/or a different number of digits, depending on the new base.

So here in this repository you will be learning how to convert betweeen differnt numbersystem. 

Note : In all the conversions below both our input and output will be in strings.
 
### 1. Binary to decimal 
The algorithm to convert a binary number to decimal is as follows:

i.  Start from the rightmost digit and multiply each digit by the power of 2, starting from 0.
ii. Add up all the products obtained in step 1 to obtain the decimal equivalent.

Here's an example of converting binary number 1001 to decimal:

1001 in binary is 1 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0 = 8 + 1 = 9 in decimal.
So the decimal equivalent of binary number 1001 is 9.

Code : 

        for(int i=num.length()-1; i>=0; i--){
            dec+=int(num[i]-'0')*pow(2,num.length()-i-1);
        }
        ans = to_string(dec)+ans;
Explanation :
We are given a binary number **num** in form of string.  As per the algorithm discussed above first we need to start from the rightmost digit, hence we loop from last character of string **num** till its first character and multiply value at each index with 2 the power of (length of the string -1-currentIndex) i.e 2^(length-1-i) and add this value to our decimal number which was initially 0. As the given number is in string and we want its integer value hence we substract '0' from characters.

### 2. Binary to Octal
The algorithm to convert a binary number to octal is as follows:

i.  Group the binary number into sets of 3 bits starting from the rightmost bit.
ii.  Convert each group of 3 bits into its equivalent decimal number.
iii.  The decimal numbers obtained in step 2 form the octal equivalent of the binary number.
    

Here's an example of converting binary number 10011011 to octal:
1.  Group the binary number into sets of 3 bits: 100 110 101
2.  Convert each group of 3 bits into its equivalent decimal number: 4 6 5
3.  The decimal numbers obtained in step 2 form the octal equivalent of the binary number: 465

So the octal equivalent of binary number 10011011 is 465.  

Code:

    for(int i=n.length()-1, oct=0,count=0; i>=0; i--){
            oct += int(n[i]-'0')*pow(2,count);
            count++;
            if(count==3 || i==0){
                ans = to_string(oct)+ ans;
                oct=0; count=0;
            }    
        }
