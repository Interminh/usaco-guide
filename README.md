# usaco-guide

This repository is my personal working collection of solved USACO problems (starting with Bronze-level material). The goal is simple: practice problem-solving patterns, keep clean C++ implementations, and leverage different tools in my competitive coding journey.

Below is a quick tour of what’s in the repo right now, how to run the solutions, and a few notes about maintenance and contribution.

---

## What’s in this repo (by topic)
- Baseline knowledge/
  - Short, fundamental problems used to build intuition. Examples: `abc.cpp`, `teleport.cpp`. These are often one-file solutions that focus on basic array/logic operations.
- Complete Search/
  - Problems that rely on brute-force / exhaustive search and combinatorial enumeration. Example: `checkup.cpp`, `tracing.cpp`.
- Input and Output/
  - IO-focused exercises and small examples demonstrating reading/writing formats and fast IO techniques. Example: `paint.cpp`, `weird.cpp`.
- Simulation/
  - Problems modeled as step-by-step simulation of a system (often with time steps or discrete events). Examples: `blocks.cpp`, `rut.cpp`, `speeding.cpp`.
- Templates/
  - Reusable snippets I paste into problem files (fast input/output, debug header). Files: `fastInputOutput.txt`, `debugHeader.txt`.
- .vscode/
  - Personal editor settings (safe to ignore if you use a different editor).

Notes: many directories currently include compiled artifacts (Windows `.exe` files) and occasional `.out` sample outputs; the canonical source files are the `.cpp` files.

---

## Language & approach
- Language: C++ (standard library + STL)
- Style: Single-file, self-contained solutions designed for competitive programming (read from stdin, write to stdout).
- No external build system: each `.cpp` is compiled individually with a C++ compiler.

---

## How to compile and run
Pick a source file and compile with your preferred compiler (example uses g++):

- Compile:
  - g++ -std=c++17 -O2 "Simulation/blocks.cpp" -o blocks
- Run (stdin or redirect from a file):
  - ./blocks < input.txt

If you prefer to compile many files at once, a small Makefile or script could be added (see “Suggestions” below).

---

## Contribution & usage
- This repository is primarily a personal notebook. If you find an issue with a solution or want to suggest an improvement (style, performance, or better templates), feel free to open a PR.
- If you want to add problem statements or move binaries into a `.bin/` folder, that would help keep the repo focused on readable source code.

---


