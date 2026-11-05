// from server: 100% by auto
extern "C" void __cdecl G1_func_00676540(void*);
struct S_func_00676540 {
    virtual ~S_func_00676540();
    void* m_p;
};
S_func_00676540::~S_func_00676540()
{
    if (m_p)
        G1_func_00676540(m_p);
}
