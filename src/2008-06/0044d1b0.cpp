// from server: 100% by king_originala
struct Iterator
{
    void* owner;
    void* position;
};

struct S
{
    bool predicate(void*, void*);
    int f(Iterator first, Iterator last);
};

struct Callback
{
    bool (S::*method)(void*, void*);
    S* object;
};

extern void* __cdecl search(void*, void*, Callback);
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

int S::f(Iterator first, Iterator last)
{
    Callback callback = { &S::predicate, this };
    Iterator result = first;
    result.position = search(first.position, last.position, callback);

    if (!result.owner || result.owner != last.owner)
        _invalid_parameter_noinfo();

    return result.position == last.position;
}
