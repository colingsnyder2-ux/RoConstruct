// from server: 100% by colin
struct LaserTool {
    int reserved0;
    int reserved1;
    int field8;
    int fieldC;
    void clearState();
};

void LaserTool::clearState() {
    field8 = 0;
    fieldC = 0;
}
