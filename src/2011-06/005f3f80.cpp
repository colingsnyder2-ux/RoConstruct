// from server: 32% by atomic.potato
extern "C" void __stdcall cb_005cb660();
extern "C" void __stdcall cb_006a5b20();
extern "C" int __stdcall cb_005ba420();

struct S {
    char pad0[0x14];
    int field14;
    char pad18[0x10];
    int field28;
    int field2c;
    void* ctor(int, int, int, int);
};

void* S::ctor(int a, int b, int c, int d) {
    cb_005cb660();
    cb_006a5b20();
    *(int*)this = 0xa91748;
    field28 = c;
    field2c = d;
    ++*(int*)0xcca608;
    field14 = cb_005ba420();

    return this;
}
