// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004dd610  unit: RBX::RenderBase::Mesh::Level  size: 385 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd610
//
// 004dd610  83ec10               sub esp, 0x10
// 004dd613  53                   push ebx
// 004dd614  8bd9                 mov ebx, ecx
// 004dd616  8b4318               mov eax, dword ptr [ebx + 0x18]
// 004dd619  8b4804               mov ecx, dword ptr [eax + 4]
// 004dd61c  80793500             cmp byte ptr [ecx + 0x35], 0
// 004dd620  55                   push ebp
// 004dd621  8bd0                 mov edx, eax
// 004dd623  56                   push esi
// 004dd624  8b742424             mov esi, dword ptr [esp + 0x24]
// 004dd628  b001                 mov al, 1
// 004dd62a  57                   push edi
// 004dd62b  89542410             mov dword ptr [esp + 0x10], edx
// 004dd62f  88442414             mov byte ptr [esp + 0x14], al
// 004dd633  0f8591000000         jne 0x4dd6ca
// 004dd639  8da42400000000       lea esp, [esp]
// 004dd640  d9410c               fld dword ptr [ecx + 0xc]
// 004dd643  894c2410             mov dword ptr [esp + 0x10], ecx
// 004dd647  d81e                 fcomp dword ptr [esi]
// 004dd649  dfe0                 fnstsw ax
// 004dd64b  f6c441               test ah, 0x41
// 004dd64e  744a                 je 0x4dd69a
// 004dd650  d9410c               fld dword ptr [ecx + 0xc]
// 004dd653  d81e                 fcomp dword ptr [esi]
// 004dd655  dfe0                 fnstsw ax
// 004dd657  f6c405               test ah, 5
// 004dd65a  7b44                 jnp 0x4dd6a0
// 004dd65c  d94110               fld dword ptr [ecx + 0x10]
// 004dd65f  d85e04               fcomp dword ptr [esi + 4]
// 004dd662  dfe0                 fnstsw ax
// 004dd664  f6c441               test ah, 0x41
// 004dd667  7431                 je 0x4dd69a
// 004dd669  d94110               fld dword ptr [ecx + 0x10]
// 004dd66c  d85e04               fcomp dword ptr [esi + 4]
// 004dd66f  dfe0                 fnstsw ax
// 004dd671  f6c405               test ah, 5
// 004dd674  7b2a                 jnp 0x4dd6a0
// 004dd676  d94114               fld dword ptr [ecx + 0x14]
// 004dd679  d85e08               fcomp dword ptr [esi + 8]
// 004dd67c  dfe0                 fnstsw ax
// 004dd67e  f6c441               test ah, 0x41
// 004dd681  7417                 je 0x4dd69a
// 004dd683  d94114               fld dword ptr [ecx + 0x14]
// 004dd686  d85e08               fcomp dword ptr [esi + 8]
// 004dd689  dfe0                 fnstsw ax
// 004dd68b  f6c405               test ah, 5
// 004dd68e  7b10                 jnp 0x4dd6a0
// 004dd690  8b460c               mov eax, dword ptr [esi + 0xc]
// 004dd693  8b5118               mov edx, dword ptr [ecx + 0x18]
// 004dd696  3bc2                 cmp eax, edx
// 004dd698  7304                 jae 0x4dd69e
// 004dd69a  b001                 mov al, 1
// 004dd69c  eb0f                 jmp 0x4dd6ad
// 004dd69e  7604                 jbe 0x4dd6a4
// 004dd6a0  32c0                 xor al, al
// 004dd6a2  eb09                 jmp 0x4dd6ad
// 004dd6a4  8b4610               mov eax, dword ptr [esi + 0x10]
// 004dd6a7  3b411c               cmp eax, dword ptr [ecx + 0x1c]
// 004dd6aa  0f9cc0               setl al
// 004dd6ad  88442414             mov byte ptr [esp + 0x14], al
// 004dd6b1  84c0                 test al, al
// 004dd6b3  7404                 je 0x4dd6b9
// 004dd6b5  8b09                 mov ecx, dword ptr [ecx]
// 004dd6b7  eb03                 jmp 0x4dd6bc
// 004dd6b9  8b4908               mov ecx, dword ptr [ecx + 8]
// 004dd6bc  80793500             cmp byte ptr [ecx + 0x35], 0
// 004dd6c0  0f847affffff         je 0x4dd640
// 004dd6c6  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dd6ca  8b3b                 mov edi, dword ptr [ebx]
// 004dd6cc  8bea                 mov ebp, edx
// 004dd6ce  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004dd6d2  897c2418             mov dword ptr [esp + 0x18], edi
// 004dd6d6  84c0                 test al, al
// 004dd6d8  745a                 je 0x4dd734
// 004dd6da  8b4b18               mov ecx, dword ptr [ebx + 0x18]
// 004dd6dd  8b29                 mov ebp, dword ptr [ecx]
// 004dd6df  85ff                 test edi, edi
// 004dd6e1  7404                 je 0x4dd6e7
// 004dd6e3  3bff                 cmp edi, edi
// 004dd6e5  740a                 je 0x4dd6f1
// 004dd6e7  ff1590288000         call dword ptr [0x802890]
// 004dd6ed  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dd6f1  3bd5                 cmp edx, ebp
// 004dd6f3  752e                 jne 0x4dd723
// 004dd6f5  56                   push esi
// 004dd6f6  52                   push edx
// 004dd6f7  6a01                 push 1
// 004dd6f9  8d542424             lea edx, [esp + 0x24]
// 004dd6fd  52                   push edx
// 004dd6fe  8bcb                 mov ecx, ebx
// 004dd700  e8cbf6ffff           call 0x4dcdd0
// 004dd705  5f                   pop edi
// 004dd706  8bc8                 mov ecx, eax
// 004dd708  8b11                 mov edx, dword ptr [ecx]
// 004dd70a  8b442420             mov eax, dword ptr [esp + 0x20]
// 004dd70e  8b4904               mov ecx, dword ptr [ecx + 4]
// 004dd711  5e                   pop esi
// 004dd712  5d                   pop ebp
// 004dd713  8910                 mov dword ptr [eax], edx
// 004dd715  894804               mov dword ptr [eax + 4], ecx
// 004dd718  c6400801             mov byte ptr [eax + 8], 1
// 004dd71c  5b                   pop ebx
// 004dd71d  83c410               add esp, 0x10
// 004dd720  c20800               ret 8
// 004dd723  8d4c2418             lea ecx, [esp + 0x18]
// 004dd727  e8f4271900           call 0x66ff20
// 004dd72c  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004dd730  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004dd734  56                   push esi
// 004dd735  8d550c               lea edx, [ebp + 0xc]
// 004dd738  52                   push edx
// 004dd739  8d4b08               lea ecx, [ebx + 8]
// 004dd73c  e8efecffff           call 0x4dc430
// 004dd741  84c0                 test al, al
// 004dd743  7435                 je 0x4dd77a
// 004dd745  8b442410             mov eax, dword ptr [esp + 0x10]
// 004dd749  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004dd74d  56                   push esi
// 004dd74e  50                   push eax
// 004dd74f  51                   push ecx
// 004dd750  8d542424             lea edx, [esp + 0x24]
// 004dd754  52                   push edx
// 004dd755  8bcb                 mov ecx, ebx
// 004dd757  e874f6ffff           call 0x4dcdd0
// 004dd75c  5f                   pop edi
// 004dd75d  8bc8                 mov ecx, eax
// 004dd75f  8b11                 mov edx, dword ptr [ecx]
// 004dd761  8b442420             mov eax, dword ptr [esp + 0x20]
// 004dd765  8b4904               mov ecx, dword ptr [ecx + 4]
// 004dd768  5e                   pop esi
// 004dd769  5d                   pop ebp
// 004dd76a  8910                 mov dword ptr [eax], edx
// 004dd76c  894804               mov dword ptr [eax + 4], ecx
// 004dd76f  c6400801             mov byte ptr [eax + 8], 1
// 004dd773  5b                   pop ebx
// 004dd774  83c410               add esp, 0x10
// 004dd777  c20800               ret 8
// 004dd77a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004dd77e  8938                 mov dword ptr [eax], edi
// 004dd780  5f                   pop edi
// 004dd781  5e                   pop esi
// 004dd782  896804               mov dword ptr [eax + 4], ebp
// 004dd785  5d                   pop ebp
// 004dd786  c6400800             mov byte ptr [eax + 8], 0
// 004dd78a  5b                   pop ebx
// 004dd78b  83c410               add esp, 0x10
// 004dd78e  c20800               ret 8

// from server: 78% by colin
// roc-cl: 50727
// roc-lang: cpp
#include <map>
#include <intrin.h>

struct Vector3 { float x, y, z; };

static inline int __fastcall compareVec(const Vector3& p, const Vector3& q)
{
    if (q.x < p.x) return -1;
    if (q.x > p.x) return 1;
    if (q.y < p.y) return -1;
    if (q.y > p.y) return 1;
    if (q.z < p.z) return -1;
    if (q.z > p.z) return 1;
    return 0;
}

struct Key {
    Vector3 pos;
    unsigned int index;
    int value;
};

struct KeyLess {
 bool operator()(const Key&a,const Key&b)const {
    int c=compareVec(b.pos,a.pos);
    bool less;
    if(c<0)less=true;
    else if(c>0)less=false;
    else if(a.index<b.index)less=true;
    else if(a.index>b.index)less=false;
    else less=a.value<b.value;
    return less;
 }
};

struct Level {
    int data[5];
};

typedef std::map<Key, Level, KeyLess> LevelMap;

std::pair<LevelMap::iterator, bool> insertLevel(LevelMap& m, const LevelMap::value_type& v)
{
    return m.insert(v);
}
