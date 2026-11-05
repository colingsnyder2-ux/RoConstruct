// from server: 100% by auto
extern "C" void __cdecl G1_func_00806290(void*);
struct S_func_00806290 {
    virtual ~S_func_00806290();
    void* m_p;
};
S_func_00806290::~S_func_00806290()
{
    if (m_p)
        G1_func_00806290(m_p);
}
