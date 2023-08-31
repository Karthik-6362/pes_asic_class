# PES_ASIC_CLASS

# Quick Links:-
- [Installation of RV64 toolcahin](#Installation_of_RISC-v_toolchain)
- [DAY-1 :- Executin simple codes in c using gcc compiler,spike and debugging it](#DAY1)
- [DAY-2 :- ABI,Memory allocation,ADD,LOAD,STORE instructions),Function call and PICORV-32](#DAY2)
- [RTL design using Verilog with sky130 technology](#RTL_design_using_Verilog_with_sky130_technology)
- - [Softwares installation](#Softwares_installation)
- - [DAY-1](#DAY-1)
  - [DAY-2](#DAY-2)



## Installation_of_RISC-v_toolchain
### https://github.com/kunalg123/riscv_workshop_collaterals/blob/master/run.sh
From the above link we need to run the commands in "run.sh".
#### To check whether the installation is successfull or not use the cmd "riscv64-unknown-elf-gcc --version"
![RISCV64 VERSION](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/041b9ff6-d6c5-4ca8-8305-39f94465d064)
# DAY1
<details>
	<summary> ISA </summary>
	
## Instruction Set Architecture (ISA) is a set of rules and specifications that define the software-visible aspects of a computer's central processing unit (CPU). It provides a standardized interface between the hardware and the software, allowing software developers to write programs that can run on different hardware platforms without needing to know the intricate details of the underlying hardware.

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

<details>
<summary> Using SPIKE for compiling and debugging </summary>

## pike simulation and debugging
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

</details>

# DAY2

<details>
	<summary> ABI </summary>
	
## Application binary interface (ABI)
- The "Application Binary Interface" (ABI) in the context of RISC-V is a interface that defines how software interacts with a specific hardware platform, including aspects like function calling conventions, register usage, and data representation.
- It ensures compatibility between compiled software and different implementations of the RISC-V architecture.
  
</details>

<details>
	<summary>Memory allocation of double word</summary>
	
## Memory allocation for double word
- Double word has a size of 64 bits
- We use little endian memory addressing system
- We can directly load the data into registers (or)
- The data can be split into bits and can be stored in 8 consecutive registers

</details>

<details>
	<summary> LOAD instruction</summary>
	
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

</details>

<details>
	<summary>ADD instruction </summary>\
	
## ADD Instruction

![Screenshot 2023-08-21 185014](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/9327081c-577d-4774-8777-1954a3eb9d80)
- syntax:- add rd,rs1,rs2
- - ld:- Adds the data in rs1 and rs2 and stores in rd
  - Instruction format:- ![Screenshot 2023-08-21 185044](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/d15dbd15-21c2-4b2d-af22-e80fa18804fe)
  - -  Opcode    :-  Gives what type of instruction
    - funct3     :-  3-bit data which give the operation to be performed
    - rd         :-  Destination register
    - rs1 & rs2  :-  Two source registers are used as there are two operands
      
</details>

<details>
	<summary> STORE instruction </summary>

## STORE instruction
![Screenshot 2023-08-21 183414](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/6f683396-8b3e-4acf-8fec-fb20dd0e3158)
- syntax:- sd rs2,offset(rs1)
- - sd:- stores the data from rs2 into (offset + rs1)
  - Instruction Format:- ![Screenshot 2023-08-21 190032](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/b355c806-44df-460b-9040-3b0ac1898a56)
 
</details>

<details>
<summary>ABI names of registers </summary>

## Registers and their ABI names
![php5Rx2Fk](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/60291646-4ba4-4e67-8bbe-7ae39a6cdca5)

</details>

<details>
<summary> Lab on function call </summary>

# LAB
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

</details>

<details>
<summary>PICORV-32 </summary>

# PICORV32 :- It is an open-source RISC-V compatible CPU core that is designed to be small, simple, and efficient and implement RISC's instrucion sets.

![Pcorv32](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/4a5be9a5-8372-40cb-8fd9-431169fd83f4)

![picorv32 file](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/80125716-87fc-42d1-8c79-d6f4e2368352)
 </details>

 # RTL_design_using_Verilog_with_sky130_technology
 
 ## Softwares_installation
 <details>
	 <summary>IVerilog</summary>
	 
  ### commands to install Iverilog 
  ```
sudo apt install iverilog
```
  ### Version of IVerilog installed
  ![IVerilog version](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/9a03cef5-4adf-4d15-8ea9-b616ace91f5b)

</details>

 <details>
	 <summary>GTKWave</summary>

  ### commands to install GTKWave
  ```
sudo apt install gtkwave
```
### Version of GTKWave installed 
![gtkwave installation](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/24ea3809-72e8-4af8-9df0-52fc947a1c25)

 </details>
 
 <details>
	 <summary>YOSYS </summary>

  ### Commands used to install YOSYS'
  ```
git clone https://github.com/YosysHQ/yosys.git
cd yosys
sudo apt install make
sudo apt-get update
sudo apt-get install build-essential clang bison flex  libreadline-dev gawk tcl-dev libffi-dev git  graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev
make config-gcc
make
```
### Version of YOSYS installed
![yosys installation](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/3aca747f-fa5a-470c-a320-cc985eb708a9)

 </details>

 <details>
	 <summary>Files /Source codes for Labs</summary>
	 
### commands used to install these 
```
git clone https://github.com/kunalg123/vsdflow.git
cd vsdflow
chmod 777 opensource_eda_tool_install.sh
./opensource_eda_tool_install.sh 
```
![Installation of required source codes](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/8ff1a821-0cc4-4afe-a0ce-b79872d585ec)

 </details>

# DAY-1
 
 <details>
 <summary>Intro to Verilog RTL design and synthesis  </summary>
	 
 ### Simulator  :- Tool(IVerilog) used to check/verify a design whenever the inputs change.
 ### Design     :- Set of verilog codes that have intended functionality.
 ### Testbench  :- Setup of applying stimulus to the design and verify the accuracy of the design.
![testbench](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/3f438a46-8756-4143-b648-19ab7bf0a589)
### IVerilog based simulation flow :- 
![iverilog based system flow](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/3174e610-0ffa-4d71-86b4-f01f9b58677b)
- Based on the changes in the inputs the output will be manipulated depending on the design.
- A vcd (Value Change Dump format) file will be generated.
- To view this vcd file we use gtkwave tool which displays the outut.

</details>

<details>
	<summary>Source codes and testbenches</summary>
	
### Commands used 
```
git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop
```
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/01ccefe5-524f-4373-b096-6d7358d8760a)

</details>

<details>
	<summary> Using iverilog to load mux.v program and tretbench from the source files and execute the VCD file</summary>
	
### Commands used:- 
```
// get intp the folder containing the verilog code and the testbench files
iverilog good_mux.v tb_good_mux.v
./a.out // This will generate the VSD file
gtkwave tb_good_mux.vsd // This will open up the waveform based on the testbench
```
### Executing the a.out and .vcd files:-
![Executing the a out and vcd file on gtkwave](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/7dcc88ec-edf7-43c6-b9e3-41becee2523c)

### gtkwave output :-
![Output of gtkwave for good_mux](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/111c7454-ed1b-4f03-9123-cb333e678102)

</details>

<details>
	<summary>Analysing the logic and testbench</summary>

 ### good_mux.v:- 
 ![good_mux v](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/920f7672-2ea6-4d9f-a4dc-20b3bc964bf5)

 ### tb_good_mux.v:- 
 - $dumpfile("tb_good_mux.vcd"); // This instructs the simulator to generate a .vcd file which can be used on GTKWave to view the out[ut waveforms.
 ![tb_good_mux v](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/fd539d05-c0a4-492c-9b19-ee0e949be5ec)


</details>

<details>
	<summary>YOSYS and Logic Synthesis</summary>
 
### YOSYS setup:- 
![YOSYS setup](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/5edd408a-fb91-4252-9ebe-307d19856b6b)

- The design file and the .lib files are applied to YOSYS to get a synthesised output(netlist)
- read_verilog:- used to read the design
- read_liberty:- used to read the library files
- write_verilog:- used on netlist file to get netlist

### Veifying the synthesis:-
![Verify the synthesus](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/db9309df-4c2f-41f9-a314-3973345cd399)

- the same .tb file can be used here along with the netlist file generated
- RTL design:- Behavioural representation of the required design (in VHDL)
- Synthesis:- Converting RTL into gate level/netlist
- Synthesiszer:- (YOSYS) converts RTL into netlist

</details>

<details>
	<summary>.lib files:- </summary>

 - It consists of all the standard library files(collection of logical modules and all gates of different delays)
 - Why gates of different delays:-
 - - To satisfy the timing delays of different combinational logics
   - T_clk > T_cq_A + T_comb + T_setup_b (we need fast gates here)
   - T_hold < Tcq_A + T_comb (need slow gates)

</details>

<details>
	<summary>Lab on YOSYS </summary>

 ### We read the .lib and design diles on yosys to get the netlist output
### Commands used:- 
```
read_liberty -lib /path to .lib file
read_verilog good_mux.v
synth -top module_name
abc -liberty /path to .lib file/
show
write_verilog -noattr good_mux_netlist.v
!gvim good_mux_netlist.v
```
- read_liberty -lib /path to .lib file/   // It reads all the components in the .lib file
- read_verilog good_mux.v             // This will read the desgn verilog file
- - ![Execution of read liberty and  read verilog](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/5eba649d-2a0a-459b-927d-0aa53e0b1818)
- synth -top module_name    // This will synthesis the module specified
- - ![Output of synth -top](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/05462979-f72b-4625-8423-af16fc5f7ee8)
- abc -liberty /path to .lib file/   // This will generate the netlist file based on the .lib file mentioned
- - ![Execution of abc -liberty ](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/b0733448-6835-4cd0-bcda-4c232e764ee6)
- show   // Used to see the synthesised output / netlist
- - ![Synthesized output of good_mux](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/83091349-a6e2-4031-b015-45482d71bc0e)
- write_verilog -noattr good_mux_netlist.v // This command writes the netlist into the specifies file
- !gvim good_mux_netlist.v  // This command will display the netlist.v file
- - ![Netlist representation of the mux](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/8e666e9f-79f1-41e1-870b-c5cfc23675fd)
  
</details>


# DAY-2

<details>
	<summary>.lib files </summary>

## commands used in terminal :- 
```
gvim /path to the .lib file/
```
## commands used in vim:-
```
syn off // Switches off the highlighting of the syntax
se un  // used to enable the line numbers
/cell  // used to find a word cell
vsp   // Opens another window of the same file
```
it contains:- 
- Conditions of PVT(Pressure Voltage Temperature) for proper working
- Default values/units
- - time_unit : "1ns";
  - voltage_unit : "1V";
  - leakage_power_unit : "1nW";
  - current_unit : "1mA";
  - pulling_resistance_unit : "1kohm";
  - capacitive_load_unit(1.0000000000, "pf");
  - default_operating_conditions : "tt_025C_1v80";
- Standard cells
- Leakage powers of all the cells for different inputs
- About the technology("CMOS")
- 

## .lib file:- 
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/d1c0aadb-6cef-4fab-a7a9-738635e677ea)

## Different versions of the and2 gate:- 

### and2_0:-
![and2_0](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/f51956e2-5536-49c5-bead-3d4a07af4b8f)

### and2_2:- 
![and2_2](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/03ab1e2b-1467-45dc-8abb-bf9a07600df5)

### and2_4:-
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/e4d5275d-7e0a-4591-a89c-a35658d59a48)

### Observation:- 
- In terms of area and power :- and2_4 > and2_2 >and2_0
- Wider cells occupy high area and consume high power and the delay is low
- smaller cells occupy low area and consume low power and the delay is high   

</details>


<details>
	<summary>Hierarchical vs Flat Synthesis </summary>

 ## Synthesizing a module named multiple_modules.v using /YOSYS
 - It contains two sub-modules
 - ![Multiple_modules v](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ffa7add0-f537-4075-b6be-a2ad4564c822)

## command used:- 
```
read_liberty -lib /path to .lib file/    // reads the .lib file onto YOSYS
read_verilog multiple_modules.v          // reads the .v file specified
synth -top multiple-modules              // synthesizes the design by taking specified module as top module  
abc -liberty /path to .lib file/         // links the .lib file to the design
show                                     // displays the synthesized design
write_verilog -noattr multiple_modules_hier.v    // writes the netlist into the specified file 
!gvim multiple_modules_hier.v            // displays the netlist file
```
 ## Opening YOSYS and reading the .lib file:- 
 ![Openig YOSYS and reading liberty files](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/5a15e800-70c3-4c3b-a4bd-039531a33344)

## Reading the moltiple_modules.v file on YOSYS:-
![reading the file onto yosys](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ffd41d13-4c03-4617-9c32-c7c225df6459)

## Using synth command to synthesize the design:-
![Synthesis1 of of the file](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/8e1161bb-86d6-4137-a782-7f6552f95ad5)

![Synthesis2 of of the file](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/7e3dcc6f-bfc2-486d-a397-4f69d9bd790d)

## Linking the .lib file to the design:-
![Linking  lib with design](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/59c0eea0-b330-474f-bb04-8c547b118898)
  
## Synthesized output:- 
![Synthesizes output of the design](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/09d1dc75-9565-435d-ac31-741890270149)

## Using write_verilog to write the netlist:- 
![Using write_verilog to write the netlist](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/6ff263a1-cc1b-4174-a357-60581bf9b17a)

## The output netlist:- 
![Netlist_1](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/c0ba177d-7a18-4763-9d41-6b158e7e515c)
![Netlist_2](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/5b30983e-0d01-4172-85cf-6fbcbcf861bf)

## Expected v/s synthesized design:- 
![Theory](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/9293f26d-182d-4229-aafd-d016be6ae579)

## Observations:- 
- The synthesized and the expected design are different because the expected uses PMOS stacking which is not prefferable
- Using de-morgans law we can verify the design.
- The netlist file contains the hierarchy as mentioned in the design file.
- In the netlist file one NAND gate and two inverters are used instaed of using a and gate & or gate as specified in the design


</details>


<details>
	<summary>Flat synthesis </summary>

 ## Flat synthesis:- 
 - Using the command " flatten " to flatten the hierarchy and directly initialize the required modules under the main module.
 - Does not preserve hierarchy.
 
```
commands used:- 
read_liberty -lib /path to .lib file/    // reads the .lib file onto YOSYS
read_verilog multiple_modules.v          // reads the .v file specified
synth -top multiple-modules              // synthesizes the design by taking specified module as top module  
abc -liberty /path to .lib file/         // links the .lib file to the design
flatten                                  // It flattens the hierarchy
show                                     // displays the synthesized design
write_verilog -noattr multiple_modules_flat.v    // writes the netlist into the specified file 
!gvim multiple_modules_flat.v            // displays the netlist file```
```

## Commands execution:- 
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/f2599e97-d266-4f63-8a2a-835bb389368c)

## Synthesized output:- 
![Synthesized output](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/73dcf440-d035-4312-ba0e-195d69c5098d)

## Output netlist:- 
![Netlist code](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ff3f9863-59a8-417a-9e49-faab5ea5c447)

## Observations:- 

- If the flatten command is used then the hierarchy is not preserved.
- There is no seperate modules for and & or sub-modules.
- The netlist of the sub-modules are written into the main module. 

 </details>


<details>
	<summary>Sub-module level synthesis  </summary>

- It is synthesizing each submodule seperately and then stiching to form the entire design.
- It is used when we have multiple instances if the same module in the design,so that the netlist can be reused.
- When the size of the design is too high,then we divide the design into sub-modules and  the synthesize it.
- Syntax:- synth -top /module-name/    // The module name specified will be synthesized.
 
 ## Commands used:- 
 ```
read_liberty -lib /path to .lib file/    // reads the .lib file onto YOSYS
read_verilog multiple_modules.v          // reads the .v file specified
synth -top sub_module1              // synthesizes the design by taking specified module as top module  
abc -liberty /path to .lib file/         // links the .lib file to the design
show                                     // displays the synthesized design
write_verilog -noattr multiple_modules_submodule1.v    // writes the netlist into the specified file 
!gvim multiple_modules_submodule1.v            // displays the netlist file

```

## Cmds execution:-
![Cmds](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/1ff1fb87-44a9-4b95-b13e-e5eb3e31c898)

## Synthesis of sub_module1:-
![and(sub-module1) synth](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/8f04faf3-68fe-4f26-82c3-e949efeb4e65)

## Synthesized output:- 
![sub-module1 synthesized op](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/e7328536-0181-4e20-aadb-47ac3164ae57)

## synthesis of sub_module2:-
![or(sub-module2) synth](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ce6f2d6c-4246-42b9-9813-12924e006903)

## Synthesized output:- 
![sub-module2 synthesized op](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/0c3e8906-df7d-4cc6-ac0a-3b494c4c2bc3)


</details>


<details>
	<summary>Why flops and folps coding style </summary>

## WHY Flops:-
- Beacuse the combinational logic in series can cause glitches.
- To store the intermediate values during execution.
- Keep the glitching values of the combinational logic away from on another.Even though the input of the flop is glitching the output of the flop will be stable
- Higher the number of comb logics, the glitches will be carrued forward so it produces outputs.
- Sync flop:- It will have both reset and clk in the sensitivity list.
- ASync flop:- It will have only clk in the sensitivity list. 
- In the example below for the b=values of a,b,c as (0,0,1) and (1,1,0) we should get an output of 1, but in this case we get the som glitched output in between.

![IMG_20230831_200528](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/9eba71be-b785-4a1b-997a-9e68702a9ba5)

<details>
	<summary>Async reset:-</summary>

- Irrespective of the clk if the reset it turned to 1(posedge) the output will be set to 0.
- After the reset it turned dowm to 0 the output copies the data on every posedge of clk.
### Cmds used:- 
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/f33fb534-858d-4343-bd4e-86c031564e02)

### Code:- 
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/ff35d66f-2fdb-4a3a-9895-e497d69ffee7)

### GTKWave output:- 
![image](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/7f0b3fba-fffa-428c-8fda-3e6c6bdd6258)

</details>

<details>
<summary>Async set:-</summary>

 - Irrespective of the clk if the set it turned to 1(posedge) the output will be set to 1.
- After the set it turned dowm to 0 the output copies the data on every posedge of clk.

### Cmds used:-
![cmds](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/d544f867-63bc-482b-99f2-2e9647a0fe66)
 
### Code:- 
![code](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/2ab9d175-81cb-4f73-ac06-f7748051eb9f)

### GTKwave output:-
![wave](https://github.com/Karthik-6362/pes_asic_class/assets/137412032/cc2e6e86-88f3-4887-8726-12252692afd1)

</details>

 
</details>


