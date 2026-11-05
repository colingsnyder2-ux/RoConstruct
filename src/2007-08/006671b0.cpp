// from server: 61% by colin
extern "C" __declspec(dllimport) void *__stdcall SendMessageA(void *, unsigned int, unsigned int, long);

struct CRobloxTreeCtrl {
    void *vtable;
    void *field_4;
    char pad_8[0x2c];
    void *field_34;
    void sub_665FE0(void *);
    void sub_6671B0(void *);
};

void CRobloxTreeCtrl::sub_6671B0(void *arg) {
    void *old = field_4;
    field_4 = arg;
    if (arg == 0) {
        void *hwnd = *(void **)((char *)field_34 + 0x20);
        void *result = SendMessageA(hwnd, 0x110a, 9, 0);
        void *edi = result;
        if (edi != 0) {
            char al = ((char (__thiscall *)(void *, int, void *))0x73863a)(field_34, 2, edi);
            if ((al & 2) == 0) {
                edi = 0;
            }
        }
        void (__thiscall *fn)(void *, void *, int) = *(void (__thiscall **)(void *, void *, int))((char *)*(void **)this + 0x4c);
        fn(this, edi, 0);
        if (edi != 0) {
            sub_665FE0(edi);
        }
    }
}
