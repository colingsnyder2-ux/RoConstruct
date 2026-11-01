// from server: 100% by auto
extern "C" void __cdecl G1_func_00843450(void*);
struct S_func_00843450 {
    virtual ~S_func_00843450();
    void* m_p;
};
S_func_00843450::~S_func_00843450()
{
    if (m_p)
        G1_func_00843450(m_p);
}
