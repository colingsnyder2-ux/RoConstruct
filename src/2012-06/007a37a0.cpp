// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 007f2530  unit: RBX::VGuiObject::?$EventDesc  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007f2530
//
// 007f2530  8b442404             mov eax, dword ptr [esp + 4]
// 007f2534  85c0                 test eax, eax
// 007f2536  7410                 je 0x7f2548
// 007f2538  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 007f253b  83c0e4               add eax, -0x1c
// 007f253e  03c8                 add ecx, eax
// 007f2540  e8cb27f4ff           call 0x734d10
// 007f2545  c20400               ret 4
// 007f2548  8b492c               mov ecx, dword ptr [ecx + 0x2c]
// 007f254b  33c0                 xor eax, eax
// 007f254d  03c8                 add ecx, eax
// 007f254f  e8bc27f4ff           call 0x734d10
// 007f2554  c20400               ret 4

struct InstanceBase {
    char pad[0x1c];
};

struct DescBase {
    int field_0;
};

struct Signal {
    int f();
};

struct EventClass : InstanceBase, DescBase {
};

struct EventDesc {
    char pad[0x2c];
    Signal EventClass::* sig;
    int invoke(DescBase* source);
};

int EventDesc::invoke(DescBase* source)
{
    return (static_cast<EventClass*>(source)->*sig).f();
}
