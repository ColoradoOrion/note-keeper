#pragma once
#include "note.h"

void append(struct Note *note);

void create(struct Note *note);

void delete (struct Note *note);

void read(struct Note *note, bool displayWhenActive);