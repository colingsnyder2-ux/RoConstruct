// from server: 37% by atomic.potato
struct S
{
    void* pad[75];
    struct T
    {
        struct V
        {
            void (__thiscall *f)(void*, void*);
        };
        V* v;
    };
    T* member;
    void* f(void*);
};

void* S::f(void* arg)
{
    void* value = arg ? (char*)arg + 0x1c : 0;
    member->v->f(member->v, value);
    return arg;
}
