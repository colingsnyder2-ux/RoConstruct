// roc 2012-06 00b20620  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20620
//
// 00b20620  b96453e500           mov ecx, 0xe55364
// 00b20625  e9c618a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20620 { void m(); };
extern T_func_00b20620 G1_func_00b20620;
void func_00b20620()
{
    G1_func_00b20620.m();
}
