// from server: 34% by atomic.potato
struct S {
    char pad[0x10];
    void (__stdcall *fn)(int, unsigned char);
    char pad2[4];
    void f(int a, unsigned char* b);
};

void S::f(int a, unsigned char* b)
{
    if (a != 0) {
        unsigned char c = *b;
        void (__stdcall *fn)(int, unsigned char) = this->fn;
        int base = *(int*)((char*)this + 0x14);
        fn(base + (a - 0x1c), c);
    } else {
        unsigned char c = *b;
        void (__stdcall *fn)(int, unsigned char) = this->fn;
        int base = *(int*)((char*)this + 0x14);
        fn(base + 0, c);
    }
}
