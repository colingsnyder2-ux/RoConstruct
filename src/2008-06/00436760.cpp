// from server: 100% by colin
extern "C" void __cdecl free_mem(void *);

struct Item;

struct ItemVTable {
    void (__stdcall *slots[3])(Item *);
};

struct Item {
    ItemVTable *vtable;
};

struct COutputView {
    unsigned char padding[16];
    Item ***map;
    unsigned int mapSize;
    unsigned int first;
    unsigned int size;

    void clear();
};

void COutputView::clear()
{
    while (size != 0) {
        if (size != 0) {
            unsigned int idx = size + first - 1;
            unsigned int bucket = idx >> 2;
            if (mapSize <= bucket)
                bucket -= mapSize;
            Item *&item = map[bucket][idx & 3];
            if (item != 0)
                item->vtable->slots[2](item);

            if (--size == 0)
                first = 0;
        }
    }

    unsigned int i = mapSize;
    while (i > 0) {
        --i;
        if (map[i] != 0)
            free_mem(map[i]);
    }

    if (map != 0)
        free_mem(map);

    mapSize = 0;
    map = 0;
}
