// from server: 69% by atomic.potato
extern "C" void __stdcall Function6507c0(void *, void *);

struct G3D_VVector2int16_TypedPropertyDescriptor
{
    void *f(void *, void *);
};

void *G3D_VVector2int16_TypedPropertyDescriptor::f(void *a, void *b)
{
    void *vtable = *(void **)((char *)this + 0x1c);
    void *fn = *(void **)((char *)vtable + 8);
    void *result = 0;
    ((void (__stdcall *)(void *, void **, void *))fn)(vtable, &result, b);
    Function6507c0(result, &result);
    return result;
}
