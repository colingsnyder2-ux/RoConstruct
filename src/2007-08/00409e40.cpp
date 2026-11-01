// from server: 83% by colin
struct Inner {
    void* vtbl;
};

struct Outer {
    char pad[0x28];
    Inner* inner;
};

void func_00409e40(Outer* obj)
{
    Inner* p = obj->inner;
    void** vt = (void**)p->vtbl;
    void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
    fn(p);
}
