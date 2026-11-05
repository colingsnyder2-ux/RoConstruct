// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /EHsc /MD /Oy
typedef long HRESULT;
typedef struct _GUID { unsigned long a; unsigned short b,c; unsigned char d[8]; } IID;
typedef const IID& REFIID;
typedef struct HWND__* HWND;
typedef struct __POSITION* POSITION;
extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(HWND);
namespace std { class exception { public: virtual ~exception(); const char* what() const; void* _m; int _f; }; }
struct IUnknown { virtual HRESULT __stdcall QueryInterface(REFIID, void**)=0; virtual unsigned long __stdcall AddRef()=0; virtual unsigned long __stdcall Release()=0; };
struct AFX_MODULE_STATE;
struct _AFX_THREAD_STATE { void* _v; AFX_MODULE_STATE* m_pModuleState; };
class CWinApp;
struct AFX_MODULE_STATE { void* _v; CWinApp* m_pCurrentWinApp; };
AFX_MODULE_STATE* __stdcall AfxGetAppModuleState();
AFX_MODULE_STATE* __stdcall AfxGetModuleState();
void __stdcall AfxDeactivateActCtx(unsigned long, unsigned long);
struct AFX_MAINTAIN_STATE2 {
 AFX_MAINTAIN_STATE2(AFX_MODULE_STATE*);
 ~AFX_MAINTAIN_STATE2() {
  if (m_pThreadState) m_pThreadState->m_pModuleState = m_pPrevModuleState;
  if (m_bValidActCtxCookie) AfxDeactivateActCtx(0, m_ulActCtxCookie);
 }
 AFX_MODULE_STATE* m_pPrevModuleState;
 _AFX_THREAD_STATE* m_pThreadState;
 unsigned long m_ulActCtxCookie;
 int m_bValidActCtxCookie;
};
class CObject { public: virtual ~CObject(); };
class CCmdTarget : public CObject { public: char _c[0x1c]; };
class CFrameWnd;
class CWnd : public CCmdTarget { public: HWND m_hWnd; CFrameWnd* GetParentFrame() const; int ShowWindow(int); };
class CFrameWnd : public CWnd {};
class CView : public CWnd {};
class CDocument : public CCmdTarget {
public:
 virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
 virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
 virtual POSITION GetFirstViewPosition() const; // 0x68
 virtual CView* GetNextView(POSITION&) const;  // 0x6c
 virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
 virtual void OnCloseDocument(); // 0x84
};
class CWinApp : public CCmdTarget {};
inline CWinApp* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }
class CRobloxView : public CView {public:void setEmbedded(bool,bool);};
class CRobloxDoc : public CDocument {public: char _d[0x94-0x20]; IUnknown* workspace; };
class CRobloxApp : public CWinApp {public:CRobloxDoc* createDocument();};
class AuthenticationFacet {public:HRESULT authenticate();};
extern const IID IID_App;
extern HRESULT __cdecl reportError(REFIID,const char*,HRESULT);
extern HRESULT __cdecl reportException(REFIID,const std::exception&);
extern HRESULT __cdecl createWorkspace(IUnknown**,void*);
template<class T> class CComPtr { public:
 T* p;
 CComPtr(T* lp) { p = lp; if (p) p->AddRef(); }
 ~CComPtr() { if (p) p->Release(); }
 HRESULT CopyTo(T** pp) { if (pp == 0) return 0x80004003L; *pp = p; if (p) p->AddRef(); return 0; }
};
static __forceinline CView* firstView(CDocument* d){POSITION pos=d->GetFirstViewPosition(); if(!pos) return 0; return d->GetNextView(pos);}
static __forceinline HRESULT makeWorkspace(IUnknown*& w){IUnknown* c; HRESULT r=createWorkspace(&c,0); if(!r) w=c; return r;}
class AppFacet {public:HRESULT __stdcall create(int,IUnknown**);};
HRESULT __stdcall AppFacet::create(int windowType,IUnknown** out) {
 AFX_MAINTAIN_STATE2 _ctlState(AfxGetAppModuleState());
 CDocument* document=0;
 try {
  HRESULT auth=reinterpret_cast<AuthenticationFacet*>(reinterpret_cast<char*>(this)-0x10)->authenticate();
  if(auth)return auth;
  CRobloxApp* app=static_cast<CRobloxApp*>(AfxGetApp());
  IUnknown* workspace;
  CView* view=0;
  switch(windowType) {
  case 0: {
   IUnknown* c;
   HRESULT result=createWorkspace(&c,0);
   if(result) return reportError(IID_App,"Couldn't create workspace",result);
   workspace=c;
   break;
  }
  case 2: {
   CRobloxDoc* doc=app->createDocument();
   document=doc;
   workspace=doc->workspace;
   view=firstView(doc);
   if(view) {
    CRobloxView* robloxView=dynamic_cast<CRobloxView*>(view);
    if(robloxView)robloxView->setEmbedded(false,true);
   }
   break;
  }
  default: return reportError(IID_App,"requested WindowType is invalid",87);
  }
  if(view) {
    view->GetParentFrame()->ShowWindow(5);
    ::SetForegroundWindow(view->m_hWnd);
  }
  CComPtr<IUnknown> iworkspace(workspace);
  HRESULT result=iworkspace.CopyTo(out);
  if(result)return reportError(IID_App,"iworkspace.CopyTo failed",result);
  return 0;
 } catch(const std::exception& error) {
  if(document)document->OnCloseDocument();
  return reportException(IID_App,error);
 }
}
