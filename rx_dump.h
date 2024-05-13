#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    const char* GetIndentStr(uint32_t indent);
    const char* GetIndentStrEx(uint32_t indent, bool for_html);

#ifdef __cplusplus
}
#endif

