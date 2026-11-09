// from server: 95% by atomic.potato
extern "C" void __cdecl Function414da0(const char *);

struct S {
    char padding[132];
    int member_84;
    void f(const char *);
};

void S::f(const char *value)
{
    if (member_84 != (int)value) {
        member_84 = (int)value;
        Function414da0("|$0PW");
    }
}
