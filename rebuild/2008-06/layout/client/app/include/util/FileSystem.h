// =============================================================================
// FileSystem.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/util/FileSystem.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
