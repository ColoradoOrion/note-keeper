#include <stdio.h>
#include "note.h"
#include "file_operations.h"

void printBanner()
{
    printf("===============================================================\n"
           "                           Note Keeper\n"
           "===============================================================\n");
}

void printOptions()
{
    printf("Enter command: (c)reate, (r)ead, (a)ppend, (d)elete, (q)uit: ");
}

void runProgram()
{
    struct Note activeNote;
    clearNote(&activeNote);

    char command;
    do
    {
        printOptions();

        // print options
        command = getchar();
        getchar(); // remove trainling new line from buffer

        switch (command)
        {
        case 'c':
        case 'C':
            create(&activeNote);
            break;
        case 'r':
        case 'R':
            read(&activeNote, true);
            break;
        case 'a':
        case 'A':
            append(&activeNote);
            break;
        case 'd':
        case 'D':
            delete (&activeNote);
            break;
        }

    } while (command != 'q' && command != 'Q');

    printf("Goodbye!\n");
}