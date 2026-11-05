// from server: 100% by colin
extern "C" __declspec(dllimport) void *__stdcall SendMessageA(void *, unsigned int, unsigned int, long);
extern "C" void *__stdcall sub_6301C0(void *);

struct CRobloxTreeCtrl {
    char pad[0x20];
    void *field_20;
    void method(int, int *);
};

void CRobloxTreeCtrl::method(int a, int *b) {
    void *h = SendMessageA(field_20, 0x110f, 0, 0);
    void *r = sub_6301C0(h);
    SendMessageA(*(void **)((char *)r + 0x20), 0xc5, 0x20, 0);
    *b = 0;
}
