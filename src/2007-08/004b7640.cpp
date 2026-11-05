// from server: 100% by colin
// roc 2007-08 004b7640  unit: Exposer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b7640
//
// 004b7640  a1cceb8b00           mov eax, dword ptr [0x8bebcc]
// 004b7645  c3                   ret 

struct Exposer {
    int f();
};

extern int G1_func_008bebcc;

int Exposer::f() {
    return G1_func_008bebcc;
}
