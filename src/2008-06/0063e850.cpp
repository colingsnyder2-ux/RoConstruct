// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
extern char table1[];
extern char table2[];

struct S_func_006159f0 {
    int f(int a1);
};

struct S {
    S* f(int a1, bool a2, int a3);
};

S* S::f(int a1, bool a2, int a3)
{
    ((S_func_006159f0*)this)->f(a1);
    *(char**)((char*)this + 0) = table1;
    *(char**)((char*)this + 4) = table2;
    *(volatile int*)((char*)this + 28) = 0;
    *(volatile int*)((char*)this + 32) = 0;
    *(volatile int*)((char*)this + 44) = 0;
    *(bool*)((char*)this + 36) = a2;
    *(int*)((char*)this + 40) = a3;
    return this;
}
