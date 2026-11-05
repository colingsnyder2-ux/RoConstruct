// from server: 79% by atomic.potato
extern "C" unsigned long __stdcall inet_addr(const char*);

struct CXTPRichRender_XTextHost {
    void sub_564AA0(int, int, int, int, int, int);
    void f(int, int, int, int, int, int);
};

void CXTPRichRender_XTextHost::f(int a, int b, int c, int d, int e, int f)
{
    unsigned long r = inet_addr((const char*)e);
    sub_564AA0(a, b, c, d, (int)r, f);
}
