// from server: 100% by auto
extern "C" void __cdecl G1_func_006df120(void*);
struct S_func_006df120 {
    virtual ~S_func_006df120();
    void* m_p;
};
S_func_006df120::~S_func_006df120()
{
    if (m_p)
        G1_func_006df120(m_p);
}
