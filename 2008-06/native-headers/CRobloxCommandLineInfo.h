#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxCommandLineInfo | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 5ff8d152 | roc native-status --write
#include <afxwin.h>
#include <string>
#include <vector>

// Fields initialized by 0044c1b0; vector destroyed by 0044c360.
class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool flag28, flag29, flag2a, flag2b, flag2c, flag2d, embeddedIde, noStartPage;
    std::vector<std::string> files;
    CRobloxCommandLineInfo();
    virtual void ParseParam(const char*, BOOL, BOOL);
};
