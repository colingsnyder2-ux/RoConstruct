// from server: 100% by king_originala
struct Bucket;
struct Item;

struct Iterator
{
    unsigned char state[8];
    bool func_00540f20(const Iterator &) const;
    Iterator &func_00541160();
    Bucket *func_005462c0() const;
    Bucket *func_00541180() const;
};

struct Collection
{
    Iterator func_00540630();
    Iterator func_00540660();
};

struct Items
{
    unsigned char state[24];
    unsigned int func_00546320() const;
    Item *&func_00552e60(unsigned int);
    Item *&func_00552e90();
    void func_00552ec0();
};

struct Bucket
{
    unsigned char padding[12];
    Items items;
    unsigned int cursor;
};

struct S
{
    unsigned char padding[8];
    Collection collection;
    Bucket *func_005529b0(Item *);
    int func_005528e0(Item *, Bucket *);
    int func_00552a60();
};

#pragma optimize("", off)
int S::func_00552a60()
{
    int total = 0;

    for (Iterator i = collection.func_00540630();
         i.func_00540f20(collection.func_00540660());
         i.func_00541160())
    {
        i.func_005462c0()->cursor = 0;
    }

    for (Iterator j = collection.func_00540630();
         j.func_00540f20(collection.func_00540660());
         j.func_00541160())
    {
        Bucket *bucket = j.func_00541180();

        while (bucket->cursor < bucket->items.func_00546320())
        {
            struct Locals
            {
                Bucket *destination;
                Item *item;
            } locals;

            locals.item = bucket->items.func_00552e60(bucket->cursor);
            locals.destination = func_005529b0(locals.item);

            if (locals.destination != bucket)
            {
                bucket->items.func_00552e60(bucket->cursor) =
                    bucket->items.func_00552e90();
                bucket->items.func_00552ec0();
                total += func_005528e0(locals.item, locals.destination);
            }
            else
            {
                bucket->cursor = bucket->cursor + 1;
            }
        }
    }

    return total;
}
#pragma optimize("", on)
