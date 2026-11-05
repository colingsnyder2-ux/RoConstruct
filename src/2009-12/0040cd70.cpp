// from server: 92% by atomic.potato
typedef int BOOL;

extern "C" BOOL __stdcall CallBrowser(void*);

struct CIDEBrowserView
{
    void* vftable;
    char data[0x2ac];
    void* browser;
    void f(void*);
};

void CIDEBrowserView::f(void* arg)
{
    void* value = *(void**)arg;
    BOOL result = CallBrowser((char*)this + 0x2b0);
    ((void (__thiscall *)(void*, BOOL))(*(void**)value))(arg, result == 0);
}
