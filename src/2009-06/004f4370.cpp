// from server: 100% by why2
// roc 2009-06 004f4370  unit: Exposer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f4370

struct Exposer {
    void f();
};

extern char g_8c7f60;

void Exposer::f() {
    void (__thiscall *fn)(Exposer *, char *);
    fn = *(void (__thiscall **)(Exposer *, char *))(*(char **)this + 0x4c);
    fn(this, &g_8c7f60);
}
