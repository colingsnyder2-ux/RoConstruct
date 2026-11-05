// from server: 100% by why2
struct RBX_Tool {
    char pad[0x120];
    int field_0x120;
    bool isReady();
};

bool RBX_Tool::isReady() {
    return field_0x120 >= 5;
}
