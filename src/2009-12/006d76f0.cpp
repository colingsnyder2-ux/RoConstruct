// from server: 100% by atomic.potato
struct LaserTool {
    char pad[8];
    int field_8;
    int field_c;
    void clear();
};

void LaserTool::clear() {
    field_8 = 0;
    field_c = 0;
}
