// from server: 47% by atomic.potato
struct S
{
    void *field_1c;

    int f(int value);
};

extern "C" int call_member(void *, void *);
extern "C" int function_6cd500(int, int);

int S::f(int value)
{
    void *object = field_1c;
    void *vtable = *(void **)object;
    void *target = *(void **)((char *)vtable + 0x0c);
    int result = call_member(target, (void *)value);
    return function_6cd500(result, value);
}
