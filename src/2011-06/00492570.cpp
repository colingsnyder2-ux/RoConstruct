// from server: 72% by atomic.potato
struct CSelectionCaption
{
    int value;
    int method(int);
};

extern "C" int __cdecl G1_func_0080A62E();

struct G2_Arg
{
    int unused;
};

int G2_func_00427550(G2_Arg *, int);

int CSelectionCaption::method(int arg)
{
    int result = G1_func_0080A62E();
    if (result != -1)
        return result;

    G2_func_00427550((G2_Arg *)((char *)this + 0x190), arg);
    return 0;
}
