// from server: 34% by tester
struct CStr {
    char pad[0x1c];
    void* p;
};

struct String {
    char pad[0x1c];
};

extern "C" {
    void __stdcall sub_7d20f0();
    void* __stdcall sub_67f480();
    void __stdcall sub_684840(void*);
    void __stdcall sub_b22654();
    void __stdcall sub_b22648(const char*);
    void __stdcall sub_b2263c();
}

struct Clothing {
    char pad0[0x80];
    CStr field80;
    char pad1[0x1c];
    String fieldA0;
    int init();
};

int Clothing::init() {
    sub_7d20f0();
    *(int*)((char*)this + 0) = 0xbc00fc;
    *(int*)((char*)this + 4) = 0xbc00f0;
    *(int*)((char*)this + 0x18) = 0xbc00e4;
    *(int*)((char*)this + 0x1c) = 0xbc00d8;
    *(int*)((char*)this + 0x80) = 0xbc00d0;
    sub_b22654();
    field80.p = sub_67f480();
    sub_b22648("Shirt Graphic");
    sub_684840(&fieldA0);
    sub_b2263c();
    return (int)this;
}
