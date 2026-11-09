// from server: 100% by king_originala
typedef void (__thiscall *Callback)(void*, int);

struct Iterator {
    int unused;
    int* current;
};

struct Operation {
    Callback callback;
    int adjustment;
    char* object;
    int unused;
};

Operation __cdecl apply(Iterator first, Iterator last, Operation operation)
{
    register int* current = first.current;
    register int* end = last.current;

    if (current != end) {
        do {
            operation.callback(operation.object + operation.adjustment, *current);
            ++current;
        } while (current != end);
    }

    return operation;
}
