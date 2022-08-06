# Note Keeper

This was a small exercise we did for the purpose of learning/reviewing C

## Build

```bash
gcc  main.c file_operations.c note.c ui.c -Wall -o main.exe
```

## Run

```bash
./main.exe
```

## Debug (VS Code)
```bash
# "-g" flag creates debug symbols
gcc -g main.c file_operations.c note.c ui.c -Wall -o main.exe
```

From VS Code, run the debugger