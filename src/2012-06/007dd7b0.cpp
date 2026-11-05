// from server: 75% by atomic.potato
extern "C" bool __cdecl compare_strings(const char* const&, const char&);

struct EventDesc
{
    int match(const char* a, const char* b);
};

int EventDesc::match(const char* a, const char* b)
{
    const char* p = *reinterpret_cast<const char* const*>(a);
    while (p)
    {
        if (compare_strings(*reinterpret_cast<const char* const*>(b),
                            *(p - 0x20)))
            break;
        p = *reinterpret_cast<const char* const*>(p);
    }
    return reinterpret_cast<int>(p);
}
