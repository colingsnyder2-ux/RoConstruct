// from server: 100% by colin
extern "C" int __cdecl func_5bf350(int, int, int);
extern "C" int __cdecl func_5bf240(int, int, int);
extern "C" int __cdecl func_56c740(int, int, int);
extern int G_func_8abe7c;

int func_00535700(int a)
{
    int v1 = func_5bf350(a, 2, 0);
    int v2 = func_5bf240(a, 1, G_func_8abe7c);
    func_56c740(v2, v1, a);
    return 0;
}
