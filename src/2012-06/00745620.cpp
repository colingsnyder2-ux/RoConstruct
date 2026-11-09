// from server: 60% by atomic.potato
struct S
{
    int f();
};

extern "C" void helper(void*);

typedef void (*StringCopy)(void*, const void*);

extern StringCopy g_string_copy;

int S::f()
{
    void* value = 0;
    helper(&value);
    g_string_copy(this, value);
    return 0;
}
