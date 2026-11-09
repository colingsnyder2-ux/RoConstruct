// from server: 100% by auto
extern "C" void __cdecl G1_func_008bc590(void*);
struct S_func_008bc590 {
    virtual ~S_func_008bc590();
    void* m_p;
};
S_func_008bc590::~S_func_008bc590()
{
    if (m_p)
        G1_func_008bc590(m_p);
}
