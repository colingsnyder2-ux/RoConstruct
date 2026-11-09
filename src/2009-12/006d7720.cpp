// from server: 100% by atomic.potato
struct LaserTool {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    void get(int*, int*, int*, int*);
};

void LaserTool::get(int* a, int* b, int* c, int* d) {
    *a = field_0;
    *b = field_4;
    *c = field_8;
    *d = field_c;
}
