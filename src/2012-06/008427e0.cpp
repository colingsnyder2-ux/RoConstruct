// from server: 55% by Intel
struct Slot {
    char pad[0xc];
    void method(int);
};

void Slot::method(int a) {
    __try {
        ((void (__thiscall*)(void*, int))0x8422a0)((char*)this + 0xc, a);
    }
    __except(1) {
    }
}
