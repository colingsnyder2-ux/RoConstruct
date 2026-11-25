// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 0074dc60  unit: RBX::Network::VPlayer::?$BoundYieldFuncDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0074dc60
//
// 0074dc60  56                   push esi
// 0074dc61  8bf1                 mov esi, ecx
// 0074dc63  8b4638               mov eax, dword ptr [esi + 0x38]
// 0074dc66  50                   push eax
// 0074dc67  e8a8442300           call 0x982114
// 0074dc6c  83c404               add esp, 4
// 0074dc6f  8bce                 mov ecx, esi
// 0074dc71  e87a42e4ff           call 0x591ef0
// 0074dc76  f644240801           test byte ptr [esp + 8], 1
// 0074dc7b  7409                 je 0x74dc86
// 0074dc7d  56                   push esi
// 0074dc7e  e891442300           call 0x982114
// 0074dc83  83c404               add esp, 4
// 0074dc86  8bc6                 mov eax, esi
// 0074dc88  5e                   pop esi
// 0074dc89  c20400               ret 4

extern "C" void __cdecl sub_982114(void*);
extern "C" void __fastcall sub_591EF0(void*);

struct VPlayerBoundYieldFuncDesc {
    char pad[0x2c];
    void* field_38;
    void* destroy(unsigned int flags);
};

void* VPlayerBoundYieldFuncDesc::destroy(unsigned int flags)
{
    sub_982114(field_38);
    sub_591EF0(this);
    if (flags & 1) {
        sub_982114(this);
    }
    return this;
}
