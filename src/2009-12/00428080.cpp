// from server: 77% by atomic.potato
extern "C" void __cdecl func_007fa160(int);

struct CMainFrame
{
    CMainFrame* f();
};

CMainFrame* CMainFrame::f()
{
    func_007fa160(0);
    *(int*)this = 0x9a3b84;
    *(int*)((char*)this + 0x20) = 0x9a3b24;
    return this;
}
