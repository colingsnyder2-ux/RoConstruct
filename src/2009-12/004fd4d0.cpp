// from server: 88% by atomic.potato
struct S {
};

extern "C" void __stdcall sub_4FB810(int, int, int, int);

void __cdecl f(int a, int b, int c) {
    if (c != 4) {
        char z = 0;
        sub_4FB810(a, b, c, *(int*)&z);
        return;
    }
    *(int*)a = 0xb13298;
    *(char*)(a + 4) = 0;
    *(char*)(a + 5) = 0;
}
