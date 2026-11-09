// from server: 31% by Intel
typedef int DWORD;

extern "C" void __stdcall func_0445790(DWORD arg);

struct D {
    char padding1[260];
    unsigned char flag;
    int f();
};

int D::f() {
    DWORD val = 0;
    if (this->flag == 0) {
        val = 1;
    }
    func_0445790(val);
    return 0;
}
