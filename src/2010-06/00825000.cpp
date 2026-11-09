// from server: 100% by auto
extern "C" void __cdecl G1_func_00825000(void*);
struct S_func_00825000 {
    virtual ~S_func_00825000();
    void* m_p;
};
S_func_00825000::~S_func_00825000()
{
    if (m_p)
        G1_func_00825000(m_p);
}
