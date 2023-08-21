# pes_asic_class
## installation
### https://github.com/kunalg123/riscv_workshop_collaterals/blob/master/run.sh
From the above link we need to run the commands in "run.sh".
#### To check whether the installation is successfull or not use the cmd "riscv64-unknown-elf-gcc --version"
![RISCV64 VERSION](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/041b9ff6-d6c5-4ca8-8305-39f94465d064)
## DAY1
#### Instruction Set Architecture (ISA) is a set of rules and specifications that define the software-visible aspects of a computer's central processing unit (CPU). It provides a standardized interface between the hardware and the software, allowing software developers to write programs that can run on different hardware platforms without needing to know the intricate details of the underlying hardware.
## LAB
### Writing a simple c code and compiling it using gcc compiler
#### Program to calculate the sum of numbers from 1 to n(taken as 5 below)

<pre>
  
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
</pre>

#### To display the code on the terminal,compile it using GCC and get the output use the following commands
<pre>
  cat sum.c     // will display code on terminal
  gcc sum.c     // will compile the code
  ./a.out       // wil display the output
</pre>
![WhatsApp Image 2023-08-21 at 3 48 28 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/c6dfb0af-1a20-4598-945c-1c288c42b741)

#### To compile the same code using riscv compiler and get output
<pre>
  riscv64-unknown-elf-gcc -o1 -mabi=rv64i -march=rv64i -o sum.o sum.c     // compiles the code
  
</pre>
##### An error occured 
![WhatsApp Image 2023-08-21 at 3 58 17 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/f2ec496a-aa40-47a0-b85d-1f3c7db7ce39)
##### solution changing the paths 
<pre>
  vim ~/.bashrc
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/riscv64-unknown-elf/bin:$PATH
</pre>
##### After re-running all the above commands we get the output
<pre>
  vim ~/.bashrc
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/bin:$PATH
export PATH=~/riscv_toolchain/riscv64-unknown-elf-gcc-8.3.0-2019.08.0-x86_64-linux-ubuntu14/riscv64-unknown-elf/bin:$PATH
</pre>
![WhatsApp Image 2023-08-21 at 4 02 59 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/36d4f0f1-f1ba-46a6-8d7e-d568712bb082)

#### Now let's open the assembly-level code of the the previously compiled code
<pre>
  riscv64-unknown-elf-objdump -d sum.o 
  riscv64-unknown-elf-objdump -d sum.o | less 
  //The difference between the two commands is that the second command is using a Unix utility 
  called less to display the output in a paginated manner, allowing you to scroll through the 
  disassembled code one screen at a time.
</pre>
#### using -o optimization
![WhatsApp Image 2023-08-21 at 4 23 45 PM (1)](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/01ed2dc6-86bc-4cc3-b40b-b8f60c5c3a08)
#### using Ofast optimization
![WhatsApp Image 2023-08-21 at 4 24 17 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/388bf05e-9d4f-4a86-b562-78ef8584cc90)

##Spike simulation and debugging
<pre>
  spike -d pk sum.o //This command debugs the sum.o file 
  until pc 0 10184   // This command runs debugging unitl the 10184th line
  reg 0 sp         // This command will show us the data stored in the specifed register
  // Upon pressing ENTER the next line will be executed
</pre>
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

#LAB

## program to find out the highest and lowest values in unsigned long long int
<pre>
#include <stdio.h>
#include <math.h>
int main(){
	unsigned long long int max = (unsigned long long int) (pow(2,64) -1);
	unsigned long long int min = (unsigned long long int) (pow(2,64) *(-1));
	printf("Minimum value is %llu\n",min);
	printf("Maximum value is %llu\n",max);
	return 0;
}
</pre>

![WhatsApp Image 2023-08-21 at 5 43 05 PM](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/c7ccd2ba-3151-4637-8fff-e127f87e0b4e)


