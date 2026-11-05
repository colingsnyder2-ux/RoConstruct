// from server: 100% by atomic.potato
extern "C" void __stdcall Function_00414da0(void *);

struct EventDesc_008c9540
{
    char pad0[164];
    void *m_value;
    void Set(void *value);
};

void EventDesc_008c9540::Set(void *value)
{
    if (m_value != value)
    {
        m_value = value;
        Function_00414da0((void *)0xe53a34);
    }
}
