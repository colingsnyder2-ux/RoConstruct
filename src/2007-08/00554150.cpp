// from server: 51% by colin
// roc 2007-08 00554150  unit: RBX::VTeam::?$FactoryProduct  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00554150
//
// 00554150  7f7a                 jg 0x5541cc
// 00554152  008948108950         add byte ptr [ecx + 0x50891048], cl
// 00554158  14eb                 adc al, 0xeb
// 0055415a  0233                 add dh, byte ptr [ebx]
// 0055415c  c0568b74             rcl byte ptr [esi - 0x75], 0x74
// 00554160  240c                 and al, 0xc
// 00554162  6a00                 push 0
// 00554164  c744240800000000     mov dword ptr [esp + 8], 0
// 0055416c  8906                 mov dword ptr [esi], eax
// 0055416e  e8efba0d00           call 0x62fc62
// 00554173  83c404               add esp, 4
// 00554176  8bc6                 mov eax, esi
// 00554178  5e                   pop esi
// 00554179  59                   pop ecx
// 0055417a  c3                   ret 

struct S_00554150
{
    void* field0;
    void* f();
};

extern "C" void* __cdecl G_func_0062fc62(void*);

void* S_00554150::f()
{
    void* p = 0;
    void* r = G_func_0062fc62(p);
    field0 = r;
    return this;
}
