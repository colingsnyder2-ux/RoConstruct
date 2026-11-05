// from server: 100% by auto
extern "C" void __cdecl G1_func_00699280(void*);
struct S_func_00699280 {
    virtual ~S_func_00699280();
    void* m_p;
};
S_func_00699280::~S_func_00699280()
{
    if (m_p)
        G1_func_00699280(m_p);
}
