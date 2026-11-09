// from server: 37% by atomic.potato
struct NewNullTool {
    char pad0[0x18];
    int field18;
    void* construct();
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl func_7879b0(void*, int);

void* NewNullTool::construct() {
    void* p = operator_new(0x48);
    if (p) {
        func_7879b0(p, this->field18);
    }
    return p;
}
