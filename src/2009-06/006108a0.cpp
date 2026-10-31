// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005832c0  unit: RBX::CameraZoomExtentsCommand  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005832c0
//
// 005832c0  51                   push ecx
// 005832c1  8b4108               mov eax, dword ptr [ecx + 8]
// 005832c4  85c0                 test eax, eax
// 005832c6  7412                 je 0x5832da
// 005832c8  8b4904               mov ecx, dword ptr [ecx + 4]
// 005832cb  8d1424               lea edx, [esp]
// 005832ce  890c24               mov dword ptr [esp], ecx
// 005832d1  52                   push edx
// 005832d2  8d4804               lea ecx, [eax + 4]
// 005832d5  e8062ae8ff           call 0x405ce0
// 005832da  59                   pop ecx
// 005832db  c3                   ret 

struct Receiver {
    void invoke(void* const* value);
};

struct Target {
    unsigned long padding;
    Receiver receiver;
};

struct S {
    unsigned long padding;
    void* value;
    Target* target;
    void f();
};

void S::f()
{
    if (target) {
        void* copy = value;
        target->receiver.invoke(&copy);
    }
}
