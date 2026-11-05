// from server: 100% by auto
extern "C" void __cdecl G1_func_00869e00(void*);
struct S_func_00869e00 {
    virtual ~S_func_00869e00();
    void* m_p;
};
S_func_00869e00::~S_func_00869e00()
{
    if (m_p)
        G1_func_00869e00(m_p);
}
