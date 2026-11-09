// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 007accd0  unit: RBX::RenderBase::MaterialBase::Level  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007accd0
//
// 007accd0  51                   push ecx
// 007accd1  687ce49000           push 0x90e47c
// 007accd6  8d442404             lea eax, [esp + 4]
// 007accda  50                   push eax
// 007accdb  c74424083c748200     mov dword ptr [esp + 8], 0x82743c
// 007acce3  e8a448efff           call 0x6a158c

struct S_func_007accd0
{
    void f();
};

void S_func_007accd0::f()
{
    throw "shouldn't be here";
}
