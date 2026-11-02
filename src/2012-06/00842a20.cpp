// from server: 4% by tajop
struct Slot {
    char pad[0xc];
    void sub_842960(int);
};

void Slot::sub_842960(int) {}

void f(Slot* self, int a) {
    self->sub_842960(a);
}
