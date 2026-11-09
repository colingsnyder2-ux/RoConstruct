// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0 roc_espclaude_14507603bc13e812.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL
#endif
#include <windows.h>
#include <atlstr.h>

extern CStringA __cdecl makeString(int);

void cleanFiles()
{
    CStringA path = makeString(0);
    WIN32_FIND_DATAA entry;
    if (path != "") {
        HANDLE handle = FindFirstFileA(path + "*.*", &entry);
        if (handle != INVALID_HANDLE_VALUE) {
            do {
                if (!(entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                    DeleteFileA(path + entry.cFileName);
            } while (FindNextFileA(handle, &entry));
        }
    }
}
