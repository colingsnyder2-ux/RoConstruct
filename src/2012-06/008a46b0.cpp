// from server: 27% by atomic.potato
struct S
{
    int f();
    int pad[3];
};

extern "C" int G1_func_00495f40(int *);
extern "C" int __cdecl G1_func_00983b6a(int);
extern "C" int __stdcall G1_import_00b229ec(int, int);

S *G1_global_00dae1bc;

int S::f()
{
    int value = G1_func_00495f40((int *)((char *)this->pad[2] + 0xac4));
    if (!value)
        return 0;
    value = G1_func_00983b6a(value);
    return G1_import_00b229ec((int)G1_global_00dae1bc, value);
}
