# c-encoder-decoder-operations
A project that simulates a simple miniprocessor that can execute arithmetic operations (addition, subtraction, multiplication, and division) on numbers of a specified dimension. The processor reads encoded instructions, which are unsigned integers that contain information about the operations to be performed and the dimension of the numbers involved.

# Table of Contents
1. [About the project](#start-description)
2. [Building the Project](#build-description)
3. [Conclusion](#use-description)

<a name="start-description"></a>
## About the project

The project simulates a simple **miniprocessor** that can execute arithmetic operations (addition, subtraction, multiplication, and division) on numbers of a specified dimension. The processor reads **encoded** instructions, which are unsigned integers that contain information about the operations to be performed and the dimension of the numbers involved:

* First 3 bits are for **number of operations** <= 8
* The next **2 * number_of_operations** bits are for the operations itself "+, -, *, /"
* The next 4 bits are for **dimension** of an operation member (If you want to add numbers of 11 bits that the dimension has to be **11**) <= 16 (working with short ints)

The project comes with **three** source files: encoder.c, opernum.c, and decoder.c.

* **encoder.c** - The file that will take your instruction and will encode it for the program processor.

* **opernum.c** - Takes an encoded instruction and determines the number of operator members (i.e., numbers that will be used in the operations). An operator member is a **unsigned short int** number that we will extract the desired numbers of desired dimension.

* **decoder.c** - Takes an encoded instruction and the operator members and performs the specified operations.
  You should provide for the program the encoded instruction and the **operator members** (short ints). The program has 4 modes:
    * (0) Show the decoded instruction in the specified file
    * (1) Execute the instruction considering that the dimension is a power of two from
      [1, 16] and the precendence of the operators does NOT matter.
    * (2) Execute the instruction considering that the dimension is any number form [1, 16]
      and the precedence of the operators does NOT matter.
    * (3) Execute the instruction considering that the dimension is any number form [1, 16]
      and the precedence of the operators DOES matter.

<a name="build-description"></a>
## Building the Project

To use this project, you will need a C compiler such as GCC installed on your machine.

To begin, clone the project and change the directory into it, then run the make command to build the project:

```BASH
    cd build
    make
```

After above commands you will get 3 executables:

* encoder
* opernum
* decoder

To clean up the project directory, run the following command:

```BASH
    make clean
```

<a name="use-description"></a>
## Conclusion

This project provides a simple implementation of a miniprocessor that can execute arithmetic operations on numbers of a specified dimension. With this project, you can learn about bitwise operators and how they can be used to perform arithmetic operations. Have fun experimenting with it!

---

