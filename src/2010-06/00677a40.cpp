// from server: 48% by atomic.potato
struct VTable_00677a40
{
    int (*unused)();
    int (*f)();
};

extern "C" void __cdecl Function_0074ebb0(void *, int);

struct Geometry_00677a40
{
    void *field_f0;
    void f();
};

void Geometry_00677a40::f()
{
    void *p = *(void **)((char *)this + 0xf0);
    int value = ((VTable_00677a40 *)*(void **)p)->f();
    Function_0074ebb0((char *)p + 4, value == 1);
}
