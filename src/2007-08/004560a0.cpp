// from server: 100% by Yeetserama
// hypothesis: 004560a0 follows two pointers from a call result and returns a
// byte. The target's eax chaining matches /O1 codegen for this unit.
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
struct C_func_004560a0 {
    char pad0[0xe0];
    char value;
};

struct B_func_004560a0 {
    char pad0[0x20];
    C_func_004560a0* c;
};

struct A_func_004560a0 {
    char pad0[4];
    B_func_004560a0* b;
};

extern "C" A_func_004560a0* __cdecl sub_0062ff02();

char __cdecl f()
{
    A_func_004560a0* a = sub_0062ff02();
    B_func_004560a0* b = a->b;
    C_func_004560a0* c = b->c;
    return c->value;
}
