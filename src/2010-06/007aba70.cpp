// from server: 100% by auto
extern "C" void __cdecl G1_func_007aba70(void*);
struct S_func_007aba70 {
    virtual ~S_func_007aba70();
    void* m_p;
};
S_func_007aba70::~S_func_007aba70()
{
    if (m_p)
        G1_func_007aba70(m_p);
}
