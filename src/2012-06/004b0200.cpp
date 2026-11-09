// from server: 51% by atomic.potato
struct TextDisplay
{
    char pad0[4];
    char m_enabled;
    char pad5[263];
    struct VTable
    {
        int (*unused0)();
        int (*unused1)();
        int (*unused2)();
        char (*check)();
    };
    VTable* m_object;
    int f();
};

int TextDisplay::f()
{
    if (!m_enabled)
        return 0;
    if (m_object->check())
        return 0;
    return 1;
}
