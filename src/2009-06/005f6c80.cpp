// from server: 32% by atomic.potato
extern "C" void __stdcall sub_4D1460();
extern "C" void __stdcall sub_718A32(void*);
extern "C" void __stdcall sub_5D2B60();

struct S {
    char pad0[0x14];
    void* field14;
    char pad18[0x80];
    void* field98;
    virtual ~S();
};

S::~S() {
    void* p = field98;
    if (p) {
        sub_4D1460();
        sub_718A32(p);
    }
    *(void**)this = (void*)0x8d696c;
    *(void**)((char*)this + 0x14) = (void*)0x8d6960;
    *(void**)((char*)this + 0x18) = (void*)0x8d6958;
    *(void**)((char*)this + 0x20) = (void*)0x8d6950;
    sub_5D2B60();
}
