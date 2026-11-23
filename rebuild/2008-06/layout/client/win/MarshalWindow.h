// =============================================================================
// MarshalWindow.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/MarshalWindow.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <atlbase.h>
#include <atlwin.h>
#include <atlsync.h>

namespace RBX
{
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
