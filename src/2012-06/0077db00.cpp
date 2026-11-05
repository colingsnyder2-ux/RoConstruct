// from server: 100% by tester
struct Base {
    void destroy();
};

struct S : Base {
    void* vtbl0;
    void* vtbl4;
    char pad[0x10];
    void* vtbl18;
    void* vtbl1c;
    S* construct(unsigned int flags);
};

extern "C" void __stdcall sub_685090();
extern "C" void __cdecl sub_982114(void*);

S* S::construct(unsigned int flags)
{
    vtbl0 = (void*)0xbb0cf4;
    vtbl4 = (void*)0xbb0ce8;
    vtbl18 = (void*)0xbb0cdc;
    vtbl1c = (void*)0xbb0cd0;
    sub_685090();
    if (flags & 1) {
        sub_982114(this);
    }
    return this;
}
