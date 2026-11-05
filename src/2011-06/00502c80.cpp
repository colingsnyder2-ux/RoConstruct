// from server: 53% by atomic.potato
struct S
{
    char reserved[0xb8];
    void __cdecl update(float *);
};

extern "C" float __cdecl get_value(void *);
extern "C" void __cdecl update_value(S *, float *);

void S::update(float *p)
{
    float value = get_value(this + 0xb8);
    update_value(this, &value);
}
