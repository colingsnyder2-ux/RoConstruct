// from server: 50% by atomic.potato
extern "C" void __cdecl Function0040C080(void *);

struct S
{
    char padding[200];
    float value;

    void set(float v);
};

void S::set(float v)
{
    value = v;
    Function0040C080((void *)0x00B959F4);
}
