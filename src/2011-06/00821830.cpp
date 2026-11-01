// from server: 100% by auto
extern "C" void __cdecl G1_func_00821830(void*);
struct S_func_00821830 {
    virtual ~S_func_00821830();
    void* m_p;
};
S_func_00821830::~S_func_00821830()
{
    if (m_p)
        G1_func_00821830(m_p);
}
