// from server: 72% by atomic.potato
extern "C" void* G0_func_004fca00(int, const char*);
extern "C" void G0_func_004f5230(void*);
extern "C" void G1_func_007e1de0();

void func_006a48a0()
{
    void* p = G0_func_004fca00(4, "User-generated crash");
    G0_func_004f5230(p);
    G1_func_007e1de0();
}
