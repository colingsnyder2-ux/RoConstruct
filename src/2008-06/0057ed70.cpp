// from server: 100% by king_originala
struct Iterator
{
    void* owner;
    void** position;
};

struct Function
{
    void (__cdecl *callback)(void*, void*);
    void* context;
    Function();
};

Function __cdecl apply(Iterator first, Iterator last, Function function)
{
    void** position = first.position;
    void** end = last.position;

    for (; position != end; ++position)
        function.callback(function.context, *position);

    return function;
}
