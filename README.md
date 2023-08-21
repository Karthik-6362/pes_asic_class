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

