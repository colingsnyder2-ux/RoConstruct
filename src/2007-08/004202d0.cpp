// from server: 54% by colin
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);

struct CRobloxTreeCtrl {
    char pad[0x20];
    void* hwnd;
    char pad2[0x70];
    void* field94;
    char pad3[0x0c];
    unsigned char fieldA4;
    void sub_630496();
    void func();
};

void CRobloxTreeCtrl::func()
{
    sub_630496();
    unsigned char* p = &fieldA4;
    unsigned char saved = *p;
    *p = 1;
    SendMessageA(hwnd, 0x1101, 0, 0xffff0000);
    if (field94) {
        void** vt = *(void***)field94;
        ((void (__stdcall*)(void*, int))vt[1])(field94, 1);
        field94 = 0;
    }
    *p = saved;
}
