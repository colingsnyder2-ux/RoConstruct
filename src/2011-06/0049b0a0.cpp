// from server: 68% by atomic.potato
struct VideoControl
{
    char padding0[0x10c];
    void* m_control;
    char padding1[0x0c];
    void* m_value;
    void f(void*);
};

void VideoControl::f(void*)
{
    struct VTable
    {
        char pad0[0x0c];
        unsigned char (__thiscall* ready)(void*);
        char pad1[4];
        void (__thiscall* update)(void*, void*);
    };

    VTable* table = *(VTable**)m_control;
    if ((*table->ready)(m_control))
        (*table->update)(m_control, m_value);
}
