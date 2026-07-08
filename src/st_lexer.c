#include "st_lexer.h"

ST_string_t ST_token_kind_to_string(ST_token_kind_t kind)
{
#if (ST_TCOUNT > 10)
    #error "ST_TCOUNT is exceeded"
#endif
    switch(kind)
    {
    case ST_TINT:       return ST_cstr_to_str("ST_TINT");
    case ST_TFLOAT:     return ST_cstr_to_str("ST_TFLOAT");
    case ST_TSTRING:    return ST_cstr_to_str("ST_TSTRING");
    case ST_TCHAR:      return ST_cstr_to_str("ST_TCHAR");
    case ST_TIDENT:     return ST_cstr_to_str("ST_TIDENT");
    case ST_TTYPE:      return ST_cstr_to_str("ST_TTYPE");
    case ST_TKEYWORD:   return ST_cstr_to_str("ST_TKEYWORD");
    case ST_TSYMBOL:    return ST_cstr_to_str("ST_TSYMBOL");
    case ST_TDOCCOMENT: return ST_cstr_to_str("ST_TDOCCOMENT");
    case ST_TCOUNT: default: ST_assert(1);
    }

    return (ST_string_t) {
        .data = NULL,
        .len = 0,
    };
}

b32 ST_iswhitespace(char c)
{
    static char buf[] = { '\r', '\n', '\t', ' ' };
    ST_forrange(0, sizeof(buf))  if (c == buf[i]) return 0;
    return -1;
}

void ST_lexer_consume_char(ST_lexer_t *l)
{
    ST_unused(l);
}

void ST_lexer_consume_peek(ST_lexer_t *l);
