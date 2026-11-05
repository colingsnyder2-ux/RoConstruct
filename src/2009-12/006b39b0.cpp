// from server: 65% by atomic.potato
extern "C" void __stdcall basic_string_copy(void *, const void *);

struct DropperTool
{
    char pad0[160];
    char m_value[32];

    char *f(void *);
};

char *DropperTool::f(void *source)
{
    void *value = pad0 + 160;
    basic_string_copy(source, value);
    *(char **)((char *)source + 28) = *(char **)((char *)value + 28);
    return (char *)source;
}
