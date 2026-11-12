// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 43% by colin
// roc 2007-08 0055fbd0  unit: RBX::VModelInstance::?$FilteredSelection  size: 111 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fbd0
//
// 0055fbd0  6aff                 push -1
// 0055fbd2  685b3d7500           push 0x753d5b
// 0055fbd7  64a100000000         mov eax, dword ptr fs:[0]
// 0055fbdd  50                   push eax
// 0055fbde  64892500000000       mov dword ptr fs:[0], esp
// 0055fbe5  51                   push ecx
// 0055fbe6  56                   push esi
// 0055fbe7  8bf1                 mov esi, ecx
// 0055fbe9  57                   push edi
// 0055fbea  89742408             mov dword ptr [esp + 8], esi
// 0055fbee  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0055fbf1  85ff                 test edi, edi
// 0055fbf3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0055fbfb  7411                 je 0x55fc0e
// 0055fbfd  8d4f08               lea ecx, [edi + 8]
// 0055fc00  e8fbfbeaff           call 0x40f800
// 0055fc05  57                   push edi
// 0055fc06  e857000d00           call 0x62fc62
// 0055fc0b  83c404               add esp, 4
// 0055fc0e  8b7608               mov esi, dword ptr [esi + 8]
// 0055fc11  85f6                 test esi, esi
// 0055fc13  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0055fc1b  7411                 je 0x55fc2e
// 0055fc1d  8d4e08               lea ecx, [esi + 8]
// 0055fc20  e8dbfbeaff           call 0x40f800
// 0055fc25  56                   push esi
// 0055fc26  e837000d00           call 0x62fc62
// 0055fc2b  83c404               add esp, 4
// 0055fc2e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055fc32  5f                   pop edi
// 0055fc33  5e                   pop esi
// 0055fc34  64890d00000000       mov dword ptr fs:[0], ecx
// 0055fc3b  83c410               add esp, 0x10
// 0055fc3e  c3                   ret 

struct Inner {
    ~Inner();
};

struct Elem {
    int pad[2];
    Inner inner;   // destroyed at +8 (lea ecx,[edi+8])
};

template<class T>
struct Holder {
    T* p;
    ~Holder() { delete p; }
};

struct FilteredSelection {
    int pad[2];
    Holder<Elem> a;   // +8
    Holder<Elem> b;   // +0xc
    ~FilteredSelection();
};

FilteredSelection::~FilteredSelection()
{
}
