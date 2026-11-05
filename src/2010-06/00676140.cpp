// from server: 89% by atomic.potato
struct EventDesc
{
};

int __cdecl invoke(char *event, void *receiver)
{
    typedef void (__thiscall *Fn)(void *, void *);
    void *object = receiver ? (char *)receiver + 0x20 : 0;
    Fn fn = *(Fn *)(*(void ***)object + 0x10);
    fn(object, event + 0x20);
    return 0;
}
