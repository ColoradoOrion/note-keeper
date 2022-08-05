#include <stdio.h>
#include <string.h>

#define TITLE_LENGTH 20
#define CONTENT_LENTGH 255
#define FILE_LENGTH 30
#define PATH_LENGTH 100

struct Note
{
    char title[TITLE_LENGTH + 1];
    char content[CONTENT_LENTGH + 1];
};

void clearNote(struct Note *note)
{

    memset(note->title, 0, TITLE_LENGTH * sizeof(note->title[0]));
    memset(note->content, 0, CONTENT_LENTGH * sizeof(note->content[0]));
}

void removeNewLine(char value[])
{
    value[strcspn(value, "\n")] = 0;
}

void generateNotePath(char *operation, char title[], char path[])
{

    printf("%s - Enter a note Title: ", operation);

    fgets(title, TITLE_LENGTH, stdin);
    removeNewLine(title);

    snprintf(path, PATH_LENGTH, "./%s.txt", title);
}

void create()
{
    struct Note note;
    clearNote(&note);

    char path[PATH_LENGTH];
    generateNotePath("CREATE", note.title, path);

    printf("CREATE - Enter note content: ");
    fgets(note.content, sizeof(note.content), stdin);
    removeNewLine(note.content);

    FILE *filePointer = fopen(path, "w");
    int i = fputs(note.title, filePointer);
    i = fputs("\n", filePointer);
    i = fputs(note.content, filePointer);
    fclose(filePointer);
}

void delete ()
{
    char title[TITLE_LENGTH];

    char path[PATH_LENGTH];
    generateNotePath("CREATE", title, path);

    if (remove(path) == 0)
    {
        printf("%s removed\n", path);
    }
    else
    {
        printf("Unable to remove %s\n", path);
    }
}

void read(struct Note * note)
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

int main()
{
    // greeting

    printf("===============================================================\n"
           "                           Note Keeper\n"
           "===============================================================\n");

    struct Note activeNote;
    clearNote(&activeNote);

    // loop while action
    char command;
    do
    {

        printf("Enter command: (c)reate, (r)ead, (u)pdate, (d)elete, (q)uit: ");

        // print options
        command = getchar();
        getchar();

        switch (command)
        {
        case 'c':
        case 'C':
            create();
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
            break;
        case 'd':
        case 'D':
            delete ();
            break;
        }

    } while (command != 'q' && command != 'Q');

    printf("Goodbye!\n");

    return 0;
}