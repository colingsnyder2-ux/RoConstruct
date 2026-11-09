// from server: 62% by atomic.potato
extern "C" void __cdecl destroy_locale(void*);

struct S
{
    unsigned char pad4c[0x4c];
    void* stream;
    unsigned char flags;
    void f(void*);
};

void S::f(void* value)
{
    if ((flags & 1) && stream)
    {
        destroy_locale(value);
        destroy_locale(&value);
    }
}
