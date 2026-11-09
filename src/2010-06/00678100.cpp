// from server: 100% by atomic.potato
struct Primitive
{
    void get();
};

void Primitive::get()
{
    void *p = *(void **)((char *)this + 0xf0);
    void **vtable = *(void ***)p;
    ((void (__thiscall *)(void *))vtable[6])(p);
}
