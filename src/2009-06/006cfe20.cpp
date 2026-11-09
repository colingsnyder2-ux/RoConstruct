// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2009-06 006cfe20  unit: RBX::HUMAN::Climbing  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cfe20
//
// 006cfe20  6aff                 push -1
// 006cfe22  6820118700           push 0x871120
// 006cfe27  64a100000000         mov eax, dword ptr fs:[0]
// 006cfe2d  50                   push eax
// 006cfe2e  64892500000000       mov dword ptr fs:[0], esp
// 006cfe35  83ec3c               sub esp, 0x3c
// 006cfe38  56                   push esi
// 006cfe39  8bf1                 mov esi, ecx
// 006cfe3b  8b4608               mov eax, dword ptr [esi + 8]
// 006cfe3e  8b8024020000         mov eax, dword ptr [eax + 0x224]
// 006cfe44  57                   push edi
// 006cfe45  89442408             mov dword ptr [esp + 8], eax
// 006cfe49  85c0                 test eax, eax
// 006cfe4b  0f842a010000         je 0x6cff7b
// 006cfe51  53                   push ebx
// 006cfe52  55                   push ebp
// 006cfe53  8d4c2414             lea ecx, [esp + 0x14]
// 006cfe57  e8b4a7f8ff           call 0x65a610
// 006cfe5c  8d4c2414             lea ecx, [esp + 0x14]
// 006cfe60  51                   push ecx
// 006cfe61  8b4e08               mov ecx, dword ptr [esi + 8]
// 006cfe64  c744245800000000     mov dword ptr [esp + 0x58], 0
// 006cfe6c  e89f89f9ff           call 0x668810
// 006cfe71  8b442424             mov eax, dword ptr [esp + 0x24]
// 006cfe75  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006cfe79  8bd8                 mov ebx, eax
// 006cfe7b  3bc8                 cmp ecx, eax
// 006cfe7d  760e                 jbe 0x6cfe8d
// 006cfe7f  ff15ace98900         call dword ptr [0x89e9ac]
// 006cfe85  8b442424             mov eax, dword ptr [esp + 0x24]
// 006cfe89  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006cfe8d  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006cfe91  8be9                 mov ebp, ecx
// 006cfe93  3bc8                 cmp ecx, eax
// 006cfe95  7606                 jbe 0x6cfe9d
// 006cfe97  ff15ace98900         call dword ptr [0x89e9ac]
// 006cfe9d  8b542414             mov edx, dword ptr [esp + 0x14]
// 006cfea1  53                   push ebx
// 006cfea2  57                   push edi
// 006cfea3  55                   push ebp
// 006cfea4  52                   push edx
// 006cfea5  8d4c243c             lea ecx, [esp + 0x3c]
// 006cfea9  e8a2feffff           call 0x6cfd50
// 006cfeae  8b4e08               mov ecx, dword ptr [esi + 8]
// 006cfeb1  c644245401           mov byte ptr [esp + 0x54], 1
// 006cfeb6  e8356af9ff           call 0x6668f0
// 006cfebb  33ff                 xor edi, edi
// 006cfebd  5d                   pop ebp
// 006cfebe  5b                   pop ebx
// 006cfebf  3bc7                 cmp eax, edi
// 006cfec1  744f                 je 0x6cff12
// 006cfec3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cfec7  d9ee                 fldz 
// 006cfec9  8b89b0000000         mov ecx, dword ptr [ecx + 0xb0]
// 006cfecf  8b8018010000         mov eax, dword ptr [eax + 0x118]
// 006cfed5  51                   push ecx
// 006cfed6  d91c24               fstp dword ptr [esp]
// 006cfed9  8d542428             lea edx, [esp + 0x28]
// 006cfedd  52                   push edx
// 006cfede  50                   push eax
// 006cfedf  e88c17feff           call 0x6b1670
// 006cfee4  84c0                 test al, al
// 006cfee6  742a                 je 0x6cff12
// 006cfee8  8d4c2424             lea ecx, [esp + 0x24]
// 006cfeec  c644244c00           mov byte ptr [esp + 0x4c], 0
// 006cfef1  e8ba89feff           call 0x6b88b0
// 006cfef6  8d4c240c             lea ecx, [esp + 0xc]
// 006cfefa  e851a4f1ff           call 0x5ea350
// 006cfeff  5f                   pop edi
// 006cff00  b001                 mov al, 1
// 006cff02  5e                   pop esi
// 006cff03  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006cff07  64890d00000000       mov dword ptr fs:[0], ecx
// 006cff0e  83c448               add esp, 0x48
// 006cff11  c3                   ret 
// 006cff12  8b4e08               mov ecx, dword ptr [esi + 8]
// 006cff15  e89667f9ff           call 0x6666b0
// 006cff1a  3bc7                 cmp eax, edi
// 006cff1c  7425                 je 0x6cff43
// 006cff1e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cff22  d9ee                 fldz 
// 006cff24  8b89b0000000         mov ecx, dword ptr [ecx + 0xb0]
// 006cff2a  8b8018010000         mov eax, dword ptr [eax + 0x118]
// 006cff30  51                   push ecx
// 006cff31  d91c24               fstp dword ptr [esp]
// 006cff34  8d542428             lea edx, [esp + 0x28]
// 006cff38  52                   push edx
// 006cff39  50                   push eax
// 006cff3a  e83117feff           call 0x6b1670
// 006cff3f  84c0                 test al, al
// 006cff41  75a5                 jne 0x6cfee8
// 006cff43  8d4c2424             lea ecx, [esp + 0x24]
// 006cff47  c644244c00           mov byte ptr [esp + 0x4c], 0
// 006cff4c  e85f89feff           call 0x6b88b0
// 006cff51  8b442418             mov eax, dword ptr [esp + 0x18]
// 006cff55  3bc7                 cmp eax, edi
// 006cff57  7409                 je 0x6cff62
// 006cff59  50                   push eax
// 006cff5a  e8d38a0400           call 0x718a32
// 006cff5f  83c404               add esp, 4
// 006cff62  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006cff66  50                   push eax
// 006cff67  897c241c             mov dword ptr [esp + 0x1c], edi
// 006cff6b  897c2420             mov dword ptr [esp + 0x20], edi
// 006cff6f  897c2424             mov dword ptr [esp + 0x24], edi
// 006cff73  e8ba8a0400           call 0x718a32
// 006cff78  83c404               add esp, 4
// 006cff7b  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 006cff7f  5f                   pop edi
// 006cff80  32c0                 xor al, al
// 006cff82  5e                   pop esi
// 006cff83  64890d00000000       mov dword ptr fs:[0], ecx
// 006cff8a  83c448               add esp, 0x48
// 006cff8d  c3                   ret 

