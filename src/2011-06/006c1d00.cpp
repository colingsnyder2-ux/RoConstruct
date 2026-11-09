// from server: 33% by atomic.potato
struct S {
    char pad0[0x1c];
    int field1c;
    S* __cdecl ctor(const S* other);
};

extern "C" void __stdcall string_copy_ctor(void*, const void*);
extern "C" void __stdcall string_dtor(void*);

S* S::ctor(const S* other) {
    char buf[0x1c];
    string_copy_ctor(buf, other);
    field1c = *(int*)((char*)other + 0x1c);
    string_dtor(buf);
    return this;
}
