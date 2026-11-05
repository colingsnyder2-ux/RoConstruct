// from server: 100% by why2
struct RBX_Workspace {
    char pad[0x110];
    int field_110;
    char pad2[0x4];
    int field_118;
    int get();
};

int RBX_Workspace::get() {
    int v = field_110;
    if (v == 0)
        v = field_118;
    return v;
}
