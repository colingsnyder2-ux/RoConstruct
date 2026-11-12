// from server: 66% by EspClaude
// from server: 56% by colin
// roc 2007-08 00489800  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489800
//
// 00489800  56                   push esi
// 00489801  8bf1                 mov esi, ecx
// 00489803  c70630af7900         mov dword ptr [esi], 0x79af30
// 00489809  8b4608               mov eax, dword ptr [esi + 8]
// 0048980c  85c0                 test eax, eax
// 0048980e  7409                 je 0x489819
// 00489810  50                   push eax
// 00489811  e84c641a00           call 0x62fc62
// 00489816  83c404               add esp, 4
// 00489819  c7460800000000       mov dword ptr [esi + 8], 0
// 00489820  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00489827  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0048982e  5e                   pop esi
// 0048982f  c3                   ret 
// 00489830  56                   push esi
// 00489831  8bf1                 mov esi, ecx
// 00489833  c70640af7900         mov dword ptr [esi], 0x79af40
// 00489839  8b4608               mov eax, dword ptr [esi + 8]
// 0048983c  85c0                 test eax, eax
// 0048983e  7409                 je 0x489849
// 00489840  50                   push eax
// 00489841  e81c641a00           call 0x62fc62
// 00489846  83c404               add esp, 4
// 00489849  c7460800000000       mov dword ptr [esi + 8], 0
// 00489850  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00489857  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0048985e  5e                   pop esi
// 0048985f  c3                   ret 


#include <vector>

namespace RBX { namespace Network {
struct VPlayerFactoryProduct {
    virtual void create();
    ~VPlayerFactoryProduct();
    std::vector<int> items;
};

VPlayerFactoryProduct::~VPlayerFactoryProduct()
{
}
} }
