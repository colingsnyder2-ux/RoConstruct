// from server: 100% by EspClaude
// roc 2009-06 0046e090  unit: VCWorkspace::?$CComObject  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046e090
//
// 0046e090  83ec10               sub esp, 0x10
// 0046e093  e876ac2a00           call 0x718d0e
// 0046e098  50                   push eax
// 0046e099  8d4c2404             lea ecx, [esp + 4]
// 0046e09d  e866ac2a00           call 0x718d08
// 0046e0a2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046e0a6  e845ffffff           call 0x46dff0
// 0046e0ab  8b442404             mov eax, dword ptr [esp + 4]
// 0046e0af  85c0                 test eax, eax
// 0046e0b1  7406                 je 0x46e0b9
// 0046e0b3  8b0c24               mov ecx, dword ptr [esp]
// 0046e0b6  894804               mov dword ptr [eax + 4], ecx
// 0046e0b9  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0046e0be  740c                 je 0x46e0cc
// 0046e0c0  8b542408             mov edx, dword ptr [esp + 8]
// 0046e0c4  52                   push edx
// 0046e0c5  6a00                 push 0
// 0046e0c7  e830ac2a00           call 0x718cfc
// 0046e0cc  33c0                 xor eax, eax
// 0046e0ce  83c410               add esp, 0x10
// 0046e0d1  c20400               ret 4
// copied from an identical function in another client (function ?function@ns_ROCX000035@@YGHPAUObject@1@@Z)

namespace ns_ROCX000035 {
struct StateSlot
{
    unsigned long reserved;
    void* value;
};

struct StateGuard
{
    void* previous;
    StateSlot* slot;
    void* context;
    int active;

    void initialize(void*);
};

struct Object
{
    void update();
};

extern "C" void* __stdcall getState();
extern "C" void __stdcall releaseState(int, void*);

int __stdcall function(Object* object)
{
    StateGuard guard;
    guard.initialize(getState());
    object->update();

    if (guard.slot)
        guard.slot->value = guard.previous;

    if (guard.active)
        releaseState(0, guard.context);

    return 0;
}
}
