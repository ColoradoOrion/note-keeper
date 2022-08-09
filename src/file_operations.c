#include "../include/file_operations.h"
#include "../include/note.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

    note->isValid = true;
}

void delete (struct Note *note)
{
    char title[TITLE_LENGTH];
    title[0] = '\0';

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

void read(struct Note *note, bool displayWhenActive)
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
        note->isValid = true;

        if (displayWhenActive)
        {
            printf("Active note is now \"%s\"\n", note->title);
            printf("Content:\n%s\n", note->content);
        }
    }
    else
    {
        printf("No note with title \"%s\" exists. No active note.\n", note->title);
        clearNote(note);
    }
}

void append(struct Note *note)
{
    read(note, false);
    if (note->isValid)
    {
        printf("APPEND - Add content to note: ");
        char newContent[CONTENT_LENTGH];
        fgets(newContent, CONTENT_LENTGH, stdin);
        removeNewLine(newContent);

        int newContentLength = strlen(newContent);
        int oldContentLength = strlen(note->content);

      /*   if(newContentLength + oldContentLength + 1 > CONTENT_LENTGH){
            strcspn()
        } */

        char path[PATH_LENGTH];
        generateNotePath("APPEND", note->title, path);
        FILE *filePointer = fopen(path, "a");
        if (filePointer)
        {
            fputs(" ", filePointer);
            fputs(newContent, filePointer);
            fclose(filePointer);
        }
        else
        {
            printf("%s not found for appending", path);
            clearNote(note);
        }
    }
}