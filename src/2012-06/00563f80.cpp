// from server: 91% by atomic.potato
struct S_00563f80 {
    char pad_0[8];
    void* f_8;
    void method(int a, int b);
};

extern "C" void __fastcall sub_00563770(void* out, void* self, int arg);

void S_00563f80::method(int a, int b) {
    void* p = f_8;
    void* self;
    if (p) {
        self = (char*)p - 9;
    } else {
        self = 0;
    }
    char buf[8];
    sub_00563770(buf, self, b);
    *(int*)a = *(int*)buf;
    *(char*)((char*)a + 4) = buf[4];
}
