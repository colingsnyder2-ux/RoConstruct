// from server: 42% by atomic.potato




extern "C" void __stdcall sub_4F0E10(int, short*);
extern "C" void __stdcall sub_4F90C0(short*);

struct Replicator {
    char pad0[4];
    int field4;
    void ChangePropertyItem(int, int);
};

void Replicator::ChangePropertyItem(int a, int b) {
    short local = 0;
    sub_4F0E10(a, &local);
    if (field4 != 0) {
        sub_4F90C0(&local);
    }
}
