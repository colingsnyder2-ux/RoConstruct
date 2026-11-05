// from server: 72% by atomic.potato
struct CIDEBrowserView
{
    char pad[0x2b0];
    char sub[0x100];
    void f();
};

extern "C" int __stdcall sub_98DE84(int, const char*);
extern "C" int __stdcall sub_98DE80(int, int, int, int, int, int);

struct Other
{
    void g(int);
};

void CIDEBrowserView::f()
{
    char* p = (char*)this + 0x2b0;
    if (sub_98DE84((int)p, ">Authoring"))
    {
        int r = sub_98DE80((int)p, 0, 0, 0, 0, 0);
        ((Other*)this)->g(r);
    }
}
