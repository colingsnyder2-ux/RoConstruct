// from server: 100% by tester
struct KeyButton {
    char pad[0x148];
    int field_148;
    void sub_64EFD0(int* arg);
};

void KeyButton::sub_64EFD0(int* arg) {
    int* p = *(int**)((char*)arg + 4);
    int v = field_148;
    void (__thiscall *fn)(int*, int, int) = *(void (__thiscall **)(int*, int, int))(*(int*)p + 0x18);
    fn(p, v, 0);
}
