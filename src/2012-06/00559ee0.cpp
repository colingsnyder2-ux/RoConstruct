// from server: 55% by atomic.potato
struct S_func_00559ee0
{
    char pad0[0x18];
    int m_field18;
    int m_field1c;
};

extern "C" void __stdcall S_func_00685090();
extern "C" void __stdcall S_func_00982114(void *);

S_func_00559ee0 *__stdcall S_func_00559ee0_ctor(S_func_00559ee0 *self, char flag)
{
    self->m_field18 = 0x00b730b8;
    self->m_field1c = 0x00b730ac;
    S_func_00685090();
    if (flag & 1)
    {
        S_func_00982114(self);
    }
    return self;
}
