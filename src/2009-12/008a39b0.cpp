// from server: 77% by atomic.potato
extern "C" void G1_func_008a4300(void*);
extern "C" void __cdecl G2_func_0098de74(void*);

struct S_func_008a39b0 {
    void* m_vftable;
    char m_data[96];
    int m_value;
    char m_tail[12];
    void* f();
};

void* S_func_008a39b0::f()
{
    G1_func_008a4300(this);
    m_vftable = (void*)0xa05b14;
    G2_func_0098de74((char*)this + 0x74);
    m_value = 1;
    return this;
}
