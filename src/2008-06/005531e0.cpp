// from server: 100% by king_originala
struct Item {
    char data[40];
};

extern "C" void __cdecl helper(Item *, int, int, void *);

struct S {
    char padding[8];
    char context;

    Item *f(Item *, int, int);
};

#pragma optimize("", off)
Item *S::f(Item *first, int count, int value)
{
    helper(first, count, value, &context);
    return first + count;
}
