#pragma once
// >>> native-status (generated) -- do not edit >>>
// CMainFrame | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 39e10fa9 | roc native-status --write
#include "CMainFrameBases.h"
#include "util/boost.hpp"
#include <boost/scoped_ptr.hpp>
#include "CSelectionCaption.h"
#include "CDataModelPropGrid.h"

class CFrameResource;
// Inactive candidate: names, pointer ownership and virtual methods remain unverified.
class CMainFrame : public CXTPMDIFrameWnd,
                   public RBX::Listener<RBX::FillToolColor, RBX::BrickColor> {
    DECLARE_DYNAMIC(CMainFrame)
public:
    DECLARE_MESSAGE_MAP()
public:
    CMainFrame();
    virtual ~CMainFrame();
    void showDockPane(int, CRect, XTPDockingPaneDirection);
    void setFullscreen(bool);
    void configureFullscreen();
    void updateMonitor();
    void restoreFullscreen();
    void showEditorChrome(bool);
    void hideEditorChrome();
    void exchangeLayout(CXTPPropExchange*, int);
    bool initializeToolbars(bool);
    virtual BOOL PreCreateWindow(CREATESTRUCT&);                    // 0042e500
    virtual void OnSetPreviewMode(BOOL, CPrintPreviewState*);       // 00430ae0
    afx_msg void OnActivate(UINT, CWnd*, BOOL);
    afx_msg void OnGetMinMaxInfo(MINMAXINFO*);
    afx_msg void OnActivateApp(BOOL, DWORD);
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg void OnClose();
    afx_msg void OnPaint();
    afx_msg void OnDestroy();
    afx_msg void OnWindowPosChanging(WINDOWPOS*);
    afx_msg LRESULT handle_4314e0(WPARAM, LPARAM);
    afx_msg int handle_42fcf0(void*);
    afx_msg int handle_42fe00(void*);
    afx_msg void handle_431260(NMHDR*, LRESULT*);
    afx_msg void handle_431160(NMHDR*, LRESULT*);
    afx_msg void handle_42e550(CCmdUI*);
    afx_msg void handle_4300d0(CCmdUI*);
    afx_msg void handle_42ed00(CCmdUI*);
    afx_msg void handle_42ed20(CCmdUI*);
    afx_msg void handle_42edd0(CCmdUI*);
    afx_msg void handle_42eec0(CCmdUI*);
    afx_msg void handle_42eef0(CCmdUI*);
    afx_msg void handle_42fbf0();
    afx_msg void handle_42fbb0();
    afx_msg void handle_42fb80();
    afx_msg void handle_42e5e0();
    afx_msg void handle_42e610();
    afx_msg void handle_42ecf0();
    afx_msg void handle_430bd0();
    afx_msg void handle_42ee80();
    afx_msg void handle_42ee90();
    afx_msg void handle_4314c0();
    afx_msg void handle_431ce0();
    virtual void onEvent(const RBX::FillToolColor*, RBX::BrickColor);
    boost::scoped_ptr<RBX::worker_thread> keepAlive;
    bool stateF8;
    bool stateF9;
    bool stateFA;
    HMONITOR monitor;
    CFrameResource* resource;
    bool state104;
    bool state105;
    CString text;
    CXTWindowPos windowPosition;
    CXTPDockingPaneManager dockingPanes;
    CXTPTabClientWnd tabClient;
    boost::scoped_ptr<CXTSplitterWnd> splitter;
    boost::scoped_ptr<CDataModelPropGrid> propertyGrid;
    boost::scoped_ptr<CSelectionCaption> selectionCaption;
    CXTThemeManager theme;
    CXTPStatusBar status;
// Declarations proven by closure symbols (mangled names) of the 2008-06 client.
public:
    int showFrame(int);
};

