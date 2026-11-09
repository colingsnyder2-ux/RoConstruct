// from server: 58% by atomic.potato
struct S
{
    char pad[0xb8];
    char value[0x20];

    S& f(S& source);
};

extern "C" void copy_string(void*, const void*);

S& S::f(S& source)
{
    copy_string((void*)&value[0], (const void*)&source.value[0]);
    source.value[0x1c] = value[0x1c];
    return source;
}
