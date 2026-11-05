// from server: 33% by atomic.potato
extern "C" void __cdecl sub_6327E0();
extern "C" void __cdecl sub_7F4929();

struct S {
    void f();
};

void S::f()
{
    *(int*)0xB85158 |= 1;
    if (!(*(int*)0xB85158 & 1)) {
        sub_6327E0();
        *(int*)0xB85144 = 0x9CBCD8;
        sub_7F4929();
    }
}
