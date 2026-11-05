// from server: 47% by atomic.potato
struct S {
    char pad0[0x20];
    void* m_str;
    void ctor(void*);
    S* init(void*);
};

extern "C" void __stdcall string_copy_ctor(void*, const void*);

S* S::init(void* src)
{
    string_copy_ctor(&m_str, src);
    ctor((char*)src + 0x20);
    return this;
}
