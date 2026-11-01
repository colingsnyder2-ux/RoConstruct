// from server: 100% by tester
struct Primitive
{
    void get();
};

void Primitive::get()
{
    void *p = *(void **)((char *)this + 0x104);
    void **vtable = *(void ***)p;
    ((void (__thiscall *)(void *))vtable[6])(p);
}
