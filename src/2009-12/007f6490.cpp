// from server: 82% by atomic.potato
extern "C" int __stdcall G1_func_0098de80(int);
extern "C" int __stdcall G1_func_0098de84(int, int);

int func_007f6490(int a, int b)
{
    return G1_func_0098de84(a, G1_func_0098de80(b)) != 0;
}
