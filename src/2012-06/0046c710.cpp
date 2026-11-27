// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /GR
class CWnd { public: virtual void v(); };
class CMainFrame : public CWnd { };
struct App { char pad[0x20]; CWnd* wnd; };
struct State { int a; App* app; };
State* GetState();
CMainFrame* Function() { CWnd* w = GetState()->app->wnd; return dynamic_cast<CMainFrame*>(w); }
