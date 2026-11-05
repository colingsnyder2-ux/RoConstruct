// from server: 100% by atomic.potato
struct Inner {
    void f(void* out);
};

struct S {
    int Get(void* out);
};

int S::Get(void* out)
{
    ((Inner*)(*(void**)((char*)this + 8)))->f(out);
    return (int)out;
}
