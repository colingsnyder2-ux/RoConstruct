// from server: 49% by atomic.potato
struct VBodyPosition {
    void* vtable;
    void construct();
};

extern "C" {
    extern unsigned char byte_E580B3;
    extern int dword_E3796C;
    extern int (__cdecl *dword_E5809C)(int, int, int);
    extern void __cdecl sub_972290(int, int);
    extern void* __cdecl sub_4019D0(void*);
    extern void __cdecl sub_4A11D0(void*);
    extern void* __cdecl sub_7687D0();
}

void VBodyPosition::construct()
{
    this->vtable = (void*)0xBAFCA8;
    if (byte_E580B3 != 0 && dword_E3796C != 0x29A) {
        if (dword_E5809C != 0) {
            if (dword_E5809C(0xE2, 0xB42FA8, 0xB42F90) != 0) {
                goto done;
            }
        }
        sub_972290(byte_E580B3, 0xB43368);
    }
done:
    void* p = sub_7687D0();
    void* q = sub_4019D0(&p);
    sub_4A11D0(q);
}
