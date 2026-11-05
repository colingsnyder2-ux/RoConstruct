// from server: 83% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_7A799A(void *);

struct S {
    void SetImpl();
};

void S::SetImpl()
{
    void *p = *(void **)((char *)this + 0xA0);
    if (p)
        sub_7A799A(p);
    ((void (__thiscall *)(S *))0x599C50)(this);
}
