// from server: 100% by auto
extern "C" void __cdecl G1_func_0085b110(void*);
struct S_func_0085b110 {
    virtual ~S_func_0085b110();
    void* m_p;
};
S_func_0085b110::~S_func_0085b110()
{
    if (m_p)
        G1_func_0085b110(m_p);
}
