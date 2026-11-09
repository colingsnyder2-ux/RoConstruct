// from server: 31% by atomic.potato
struct S_func_00696690 {
    char pad0[4];
    void f(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __cdecl sub_00693A00(int, int, int, int, int);
extern "C" void* __cdecl sub_006963C0(int, int);
extern "C" void __cdecl sub_006937B0();
extern "C" void __cdecl sub_00982114(void*);
extern "C" void __cdecl sub_00972290(int, void*);
extern "C" int __cdecl sub_00B229EC(void*, void*);

void S_func_00696690::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* p;
    void* q;
    int v;

    p = sub_00693A00(a1, a2, a3, a4, a5);
    v = *(int*)p;
    *(int*)p = 0;
    q = sub_006963C0(a6, a7);
    sub_006937B0();
    sub_00982114((void*)a8);
    *(int*)this = 0xb9335c;
    if (*(char*)0xe580b3 != 0) {
        if (sub_00B229EC((void*)0xd9b498, (void*)0xd9b498) == 0) {
            if (*(void**)0xe5809c != 0) {
                if (((int(__cdecl*)(int, void*, void*))*(void**)0xe5809c)(0xae, (void*)0xb58618, (void*)0xb44978) != 0)
                    goto done;
            }
            sub_00972290(*(unsigned char*)0xe580b3, (void*)0xb58680);
        }
    }
done:
    (void)v;
    (void)q;
}
