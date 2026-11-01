// from server: 100% by king_originala
typedef int (__stdcall *Method)(void *, int, int, int, int, int, int, int);

struct Interface {
    Method *table;
};

struct State {
    char padding[12];
    Interface *object;
    int reserved;
    int ready;
    int initialize(int);
};

extern State state;

int __stdcall func(int a1, int a2, int a3, int a4, int a5,
                   int a6, int a7, int a8, int a9)
{
    int result = 0;
    if (!state.object || !state.ready)
        result = state.initialize(a4);
    if (state.object)
        result = state.object->table[11](state.object, a1, a2,
                                         a5, a6, a7, a8, a9);
    return result;
}
