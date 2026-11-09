// from server: 83% by atomic.potato
struct ExceptionAsyncResult
{
    int unused;
    int field4;
    void f();
};

extern "C" void __cdecl sub_446190(void *, int);
extern "C" void __cdecl sub_983144(void *, const char *);

void ExceptionAsyncResult::f()
{
    char buffer[44];
    sub_446190(buffer, field4);
    sub_983144(buffer, "d$(h");
}
