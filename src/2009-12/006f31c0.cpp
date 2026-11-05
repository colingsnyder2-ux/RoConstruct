// from server: 46% by atomic.potato
struct SurfaceEnumPropDescriptor
{
    void *pad0;
    void *pad1;
    void *pad2;
    void *pad3;
    void *pad4;
    int f(void *);
};

extern "C" int InvokeDescriptor(void *, void *);
extern "C" int __cdecl Call0065ead0(void *, int *);

int SurfaceEnumPropDescriptor::f(void *arg)
{
    void *object;
    int value;
    object = *(void **)((char *)this + 0x20);
    value = InvokeDescriptor(*(void **)object, arg);
    return Call0065ead0(this, &value);
}
