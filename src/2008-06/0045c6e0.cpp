// from server: 100% by king_originala
struct Result {
    int data[22];
};

struct S {
    Result* (__cdecl *function)(void*);
    void* argument;
};

Result __cdecl f(S* s)
{
    return *s->function(s->argument);
}
