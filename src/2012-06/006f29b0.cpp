// from server: 76% by atomic.potato
extern "C" void *__cdecl sub_79a9f0(void *);

struct FirstPersonCommand
{
    char padding[12];
    void *field_0c;
    void *f();
};

void *FirstPersonCommand::f()
{
    void *value = sub_79a9f0(field_0c);
    if (value)
        return (char *)value + 0x134;
    return 0;
}
