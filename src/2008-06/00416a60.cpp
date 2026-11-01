// from server: 100% by king_originala
struct Interface
{
    virtual void __stdcall slot0() = 0;
    virtual void __stdcall slot1() = 0;
    virtual void __stdcall slot2() = 0;
    virtual void __stdcall slot3() = 0;
    virtual void __stdcall slot4() = 0;
    virtual void __stdcall slot5() = 0;
    virtual void __stdcall slot6() = 0;
    virtual void __stdcall slot7() = 0;
    virtual void __stdcall slot8() = 0;
    virtual void __stdcall slot9() = 0;
    virtual void __stdcall slot10() = 0;
    virtual int __stdcall forward(int, int, int, int, int, int, int) = 0;
};

struct State
{
    unsigned char reserved[12];
    Interface* object;
    unsigned char reserved2[4];
    int ready;

    int initialize(int);
};

extern State state;

int __stdcall dispatch(int a1, int a2, int a3, int a4,
                       int a5, int a6, int a7, int a8, int a9)
{
    int result = 0;
    if (!state.object || !state.ready)
        result = state.initialize(a4);

    if (state.object)
        result = state.object->forward(a1, a2, a5, a6, a7, a8, a9);

    return result;
}
