// from server: 35% by Intel
struct EventData {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    int func();
};

extern "C" void __stdcall __security_cookie_check(int);
extern "C" void __cdecl sub_437B80(EventData*);

int EventData::func() {
    int cookie = *(int*)0x8B5188 ^ (int)this;
    __security_cookie_check(cookie);

    if (field_C) {
        sub_437B80(this);
        int edi = field_10;
        int eax = field_4;
        int ecx = field_C;
        int edx = *(int*)ecx;
        int (*func)(int, int) = (int(*)(int, int))*(int*)(edx + 8);
        func(edi, eax);
    }
    return 0;
}
