// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <deque>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long countableCounter;
class Countable {
public:
    Countable() { InterlockedIncrement(&countableCounter); }
};
class Conn1 : public Countable {
public:
    Conn1() : a(0) {}
    void* a;
};
class Pre { public: Pre() : b(0) {} void* b; };
class Conn2 : public Pre, public Countable {
public:
    Conn2() : c(0), d(0) {}
    void* c; void* d;
};
class CXTPReportView {
public:
    CXTPReportView();
    virtual ~CXTPReportView();
    char pad[0x374];
};
class CRobloxReportView : public CXTPReportView {
public:
    CRobloxReportView();
    struct Q { std::deque<int> d; int n; Q() : n(0) {} } items;
    bool b39c;
    Conn1 c1;
    Conn2 c2;
    int x3b0, x3b4, x3b8, x3bc, x3c0;
};
CRobloxReportView::CRobloxReportView()
    : b39c(false), x3b0(0), x3b4(0), x3b8(0), x3bc(0), x3c0(0)
{
}
