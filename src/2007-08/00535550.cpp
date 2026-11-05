// from server: 100% by colin
extern int GLOBAL_0089F7D8;

extern int __cdecl func_005BF350(int, int, int);
extern int __cdecl func_005BF240(int, int, int);
extern int __cdecl func_0056C740(int, int, int);

int __cdecl func_00535550(int a)
{
    int v1 = func_005BF350(a, 2, 0);
    int v2 = func_005BF240(a, 1, GLOBAL_0089F7D8);
    func_0056C740(v2, v1, a);
    return 0;
}
