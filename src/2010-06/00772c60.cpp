// from server: 51% by atomic.potato
struct S
{
    int f(int, int);
};

extern "C" void __stdcall G1_func_009ea404();
extern "C" void G1_func_00446d40(void *, void *);

int S::f(int a, int b)
{
    G1_func_009ea404();
    G1_func_00446d40((char *)this + 0x18, (void *)b);
    return 0;
}
