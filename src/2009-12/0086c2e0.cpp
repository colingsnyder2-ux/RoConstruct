// from server: 80% by atomic.potato
struct CSelectionCaption
{
    void f(int value);
};

struct VTable
{
    void (__thiscall *fn)(void *, int, CSelectionCaption *);
};

extern "C" void *GetObject(CSelectionCaption *);

void CSelectionCaption::f(int value)
{
    void *object = GetObject(this);
    VTable *table = *(VTable **)object;
    table->fn(object, value, this);
}
