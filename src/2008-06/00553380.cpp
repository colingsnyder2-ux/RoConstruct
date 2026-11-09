// from server: 100% by king_originala
struct Element {
    char data[40];
};

struct Iterator {
    void* first;
    void* second;
};

struct Functor {
    unsigned int first;
    unsigned int second;
    Functor();
    void __thiscall operator()(Element*);
};

extern Element* __cdecl unwrap(Iterator*);

#pragma optimize("", off)
Functor __cdecl apply(Iterator begin, Iterator end, Functor function)
{
    struct {
        Element* current;
        Element* finish;
    } pointers;

    pointers.current = unwrap(&begin);
    pointers.finish = unwrap(&end);
    for (; pointers.current != pointers.finish; ++pointers.current)
        function(pointers.current);
    return function;
}
#pragma optimize("", on)
