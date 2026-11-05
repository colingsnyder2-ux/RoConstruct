// from server: 91% by atomic.potato
struct LaserTool {
    struct VTable {
        void (__thiscall *func_4c)(LaserTool *);
    };

    VTable *vtable;
    char pad[0x90];
    double field_98;

    double f();
};

double LaserTool::f() {
    vtable->func_4c(this);
    return field_98;
}
