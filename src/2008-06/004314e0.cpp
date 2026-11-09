// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Native MFC9 and XTP11.2.2 virtual APIs plus target-proven minimal storage views.
// Frame/owner/runtime-class labels identify measured UI roles, not recovered original symbols.
// RTTI proves CXTSplitterWnd118, CSelectionCaption1c8 and CDataModelPropGrid248.
#include <stddef.h>
typedef int BOOL;typedef unsigned int UINT;typedef unsigned long DWORD;typedef unsigned long DWORD_PTR;typedef unsigned long WPARAM;typedef long LPARAM;typedef long LRESULT;typedef long HRESULT;typedef long INT_PTR;typedef long DISPID;typedef unsigned long COLORREF;
typedef void*HWND;typedef void*HMENU;typedef void*HICON;typedef void*LPVOID;typedef const char*LPCTSTR;typedef wchar_t*BSTR;
struct RECT{long left,top,right,bottom;};typedef RECT*LPRECT;
struct SIZE{long cx,cy;};struct CSize:SIZE{};
struct CRect:RECT{CRect(int a,int b,int c,int d){left=a;top=b;right=c;bottom=d;}};
struct CPoint{long x,y;};struct CREATESTRUCT;struct TOOLINFO;struct VARIANT;struct IDispatch;struct IAccessibleProxy;struct CDataExchange;struct COleControlSite;struct COleControlContainer;struct _AFX_OCC_DIALOG_INFO;struct CMenu;struct CScrollBar;struct CCreateContext;struct CView;struct CDC;struct CBrush;struct CFont;struct DRAWITEMSTRUCT;typedef DRAWITEMSTRUCT*LPDRAWITEMSTRUCT;struct GUID;typedef const GUID&REFCLSID;typedef LRESULT(__stdcall*WNDPROC)(HWND,UINT,WPARAM,LPARAM);
extern "C" __declspec(dllimport) BOOL __stdcall IsWindow(HWND);
extern "C" __declspec(dllimport) LRESULT __stdcall SendMessageA(HWND,UINT,WPARAM,LPARAM);
struct CRuntimeClass;struct CArchive;struct CDumpContext;struct CWnd;struct CException;struct MSG;struct IID;struct AFX_CMDHANDLERINFO;struct CTypeLibCache;struct CPtrArray;
struct CObject {virtual CRuntimeClass*GetRuntimeClass()const;virtual ~CObject();virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;};
struct CCmdTarget:CObject {
 virtual int OnCmdMsg(unsigned,int,void*,AFX_CMDHANDLERINFO*);virtual void OnFinalRelease();virtual int IsInvokeAllowed(long);virtual int GetDispatchIID(IID*);virtual unsigned GetTypeInfoCount();virtual CTypeLibCache*GetTypeLibCache();virtual long GetTypeLib(unsigned long,void**);
 virtual const void*GetMessageMap()const;virtual const void*GetCommandMap()const;virtual const void*GetDispatchMap()const;virtual const void*GetConnectionMap()const;virtual const void*GetInterfaceMap()const;virtual const void*GetEventSinkMap()const;
 virtual int OnCreateAggregates();virtual void*GetInterfaceHook(const void*);virtual int GetExtraConnectionPoints(CPtrArray*);virtual void*GetConnectionHook(const IID&);
 char opaque[0x20-4];
};

