// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_folderprivatecontext64f515c78711e091.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
typedef std::string String;
extern "C" {
    extern long (__stdcall *SHGetSpecialFolderLocation)(void*, int, void**);
    extern int (__stdcall *SHGetPathFromIDListA)(const void*, char*);
}

static __declspec(noinline) String getFolderPath(int folder)
{
    String result;
    void* item;
    char path[260];

    if (SHGetSpecialFolderLocation(0, folder, &item) >= 0) {
        if (SHGetPathFromIDListA(item, path))
            result = path;
    }

    return result;
}

extern void consumeFolderPath(const String&);
void inspectFolder(int folder){consumeFolderPath(getFolderPath(folder));}
