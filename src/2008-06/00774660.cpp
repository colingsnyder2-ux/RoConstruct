// from server: 100% by auto
extern "C" void __cdecl G1_func_00774660(void*);
struct S_func_00774660 {
    virtual ~S_func_00774660();
    void* m_p;
};
S_func_00774660::~S_func_00774660()
{
    if (m_p)
        G1_func_00774660(m_p);
}
