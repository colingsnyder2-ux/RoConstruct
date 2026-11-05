// from server: 100% by atomic.potato
struct TypeInfo;

extern "C" int (__thiscall *type_info_equal)(TypeInfo *, TypeInfo *);

struct S
{
    int f();
};

int S::f()
{
    TypeInfo *p = *(TypeInfo **)this;
    return type_info_equal((TypeInfo *)0xb1d7b4, *(TypeInfo **)((char *)p + 8));
}
