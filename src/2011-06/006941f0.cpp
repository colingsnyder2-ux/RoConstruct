// from server: 58% by atomic.potato
struct S
{
    char padding[0x94];
    char value[0x20];

    S* f(S* source);
};

extern "C" void copy_string(void* destination, const void* source);

S* S::f(S* source)
{
    copy_string(source->value, value);
    source->value[0] = 0;
    return source;
}
