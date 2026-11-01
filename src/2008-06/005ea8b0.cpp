// from server: 100% by king_originala
struct Item {
    char pad0[0x50];
    int index;
    char pad1[4];
    void* owner;
};

struct P_func_0060cc40 {
    void g();
};

struct S_func_0060cc40 {
    P_func_0060cc40* m_p;
    void f();
};

struct Manager {
    void remove(Item*);
};

struct Array {
    Item** data;
    int size;

    void resize(int, int);
    __forceinline void erase(int);
};

struct World {
    char pad0[0x84];
    S_func_0060cc40* first;
    Manager* second;
    char pad1[0x20];
    Array items;

    void detach(Item*, int);
    void remove(Item*);
};

__forceinline void Array::erase(int index)
{
    Item* last = data[size - 1];
    data[index] = last;
    last->index = index;
    resize(size - 1, 0);
}

void World::remove(Item* item)
{
    detach(item, 0);
    (first->*reinterpret_cast<void (S_func_0060cc40::*)(Item*)>(
        &S_func_0060cc40::f))(item);
    second->remove(item);
    items.erase(item->index);
    item->index = -1;
    item->owner = 0;
}
