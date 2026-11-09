// from server: 100% by tester
struct Replicator {
    void f(int, int);
};

void Replicator::f(int a, int b) {
    void (__thiscall *fn)(Replicator*, int);
    fn = *(void (__thiscall **)(Replicator*, int))(*(int*)this + 0x10);
    fn(this, a);
}