// from server: 100% by EspClaude
// roc 2008-06 006444f0  unit: RBX::HUMAN::Climbing
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <set>

namespace RBX {
class Primitive;
class PartInstance {
public:
    char pad[0x118];
    Primitive* primitive;
    Primitive* getPartPrimitive() const { return primitive; }
};
class ContactManager {
public:
    bool intersectingOthers(Primitive* p, const std::set<Primitive*>& ignore, float overlap);
};
class World {
public:
    char pad[0xb0];
    ContactManager* contactManager;
    ContactManager* getContactManager() const { return contactManager; }
};
class Humanoid {
public:
    char pad[0x224];
    World* world;
    World* getWorld() const { return world; }
    void getPrimitives(std::vector<Primitive*>& primitives);
    PartInstance* getLeftArm();
    PartInstance* getRightArm();
};
namespace HUMAN {
class Climbing {
public:
    void* vtbl;
    void* pad;
    Humanoid* humanoid;
    bool armsTouching();
};

bool Climbing::armsTouching()
{
    World* world = humanoid->getWorld();
    if (world)
    {
        std::vector<Primitive*> primitives;
        humanoid->getPrimitives(primitives);
        std::set<Primitive*> ignore(primitives.begin(), primitives.end());

        PartInstance* leftArm = humanoid->getLeftArm();
        if (leftArm && world->getContactManager()->intersectingOthers(leftArm->getPartPrimitive(), ignore, 0.0f))
            return true;
        PartInstance* rightArm = humanoid->getRightArm();
        if (rightArm && world->getContactManager()->intersectingOthers(rightArm->getPartPrimitive(), ignore, 0.0f))
            return true;
    }
    return false;
}
}
}
