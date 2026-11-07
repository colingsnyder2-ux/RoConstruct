#pragma once
// >>> native-status (generated) -- do not edit >>>
// CScriptEditor | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 15706d41 | roc native-status --write
#include <afxwin.h>
#include <afxext.h>
#include <afxdlgs.h>
#include <afxtempl.h>
#include <Platform.h>
#include <Scintilla.h>
#include <SciLexer.h>
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "util/RunStateOwner.h"

namespace RBX { class Script; }

// RTTI names the statically linked PJ Naughter wrapper classes Scintilla::CScintillaCtrl,
// Scintilla::CScintillaView and Scintilla::CScintillaFindReplaceDlg. The v1.20 CScintillaCtrl
// (tools/libs/scintilla-mfc-1.20) reproduces the binary members used here byte for byte
// (ctor 0045ffe0, dtor 00460000, GetCurrentPos 00460120, SetReadOnly 00460c90, ...).
namespace Scintilla {
#include "ScintillaCtrl.h"

class CScintillaFindReplaceDlg;

// Binary CScintillaView: CRuntimeClass 0081a8c8 (size 0xec), vtable 0081aa74 (140 slots),
// ctor 00461f00, dtor 00461fd0. Older than v1.20: no GetReplaceAllTarget, no virtual
// Load/SaveMarginSettings, no m_bPersistMarginSettings. CView ends at slot 100; the
// wrapper's own virtuals occupy slots 101..139 in the order below.
class CScintillaView : public CView {
public:
    CScintillaView();
    CScintillaCtrl& GetCtrl();                                   // 004613d0

protected:
    virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo);
    virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
    virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
    virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo = NULL);
    virtual BOOL PaginateTo(CDC* pDC, CPrintInfo* pInfo);
    virtual long PrintPage(CDC* pDC, CPrintInfo* pInfo, long nIndexStart, long nIndexStop);
    virtual void PrintHeader(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint);
    virtual void PrintFooter(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint);
    virtual void OnFindNext(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
    virtual void TextNotFound(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression, BOOL bReplaced);
    virtual BOOL FindText(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
    virtual void OnEditFindReplace(BOOL bFindOnly);
    virtual BOOL FindTextSimple(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
    virtual void OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase, BOOL bWord, BOOL bRegularExpression, LPCTSTR lpszReplace);
    virtual void OnReplaceAll(LPCTSTR lpszFind, LPCTSTR lpszReplace, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
    virtual BOOL SameAsSelected(LPCTSTR lpszCompare, BOOL bCase, BOOL bWord, BOOL bRegularExpression);
    virtual long FindAndSelect(DWORD dwFlags, TextToFind& ft);
    virtual void AdjustFindDialogPosition();
    virtual CScintillaFindReplaceDlg* CreateFindReplaceDialog();
    virtual void OnDraw(CDC*);
    virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
    virtual void DeleteContents();
    virtual void Serialize(CArchive& ar);
    virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
    virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
    virtual void OnStyleNeeded(SCNotification* pSCNotification);
    virtual void OnCharAdded(SCNotification* pSCNotification);
    virtual void OnSavePointReached(SCNotification* pSCNotification);
    virtual void OnSavePointLeft(SCNotification* pSCNotification);
    virtual void OnModifyAttemptRO(SCNotification* pSCNotification);
    virtual void OnDoubleClick(SCNotification* pSCNotification);
    virtual void OnUpdateUI(SCNotification* pSCNotification);
    virtual void OnModified(SCNotification* pSCNotification);
    virtual void OnMacroRecord(SCNotification* pSCNotification);
    virtual void OnMarginClick(SCNotification* pSCNotification);
    virtual void OnNeedShown(SCNotification* pSCNotification);
    virtual void OnPainted(SCNotification* pSCNotification);
    virtual void OnUserListSelection(SCNotification* pSCNotification);
    virtual void OnDwellStart(SCNotification* pSCNotification);
    virtual void OnDwellEnd(SCNotification* pSCNotification);
    virtual void OnZoom(SCNotification* pSCNotification);
    virtual void OnHotSpotClick(SCNotification* pSCNotification);
    virtual void OnHotSpotDoubleClick(SCNotification* pSCNotification);
    virtual void OnCallTipClick(SCNotification* pSCNotification);
    virtual void OnAutoCSelection(SCNotification* pSCNotification);
    virtual void OnChange();
    virtual void OnSetFocus();
    virtual void OnKillFocus();

    CScintillaCtrl m_Edit;               // +0x58
    CArray<int, int> m_aPageStart;       // +0xb4
    CRect m_rMargin;                     // +0xc8
    BOOL m_bFirstSearch;                 // +0xd8
    BOOL m_bUseROFileAttributeDuringLoading; // +0xdc
    BOOL m_bPrintHeader;                 // +0xe0
    BOOL m_bPrintFooter;                 // +0xe4
    BOOL m_bUsingMetric;                 // +0xe8

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);  // 00462c60

    DECLARE_MESSAGE_MAP()
    DECLARE_DYNCREATE(CScintillaView)
};
}

