// from server: 52% by atomic.potato
struct S {
    char pad[0x28];
    void (__stdcall *fn)(int, int);
    int extra;
    void f(int, int);
};

extern "C" int __cdecl sub_80B2EA(int, int, int, int, int);
extern "C" void __cdecl sub_80B0AC(void*, void*);
extern "C" void* __cdecl sub_A40A10(void*, void*);

void S::f(int a, int b)
{
    int r = sub_80B2EA(a, 0, 0xC073F8, 0xC84D20, 0);
    if (r == 0) {
        void* p;
        sub_A40A10(&p, (void*)0xA5C10C);
        sub_80B0AC(&p, (void*)0xB989FC);
    }
    fn(extra + r, b);
}
