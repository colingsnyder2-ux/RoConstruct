// from server: 100% by auto
extern "C" void __cdecl G1_func_006cb610(void*);
struct S_func_006cb610 {
    virtual ~S_func_006cb610();
    void* m_p;
};
S_func_006cb610::~S_func_006cb610()
{
    if (m_p)
        G1_func_006cb610(m_p);
}
