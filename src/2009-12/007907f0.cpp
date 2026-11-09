// from server: 66% by atomic.potato
extern "C" void __cdecl Function_7e20e0(void *, const char *, int);
extern "C" void __cdecl Function_7f4878(void *, const char *);

struct LuaArguments
{
    void __cdecl f(int);
};

void __cdecl LuaArguments::f(int value)
{
    char buffer[4];
    Function_7e20e0(buffer, "%s cannot be assigned to", value);
    Function_7f4878(buffer, "L$8PQ");
}
