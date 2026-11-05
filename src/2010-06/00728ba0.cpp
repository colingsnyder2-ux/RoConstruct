// from server: 79% by atomic.potato
extern "C" void __cdecl sub_7957a0(void *, const char *, int);
extern "C" void __cdecl sub_7a89b2(void *, const char *);

struct LuaArguments
{
    void *value;

    void __cdecl assign(const char *name);
};

void __cdecl LuaArguments::assign(const char *name)
{
    char buffer[40];

    sub_7957a0(buffer, "%s cannot be assigned to", (int)name);
    sub_7a89b2(buffer, "L$8PQ");
}
