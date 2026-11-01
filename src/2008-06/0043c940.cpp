// from server: 100% by king_originala
struct Operation {
    void (__thiscall *apply)(void *, void *, int *);
    char *object;
    int displacement;
    void *(__thiscall *get)(void *);
    int unused;
    int value;
};

Operation __cdecl f(int, char *first, int, char *last, Operation operation)
{
    while (first != last) {
        void *value = operation.get(first);
        operation.apply(operation.displacement + operation.object,
                        value, &operation.value);
        first += 8;
    }
    return operation;
}
