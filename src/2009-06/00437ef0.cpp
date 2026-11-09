// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0043d6c0  unit: G3D::VColor3::?$XItem  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043d6c0
//
// 0043d6c0  8b442408             mov eax, dword ptr [esp + 8]
// 0043d6c4  56                   push esi
// 0043d6c5  8bf1                 mov esi, ecx
// 0043d6c7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043d6cb  50                   push eax
// 0043d6cc  51                   push ecx
// 0043d6cd  8bce                 mov ecx, esi
// 0043d6cf  e84ce9ffff           call 0x43c020
// 0043d6d4  33c0                 xor eax, eax
// 0043d6d6  898638010000         mov dword ptr [esi + 0x138], eax
// 0043d6dc  898634010000         mov dword ptr [esi + 0x134], eax
// 0043d6e2  898630010000         mov dword ptr [esi + 0x130], eax
// 0043d6e8  c7067c498100         mov dword ptr [esi], 0x81497c
// 0043d6ee  c746201c498100       mov dword ptr [esi + 0x20], 0x81491c
// 0043d6f5  c7860c01000014498100 mov dword ptr [esi + 0x10c], 0x814914
// 0043d6ff  8bc6                 mov eax, esi
// 0043d701  5e                   pop esi
// 0043d702  c20800               ret 8

struct VColor3 {
    char pad[0x130];
    int field130;
    int field134;
    int field138;
    void baseInit(int a, int b);
    VColor3* init(int a, int b);
};

VColor3* VColor3::init(int a, int b) {
    baseInit(a, b);
    field138 = 0;
    field134 = 0;
    field130 = 0;
    *(int*)this = 0x81497c;
    *(int*)((char*)this + 0x20) = 0x81491c;
    *(int*)((char*)this + 0x10c) = 0x814914;
    return this;
}
