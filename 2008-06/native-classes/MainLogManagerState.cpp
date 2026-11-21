// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr-len /I{headers}/std-noinline-string /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Rendering/g3d/include /I{headers}/../../../tools/rbxgs/Client/boost_1_34_1/src /I{headers}
// MainLogManager state and construction (2008-06 MainLogManager / ThreadLogManager unit, 00427a20..0042a330).
// Uses the Dec 2007 OpenRBX class (native-donor-2007/LogManager.h, the same header MainLogManagerRecovery.cpp
// uses): native-headers/LogManager.h does not declare MainLogManager::CullLogs (header proposal).
#include <afxwin.h>
namespace RBX { const char* get_thread_name(); }
#include "../native-donor-2007/LogManager.h"
#include <atltime.h>
#include <algorithm>
#include <list>

// Set by MainLogManager construction and cleared during its destruction.
MainLogManager* mainLogManager = 0;

namespace {
// Predicate of the find_if 00429b50 (its 8-byte CFileTime is passed by value: the two dwords
// ftCreationTime of the found file).
struct DateCompare
{
    ATL::CFileTime fileTime;

    DateCompare(const WIN32_FIND_DATA& data) : fileTime(data.ftCreationTime) {}

    bool operator()(WIN32_FIND_DATA data) const { return fileTime < ATL::CFileTime(data.ftCreationTime); }
};
}

// 00429f30 (591 B, registry placeholder func_00429f30): called three times by the constructor 0042a1c0 with
// ("\\", 32), ("error\\", 32), ("archive\\", 32) and ECX = this; GetLogPath 00427ba0 on the LogManager subobject
// (+4), PathAppend / PathAddBackslash, FindFirstFile(path + "*.*"), find_if 00429b50 + list insert 004297e0 sorted
// by creation time, then DeleteFile on all but the newest maxLogs. Body: OpenRBX LogManager.cpp CullLogs.
void MainLogManager::CullLogs(const char* folder, int maxLogs)
{
    // 00429f30 inlines CPathT::Append here (StringLength / GetLength / GetBuffer / PathAppendA / ReleaseBuffer
    // imports); this build calls the out-of-line Append COMDAT instead (543 vs 591 B, the only remaining
    // difference besides the branch offsets). Rejected: `path += folder` (same 543 B).
    ATL::CPath path = GetLogPath();
    path.Append(folder);
    path.AddBackslash();

    std::list<WIN32_FIND_DATA> files;

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(path + "*.*", &FindFileData);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                files.insert(std::find_if(files.begin(), files.end(), DateCompare(FindFileData)), FindFileData);
            }
        } while (FindNextFile(hFind, &FindFileData));
    }

    std::list<WIN32_FIND_DATA>::iterator iter = files.begin();
    for (size_t i = maxLogs; i < files.size(); ++i) {
        DeleteFile(path + iter->cFileName);
        ++iter;
    }
}

// 0042a1c0 (361 B, ??0MainLogManager@@QAE@PBD@Z) is not repeated here: MainLogManagerRecovery.cpp already holds
// the same donor body (367 B; measured here in batch 29 with this unit's flags: the identical 367 B). The only
// difference from the target is one extra store at the start, `mov [esi], <RBX::ILogProvider vptr>`: the target
// never writes the ILogProvider-phase vptr before the final 008104cc, so RBX::ILogProvider (util/Log.h, core) is
// __declspec(novtable) in the original (header proposal). The constructor calls CullLogs 00429f30 above.
