// from server: 63% by atomic.potato
extern "C" void std_string_copy(void*, const void*);

struct S
{
    void* p8;
    void* value;
    void* source;
    S* f(void*, const void*);
};

S* S::f(void* unused, const void* input)
{
    void* base = 0;
    if (input != 0)
        base = (char*)input - 0x1c;

    typedef void* (Fn)(void*, void*);
    Fn* fn = (Fn*)value;
    void* result = fn((char*)source + (long)base, 0);

    std_string_copy((char*)unused, result);
    return (S*)unused;
}
