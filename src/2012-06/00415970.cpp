// from server: 36% by atomic.potato
extern "C" int __stdcall GetState(void*);
extern "C" void __stdcall CallVirtual(void*, int);

struct CIDEBrowserView
{
    int f(void*);
};

int CIDEBrowserView::f(void* arg)
{
    char result = (char)GetState((char*)this + 0x2b0);
    int value = result == 0;
    CallVirtual(arg, value);
    return 0;
}
