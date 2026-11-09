// from server: 100% by Intel
struct RBX_BlockBlockContact {
    int f();
};

int RBX_BlockBlockContact::f() {
    if (*(int*)((char*)this + 0x2c) == 0) {
        return 0;
    }
    return *(int*)(*(int*)((char*)this + 0x2c) + 0x20);
}
