// from server: 100% by colin
struct Interface;

typedef int (__stdcall *Method)(
    Interface *, int, int, int, int, int, int, int);

struct Interface {
    Method *vtable;
};

struct State {
    unsigned char reserved[12];
    Interface *object;
    int reserved16;
    int ready;

    int initialize(int);
};

extern State state;

int __stdcall dispatch(
    int a1, int a2, int a3, int a4, int a5,
    int a6, int a7, int a8, int a9)
{
    int result = 0;
    if (!state.object || !state.ready)
        result = state.initialize(a4);

    if (state.object)
        result = state.object->vtable[11](
            state.object, a1, a2, a5, a6, a7, a8, a9);

    return result;
}
