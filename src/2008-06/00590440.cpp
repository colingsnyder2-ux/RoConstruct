// from server: 100% by king_originala
struct Base1 {};
struct Base2 {};

struct __multiple_inheritance Object : Base1, Base2
{
    void callback();
};

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
    void (Object::*function)();
    void* argument;
    int unused;
};

struct Container
{
    int owner;
    int unused1;
    int unused2;
    Entry* first;
    Entry* last;
};

extern "C" void (__cdecl* _invalid_parameter_noinfo)();
extern Functor __cdecl apply(Iterator, Iterator, Functor);
extern void __cdecl visit(Object*, void*);
extern void __cdecl finish(void*);

void __stdcall process(Container* container, void* argument, void* context)
{
    Entry* end = container->last;

    Functor operation;
    operation.function = &Object::callback;
    operation.argument = argument;

    if (container->first > end)
        _invalid_parameter_noinfo();

    Iterator last;
    last.unused = container->owner;
    last.position = end;

    Entry* begin = container->first;
    if (begin > container->last)
        _invalid_parameter_noinfo();

    Iterator first;
    first.unused = container->owner;
    first.position = begin;

    apply(first, last, operation);

    for (unsigned int i = 0;
         i < static_cast<unsigned int>(container->last - container->first);
         ++i)
    {
        if (i >= static_cast<unsigned int>(container->last - container->first))
            _invalid_parameter_noinfo();

        visit(container->first[i].object, context);
    }

    finish(context);
}
