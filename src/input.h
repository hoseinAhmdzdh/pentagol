#pragma once

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Read one complete token so a mistyped value cannot spill into the next turn. */
static inline int read_choice(const char *prompt, const char *choices)
{
    for (;;) {
        fputs(prompt, stdout);
        fflush(stdout);
        int key;
        do {
            key = getchar();
        } while (key != EOF && isspace(key));
        if (key == EOF) return 0;

        int next = getchar();
        if ((next == EOF || isspace(next)) && key && strchr(choices, key))
            return key;
        while (next != EOF && !isspace(next))
            next = getchar();
        puts("Invalid choice. Try again.");
    }
}
