// from server: 35% by atomic.potato
extern "C" void __stdcall sub_6d53e0(void *);

struct RefPropDescriptor
{
    void target(void *value, void *value2);
};

void RefPropDescriptor::target(void *value, void *value2)
{
    void *result;
    if (value)
        sub_6d53e0(value);
    else
        result = 0;

    if (value)
        result = value;

    void *obj = *((void **)this + 8);
    void **vtable = *((void ***)obj);
    void (*fn)(void *, void *) = (void (*)(void *, void *))vtable[4];
    fn(obj, result);
}
