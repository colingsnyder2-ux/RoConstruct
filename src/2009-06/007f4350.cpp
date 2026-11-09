// from server: 100% by auto
extern "C" void __cdecl G1_func_007f4350(void*);
struct S_func_007f4350 {
    virtual ~S_func_007f4350();
    void* m_p;
};
S_func_007f4350::~S_func_007f4350()
{
    if (m_p)
        G1_func_007f4350(m_p);
}
