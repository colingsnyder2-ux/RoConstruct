// from server: 100% by auto
extern "C" void __cdecl G1_func_00891180(void*);
struct S_func_00891180 {
    virtual ~S_func_00891180();
    void* m_p;
};
S_func_00891180::~S_func_00891180()
{
    if (m_p)
        G1_func_00891180(m_p);
}
