// from server: 100% by auto
extern "C" void __cdecl G1_func_00843350(void*);
struct S_func_00843350 {
    virtual ~S_func_00843350();
    void* m_p;
};
S_func_00843350::~S_func_00843350()
{
    if (m_p)
        G1_func_00843350(m_p);
}
