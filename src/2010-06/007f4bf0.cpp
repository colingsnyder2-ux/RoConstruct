// from server: 100% by auto
extern "C" void __cdecl G1_func_007f4bf0(void*);
struct S_func_007f4bf0 {
    virtual ~S_func_007f4bf0();
    void* m_p;
};
S_func_007f4bf0::~S_func_007f4bf0()
{
    if (m_p)
        G1_func_007f4bf0(m_p);
}
