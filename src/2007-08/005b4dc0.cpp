// from server: 100% by colin
struct Geometry {
    char pad[8];
    int field8;
    char pad2[4];
    int field10;
    void method();
};

void __stdcall helper(int);

void Geometry::method() {
    int v = field10;
    if (v == 0)
        v = field8;
    helper(v);
}
