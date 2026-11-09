// from server: 100% by king_originala
struct Value
{
    virtual void reserved();
    virtual int get();
};

struct Item
{
    char padding[16];
    Value value;
};

extern int __cdecl compareValues(int, int);

int __stdcall func_0041fbb0(Item* first, Item* second, int)
{
    return compareValues(first->value.get(), second->value.get());
}
