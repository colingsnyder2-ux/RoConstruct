#pragma once
#include "CRobloxDHtmlDialog.h"

class CSaveToRobloxDialog : public CRobloxDHtmlDialog {
public:
    CSaveToRobloxDialog(IDispatch*, const char*, CWnd*);
    virtual ~CSaveToRobloxDialog();
};
