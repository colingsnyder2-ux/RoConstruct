// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// ATL CRegParser::SkipWhiteSpace analog: advance past space/tab/CR/LF.
#include <windows.h>

// INFERRED: ATL CRegParser, m_pchCur at offset 0 (binary reads [ecx] as the cursor)
struct CRegParser {
    char* m_pchCur;
};

extern "C" void __fastcall fn_00402000(CRegParser* self, int unusedEdx)
{
    for (;;) {
        switch (*self->m_pchCur) {
        case ' ':
        case '\t':
        case '\n':
        case '\r':
            self->m_pchCur = ::CharNextA(self->m_pchCur);
            continue;
        default:
            return;
        }
    }
}
