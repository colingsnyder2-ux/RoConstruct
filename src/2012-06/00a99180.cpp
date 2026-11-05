// from server: 42% by atomic.potato
extern "C" void sub_00983144(void);
extern "C" void std_string_destructor(void *);

struct S
{
    int f();
};

int S::f()
{
    sub_00983144();
    char x[80];
    std_string_destructor(x);
    return 0;
}
