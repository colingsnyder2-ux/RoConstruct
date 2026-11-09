// from server: 66% by atomic.potato
extern "C" void *std_basic_string_copy(void *, const void *);

struct S_func_006cf450 {
    char pad0[2968];
    const void *f(const void *);
};

const void *S_func_006cf450::f(const void *source)
{
    char *target = reinterpret_cast<char *>(this) + 0xb98;
    std_basic_string_copy(target, source);
    return source;
}
