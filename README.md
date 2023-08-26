# pes_asic_class

# Quick Links:-
- [Installation of RV64 toolcahin](#installation)
- [DAY-1 :- Executin simple codes in c using gcc compiler,spike and debugging it](#DAY1)
- [DAY-2 :- ABI,Memory allocation,ADD,LOAD,STORE instructions),Function call and PICORV-32](#DAY-2)
## installation
### https://github.com/kunalg123/riscv_workshop_collaterals/blob/master/run.sh
From the above link we need to run the commands in "run.sh".
#### To check whether the installation is successfull or not use the cmd "riscv64-unknown-elf-gcc --version"
![RISCV64 VERSION](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/041b9ff6-d6c5-4ca8-8305-39f94465d064)
## DAY1
<details>
	<summary> ISA </summary>
	
#### Instruction Set Architecture (ISA) is a set of rules and specifications that define the software-visible aspects of a computer's central processing unit (CPU). It provides a standardized interface between the hardware and the software, allowing software developers to write programs that can run on different hardware platforms without needing to know the intricate details of the underlying hardware.

</details>

<details>
	<summary> Using GCC compiler </summary>
### Writing a simple c code and compiling it using gcc compiler
#### Program to calculate the sum of numbers from 1 to n(taken as 5 below)

```
#include <stdio.h>
int main()
{
int i,sum=0,n=5;
for(i=1;i<=n;i++)
{
sum=sum+i;
}
printf("Sum of numbers from 1 to %d is %d",n,sum);
}

```

#### To display the code on the terminal,compile it using GCC and get the output use the following commands
```
  cat sum.c     // will display code on terminal
  gcc sum.c     // will compile the code
  ./a.out       // wil display the output
```
![WhatsApp Image 2023-08-21 at 3 48 28 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/c6dfb0af-1a20-4598-945c-1c288c42b741)

#### To compile the same code using riscv compiler and get output
```
  riscv64-unknown-elf-gcc -o1 -mabi=rv64i -march=rv64i -o sum.o sum.c     // compiles the code

```
##### An error occured 
![WhatsApp Image 2023-08-21 at 3 58 17 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/f2ec496a-aa40-47a0-b85d-1f3c7db7ce39)
##### solution changing the paths 
```
  vim ~/.bashrc
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/riscv64-unknown-elf/bin:$PATH
```
##### After re-running all the above commands we get the output
```
  vim ~/.bashrc
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/riscv64-unknown-elf/bin:$PATH
```
![WhatsApp Image 2023-08-21 at 4 02 59 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/36d4f0f1-f1ba-46a6-8d7e-d568712bb082)

#### Now let's open the assembly-level code of the the previously compiled code
```
  riscv64-unknown-elf-objdump -d sum.o 
  riscv64-unknown-elf-objdump -d sum.o | less 
  //The difference between the two commands is that the second command is using a Unix utility 
  called less to display the output in a paginated manner, allowing you to scroll through the 
  disassembled code one screen at a time.
```
#### using -o optimization
![WhatsApp Image 2023-08-21 at 4 23 45 PM (1)](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/01ed2dc6-86bc-4cc3-b40b-b8f60c5c3a08)
#### using Ofast optimization
![WhatsApp Image 2023-08-21 at 4 24 17 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/388bf05e-9d4f-4a86-b562-78ef8584cc90)

</details>

##Spike simulation and debugging
```
  spike -d pk sum.o //This command debugs the sum.o file 
  until pc 0 10184   // This command runs debugging unitl the 10184th line
  reg 0 sp         // This command will show us the data stored in the specifed register
  // Upon pressing ENTER the next line will be executed
```
![WhatsApp Image 2023-08-21 at 4 32 37 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/88d8f147-0e9e-4caa-933e-ea1c241a3532)
### We can observe that the data has changed in the register after executing
![WhatsApp Image 2023-08-21 at 4 33 11 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ab1139f8-bd98-4b95-a3e8-a27f2f94113f)

##  Integer Number Representation
### RV64 :- 
- size of double word:- 64bits
- Binary number representation
- - Unsigned:- range = 0 to (2^64 - 1)
- - Signed:-   range = [positive => 0 to 2^63-1] and [negative => -1 to 2^63-1]
- - for positive numbers msb is 0
  - for negative numbers msb is 1

# LAB

## program to find out the highest and lowest values in unsigned long long int
```
#include <stdio.h>
#include <math.h>
int main(){
	unsigned long long int max = (unsigned long long int) (pow(2,64) -1);
	unsigned long long int min = (unsigned long long int) (pow(2,64) *(-1));
	printf("Minimum value is %llu\n",min);
	printf("Maximum value is %llu\n",max);
	return 0;
}
```

![WhatsApp Image 2023-08-21 at 5 43 05 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/c7ccd2ba-3151-4637-8fff-e127f87e0b4e)

##  program to find out the highest and lowest values in signed long long int
```
#include <stdio.h>
#include <math.h>
int main(){
	long long int max = (long long int) (pow(2,63) -1);
	long long int min = (long long int) (pow(2,63) *(-1));
	printf("Minimum value is %lld\n",min);
	printf("Maximum value is %lld\n",max);
	return 0;
}
```

![WhatsApp Image 2023-08-21 at 5 50 33 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/541e2979-70f0-4f47-9bed-fe89a55b56ec)

# DAY-2

## Application binary interface (ABI)
- The "Application Binary Interface" (ABI) in the context of RISC-V is a interface that defines how software interacts with a specific hardware platform, including aspects like function calling conventions, register usage, and data representation.
- It ensures compatibility between compiled software and different implementations of the RISC-V architecture.

## Memory allocation for double word
- Double word has a size of 64 bits
- We use little endian memory addressing system
- We can directly load the data into registers (or)
- The data can be split into bits and can be stored in 8 consecutive registers

## LOAD Instruction

![Screenshot 2023-08-21 182450](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/13121084-9e45-439e-abc6-856aa261fb14)
- syntax:- ld rd,offset(rs)
- - ld:- it is the instruction used to load a double word.
  - the data in the address of (rs + offset) will be loaded into rd
  - Instruction Format:- ![Screenshot 2023-08-21 184551](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/6f54f26b-7e84-4a55-8de2-a96d3504d317)
  - - Opcode  :-  Gives what type of instruction
    - funct3  :-  3-bit data which give the operation to be performed
    - rd      :-  Destination register
    - rs      :-  Source register

## ADD Instruction

![Screenshot 2023-08-21 185014](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/9327081c-577d-4774-8777-1954a3eb9d80)
- syntax:- add rd,rs1,rs2
- - ld:- Adds the data in rs1 and rs2 and stores in rd
  - Instruction format:- ![Screenshot 2023-08-21 185044](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/d15dbd15-21c2-4b2d-af22-e80fa18804fe)
  - -  Opcode    :-  Gives what type of instruction
    - funct3     :-  3-bit data which give the operation to be performed
    - rd         :-  Destination register
    - rs1 & rs2  :-  Two source registers are used as there are two operands
      

## STORE instruction
![Screenshot 2023-08-21 183414](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/6f683396-8b3e-4acf-8fec-fb20dd0e3158)
- syntax:- sd rs2,offset(rs1)
- - sd:- stores the data from rs2 into (offset + rs1)
  - Instruction Format:- ![Screenshot 2023-08-21 190032](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/b355c806-44df-460b-9040-3b0ac1898a56)

## Registers and their ABI names
![php5Rx2Fk](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/60291646-4ba4-4e67-8bbe-7ae39a6cdca5)

#LAB
## Using function call and simulating a different algo based code

.c file:- 
```
#include<stdio.h>


extern int load( int x,int y);

int main(){
	int result=0;
	int count=9;
	result=load(0x0,count+1);
	printf("the sum is %d\n",result);
}
```

.s file:- 
```
	.section .text
.global load
.type load, @function

load:
	add a4,a0,zero
	add a2,a0,a1
	add a3,a0,zero
	
loop:	add a4,a3,a4
	addi a3,a3,1
	blt a3,a2,loop
	add a0,a4,zero
	ret
```

## Compilation and output
![WhatsApp Image 2023-08-21 at 7 44 10 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/2f5183d8-1a46-4a60-926b-8366d6586a68)

### Assembly-level code:-
![WhatsApp Image 2023-08-21 at 7 38 53 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/e8d2b5a4-2471-490b-ab2c-9801889eb104)


#PICORV32 :- It is an open-source RISC-V compatible CPU core that is designed to be small, simple, and efficient and implement RISC's instrucion sets.

![Pcorv32](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/4a5be9a5-8372-40cb-8fd9-431169fd83f4)

![picorv32 file](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/80125716-87fc-42d1-8c79-d6f4e2368352)

# Verilog R





