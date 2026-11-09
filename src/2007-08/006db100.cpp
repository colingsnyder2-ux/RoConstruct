// from server: 100% by auto
extern "C" void __cdecl G1_func_006db100(void*);
struct S_func_006db100 {
    virtual ~S_func_006db100();
    void* m_p;
};
S_func_006db100::~S_func_006db100()
{
    if (m_p)
        G1_func_006db100(m_p);
}
