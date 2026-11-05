// from server: 41% by atomic.potato
struct S {
    char pad0[8];
    int field8;
    int fieldC;
    void invoke(int a, int b);
};

extern "C" void __stdcall string_copy_ctor(void* dst, const void* src);

void S::invoke(int a, int b) {
    int* p = (int*)a;
    if (p != 0) {
        p = (int*)((char*)p - 0x1c);
    }
    char buf[0x20];
    string_copy_ctor(buf, (const void*)b);
    *(int*)(buf + 0x1c) = *(int*)((char*)b + 0x1c);
    int ecx = fieldC + (int)p;
    void (*fn)(int, int) = (void (*)(int, int))field8;
    fn(ecx, (int)buf);
}
