#include <wchar.h>
#include <locale.h>
#include "libc.h"

/* collate only by code points */
// ANDROID: Was __wcsxfrm_l in Musl
size_t wcsxfrm_l(wchar_t *restrict dest, const wchar_t *restrict src, size_t n, locale_t loc)
{
        size_t l = wcslen(src);
        if (l < n) {
                wmemcpy(dest, src, l+1);
        } else if (n) {
                wmemcpy(dest, src, n-1);
                dest[n-1] = 0;
        }
        return l;
}

size_t wcsxfrm(wchar_t *restrict dest, const wchar_t *restrict src, size_t n)
{
        return wcsxfrm_l(dest, src, n, 0);
}

weak_alias(__wcsxfrm_l, wcsxfrm_l);
