// from server: 28% by atomic.potato
struct Slot {
    char pad[0xc];
    void f(int);
};

void __stdcall helper(int, Slot*);

void Slot::f(int a) {
    helper(a, this + 1);
}
