// from server: 100% by atomic.potato
extern "C" void __cdecl sub_7D7690(void*, int, int);

struct S {
};

void __cdecl f(void* a, int b, int c) {
    if (c != 4) {
        sub_7D7690(a, b, c);
        return;
    }

    unsigned char* p = (unsigned char*)b;
    *(int*)p = 0xDCF400;
    p[4] = 0;
    p[5] = 0;
}
