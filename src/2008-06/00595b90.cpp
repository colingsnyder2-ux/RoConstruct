// from server: 100% by king_originala
struct BadFunctionCall
{
    char data[40];
    BadFunctionCall();
    ~BadFunctionCall();
};

__declspec(noreturn) void __cdecl throw_exception(const BadFunctionCall&);

struct FunctionTable
{
    void* manager;
    void (__cdecl *invoke)(void*, void*);
};

struct S
{
    FunctionTable* table;
    unsigned int reserved;
    char storage[12];

    void f(void* argument);
};

void S::f(void* argument)
{
    if (!table)
        throw_exception(BadFunctionCall());

    table->invoke(storage, argument);
}
