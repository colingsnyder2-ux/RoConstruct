// from server: 100% by auto
extern "C" void __cdecl G1_func_00744210(void*);
struct S_func_00744210 {
    virtual ~S_func_00744210();
    void* m_p;
};
S_func_00744210::~S_func_00744210()
{
    if (m_p)
        G1_func_00744210(m_p);
}
