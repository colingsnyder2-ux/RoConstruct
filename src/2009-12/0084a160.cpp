// from server: 100% by atomic.potato
typedef void* HDC;
typedef void* HGDIOBJ;

extern "C" HGDIOBJ __declspec(dllimport) __stdcall SelectObject(HDC, HGDIOBJ);

struct CXTPControlSelector
{
    int field0;
    HGDIOBJ field4;
    HDC field8;
    void f();
};

void CXTPControlSelector::f()
{
    field0 = 0x9fb988;
    SelectObject(field4, field8);
}
