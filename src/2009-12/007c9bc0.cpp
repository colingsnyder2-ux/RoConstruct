// from server: 39% by atomic.potato
extern "C" void std_string_ctor(void *);
extern "C" void typed_property_descriptor(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    char value[24];
    std_string_ctor(value);
    typed_property_descriptor((char *)this + 24, value);
    return 0;
}
