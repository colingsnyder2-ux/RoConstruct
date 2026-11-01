// from server: 100% by king_originala
struct Result
{
    unsigned int words[22];
};

struct Exception
{
    char storage[40];
    Exception();
    ~Exception();
};

__declspec(noreturn) void __cdecl throw_exception(const Exception &);

typedef Result (__cdecl *Invoker)(const void *);

struct Table
{
    void (__cdecl *manager)();
    Invoker invoke;
};

struct S
{
    const Table *table;
    unsigned int padding;
    char buffer[4];

    Result operator()() const;
};

Result S::operator()() const
{
    if (!table)
        throw_exception(Exception());

    return table->invoke(buffer);
}
