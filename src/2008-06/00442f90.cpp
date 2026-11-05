// from server: 100% by atomic.potato
extern "C" int __cdecl sub_006a17c6(void *, void *, void *, void *, int);

struct Reflection
{
    int f(void *);
};

int Reflection::f(void *value)
{
    int result = sub_006a17c6(value, 0, (void *)0x92907c, (void *)0x92a950, 0);
    return result != 0;
}
