#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "file_operations.h"
#include "note.h"
#include "ui.h"

int main()
{

    printBanner();

    struct Note activeNote;
    clearNote(&activeNote);

    // loop while action
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
            read(&activeNote);
            printf("Active note is now \"%s\"\n", activeNote.title);
            printf("Content:\n%s\n", activeNote.content);
            break;
        case 'u':
        case 'U':
            // update
            printf("UPDATE - Enter a note title: ");
            read(&activeNote);

            break;
        case 'd':
        case 'D':
            delete (&activeNote);
            break;
        }

    } while (command != 'q' && command != 'Q');

    printf("Goodbye!\n");

    return 0;
}