// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string.h>

// INFERRED: ATL::CSimpleStringT<char,0>::SetString(const char*, int); layout is m_pszData with a CStringData header before it.
struct FnSimpleStr {
    char* m_pszData;
};

struct FnStringData {
    // header lives at m_pszData - 0xc
    int nDataLength;
    int nAllocLength;
    int nRefs;
};

extern "C" void __fastcall fn_0055c190(FnSimpleStr* self, int unusedEdx);
extern "C" void __stdcall fn_00401000(long hr);
extern "C" void __fastcall fn_00407400(FnSimpleStr* self, int unusedEdx, int nLength);

static inline FnStringData* hdr(FnSimpleStr* s)
{
    return (FnStringData*)s->m_pszData - 1;
}

extern "C" void __fastcall fn_0055d950(FnSimpleStr* self, int unusedEdx, const char* pszSrc, int nLength)
{
    if (nLength == 0) {
        fn_0055c190(self, 0);
        return;
    }
    if (pszSrc == 0)
        fn_00401000(0x80070057L);

    unsigned int oldLen = hdr(self)->nDataLength;
    int offset = (int)(pszSrc - self->m_pszData);

    if (((1 - hdr(self)->nRefs) | (hdr(self)->nAllocLength - nLength)) < 0)
        fn_00407400(self, 0, nLength);

    char* data = self->m_pszData;
    if ((unsigned int)offset <= oldLen)
        memmove_s(data, hdr(self)->nAllocLength, data + offset, nLength);
    else
        memcpy_s(data, hdr(self)->nAllocLength, pszSrc, nLength);

    if (nLength < 0 || nLength > hdr(self)->nAllocLength)
        fn_00401000(0x80070057L);
    hdr(self)->nDataLength = nLength;
    self->m_pszData[nLength] = 0;
}
