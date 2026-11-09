// from server: 35% by atomic.potato
extern "C" int Function65e520(void *, int *, int);

struct SurfaceEnumPropDescriptor
{
    int f(int);
};

int SurfaceEnumPropDescriptor::f(int value)
{
    void **object = *(void ***)((char *)this + 0x20);
    typedef int (Method)(void *, int);
    Method *method = *(Method **)((char *)*(void **)object + 0x0c);
    int result = method(object, value);
    return Function65e520(this, &result, value);
}
