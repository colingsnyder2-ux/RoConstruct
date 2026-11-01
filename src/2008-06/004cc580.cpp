// from server: 100% by colin

struct Node {
    Node* next;
};

struct Item {
    char padding[0x70];
    Node link;
};

struct S {
    char padding[0x14];
    Node* buckets;
    char padding2[8];
    unsigned int current;

    void finish(Item*);
    void f(Item*);
};

void S::f(Item* item)
{
    Node* link = item ? &item->link : 0;
    Node* first = link->next;
    Node* last = link->next;

    while (last->next != link)
        last = last->next;

    last->next = first;

    unsigned int index = current;
    while (buckets[index].next == &buckets[index])
        ++index;

    current = index;
    finish(item);
}
