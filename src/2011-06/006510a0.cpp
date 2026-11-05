// from server: 38% by atomic.potato
struct String
{
    String(const String&);
};

typedef String (__thiscall *StringCopyConstructor)(String*, const String&);

struct S_func_006510a0
{
    char pad[4];
    String value;
    S_func_006510a0(const S_func_006510a0&);
};

S_func_006510a0::S_func_006510a0(const S_func_006510a0& other)
    : value(other.value)
{
}
