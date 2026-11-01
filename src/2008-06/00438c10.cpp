// from server: 100% by king_originala
struct Object;

struct Iterator {
    void* unused;
    int* current;
};

struct Functor {
    void (__thiscall *method)(Object*, int, int);
    Object* object;
    int adjustment;
    int argument;
};

Functor apply(Iterator first, Iterator last, Functor function)
{
    int* current = first.current;
    int* end = last.current;
    for (; current != end; ++current)
        function.method(
            reinterpret_cast<Object*>(
                function.adjustment + reinterpret_cast<char*>(function.object)),
            function.argument, *current);
    return function;
}
