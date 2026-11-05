// from server: 100% by king_originala
struct ExceptionObject
{
    unsigned long words[10];
    ExceptionObject();
    ~ExceptionObject();
};

__declspec(noreturn) void __cdecl raise_exception(const void* source);

struct S
{
    unsigned long* table;
    int f(int first, int second);
};

int S::f(int first, int second)
{
    if (!table)
        raise_exception(&ExceptionObject());

    typedef int (__cdecl *Invoker)(void*, int, int);
    return reinterpret_cast<Invoker>(table[1])(
        reinterpret_cast<char*>(this) + 8, first, second);
}
