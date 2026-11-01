// from server: 100% by tester
struct Slot {
    void* vtbl;
    unsigned char b4;
    unsigned char b5;
};

extern "C" void __cdecl sub_8f8f80(int, int, int);

void __cdecl sub_8f9140(int a, int b, int c)
{
    if (c != 4) {
        sub_8f8f80(a, b, c);
        return;
    }
    Slot* p = (Slot*)b;
    p->vtbl = (void*)0xdfdb10;
    p->b4 = 0;
    p->b5 = 0;
}
