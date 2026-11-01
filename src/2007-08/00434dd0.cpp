// from server: 64% by atomic.potato
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CMemberTreeView
{
    int sub_434DD0(unsigned int);
};

extern "C" int __stdcall sub_630646(unsigned int);
extern "C" void* __cdecl sub_434870(int);
extern "C" int __stdcall sub_63049C(void*);

typedef void (__thiscall *VFn)(void*);

int CMemberTreeView::sub_434DD0(unsigned int a1)
{
    int result = sub_630646(a1);
    if (result == -1)
        return -1;

    VFn fn = *(VFn*)(*(char**)((char*)this + 0x60) + 0x44);
    fn((char*)this + 0x60);

    char* p = (char*)this + 0xa0;
    void* obj = sub_434870(0xc4);
    if (obj == 0)
        return -1;

    unsigned int v = 0;
    if (p != 0)
        v = *(unsigned int*)(p + 4);

    void* hwnd = *(void**)((char*)this + 0x20);
    void* r = (void*)SendMessageA(hwnd, 0x1109, 0, v);
    sub_63049C(r);
    return 0;
}
