// from server: 69% by EspClaude
// from server: 48% by colin
// roc 2007-08 006e0ad0  unit: CXTPDockingPaneAutoHidePanel  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e0ad0
//
// Target (from roc check): ternary of two CString temporaries copied into the hidden return slot;
// pane virtual at vtable +0x5c; literal at 0x785954 is "" (first byte 0).

class CString {
public:
    __declspec(dllimport) CString(const char* psz);
    __declspec(dllimport) CString(const CString& src);
    __declspec(dllimport) ~CString();
    void* m_pszData;
};

class CXTPDockingPane {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58();
    virtual CString GetTitle();           // +0x5c
};

class CXTPDockingPaneAutoHidePanel {
public:
    CString GetTitle();
    char pad[0x1a0];
    CXTPDockingPane* m_pPane;             // +0x1a0
};

CString CXTPDockingPaneAutoHidePanel::GetTitle()
{
    return m_pPane != 0 ? m_pPane->GetTitle() : CString("");
}
