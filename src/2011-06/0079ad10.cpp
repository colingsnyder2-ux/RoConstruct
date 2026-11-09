// from server: 57% by atomic.potato
struct S
{
    void *field4;
    void *field();
};

extern "C" void * __cdecl Target(void *);

void *S::field()
{
    void *value = field4;
    if (value)
        return Target(*((void **)((char *)value + 0x30)));
    return value;
}
