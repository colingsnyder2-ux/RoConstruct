// from server: 100% by colin
struct CXTPRibbonControlSystemButton {
    char pad[0xfc];
    void* field_fc;
    int method(int, int);
};

extern "C" void* __fastcall sub_643980(void*);
extern "C" void __fastcall sub_633C70(void*);
extern "C" void* __fastcall sub_646570(void*);
extern "C" long (__stdcall *SendMessageA)(void*, unsigned int, unsigned int, long);

int CXTPRibbonControlSystemButton::method(int a, int b) {
    void* p = sub_643980(field_fc);
    sub_633C70(p);
    void* q = sub_646570(field_fc);
    void* hwnd = *(void**)((char*)q + 0x20);
    SendMessageA(hwnd, 0x112, 0xf063, 0);
    return 1;
}
