// from server: 46% by atomic.potato
struct S_func_00651930
{
    float value;
    unsigned short flags;
    void f(S_func_00651930* dst, const S_func_00651930* src);
};

void S_func_00651930::f(S_func_00651930* dst, const S_func_00651930* src)
{
    dst->value = value + src->value;
    dst->flags = flags + src->flags;
}
