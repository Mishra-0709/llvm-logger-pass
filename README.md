🛠️ LLVM Function Analyzer Pass
This project implements a custom LLVM compiler pass that analyzes LLVM IR to extract information such as function counts, instruction statistics, or apply basic optimizations. It is built using the LLVM Pass framework and written in C++.

📌 Project Overview
The LLVM Function Analyzer is a simple yet educational example of how you can:

Develop a custom analysis pass using the LLVM framework

Traverse IR (Intermediate Representation) to gather statistics

Understand and manipulate LLVM IR for optimization purposes

This is especially useful for students or professionals exploring compiler development, LLVM internals, or low-level program analysis.

⚙️ Features
Counts the number of functions defined in the LLVM IR file

Counts and classifies instructions used across all functions

Prints output statistics to terminal after running the pass

🧑‍💻 Requirements
Ensure the following tools are installed on your system:

CMake (>= 3.13)

LLVM & Clang (version 16 or above)

Git

C++ compiler (supporting C++17 or later)

