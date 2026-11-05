// from server: 81% by atomic.potato
typedef unsigned int UINT;
typedef void* HWND;
typedef unsigned long LPARAM;
typedef unsigned int WPARAM;

extern "C" void __fastcall sub_00445fa0(void*);
extern "C" int __stdcall PostMessageA(HWND, UINT, WPARAM, LPARAM);

struct CScriptReviewView
{
    void f();
};

void CScriptReviewView::f()
{
    void* p = *(void**)((char*)this + 0x380);
    if (p)
    {
        sub_00445fa0(p);
        return;
    }

    HWND h = *(HWND*)((char*)this + 0x20);
    if (h)
        PostMessageA(h, 0x465, 0, 0);
}
