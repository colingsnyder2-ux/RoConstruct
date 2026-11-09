// from server: 38% by atomic.potato
struct VVector2int16
{
    short x;
    short y;
};

struct TypedPropertyDescriptor
{
    void *pad0;
    void *pad1;
    void *pad2;
    void *property;
    void f(VVector2int16 *value);
};

void TypedPropertyDescriptor::f(VVector2int16 *value)
{
    void *object = *(void **)((char *)this + 0x1c);
    void *vtable = *(void **)object;
    typedef VVector2int16 *(__thiscall *Getter)(VVector2int16 *);
    VVector2int16 *result;
    result = ((Getter)((char *)vtable + 8))(value);
    *(VVector2int16 **)((char *)this + 0x1c) = result;
}
