// from server: 100% by atomic.potato
extern "C" void __cdecl Function_00982114(void *);

struct S_func_007b6250
{
    char pad[140];
    void *m_value;
    void SetImpl();
};

extern "C" void __fastcall Function_00685090(S_func_007b6250 *);

void S_func_007b6250::SetImpl()
{
    if (m_value)
        Function_00982114(m_value);
    Function_00685090(this);
}
