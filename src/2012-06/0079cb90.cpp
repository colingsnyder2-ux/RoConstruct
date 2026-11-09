// from server: 84% by atomic.potato
struct EventDescDispatchTarget
{
    void operator()(void *);
};

struct EventDesc
{
    unsigned long offset30;
    unsigned long offset34;
    void Dispatch(void *);
};

void EventDesc::Dispatch(void *value)
{
    unsigned long eax = (unsigned long)value;
    if (eax)
        eax -= 0x1c;
    else
        eax = 0;

    unsigned long edx = *(unsigned long *)(eax + 0x138);
    unsigned long esi = *(unsigned long *)((char *)this + 0x34);
    edx = *(unsigned long *)(edx + esi);
    edx += *(unsigned long *)((char *)this + 0x30);

    ((void (__cdecl *)(void *))0x79ba80)((void *)(edx + eax + 0x138));
}
