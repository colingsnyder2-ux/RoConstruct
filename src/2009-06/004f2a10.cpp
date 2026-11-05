// from server: 100% by why2
struct Replicator {
    void f(int, int);
};

void Replicator::f(int a, int b) {
    void (__thiscall *fn)(Replicator*, int);
    fn = *(void (__thiscall **)(Replicator*, int))(*(int*)this + 0x50);
    fn(this, a);
}
