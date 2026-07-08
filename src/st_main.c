#include "st_lexer.h"
#include "st_types.h"
#include "st_string.h"

int main(void)
{
    const char *path = "main.st";
    ST_string_t sv = {0};
    ST_arena_t *arena = ST_arena_alloc();
    if (ST_read_entire_file(arena, &sv, path) < 0) return 1;

    printf(ST_sv_fmt, ST_sv_args(sv));

    ST_arena_free(arena);
    return 0;
}
