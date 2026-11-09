// from server: 41% by atomic.potato
extern "C" void __stdcall sub_5a4c70(int, int, int);
extern "C" void __cdecl sub_7a8a63(int);

struct S {
    void f();
};

void S::f()
{
    if (!(*(unsigned char*)0xc0bf4c & 1)) {
        *(unsigned int*)0xc0bf4c |= 1;
        sub_5a4c70(0, 0xa2a998, 0);
        *(unsigned int*)0xc0bf38 = 0xa2a8f8;
        sub_7a8a63(0x9df180);
    }
}
