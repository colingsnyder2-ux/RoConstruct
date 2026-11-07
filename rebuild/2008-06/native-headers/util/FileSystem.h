#pragma once
// >>> native-status (generated) -- do not edit >>>
// FileSystem | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src da515e6d | roc native-status --write
#include <shlobj.h>
#include <string>

namespace RBX
{
    class VistaAPIs
    {
        typedef struct _TOKEN_MANDATORY_LABEL
        {
            SID_AND_ATTRIBUTES Label;
        } TOKEN_MANDATORY_LABEL, *PTOKEN_MANDATORY_LABEL;

        typedef HRESULT (WINAPI *GetKnownFolderPathPtr)(REFKNOWNFOLDERID, DWORD, HANDLE, PWSTR*);

    private:
        GetKnownFolderPathPtr getKnownFolderPath;
        HINSTANCE gShell32DLLInst;

    public:
        VistaAPIs();
        ~VistaAPIs();
        HRESULT SHGetKnownFolderPath(REFKNOWNFOLDERID, DWORD, HANDLE, PWSTR*);
        HRESULT __stdcall GetIntegrity(PUCHAR);
    };

    class FileSystem
    {
    public:
        static std::string getUserAppDataDirectory(bool, const char*);
        static std::string getCacheDirectory(bool);
    };
}
