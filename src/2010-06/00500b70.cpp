// from server: 100% by tester
struct Exposer {
    void f();
};

extern char g_8c7f60;

void Exposer::f() {
    void (__thiscall *fn)(Exposer *, char *);
    fn = *(void (__thiscall **)(Exposer *, char *))(*(char **)this + 0x4c);
    fn(this, &g_8c7f60);
}
