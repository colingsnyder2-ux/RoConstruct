// from server: 56% by atomic.potato
typedef int HGDIOBJ;
extern "C" int __stdcall DeleteObject(HGDIOBJ);

struct S
{
    int a[9];
    void f();
};

void S::f()
{
    HGDIOBJ (__stdcall *p)(HGDIOBJ) = DeleteObject;
    p(a[0]);
    p(a[2]);
}
