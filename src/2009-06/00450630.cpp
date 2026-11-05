// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 00450630  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00450630
//
// 00450630  56                   push esi
// 00450631  57                   push edi
// 00450632  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00450636  8bf1                 mov esi, ecx
// 00450638  85ff                 test edi, edi
// 0045063a  742f                 je 0x45066b
// 0045063c  8d442410             lea eax, [esp + 0x10]
// 00450640  50                   push eax
// 00450641  8d8e80000000         lea ecx, [esi + 0x80]
// 00450647  e82437feff           call 0x433d70
// 0045064c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00450650  8b7f04               mov edi, dword ptr [edi + 4]
// 00450653  8d542410             lea edx, [esp + 0x10]
// 00450657  894c2410             mov dword ptr [esp + 0x10], ecx
// 0045065b  52                   push edx
// 0045065c  8d4e54               lea ecx, [esi + 0x54]
// 0045065f  e86c8e2400           call 0x6994d0
// 00450664  8938                 mov dword ptr [eax], edi
// 00450666  5f                   pop edi
// 00450667  5e                   pop esi
// 00450668  c20800               ret 8
// 0045066b  e8f0d21700           call 0x5cd960
// 00450670  8d4c2410             lea ecx, [esp + 0x10]
// 00450674  8bf8                 mov edi, eax
// 00450676  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045067a  51                   push ecx
// 0045067b  8d4e54               lea ecx, [esi + 0x54]
// 0045067e  89442414             mov dword ptr [esp + 0x14], eax
// 00450682  e8498e2400           call 0x6994d0
// 00450687  8938                 mov dword ptr [eax], edi
// 00450689  5f                   pop edi
// 0045068a  5e                   pop esi
// 0045068b  c20800               ret 8

// from server: 100% by king_originala
// roc 2008-06 00451a60  unit: VCRobloxDoc::?$VerbBinder  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00451a60
//
// 00451a60  56                   push esi
// 00451a61  57                   push edi
// 00451a62  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00451a66  8bf1                 mov esi, ecx
// 00451a68  85ff                 test edi, edi
// 00451a6a  742c                 je 0x451a98
// 00451a6c  8d442410             lea eax, [esp + 0x10]
// 00451a70  50                   push eax
// 00451a71  8d4e78               lea ecx, [esi + 0x78]
// 00451a74  e827f9fcff           call 0x4213a0
// 00451a79  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00451a7d  8b7f04               mov edi, dword ptr [edi + 4]
// 00451a80  8d542410             lea edx, [esp + 0x10]
// 00451a84  894c2410             mov dword ptr [esp + 0x10], ecx
// 00451a88  52                   push edx
// 00451a89  8d4e54               lea ecx, [esi + 0x54]
// 00451a8c  e80f2a1100           call 0x5644a0
// 00451a91  8938                 mov dword ptr [eax], edi
// 00451a93  5f                   pop edi
// 00451a94  5e                   pop esi
// 00451a95  c20800               ret 8
// 00451a98  e8d3271000           call 0x554270
// 00451a9d  8d4c2410             lea ecx, [esp + 0x10]
// 00451aa1  8bf8                 mov edi, eax
// 00451aa3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00451aa7  51                   push ecx
// 00451aa8  8d4e54               lea ecx, [esi + 0x54]
// 00451aab  89442414             mov dword ptr [esp + 0x14], eax
// 00451aaf  e8ec291100           call 0x5644a0
// 00451ab4  8938                 mov dword ptr [eax], edi
// 00451ab6  5f                   pop edi
// 00451ab7  5e                   pop esi
// 00451ab8  c20800               ret 8

struct Node {
    void* unused;
    void* value;
};

struct Map {
    char data[44];
    void** lookup(void* const* key);
};

struct Listener {
    void update(void** node);
};

void* __cdecl getLocalScope();

struct S_func_00451a60 {
    char pad[84];
    Map map;
    Listener listener;
    void f(void* key, void* node);
};

void S_func_00451a60::f(void* key, void* node)
{
    Node* original = static_cast<Node*>(node);
    if (original) {
        listener.update(&node);
        void* value = original->value;
        node = key;
        *map.lookup(&node) = value;
    } else {
        void* value = getLocalScope();
        node = key;
        *map.lookup(&node) = value;
    }
}
