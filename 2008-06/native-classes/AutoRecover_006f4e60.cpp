// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afx.h>
#include <mbctype.h>

#pragma inline_depth(0)

// INFERRED: Control flow follows the vendor implementation. Byte-exact codegen
// remains unverified; the target has a security cookie despite the required /GS-.
extern "C" CString __cdecl fn_006f4e60(const CString& text, int number)
{
    CString escaped;
    const char* src = text;
    char* dst = escaped.GetBuffer(text.GetLength() * 2);

    while (*src != 0)
    {
        if (*src == '&')
            *dst++ = '&';

        if (_ismbblead(*src))
            *dst++ = *src++;
        *dst++ = *src++;
    }

    *dst = 0;
    escaped.ReleaseBuffer();

    CString result;

    if (number == 0)
        return escaped;

    if (number < 10)
        result.Format("&%i %s", number, (const char*)escaped);
    else if (number == 10)
        result.Format("1&0 %s", (const char*)escaped);
    else
        result.Format("%i %s", number, (const char*)escaped);

    return result;
}
