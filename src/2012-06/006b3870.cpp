// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Target { void run(int* out, int z); };
struct A { char p[0x1c]; };
struct B1 { int z; };
struct Dd : A, B1 {};
struct Client {
    char pad[0x2c];
    char* off;
    int* f(int* out, B1* inst, int z);
};
int* Client::f(int* out, B1* inst, int z)
{
    volatile int zero = 0;
    if (inst) {
        Dd& d = static_cast<Dd&>(*inst);
        Target* t = (Target*)(off + (int)&d);
        t->run(out, z);
        return out;
    }
    *out = 0;
    return out;
}