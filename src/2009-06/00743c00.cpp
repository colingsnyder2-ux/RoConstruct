// from server: 100% by auto
extern "C" void __cdecl G1_func_00743c00(void*);
struct S_func_00743c00 {
    virtual ~S_func_00743c00();
    void* m_p;
};
S_func_00743c00::~S_func_00743c00()
{
    if (m_p)
        G1_func_00743c00(m_p);
}
