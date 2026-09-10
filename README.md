# Typing Practice Program (C)

A simple command-line typing practice tool written in C. It shows the user
some text and checks whether they typed it correctly. If they make a
mistake, they are asked to try the same line again.

## Features

- **Beginner Level** – Practice with 5 random lowercase letters, generated
  using `rand()`. A new random string is generated for each round.
- **Medium Level** – Practice with everyday sentences.
- **Advanced Level** – Practice with tougher sentences that include
  punctuation, capital letters, and numbers.
- Retry loop: if you type a line incorrectly, you're asked to try it again
  until it matches exactly.
- Simple menu at the start lets you pick your level using `switch`.

## How It Works

1. The program prints instructions on how to play.
2. You choose a level (1, 2, or 3).
3. A line of text is shown to you.
4. You type it exactly as shown and press Enter.
5. The program compares your input to the original text using `strcmp()`.
   - If it matches, you move to the next line.
   - If it doesn't match, you're asked to try the same line again.
6. Once all lines/rounds in the level are done, the program ends.

## Level Details

| Level    | Content                              | Implementation             |
|----------|----------------------------------------|-----------------------------|
| Beginner | 5 random lowercase letters, 5 rounds   | Inline code (no function)  |
| Medium   | 5 pre-written sentences                | `mediumLevel()` function   |
| Advanced | 5 sentences with punctuation & numbers | `advancedLevel()` function |

## Requirements

- A C compiler (e.g. `gcc`)
- Works on Linux, macOS, or Windows (with a C compiler installed)

## How to Compile and Run

```bash
gcc typing_practice.c -o typing_practice
./typing_practice
```

On Windows (using MinGW):

```bash
gcc typing_practice.c -o typing_practice.exe
typing_practice.exe
```

## Example Run

```
==========================================
   WELCOME TO THE TYPING PRACTICE PROGRAM
==========================================

HOW TO PLAY:
1. A line of text will be shown to you on the screen.
2. Type that exact same text using your keyboard.
...

Choose your level
1. Beginner (random letters)
2. Medium (sentences)
3. Advanced (tougher sentences)
2

Type this: programming is fun and challenging
> programing is fun and challenging
Wrong, try again.

Type this: programming is fun and challenging
> programming is fun and challenging
Correct!
...

You finished the level! Great job.
```

## Key C Concepts Used

- `rand()` and `srand(time(NULL))` – generating random letters for the
  beginner level.
- 2D character arrays (`char sentences[5][100]`) – storing multiple
  sentences without using pointer syntax.
- `fgets()` – reading a full line of input (including spaces).
- `strcspn()` – removing the trailing newline character left by `fgets()`.
- `strcmp()` – comparing the user's input to the target text.
- `switch` statement – letting the user pick a difficulty level.
- Functions with array parameters (`char sentences[][100]`) – used for the
  medium and advanced levels, written with `[]` notation instead of
  pointer syntax.

## Possible Improvements (Ideas for Later)

- Track number of attempts per sentence and show a score at the end.
- Increase beginner difficulty each round (more random letters per round).
- Add a timer to calculate typing speed (WPM).
- Let the user add their own custom practice sentences.
- Merge `mediumLevel()` and `advancedLevel()` into a single reusable
  function since their logic is identical.

## Notes

This is a beginner-level C project built for learning purposes — focused
on practicing loops, arrays, string handling, and basic program structure
rather than advanced features like pointers or dynamic memory.
