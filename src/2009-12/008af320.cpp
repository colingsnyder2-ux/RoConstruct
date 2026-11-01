// from server: 100% by auto
extern "C" void __cdecl G1_func_008af320(void*);
struct S_func_008af320 {
    virtual ~S_func_008af320();
    void* m_p;
};
S_func_008af320::~S_func_008af320()
{
    if (m_p)
        G1_func_008af320(m_p);
}
