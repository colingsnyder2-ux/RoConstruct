// from server: 100% by why2
struct RBX_ContactConnector {
    char pad[0x14];
    int field14;
    int field18;
    int get(int which);
};

int RBX_ContactConnector::get(int which) {
    if (which == 0)
        return field14;
    return field18;
}
