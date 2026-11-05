// from server: 100% by auto
extern "C" void __cdecl G1_func_00716590(void*);
struct S_func_00716590 {
    virtual ~S_func_00716590();
    void* m_p;
};
S_func_00716590::~S_func_00716590()
{
    if (m_p)
        G1_func_00716590(m_p);
}
