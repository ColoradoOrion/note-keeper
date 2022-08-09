#pragma once

#include "const.h"
#include <stdbool.h>

struct Note
{
    char title[TITLE_LENGTH + 1];
    char content[CONTENT_LENTGH + 1];
    bool isValid;
};

void clearNote(struct Note * note);

void generateNotePath(char *operation, char title[], char path[]);

void removeNewLine(char value[]);