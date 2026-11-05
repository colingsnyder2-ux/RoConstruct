// from server: 100% by colin
struct Scope
{
    const char* name;
    void* previous;
    bool enabled;
    double startTime;

    Scope(const char*, bool);
    ~Scope();
};

struct Target;
struct TargetTable
{
    void* unused[2];
    int (__thiscall* invoke)(Target*, int);
};

struct Target
{
    TargetTable* table;
};

struct S_func_004ab9c0
{
    char pad0[0x2B80];
    Target* target;
    char pad1[0x1AC];
    const char* scopeName1;
    char pad2[4];
    const char* scopeName2;

    int f(int value);
};

int S_func_004ab9c0::f(int value)
{
    Scope first(scopeName1, false);
    const char* name2 = scopeName2;
    Scope second(name2, false);
    Target* t = target;
    TargetTable* tbl = t->table;
    int (__thiscall* fn)(Target*, int) = tbl->invoke;
    return fn(t, value);
}
