// from server: 57% by colin
// roc 2007-08 004370e0  unit: RBX::VStandardOut::?$Listener  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004370e0
//
// 004370e0  e839991f00           call 0x630a1e
// 004370e5  83c41c               add esp, 0x1c
// 004370e8  c3                   ret 

struct RBX_VStandardOut_Listener {
    void f();
};

extern "C" void __cdecl function_0x630a1e();

void RBX_VStandardOut_Listener::f()
{
    function_0x630a1e();
}
