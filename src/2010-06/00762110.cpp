// from server: 63% by atomic.potato
extern "C" void __stdcall Function676790(void *);
extern "C" void __stdcall Function699fa0(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *value)
{
    Function676790(value);
    Function699fa0(value, this);
}
