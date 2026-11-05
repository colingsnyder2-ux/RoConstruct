// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g0,g8,g20,g2c,g30;
extern "C" void cleanup(void*);
struct X {
    void* f0; int pad4; void* f8; char padc[0x14]; void* f20; char pad24[8]; void* f2c; void* f30;
    void base();
    X* init(int flags);
};
X* X::init(int flags) {
    f0=&g0; f8=&g8; f20=&g20; f2c=&g2c; f30=&g30;
    base();
    if (flags & 1) cleanup(this);
    return this;
}
