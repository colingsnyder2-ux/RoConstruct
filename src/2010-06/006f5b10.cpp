// from server: 34% by atomic.potato
struct T4_006f5b10 {
    char pad[0x10];
    void f_006f5b10(void* arg);
};

extern "C" void __stdcall invalid_parameter_noinfo();
extern "C" void __cdecl sub_004161f0(void*, void*);
extern "C" void* __cdecl sub_005b2960(void*);
extern "C" void sub_006f5500(T4_006f5b10*, void*);

void T4_006f5b10::f_006f5b10(void* arg)
{
    char* p = (char*)arg;
    int count = (*(int*)(p + 0x10) - *(int*)(p + 0xc)) >> 2;
    if (count <= 1)
        invalid_parameter_noinfo();

    char buf[0x1c];
    sub_004161f0(buf, (void*)(*(int*)(p + 0xc) + 4));

    int count2 = (*(int*)(p + 0x10) - *(int*)(p + 0xc)) >> 2;
    if (count2 <= 0)
        invalid_parameter_noinfo();

    void* v = sub_005b2960(*(void**)(p + 0xc));
    sub_006f5500(this, *(void**)v);
}
