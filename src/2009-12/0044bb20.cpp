// from server: 90% by atomic.potato
struct CRobloxApp
{
    CRobloxApp* __cdecl f(int, int);
};

extern "C" CRobloxApp* setf(CRobloxApp*, int, int);

CRobloxApp* CRobloxApp::f(int, int)
{
    setf(this, 0x800, 0xE00);
    return this;
}
