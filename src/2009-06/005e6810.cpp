// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056e2d0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056e2d0
//
// 0056e2d0  56                   push esi
// 0056e2d1  8d44240c             lea eax, [esp + 0xc]
// 0056e2d5  8bf1                 mov esi, ecx
// 0056e2d7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0056e2db  50                   push eax
// 0056e2dc  51                   push ecx
// 0056e2dd  e8be020500           call 0x5be5a0
// 0056e2e2  83c408               add esp, 8
// 0056e2e5  84c0                 test al, al
// 0056e2e7  741a                 je 0x56e303
// 0056e2e9  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056e2ec  8b11                 mov edx, dword ptr [ecx]
// 0056e2ee  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056e2f1  8d44240c             lea eax, [esp + 0xc]
// 0056e2f5  50                   push eax
// 0056e2f6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0056e2fa  50                   push eax
// 0056e2fb  ffd2                 call edx
// 0056e2fd  b001                 mov al, 1
// 0056e2ff  5e                   pop esi
// 0056e300  c20800               ret 8
// 0056e303  32c0                 xor al, al
// 0056e305  5e                   pop esi
// 0056e306  c20800               ret 8

extern "C" bool __cdecl convertValue(int value, int* result);

struct Receiver;

struct ReceiverTable {
    void* reserved[3];
    void (__thiscall* set)(Receiver*, void*, int*);
};

struct Receiver {
    ReceiverTable* table;
};

struct S {
    unsigned char reserved[24];
    Receiver* receiver;

    bool f(void* object, int value);
};

bool S::f(void* object, int value)
{
    if (convertValue(value, &value)) {
        receiver->table->set(receiver, object, &value);
        return true;
    }
    return false;
}
