// from server: 100% by atomic.potato
extern "C" void __cdecl sub_407560(void *);
extern "C" void __cdecl sub_407ee0(void *);

void f(void *value)
{
    if (value == 0)
        sub_407560(0);
    else
        sub_407ee0(value);
}
