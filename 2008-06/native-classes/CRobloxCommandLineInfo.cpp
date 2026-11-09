// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CRobloxCommandLineInfo | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 95a33bb7 | roc native-status --write
#include "CRobloxCommandLineInfo.h"
#include "util/standardout.h"
#include <stdlib.h>

extern CString applicationBaseUrlText;
void nativeCommandLineBaseUrl(CString value)
{
    applicationBaseUrlText = value;
}

void CRobloxCommandLineInfo::ParseParam(const char* parameter, BOOL flag, BOOL last)
{
    if (flag28) {
        nativeCommandLineBaseUrl(parameter);
        flag28 = false;
        ParseLast(last);
        return;
    }
    if (flag29) {
        { std::string value(parameter); files.push_back(value); }
        flag29 = false;
        ParseLast(last);
        return;
    }
    if (flag) {
        if (CString("No3D").CompareNoCase(parameter) == 0) {
            noStartPage = true; ParseLast(last); return;
        }
        if (CString("Browser").CompareNoCase(parameter) == 0) {
            embeddedIde = true; ParseLast(last); return;
        }
        if (CString("BaseUrl").CompareNoCase(parameter) == 0) {
            flag28 = true; ParseLast(last); return;
        }
        if (CString("Script").CompareNoCase(parameter) == 0) {
            flag29 = true; ParseLast(last); return;
        }
    }
    CCommandLineInfo::ParseParam(parameter, flag, last);
}

CRobloxCommandLineInfo::CRobloxCommandLineInfo()
    : flag28(false), flag29(false), flag2a(false), flag2b(false),
      flag2c(false), flag2d(false), embeddedIde(false), noStartPage(false)
{
    if (__argc > 0) {
        std::string command;
        for (int i = 0; i < __argc; ++i) {
            if (i) command += " ";
            command += __argv[i];
        }
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, command.c_str());
    }
}

void destroyCommandLineInfo(CRobloxCommandLineInfo* info)
{
    info->CRobloxCommandLineInfo::~CRobloxCommandLineInfo();
}
