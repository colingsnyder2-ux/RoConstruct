// from server: 77% by atomic.potato
extern "C" void G1_func_007e20e0(void *, const char *, const char *);
extern "C" void G1_func_007f4878(void *, const char *);

struct S
{
    void __cdecl f(const char *);
};

void S::f(const char *value)
{
    char buffer[32];
    G1_func_007e20e0(buffer, "%s is not a valid member", value);
    G1_func_007f4878(buffer, "L$8PQ");
}
