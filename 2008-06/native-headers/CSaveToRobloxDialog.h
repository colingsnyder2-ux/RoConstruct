#pragma once
#include "CRobloxDHtmlDialog.h"

class CSaveToRobloxDialog : public CRobloxDHtmlDialog {
    DECLARE_MESSAGE_MAP()
    DECLARE_EVENTSINK_MAP()
    DECLARE_DHTML_EVENT_MAP()
public:
    CSaveToRobloxDialog(IDispatch*, const char*, CWnd*);
    virtual ~CSaveToRobloxDialog();
    void WindowClosing(BOOL, VARIANT_BOOL*);
};

class CPublishAsPlaceDialog : public CSaveToRobloxDialog {
public:
    CPublishAsPlaceDialog(IDispatch*, CWnd*);
};

class CSaveModelToRobloxDialog : public CSaveToRobloxDialog {
public:
    CSaveModelToRobloxDialog(IDispatch*, CWnd*);
};
