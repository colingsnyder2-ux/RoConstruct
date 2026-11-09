// from server: 27% by atomic.potato
struct S_func_00702810 { virtual ~S_func_00702810(); };
S_func_00702810::~S_func_00702810() {}

extern "C" void __cdecl func_00540ae0();
extern "C" void __cdecl func_007f385a();

struct S {
    char pad0[0x10];
    S_func_00702810* field10;
    void func();
};

void S::func()
{
    S_func_00702810* p = field10;
    if (p) {
        func_00540ae0();
        func_007f385a();
    }
    this->~S();
}
