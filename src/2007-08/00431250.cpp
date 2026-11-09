// from server: 43% by colin
struct CMainFrame {
    char pad[0xec];
    char flag_ec;
    char pad2[0x3];
    int field_f0;
    void sub_430090(int, void*);
    void sub_4310a0();
    void sub_62fffe();
    int sub_630592();
    void OnSomething();
};

extern "C" {
    int __stdcall sub_688440(void*, int, void*, int);
    int __stdcall sub_688e80(void*);
    int __stdcall sub_686cd0(void*, int);
    void* __stdcall sub_62ff02();
    int __stdcall sub_77dd98(int, void*);
}

void CMainFrame::OnSomething()
{
    if (flag_ec == 0) {
        int local2 = 0;
        sub_688440(&local2, 0, (void*)0x78b10c, 0);
        int r = sub_688e80(&local2);
        if (r != 0) {
            sub_430090(1, &local2);
            int h = sub_77dd98(1, &field_f0);
            sub_686cd0(&local2, h);
        }
        sub_4310a0();
    }
    sub_62fffe();
    void* p = sub_62ff02();
    int* pi = *(int**)((char*)p + 4);
    if (pi != 0 && pi[8] == (int)this) {
        int r = sub_630592();
        if (r == 0) {
            pi[8] = r;
            void** vt = *(void***)this;
            void (*fn)(void*) = (void (*)(void*))vt[0x68/4];
            fn(this);
        }
    }
}
