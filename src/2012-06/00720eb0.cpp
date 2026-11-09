// from server: 63% by atomic.potato
extern "C" void f(int);

void f(int);

struct S
{
};

void __cdecl g(int value, int* result)
{
    if (value == 4)
    {
        *result = 0xDAE080;
        ((char*)result)[4] = 0;
        ((char*)result)[5] = 0;
    }
    else
    {
        value = value;
        f(value);
    }
}
