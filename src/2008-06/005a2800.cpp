// from server: 100% by colin
typedef int (__thiscall *Getter)(void *);
typedef void (__thiscall *Setter)(void *, int);

struct Iterator
{
    void *unused;
    char *current;
};

struct Function
{
    Setter setter;
    int adjustment;
    char *object;
    Getter getter;
    int extra1;
    int extra2;
};

Function __cdecl apply(Iterator first, Iterator last, Function function)
{
    char *current = first.current;
    char *end = last.current;
    for (; current != end; current += 8)
    {
        int value = function.getter(current);
        function.setter((void *)(function.adjustment + (int)function.object), value);
    }
    return function;
}
