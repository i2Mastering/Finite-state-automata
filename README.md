# Finite State Automaton (FSA) in C++

## Overview
This project implements a **Finite State Automaton (FSA)** in C++ that processes strings containing the characters `{a, b, c}` and determines whether they are accepted or rejected based on predefined state transitions.

## Features
- Implements **state transitions** using an enumeration.
- Processes input character by character.
- Determines if the string is **accepted** based on state rules.
- Handles user input dynamically.

## How It Works
1. **Initialize the Automaton**: An `FSA` object is created.
2. **Process Input**:
   - The user enters a string consisting of `a, b, c`, followed by `.`.
   - The automaton processes each character according to its current state.
3. **State Transitions**:
   - Moves between predefined states (`Start, dotA, dotB, dotBB, retT, retF`).
   - The string is **accepted** if it reaches `retT`, otherwise, it is rejected.
4. **Output Result**: Displays whether the input string is accepted or not.

## Installation
Ensure you have a C++ compiler installed. You can use **GCC** or **MSVC**.

## Compilation & Execution
### Using g++
```bash
g++ -o fsa fsa.cpp
./fsa
```
### Using MSVC (Windows)
```powershell
cl fsa.cpp
fsa.exe
```

## Example Output
```
Enter a string (alphabet{a,b,c}) followed by '.': aba.
String is accepted!
```

## License
This project is open-source and free to use.
