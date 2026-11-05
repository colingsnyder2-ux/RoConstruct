// from server: 100% by auto
extern "C" void __cdecl G1_func_00661760(void*);
struct S_func_00661760 {
    virtual ~S_func_00661760();
    void* m_p;
};
S_func_00661760::~S_func_00661760()
{
    if (m_p)
        G1_func_00661760(m_p);
}
