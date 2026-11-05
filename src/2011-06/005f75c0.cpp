// from server: 62% by atomic.potato
typedef int (EnumGetValue)(void *, int);

extern "C" void sub_602ab0(void *);

struct S_func_005f75c0
{
    char pad[32];
    void *descriptor;
    int f(int value);
};

int S_func_005f75c0::f(int value)
{
    char *p = (char *)descriptor;
    EnumGetValue *getValue = (EnumGetValue *)(*(unsigned long *)p + 8);
    int result = getValue(p, value);

    char *out = (char *)this + 16;
    sub_602ab0(out);
    *(int *)(out + 8) = result;
    *(int *)(out + 4) = 5;
    return 0;
}
