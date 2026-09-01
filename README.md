# C Data Modeling Problem Set

Solutions for Set 8 of PCLP (Programarea Calculatoarelor și Limbaje de Programare), a first-year course at the Faculty of Automatic Control and Computers, University POLITEHNICA of Bucharest. This set is about structures in C.

## What's inside

Each `.c` file is a separate exercise, meant to be compiled and run on its own.

- `p1.c` — adds and subtracts two complex numbers, stored as a struct with real and imaginary parts
- `p2.c` — adds two time values (hours, minutes, seconds), carrying over correctly at 60
- `p3.c` — reads a list of companies and products, then finds who has the most/least stock of a given product
- `p4.c` — a struct that contains another struct (date + time), just to show how nesting works
- `p5.c` — asks for a shape (circle, square, rectangle) and computes its perimeter; also has a commented-out version using a union instead
- `p6.c` — a small student gradebook: search a student by name, find the top grade in a subject, compute averages, sort by grade, list failing students
- `p7.c` / `p7_var2.c` — two versions of a book catalog (title, year, author): search by author, find the author with most books, sort titles alphabetically, etc. Same problem, written two different ways
- `p8.c` / `p8_var2.c` — same idea but for a list of people, using their CNP (Romanian personal ID number) to work out their birth date and sort by it

## How to run

Compile any file with gcc and run it:

```bash
gcc p6.c -o p6
./p6
```

`p5.c` needs the math library:

```bash
gcc p5.c -o p5 -lm
./p5
```

Everything is read from the console (no input files), and the prompts are in Romanian since that's how the original assignment was given.

## Notes

- No input validation to speak of — it's lab code, not production code
- Array sizes are hardcoded (small enough for the exercises)
- `p7`/`p7_var2` and `p8`/`p8_var2` solve the same problem two different ways, kept on purpose for comparison
