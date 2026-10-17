# Push Swap

A C sorting project that emits a sequence of stack operations to arrange a
list of distinct integers in ascending order. Developed as part of the 42
curriculum to practice algorithm design, input validation, and operation-cost
analysis under a restricted instruction set.

The output is a program of stack instructions, not the sorted numbers.

## Build

Requirements: a C compiler, Make, Git, and a Unix-like environment. The project
uses `libft` as a pinned Git submodule.

```sh
git clone --recurse-submodules https://github.com/civanaban2/push-swap.git
cd push-swap
make
```

The output executable is `build/push_swap`. Sources compile with
`-Wall -Wextra -Werror`, and the Makefile builds `libft/libft.a` as needed.

### Submodule access

The checked-in `.gitmodules` uses an SSH URL for libft, so the recursive clone
requires GitHub SSH access. For a public HTTPS-only checkout instead:

```sh
git clone https://github.com/civanaban2/push-swap.git
cd push-swap
git submodule init
git config submodule.libft.url https://github.com/civanaban2/libft.git
git submodule update --recursive
make
```

That setting changes only the local Git configuration, not `.gitmodules` or
the pinned libft revision. For an existing SSH-capable clone, initialize with
`git submodule update --init --recursive`.

## Usage

```sh
./build/push_swap 3 2 1
./build/push_swap "3 2 1"
./build/push_swap "3 2" 1
```

Pass distinct signed 32-bit integers, either as separate arguments or in
space-separated quoted groups. Arguments containing tabs are not equivalent
to groups separated by literal spaces in the current parser.

The program prints one operation per line to standard output. A sorted input
or an invocation without arguments produces no instructions. Validation
failures such as duplicates, non-integer tokens, or out-of-range values print
`Error` to standard error and exit with a nonzero status.

Count the generated instructions:

```sh
make count ARG="5 1 4 2 3"
```

An instruction count is not a correctness check. To check a sequence, use an
independent checker that applies the operations and confirms stack A is sorted
and stack B is empty.

## Sorting approach

The implementation keeps the two logical stacks in a shared integer array.
It handles small inputs separately and, for larger inputs:

1. Moves two values from stack A to stack B.
2. Evaluates candidate transfers using forward, reverse, and mixed rotations.
3. Chooses the candidate with the lowest calculated rotation cost.
4. Combines same-direction rotations where possible using `rr` or `rrr`.
5. Sorts the remaining small stack A and merges values back from stack B.

This is a cost-based heuristic; it does not establish that the emitted sequence
has the globally minimum number of instructions. No benchmark guarantees are
claimed here.

## Instruction vocabulary

| Instruction | Meaning |
| --- | --- |
| `sa` | Swap the top two values in A |
| `pa` / `pb` | Move the top value from B to A / A to B |
| `ra` / `rb` | Rotate A / B upward |
| `rr` | Rotate both stacks upward |
| `rra` / `rrb` | Reverse-rotate A / B |
| `rrr` | Reverse-rotate both stacks |

The stack-operation stream can be piped into a compatible checker. Stack
operations are logical instructions; the program does not launch other tools
to perform them.

## Make targets

| Target | Action |
| --- | --- |
| `make` | Build the program and libft dependency |
| `make clean` | Remove project object files |
| `make fclean` | Also remove the executable directory and clean libft |
| `make re` | Clean and rebuild; run without parallel `-j` |
| `make count ARG="..."` | Count output lines for the supplied input |
| `make test ARG="..."` | Invoke the external Linux checker via the tester target |
| `make tester ARG="..."` | Pipe output directly into that checker |
| `make leak ARG="..."` | Run Valgrind, if installed |

The test targets expect `checker/checker_linux`, which is **not included** in
the current checkout. They do not download or build it automatically. A Linux
checker binary is not directly executable on macOS. The `tester` recipe also
ignores its command's failure status, so read the checker result rather than
treating Make's exit status as proof of correctness.

## Structure

```text
Makefile
.gitmodules
inc/push_swap.h
src/
  push_swap.c             # Entry point
  arg_check*.c            # Token validation and array setup
  sort*.c                 # Sorting, stack movement and final merge
  cost.c, cost_utils.c    # Candidate rotation costs
  print_utils.c           # Operation output
  free_split.c            # Split-token cleanup
libft/                    # Pinned Git submodule
```

The implementation is an educational command-line program. It assumes
four-byte integers in some memory-copy operations, and allocation-failure
handling and parser edge cases need further review. This documentation update
does not alter those implementation details.

## License

MIT. See [LICENSE](LICENSE). The libft dependency retains its own repository
history and files.
