// from server: 100% by auto
extern "C" void __cdecl G1_func_007d2b20(void*);
struct S_func_007d2b20 {
    virtual ~S_func_007d2b20();
    void* m_p;
};
S_func_007d2b20::~S_func_007d2b20()
{
    if (m_p)
        G1_func_007d2b20(m_p);
}