// Declaration only (CRuntimeClass 0081b1ec, size 0x5c = CDocument + shared_ptr).
// CScriptEditor::OnUpdate 004657f0 reads the script shared_ptr at +0x54.
class CScriptDoc : public CDocument {
    DECLARE_DYNCREATE(CScriptDoc)
public:
    boost::shared_ptr<RBX::Script> script;   // +0x54
};

// Inactive layout recovery: CRuntimeClass 0081b208 (size 0x160, CreateObject 00465160),
// RTTI base list at vtables 0081b3dc/0081b3d0/0081b3bc/0081b3a8, constructor 00465010 and
// destructor 00465830.
class CScriptEditor : public Scintilla::CScintillaView,
                      public RBX::Listener<RBX::Instance, RBX::AncestorChanged>,
                      public RBX::MarshaledListener<RBX::Instance, RBX::PropertyChanged>,
                      public RBX::MarshaledListener<RBX::RunService, RBX::RunState> {
    DECLARE_DYNCREATE(CScriptEditor)
    DECLARE_MESSAGE_MAP()
public:
    CScriptEditor();
    virtual ~CScriptEditor();
    void setScript(boost::shared_ptr<RBX::Script> value);        // 00465260

protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);               // slot 27, 00463910
    virtual void PostNcDestroy();                                 // slot 73, 00463980
    virtual void OnInitialUpdate();                               // slot 91, 004639a0
    virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint); // slot 94, 004657f0
    virtual void OnCharAdded(SCNotification* pSCNotification);    // slot 118, 00464460
    virtual void OnDwellStart(SCNotification* pSCNotification);   // slot 130, 00464590
    virtual void OnDwellEnd(SCNotification* pSCNotification);     // slot 131, 004644e0
    virtual void OnKillFocus();                                   // slot 139, 00464960 -> 00464830

    virtual void onEvent(const RBX::Instance* source, RBX::AncestorChanged event);   // 00465500
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::PropertyChanged event); // 004659f0
    virtual void onMarshaledEvent(const RBX::RunService* source, RBX::RunState event);     // 004638d0
    virtual void marshal(const RBX::Instance* source, RBX::PropertyChanged event) throw(); // 00465110

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);          // 00463930
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized); // 00463ed0
    afx_msg LRESULT OnReload(WPARAM, LPARAM);                     // 00465 message, 004659a0
    afx_msg void OnAddBookmark();                                 // 00463f10 (command 0x80e5)
    afx_msg void OnUpdateAddBookmark(CCmdUI* pCmdUI);             // 00463f40
    afx_msg void OnRemoveBookmark();                              // 00463f80 (command 0x80e6)
    afx_msg void OnUpdateRemoveBookmark(CCmdUI* pCmdUI);          // 00463fb0
    afx_msg void OnNextBookmark();                                // 00463ff0 (command 0x80e7)
    afx_msg void OnPreviousBookmark();                            // 00464040 (command 0x80e8)
    afx_msg void OnToggleFoldMargin();                            // 00464090 (command 0x80e4)
    afx_msg void OnUpdateToggleFoldMargin(CCmdUI* pCmdUI);        // 004640d0
    afx_msg void OnToggleSelectionMargin();                       // 00464100 (command 0x80e3)
    afx_msg void OnUpdateToggleSelectionMargin(CCmdUI* pCmdUI);   // 00464140
    afx_msg void OnToggleLineNumbers();                           // 00464170 (command 0x80e2)
    afx_msg void OnUpdateToggleLineNumbers(CCmdUI* pCmdUI);       // 004641b0
    afx_msg void OnUpdateInsert(CCmdUI* pCmdUI);                  // 004641e0 (indicator 0xe704)
    afx_msg void OnUpdateLine(CCmdUI* pCmdUI);                    // 004643b0 (indicator 0xcb)
    afx_msg void OnUpdateStyle(CCmdUI* pCmdUI);                   // 00464270 (indicator 0xcc)
    afx_msg void OnUpdateFold(CCmdUI* pCmdUI);                    // 00464300 (indicator 0xcd)
    void saveScript();                                            // 00464830
    void reload();                                                // 00465550
    // Inlined into OnInitialUpdate 004639a0 (no out-of-line copies in the binary).
    void SetAStyle(int style, COLORREF fore, COLORREF back = RGB(0xff, 0xff, 0xff), int size = -1, const char* face = NULL);
    void DefineMarker(int marker, int markerType, COLORREF fore, COLORREF back);
    void updateTitle();                                           // 00464540

    boost::shared_ptr<boost::recursive_mutex> mutex;  // +0x138 DataModel mutex guarding script access
    CFrameWnd* frame;                                 // +0x140 GetParentFrame() from OnInitialUpdate
    boost::shared_ptr<RBX::Script> script;            // +0x144
    boost::shared_ptr<RBX::RunService> runService;    // +0x14c
    bool loading;                                     // +0x154
    bool running;                                     // +0x155
    bool embedded;                                    // +0x156
    CFont font;                                       // +0x158

    static int instanceCount;                         // 0096df94
    static HMODULE sciLexer;                          // 0096df90
};
