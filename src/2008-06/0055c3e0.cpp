// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_assetfolder_d9cae1fd05274db1.cpp

// Candidate translation unit (score above; library headers required).
// from server: 97% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)


extern "C" long (__stdcall *SHGetFolderPathAndSubDirA)(
    void*, int, void*, unsigned long, const char*, char*);

struct String {};
extern String assetFolder;
extern String& (__thiscall *assignString)(String*, const char*);

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

Shared __cdecl getService();
void __cdecl report(void*, int, const char*, ...);

void initializeAssetFolder()
{
    char path[260];
    if (SHGetFolderPathAndSubDirA(
            0, 35, 0, 0, "Roblox\\content\\", path) == 0) {
        assignString(&assetFolder, path);
    } else {
        report(getService().get(), 2,
               "Failed to get asset folder from registry");
    }
}
