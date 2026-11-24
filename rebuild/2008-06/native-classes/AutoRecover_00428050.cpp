// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afx.h>
#include <shlwapi.h>
#include <string>
#include <new>
#include <string.h>

// INFERRED: layout of the owning object; only the std::string at +0x30 is used.
struct LogOwner {
    char pad[0x30];
    std::string name;
};

// Free stdcall function returning a CString through a hidden pointer.
// The disassembly loads ecx with this+4 before the call; that is probably dead, so it is ignored here.
CString __stdcall logDirectory();

// INFERRED: arg1 is the hidden return slot (std::string*), arg2 is the suffix (const char*).
extern "C" std::string* __fastcall fn_00428050(LogOwner* self, int unusedEdx,
                                               std::string* out, const char* suffix)
{
    CString path = logDirectory();

    std::string fileName("log_");
    fileName += self->name;
    fileName.erase(12, std::string::npos);
    fileName.erase(4, 3);
    fileName += suffix;
    fileName += ".txt";

    const char* file = fileName.c_str();
    int need = (int)strlen(file) + path.GetLength() + 1;
    PathAppendA(path.GetBuffer(need), file);
    path.ReleaseBuffer(-1);

    new (out) std::string((LPCSTR)path);
    return out;
}
