// roc 2012-06 008457b0  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 5 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008457b0
//
// 008457b0  c6410401             mov byte ptr [ecx + 4], 1
// 008457b4  c3                   ret 
// auto-matched from its assembly shape

struct S_func_008457b0 {
    char pad0[4];
    char m_x;
    void f();
};
void S_func_008457b0::f()
{
    m_x = (char)1;
}
