// from server: 42% by atomic.potato
typedef const char *StringArg;

extern "C" void G1_basic_string_copy(void *destination, const void *source);

struct S
{
    void *base;
    void *metadata;
    void *f(void *value);
};

void *S::f(void *value)
{
    void *result = 0;
    if (value != 0)
        result = (char *)value - 28;

    void *source = (char *)metadata + (unsigned int)result;
    G1_basic_string_copy(&result, source);
    return this;
}
