#pragma once
#include <afxwin.h>

class CIDEDocManager : public CDocManager {
    friend class CRobloxApp;
    CDocTemplate* templates[4];
public:
    CIDEDocManager(bool);
};
