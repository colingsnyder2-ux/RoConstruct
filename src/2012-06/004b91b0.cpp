// from server: 100% by Intel
struct S_func_004b91b0 {
    int f(int a1, int a2);
};

int S_func_004b91b0::f(int a1, int a2)
{
    if (a2 == 0)
        return (int)0x80004003;
    *(int*)a2 = a1;
    int* p = (int*)a1;
    int* vt = (int*)*p;
    typedef int (__stdcall *Fn)(int);
    Fn fn = (Fn)vt[1];
    fn(a1);
    return 0;
}
