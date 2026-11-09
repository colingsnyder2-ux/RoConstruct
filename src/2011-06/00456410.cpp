// from server: 61% by atomic.potato
struct Inner
{
    char pad[0x24];
    unsigned int count;
    char pad2[0x88 - 0x28];
    int* items;
};

struct Outer
{
    char pad[0x20];
    void* obj;
    Inner* inner;
    bool f(unsigned int index, int value);
};

bool Outer::f(unsigned int index, int value)
{
    Inner* in = inner;
    if (index >= in->count)
        return false;
    int item = in->items[index];
    void** vtable = *(void***)obj;
    void (*fn)(void*, int*, int) = (void (*)(void*, int*, int))vtable[3];
    fn(obj, &item, value);
    return true;
}
