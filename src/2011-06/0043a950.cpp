// from server: 83% by atomic.potato
extern "C" void __cdecl sub_43a8c0(void *, int);
extern "C" void __cdecl sub_80b0ac(void *, const char *);

struct ExceptionAsyncResult
{
    int unused;
    int value;
    void f();
};

void ExceptionAsyncResult::f()
{
    char buffer[44];
    sub_43a8c0(buffer, value);
    sub_80b0ac(buffer, "d$(h");
}
