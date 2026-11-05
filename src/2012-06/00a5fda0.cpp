// from server: 46% by atomic.potato
// roc 2008-06 00a5fda0  unit: CXTColorHex::PAUHEXCOLOR_CELL::?$CList  size: 284 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00a5fda0

extern "C" {
    void* __stdcall GetParent(void*);
    int __stdcall GetClientRect(void*, void*);
    int __stdcall DrawStateA(void*, void*, void*, int, int, int, int, int, int, int);
    int __stdcall SendMessageA(void*, unsigned int, unsigned int, int);
}

struct RECT { int left; int top; int right; int bottom; };

struct CXTColorHex {
    char pad0[0x20];
    void* hwnd;
    char pad24[0x30];
    void* m_pList;
    char pad58[0x18];
    int m_nIndex;
    int OnLButtonDown(unsigned int, int, int);
    int sub_a5f9b0(unsigned int, int);
    int sub_a5fc90(void*);
};

extern "C" void* __stdcall sub_982666(void*);
extern "C" void __stdcall sub_982f96(void*);
extern "C" void __stdcall sub_982f9c(void*, void*);
extern "C" void __stdcall sub_9d5200(void*, void*, void*);
extern "C" void __stdcall sub_9d5410(void*);

int CXTColorHex::OnLButtonDown(unsigned int param1, int x, int y)
{
    int idx = sub_a5f9b0(param1, x);
    if (idx != -1)
        return 0;
    if (m_nIndex == idx)
        return 0;
    m_nIndex = idx;

    void* parent = GetParent(hwnd);
    void* obj = sub_982666(parent);
    void* p = *(void**)((char*)obj + 0x20);
    SendMessageA(p, 0x2742, (unsigned int)idx, 0);

    RECT rc;
    GetClientRect(hwnd, &rc);

    void* tmp;
    sub_982f9c(&tmp, this);

    void* tmp2;
    sub_9d5200(&tmp2, tmp, &rc);

    int w = rc.right - rc.left;
    int h = rc.bottom - rc.top;

    void* list = (char*)this + 0x54;
    if (list)
        list = *(void**)((char*)list + 4);

    DrawStateA(0, 0, 0, (int)list, 0, 0, w, h, 4, 0);

    sub_a5fc90(&tmp2);

    sub_9d5410(&tmp2);
    sub_982f96(&tmp);

    return 0;
}
