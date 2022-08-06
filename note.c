#include "note.h"
#include <string.h>
#include <stdio.h>
#include "file_operations.h"

void clearNote(struct Note *note)
{
    memset(note->title, 0, TITLE_LENGTH * sizeof(note->title[0]));
    memset(note->content, 0, CONTENT_LENTGH * sizeof(note->content[0]));
    note->isValid = false;
}

void generateNotePath(char *operation, char title[], char path[])
{

    if (title[0] == '\0')
    {
        printf("%s - Enter a note Title: ", operation);

        fgets(title, TITLE_LENGTH, stdin);
        removeNewLine(title);
    }

    snprintf(path, PATH_LENGTH, "db/%s.txt", title);
}

void removeNewLine(char value[])
{
    value[strcspn(value, "\n")] = 0;
}