// from server: 66% by atomic.potato
extern "C" void __stdcall Function744ba0(void *, void *);

struct G3D_VVector2int16_TypedPropertyDescriptor
{
    char pad[0x28];
    void *field28;
    void __stdcall f(void *value);
};

void __stdcall G3D_VVector2int16_TypedPropertyDescriptor::f(void *value)
{
    void *p = 0;
    void *obj = field28;
    void *vtbl = *(void **)obj;
    void (__stdcall *fn)(void *, void **, void *) = *(void (__stdcall **)(void *, void **, void *))((char *)vtbl + 8);
    fn(obj, &p, value);
    Function744ba0(p, &p);
}
