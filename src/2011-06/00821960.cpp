// from server: 100% by auto
extern "C" void __cdecl G1_func_00821960(void*);
struct S_func_00821960 {
    virtual ~S_func_00821960();
    void* m_p;
};
S_func_00821960::~S_func_00821960()
{
    if (m_p)
        G1_func_00821960(m_p);
}
