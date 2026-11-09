// from server: 100% by Intel
struct AdornRbxGfx {
    void func(int, int, int);
};

void AdornRbxGfx::func(int, int, int) {
    int value = 0;
    *(int*)((char*)this + 0x20) = value;
    *(int*)((char*)this + 0x24) = value;
}
