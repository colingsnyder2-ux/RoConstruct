// from server: 100% by king_originala
struct Result
{
    unsigned int a, b, c, d, e;
};

struct Exception
{
    unsigned char data[40];
    Exception();
    ~Exception();
};

__declspec(noreturn) void __cdecl throw_helper(const Exception&);

struct Dispatch
{
    void* manager;
    Result (__cdecl *invoke)(void*, int, int, int, int);
};

struct S
{
    Dispatch* dispatch;
    unsigned int reserved;
    unsigned char storage[1];

    Result f(int a, int b, int c, int d);
};

Result S::f(int a, int b, int c, int d)
{
    if (!dispatch)
        throw_helper(Exception());

    return dispatch->invoke(storage, a, b, c, d);
}
