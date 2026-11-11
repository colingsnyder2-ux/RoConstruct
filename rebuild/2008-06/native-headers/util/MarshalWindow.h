#pragma once
// >>> native-status (generated) -- do not edit >>>
// MarshalWindow | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c939ada0 | roc native-status --write
#include <atlbase.h>
#include <atlwin.h>
#include <atlsync.h>

namespace RBX {
class EventDataBase;

// Native window/registry recovery; original global initialization remains open.
class CMarshalWindow : public ATL::CWindowImpl<CMarshalWindow> {
public:
    unsigned references;
    DWORD threadId;
    ATL::CCriticalSection criticalSection;

    explicit CMarshalWindow(DWORD);
    virtual ~CMarshalWindow();
    void post(EventDataBase*);
    BEGIN_MSG_MAP(CMarshalWindow)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_USER + 101, OnMarshalEvent)
    END_MSG_MAP()
    virtual void OnFinalMessage(HWND);
    LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnMarshalEvent(UINT, WPARAM, LPARAM, BOOL&);
};
}
