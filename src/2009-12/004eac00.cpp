// from server: 33% by atomic.potato
struct S {
    char pad[0x1d0];
    unsigned int field_1d0;
    unsigned int get(unsigned int arg);
};

unsigned int S::get(unsigned int arg) {
    unsigned int local = field_1d0;
    unsigned int *p;
    if (arg < local) {
        p = &arg;
    } else {
        p = &local;
    }
    return *p;
}
