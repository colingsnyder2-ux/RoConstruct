// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct __multiple_inheritance Object;

struct Entry
{
    Object* object;
    int unused;
};

struct Iterator
{
    int unused;
    Entry* position;
};

struct Functor
{
    void (Object::*callback)(int);
    int argument;
    int unused;
};

Functor func_005903f0(Iterator first, Iterator last, Functor function)
{
    Entry* current = first.position;
    Entry* end = last.position;
    for (; current != end; ++current)
        (current->object->*function.callback)(function.argument);

    return function;
}