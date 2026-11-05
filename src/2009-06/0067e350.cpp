// from server: 100% by why2
struct Mechanism {
    char pad[0x18];
    int field_18;
};

bool isPositive(Mechanism* m, int arg) {
    return m->field_18 > 0;
}
