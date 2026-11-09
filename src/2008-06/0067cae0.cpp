// from server: 100% by king_originala
struct Item {
    unsigned int first;
    unsigned int second;
};

extern void __cdecl adjust_heap(Item *, int, int, Item);

void __cdecl make_heap(Item *first, Item *last)
{
    int count = last - first;
    int parent = count / 2;
    if (parent > 0) {
        Item *current = first + parent;
        do {
            Item value = *--current;
            --parent;
            adjust_heap(first, parent, count, value);
        } while (parent > 0);
    }
}
