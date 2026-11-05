// from server: 100% by tester
struct RBX_Tool {
    char pad[0x1ec];
    int field_0x120;
    bool isReady();
};

bool RBX_Tool::isReady() {
    return field_0x120 >= 5;
}
