#pragma once
// >>> native-status (generated) -- do not edit >>>
// CIDEDocManager | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src ad7f376c | roc native-status --write
#include <afxwin.h>

class CIDEDocManager : public CDocManager {
    friend class CRobloxApp;
    CDocTemplate* templates[4];
public:
    CIDEDocManager(bool);
};
