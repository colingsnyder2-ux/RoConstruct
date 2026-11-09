// from server: 85% by atomic.potato
extern "C" void G1_string_assign(void *, void *);

struct GfxClustererPart
{
    char data[0x1c];
    void *value;
};

void func_004cdcf0(char *begin, char *end, GfxClustererPart *source)
{
    char *p = begin;

    while (p != end)
    {
        G1_string_assign(p, source);
        *(void **)(p + 0x1c) = source->value;
        p += 0x20;
    }
}
