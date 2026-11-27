// from server: 88% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { char b[28]; ~String() { destroyString(this); } };
struct Pair { String a; String b; };
struct M;
__declspec(dllimport) void __stdcall imp(M*);
struct M { int x; };
struct CTaskSchedulerPaneView {
    int pad;
    Pair p; M m;
    ~CTaskSchedulerPaneView();
};
CTaskSchedulerPaneView::~CTaskSchedulerPaneView() { imp(&m); }