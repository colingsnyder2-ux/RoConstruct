// from server: 100% by atomic.potato
extern "C" void* (__stdcall *GetFocus)();
extern "C" long (__stdcall *SendMessageA)(void* hWnd, unsigned int msg, unsigned int wParam, long lParam);

struct CXTPCustomizeSheet_CCustomizeEdit {
    char pad[0x20];
    void* field_20;
    char pad2[0x38];
    void* field_5c;
    void sub_6c6c40();
    void func();
};

void CXTPCustomizeSheet_CCustomizeEdit::func()
{
    *(int*)((char*)field_5c + 0x190) = 1;
    if (GetFocus() == field_20) {
        void* p = field_5c;
        void** vtbl = *(void***)p;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[0x14c / 4];
        fn(p);
    }
    SendMessageA(field_20, 0xd3, 3, 0);
    sub_6c6c40();
}
