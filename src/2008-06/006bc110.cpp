// from server: 100% by auto
extern "C" void __cdecl G1_func_006bc110(void*);
struct S_func_006bc110 {
    virtual ~S_func_006bc110();
    void* m_p;
};
S_func_006bc110::~S_func_006bc110()
{
    if (m_p)
        G1_func_006bc110(m_p);
}
