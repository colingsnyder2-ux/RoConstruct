// from server: 100% by king_originala
struct Target {};

struct Item
{
    char data[8];
};

struct Callback
{
    void (Target::*method)(Item*);
    int adjustment;
    Target* object;
    int extra;
};

Callback __cdecl function_00423ac0(
    int unused1, Item* first, int unused2, Item* last, Callback callback)
{
    while (first != last)
    {
        Target* object =
            (Target*)(callback.adjustment + (char*)callback.object);
        (object->*callback.method)(first);
        ++first;
    }
    return callback;
}
