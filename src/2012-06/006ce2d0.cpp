// from server: 41% by atomic.potato
extern "C" void std_string_copy(void *, const void *);

struct S_func_006ce2d0 {
    char pad0[148];
    int f(const void *);
};

int S_func_006ce2d0::f(const void *value)
{
    char result[16];
    std_string_copy(result, value);
    return (int)value;
}
