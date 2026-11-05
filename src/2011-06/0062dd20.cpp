// from server: 100% by atomic.potato
struct T {
    void g(void*);
};

struct S_func_0062dd20 {
    char pad0[508];
    char field1[32];
    char field2[32];
    void f(void*);
};

void S_func_0062dd20::f(void* value)
{
    ((T*)field1)->g(value);
    ((T*)field2)->g(value);
}
