// from server: 100% by tajop
struct A0 { int a; };
struct B0 { int b; };
struct CMainFrame : A0, B0 { void target(); };

struct thread_data
{
    char pad[0x20];
    void (CMainFrame::*f)();
    CMainFrame* p;
    void run();
};

void thread_data::run()
{
    (p->*f)();
}
