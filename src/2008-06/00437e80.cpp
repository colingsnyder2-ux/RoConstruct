// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
struct S;
typedef void (__thiscall *Method)(S *, int);

struct Table {
    Method unused[58];
    Method target;
};

struct S {
    Table *table;
    void f(const int *value);
};

void S::f(const int *value)
{
    return table->target(this, *value);
}
