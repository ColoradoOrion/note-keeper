#include "const.h"
#include "note.h"
#include <stdio.h>
#include <string.h>

void create(struct Note *note)
{
    clearNote(note);

    char path[PATH_LENGTH];
    generateNotePath("CREATE", note->title, path);

    printf("CREATE - Enter note content: ");
    fgets(note->content, sizeof(note->content), stdin);
    removeNewLine(note->content);

    FILE *filePointer = fopen(path, "w");
    fputs(note->title, filePointer);
    fputs("\n", filePointer);
    fputs(note->content, filePointer);
    fclose(filePointer);
}

void delete (struct Note *note)
{
    char title[TITLE_LENGTH];

    char path[PATH_LENGTH];
    generateNotePath("CREATE", title, path);

    if (remove(path) == 0)
    {
        printf("%s removed\n", path);
        clearNote(note);
    }
    else
    {
        printf("Unable to remove %s\n", path);
    }
}

void read(struct Note *note)
{
    clearNote(note);

    char path[PATH_LENGTH];
    generateNotePath("READ", note->title, path);

    FILE *filePointer = fopen(path, "r");
    if (filePointer != NULL)
    {
        fgets(note->title, sizeof(note->title), filePointer);
        removeNewLine(note->title);

        fgets(note->content, sizeof(note->content), filePointer);
        fclose(filePointer);
    }
    else
    {
        printf("No note with title \"%s\" exists", note->title);
    }
}