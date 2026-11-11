// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// LogArchive | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7f2b32b3 | roc native-status --write
#include <afxwin.h>
#include <shlwapi.h>
#include <atlpath.h>
#include <direct.h>
#include <string>

std::string archiveFile(const char* file, std::string folder)
{
    ATL::CPath destination(file);
    destination.RemoveFileSpec();
    destination.Append(folder.c_str());
    if (!destination.FileExists())
        _mkdir(destination);
    ATL::CPath filename(file);
    filename.StripPath();
    destination.Append(filename);
    if (!MoveFileA(file, destination))
        DeleteFileA(file);
    return std::string(destination);
}
