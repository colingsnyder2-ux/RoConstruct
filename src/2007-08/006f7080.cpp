// from server: 100% by auto
extern "C" void __cdecl G1_func_006f7080(void*);
struct S_func_006f7080 {
    virtual ~S_func_006f7080();
    void* m_p;
};
S_func_006f7080::~S_func_006f7080()
{
    if (m_p)
        G1_func_006f7080(m_p);
}
