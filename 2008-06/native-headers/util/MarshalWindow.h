#pragma once
#include <atlbase.h>
#include <atlwin.h>
#include <atlsync.h>

namespace RBX {
class EventDataBase;

// Inactive native declaration. Window class metadata and registry remain open.
class CMarshalWindow : public ATL::CWindowImpl<CMarshalWindow> {
public:
    unsigned references;
    DWORD threadId;
    ATL::CCriticalSection criticalSection;

    explicit CMarshalWindow(DWORD);
    virtual ~CMarshalWindow();
    void post(EventDataBase*);
    static ATL::CWndClassInfo& GetWndClassInfo();
    BEGIN_MSG_MAP(CMarshalWindow)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
        MESSAGE_HANDLER(WM_USER + 101, OnMarshalEvent)
    END_MSG_MAP()
    virtual void OnFinalMessage(HWND);
    LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&);
    LRESULT OnMarshalEvent(UINT, WPARAM, LPARAM, BOOL&);
};
}
