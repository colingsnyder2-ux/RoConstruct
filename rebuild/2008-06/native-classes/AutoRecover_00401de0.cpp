// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// ATL CRegParser::CParseBuffer layout
struct CParseBuffer {
    int m_nPos;      // +0
    int m_nBufSize;  // +4
    char* m_pBuf;    // +8
};

extern "C" int fn_00401810(char* dst, unsigned size, const char* src, unsigned count); // Checked::tcsncpy_s (cdecl)

extern "C" int __fastcall fn_00401de0(CParseBuffer* self, int unusedEdx, const char* pch, int nChars)
{
    int newSize = self->m_nPos + nChars + 1;
    if (newSize <= self->m_nPos || newSize <= nChars)
        return 0;

    if (newSize >= self->m_nBufSize) {
        do {
            if (self->m_nBufSize > 0x3fffffff)
                return 0;
            self->m_nBufSize *= 2;
        } while (newSize >= self->m_nBufSize);

        // INFERRED: ATL AtlMultiply(size_t) 64-bit overflow check on m_nBufSize * sizeof(char);
        // old buffer pointer read before the check to match the original load scheduling
        char* pOld = self->m_pBuf;
        unsigned long long ull = (unsigned long long)(unsigned)self->m_nBufSize * (unsigned long long)sizeof(char);
        if (ull > 0xFFFFFFFFull)
            return 0;
        char* pTemp = (char*)CoTaskMemRealloc(pOld, (ULONG)ull);
        if (pTemp == 0)
            return 0;
        self->m_pBuf = pTemp;
    }

    if (self->m_nPos < 0 || self->m_nPos >= self->m_nBufSize)
        return 0;
    if (self->m_nBufSize - self->m_nPos > self->m_nBufSize)
        return 0;

    fn_00401810(self->m_pBuf + self->m_nPos, self->m_nBufSize - self->m_nPos, pch, nChars);
    self->m_nPos += nChars;
    self->m_pBuf[self->m_nPos] = 0;
    return 1;
}
