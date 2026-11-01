// from server: 100% by colin
struct KeyButton {
    char pad[0x100];
    void *field_100;
    void method(void *arg);
};

void KeyButton::method(void *arg)
{
    void *p = *(void **)((char *)arg + 4);
    void **vtbl = *(void ***)p;
    void (__thiscall *fn)(void *, void *, int) = (void (__thiscall *)(void *, void *, int))vtbl[5];
    fn(p, field_100, 0);
}