struct CWnd:CCmdTarget {
 HWND handle;char opaque[0x54-0x24];
 virtual void PreSubclassWindow();
 virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext );
 virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam );
 virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam );
 virtual BOOL DestroyWindow();
 virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
 virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType );
 virtual CMenu* GetMenu() const;
 virtual BOOL SetMenu(CMenu* pMenu);
 virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
 virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
 virtual void WinHelp(DWORD_PTR dwData, UINT nCmd );
 virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd );
 virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd );
 virtual BOOL ContinueModal();
 virtual void EndModalLoop(int nResult);
 virtual HRESULT EnsureStdObj();
 virtual HRESULT get_accParent(IDispatch **ppdispParent);
 virtual HRESULT get_accChildCount(long *pcountChildren);
 virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
 virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
 virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
 virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
 virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
 virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
 virtual HRESULT get_accHelp(VARIANT varChild, BSTR *pszHelp);
 virtual HRESULT get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
 virtual HRESULT get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
 virtual HRESULT get_accFocus(VARIANT *pvarChild);
 virtual HRESULT get_accSelection(VARIANT *pvarChildren);
 virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
 virtual HRESULT accSelect(long flagsSelect, VARIANT varChild);
 virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
 virtual HRESULT accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
 virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
 virtual HRESULT accDoDefaultAction(VARIANT varChild);
 virtual HRESULT put_accName(VARIANT varChild, BSTR szName);
 virtual HRESULT put_accValue(VARIANT varChild, BSTR szValue);
 virtual HRESULT SetProxy(IAccessibleProxy *pProxy);
 virtual HRESULT CreateAccessibleProxy(WPARAM wParam, LPARAM lParam, LRESULT *pResult);
 virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
 virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual WNDPROC* GetSuperWndProcAddr();
 virtual void DoDataExchange(CDataExchange* pDX);
 virtual void BeginModalState();
 virtual void EndModalState();
 virtual BOOL PreTranslateMessage(MSG* pMsg);
 virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid, VARIANT* pvar);
 virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
 virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
 virtual void PostNcDestroy();
 virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual ~CWnd();
 virtual BOOL CheckAutoCenter();
 virtual void AssertValid() const;
 virtual void Dump(CDumpContext& dc) const;
 virtual BOOL IsFrameWnd() const; 
 virtual void OnFinalRelease();
 virtual BOOL CreateControlContainer(COleControlContainer** ppContainer);
 virtual BOOL CreateControlSite(COleControlContainer* pContainer, COleControlSite** ppSite, UINT nID, REFCLSID clsid);
 virtual BOOL SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO* pOccDialogInfo);
 virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
 LRESULT SendMessage(UINT msg,WPARAM w=0,LPARAM l=0){return ::SendMessageA(handle,msg,w,l);}
};
struct CSplitterWnd:CWnd {
 enum ESplitType{splitBox,splitBar,splitIntersection,splitBorder};char opaque[0xdc-0x54];
 virtual BOOL Create(CWnd* pParentWnd, int nMaxRows, int nMaxCols, SIZE sizeMin, CCreateContext* pContext, DWORD dwStyle , UINT nID );
 virtual BOOL CreateStatic(CWnd* pParentWnd, int nRows, int nCols, DWORD dwStyle , UINT nID );
 virtual BOOL CreateView(int row, int col, CRuntimeClass* pViewClass, SIZE sizeInit, CCreateContext* pContext);
 virtual void RecalcLayout();
 virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
 virtual void OnInvertTracker(const CRect& rect);
 virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID);
 virtual void DeleteView(int row, int col);
 virtual BOOL SplitRow(int cyBefore);
 virtual BOOL SplitColumn(int cxBefore);
 virtual void DeleteRow(int rowDelete);
 virtual void DeleteColumn(int colDelete);
 virtual CWnd* GetActivePane(int* pRow , int* pCol );
 virtual void SetActivePane(int row, int col, CWnd* pWnd );
 virtual BOOL CanActivateNext(BOOL bPrev );
 virtual void ActivateNext(BOOL bPrev );
 virtual BOOL DoKeyboardSplit();
 virtual BOOL DoScroll(CView* pViewFrom, UINT nScrollCode, BOOL bDoScroll );
 virtual BOOL DoScrollBy(CView* pViewFrom, CSize sizeScroll, BOOL bDoScroll );
 virtual ~CSplitterWnd();
 virtual void AssertValid() const;
 virtual void Dump(CDumpContext& dc) const;
 virtual int HitTest(CPoint pt) const;
 virtual void GetInsideRect(CRect& rect) const;
 virtual void GetHitRect(int ht, CRect& rect);
 virtual void TrackRowSize(int y, int row);
 virtual void TrackColumnSize(int x, int col);
 virtual void DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside);
 virtual void SetSplitCursor(int ht);
 virtual void StartTracking(int ht);
 virtual void StopTracking(BOOL bAccept);
 virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
 virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 int IdFromRowCol(int,int)const;void SetRowInfo(int,int,int);
};
struct CXTThemeManagerStyleFactory;
struct CXTThemeManagerStyleHost {
 virtual ~CXTThemeManagerStyleHost();virtual CXTThemeManagerStyleFactory*CreateThemeFactory();virtual void OnThemeChanged();
 BOOL autoDelete;CRuntimeClass*factoryClass;CXTThemeManagerStyleFactory*customFactory;CXTThemeManagerStyleFactory*defaultFactory;CXTThemeManagerStyleHost*nextHost;
};
struct CXTSplitterWnd:CSplitterWnd,CXTThemeManagerStyleHost {
 CXTSplitterWnd();
 virtual ~CXTSplitterWnd();
 virtual void ShowColumn();
 virtual void HideColumn(int nColHide);
 virtual void ShowRow();
 virtual void HideRow(int nRowHide);
 virtual BOOL SwitchView(int nRow, int nCol, CView* pNewView);
 virtual CView* ReplaceView(int nRow, int nCol, CView* pNewView);
 virtual CView* ReplaceView(int nRow, int nCol, CRuntimeClass* pViewClass);
 virtual void SetSplitterStyle(DWORD dwxStyle);
 virtual DWORD GetSplitterStyle();
 virtual void EnableFlatLook(BOOL bFlatSplitter);
 virtual void SetActivePane(int row, int col, CWnd* pWnd );
 virtual void SetSplitCursor(int ht);
 virtual void OnInvertTracker(const CRect& rect);
 virtual void StartTracking(int ht);
 virtual void StopTracking(BOOL bAccept);
 virtual void DrawTracker(const CRect& rect, CBrush* pBrush);
 virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rectArg);
 int hiddenCol,hiddenRow;BOOL fullDrag,forceFullDrag,flatSplit;DWORD splitStyle;CPoint point;BOOL clipStyles;
};
struct CStatic:CWnd {
 virtual BOOL Create(LPCTSTR,DWORD,const RECT&,CWnd*,UINT);virtual void DrawItem(LPDRAWITEMSTRUCT);virtual ~CStatic();
};
struct CXTCaption:CStatic,CXTThemeManagerStyleHost {
 char opaque[0x190-0x54-24];
 virtual ~CXTCaption();
 virtual void SetCaptionColors(COLORREF clrBorder, COLORREF clrFace, COLORREF clrText);
 virtual void ModifyCaptionStyle(int nBorderSize, CFont* pFont , LPCTSTR lpszWindText , HICON hIcon );
 virtual void SetChildWindow(CWnd* pChild, CWnd* pNotifyWnd);
 virtual void KillChildWindow();
 virtual BOOL ShowPopupWindow();
 virtual void UpdateCaption(LPCTSTR lpszWindowText, HICON hIcon);
 virtual BOOL Create(CWnd* pParentWnd, LPCTSTR lpszWindowName, DWORD dwExStyle, DWORD dwStyle, const CRect& rect, UINT nID);
 virtual CRect GetTextRect() const;
 virtual void DrawCaptionBack(CDC* pDC, CRect& rcItem);
 virtual void DrawCaptionText(CDC* pDC);
 virtual void DrawCaptionIcon(CDC* pDC, CRect& rcItem);
 virtual void UpdateCaptionText(CDC* pDC);
 virtual CRect GetButtonRect() const;
};
struct CSelectionCaption:CXTCaption {char opaque[0x1c8-0x190];CSelectionCaption();};
struct CXTPPropertyGrid:CWnd {
 char opaque[0x188-0x54];virtual BOOL Create(const RECT&,CWnd*,UINT,DWORD);void ShowToolBar(BOOL);void SetTheme(int);
};
struct ActiveDocView {virtual ~ActiveDocView();void refresh();};
struct CDataModelPropGrid:CXTPPropertyGrid {char opaque[0x244-0x188];ActiveDocView activeDoc;CDataModelPropGrid();};
struct CDocument;
struct CXTPDockingPane {char opaque[0xb8];int id;int GetID()const{return id;}BOOL IsValid()const;void Attach(CWnd*);CWnd*AttachView(CWnd*,CRuntimeClass*,CDocument*,CCreateContext*);};
template<class T>struct WindowOwner {T*pointer;void reset(CWnd*);T*get()const{return pointer;}};
struct CMainFrame:CWnd {
 char opaque[0x3a8-0x54];WindowOwner<CXTSplitterWnd>splitter;WindowOwner<CDataModelPropGrid>properties;WindowOwner<CSelectionCaption>caption;
 LRESULT OnDockingPaneNotify(WPARAM,LPARAM);
};
CRuntimeClass* __stdcall viewClassA();CRuntimeClass* __stdcall viewClassB();CRuntimeClass* __stdcall viewClassC();extern CRuntimeClass viewClassD;
LRESULT CMainFrame::OnDockingPaneNotify(WPARAM notification,LPARAM parameter){
 if(notification==1){
 CXTPDockingPane*pane=(CXTPDockingPane*)parameter;
 if(!pane->IsValid()){
 switch(pane->GetID()){
 case 0xc1:{
  if(!splitter.get()||!splitter.get()->handle){
   splitter.reset(new CXTSplitterWnd);
   if(!splitter.get()->CreateStatic(this,2,1,0x50000000,0xe900))return 0;
   caption.reset(new CSelectionCaption);
   if(!((CSelectionCaption*)caption.get())->Create(splitter.get(),"",2,0x10000201,CRect(0,0,0,0),splitter.get()->IdFromRowCol(0,0)))return -1;
   properties.reset(new CDataModelPropGrid);
   properties.get()->Create(CRect(0,0,0,0),splitter.get(),splitter.get()->IdFromRowCol(1,0),0);
   properties.get()->ShowToolBar(1);properties.get()->SetTheme(6);properties.get()->activeDoc.refresh();
   splitter.get()->SetRowInfo(0,28,0);splitter.get()->SetSplitterStyle(8);
  }
  pane->Attach(splitter.get());return 1;
 }
 case 0xc2:{CWnd*view=pane->AttachView(this,&viewClassD,0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0xc0:{CWnd*view=pane->AttachView(this,viewClassA(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0x8c:{CWnd*view=pane->AttachView(this,viewClassB(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0xbf:{CWnd*view=pane->AttachView(this,viewClassC(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 }
 }else return 1;
 }
 return 0;
}
typedef char cwnd_size[sizeof(CWnd)==0x54?1:-1];
typedef char splitter_size[sizeof(CXTSplitterWnd)==0x118?1:-1];
typedef char caption_size[sizeof(CSelectionCaption)==0x1c8?1:-1];
typedef char grid_size[sizeof(CDataModelPropGrid)==0x248?1:-1];
typedef char splitter_member[offsetof(CMainFrame,splitter)==0x3a8?1:-1];
typedef char active_member[offsetof(CDataModelPropGrid,activeDoc)==0x244?1:-1];

