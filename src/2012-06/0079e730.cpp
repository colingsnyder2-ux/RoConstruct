// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Target { void run(int* out, int z); };
struct V { int v; };
struct A { char p[0x11c]; };
struct Vd : A, virtual V { };
struct Client {
    char pad[0x2c];
    Target Vd::* pm;
    int* f(int* out, Vd* inst, int z);
};
int* Client::f(int* out, Vd* inst, int z)
{
    volatile int zero = 0;
    if (inst) {
        (inst->*pm).run(out, z);
        return out;
    }
    *out = 0;
    return out;
}
