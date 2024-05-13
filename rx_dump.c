#include <stdio.h>
#include "rx_dump.h"

#define NBSP "&nbsp;"
const char szIndents[] = "                                                                                                                                                                                                                                      ";
const char szHtmlIndent[] =
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP NBSP
        ;

#define MAX_HTML_INDENT ((sizeof(szHtmlIndent)-1)/(sizeof(NBSP)-1))

const char* GetIndentStr(uint32_t indent) {
    if (indent >= sizeof (szIndents)) {
        indent = sizeof (szIndents) - 1;
    }
    return szIndents + sizeof (szIndents) - 1 - indent;
}

const char* GetIndentStrEx(uint32_t indent, bool for_html) {
    if (for_html) {
        if (indent > MAX_HTML_INDENT) {
            return szHtmlIndent;
        }
        return szHtmlIndent + sizeof (szHtmlIndent) - 1 - indent * (sizeof (NBSP) - 1);
    } else {
        return GetIndentStr(indent);
    }
}
