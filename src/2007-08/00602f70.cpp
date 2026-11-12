// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 00602f70  unit: RBX::JointStage  size: 231 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00602f70
//
// roc-flags: /O2 /GS- /EHsc /MD
// 00602f70  55                   push ebp
// 00602f71  8bec                 mov ebp, esp
// 00602f73  83e4f8               and esp, 0xfffffff8
// 00602f76  6aff                 push -1
// 00602f78  68c8c07500           push 0x75c0c8
// 00602f7d  64a100000000         mov eax, dword ptr fs:[0]
// 00602f83  50                   push eax
// 00602f84  64892500000000       mov dword ptr fs:[0], esp
// 00602f8b  83ec50               sub esp, 0x50
// 00602f8e  53                   push ebx
// 00602f8f  33c0                 xor eax, eax
// 00602f91  56                   push esi
// 00602f92  57                   push edi
// 00602f93  8bd9                 mov ebx, ecx
// 00602f95  8944244c             mov dword ptr [esp + 0x4c], eax
// 00602f99  89442450             mov dword ptr [esp + 0x50], eax
// 00602f9d  89442454             mov dword ptr [esp + 0x54], eax
// 00602fa1  8b7d08               mov edi, dword ptr [ebp + 8]
// 00602fa4  8bcf                 mov ecx, edi
// 00602fa6  89442464             mov dword ptr [esp + 0x64], eax
// 00602faa  e8611dfbff           call 0x5b4d10
// 00602faf  8bf0                 mov esi, eax
// 00602fb1  85f6                 test esi, esi
// 00602fb3  747d                 je 0x603032
// 00602fb5  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00602fb8  8b01                 mov eax, dword ptr [ecx]
// 00602fba  8b5014               mov edx, dword ptr [eax + 0x14]
// 00602fbd  56                   push esi
// 00602fbe  ffd2                 call edx
// 00602fc0  56                   push esi
// 00602fc1  e84a17fbff           call 0x5b4710
// 00602fc6  83c404               add esp, 4
// 00602fc9  8d442410             lea eax, [esp + 0x10]
// 00602fcd  50                   push eax
// 00602fce  8d4c2428             lea ecx, [esp + 0x28]
// 00602fd2  51                   push ecx
// 00602fd3  8d4b10               lea ecx, [ebx + 0x10]
// 00602fd6  89742418             mov dword ptr [esp + 0x18], esi
// 00602fda  e8d1f9fdff           call 0x5e29b0
// 00602fdf  85ff                 test edi, edi
// 00602fe1  741a                 je 0x602ffd
// 00602fe3  8d542414             lea edx, [esp + 0x14]
// 00602fe7  52                   push edx
// 00602fe8  8d442434             lea eax, [esp + 0x34]
// 00602fec  50                   push eax
// 00602fed  8d4b1c               lea ecx, [ebx + 0x1c]
// 00602ff0  897c241c             mov dword ptr [esp + 0x1c], edi
// 00602ff4  89742420             mov dword ptr [esp + 0x20], esi
// 00602ff8  e803ffffff           call 0x602f00
// 00602ffd  8b4608               mov eax, dword ptr [esi + 8]
// 00603000  3bf8                 cmp edi, eax
// 00603002  7503                 jne 0x603007
// 00603004  8b460c               mov eax, dword ptr [esi + 0xc]
// 00603007  85c0                 test eax, eax
// 00603009  741a                 je 0x603025
// 0060300b  8d4c241c             lea ecx, [esp + 0x1c]
// 0060300f  51                   push ecx
// 00603010  8d542440             lea edx, [esp + 0x40]
// 00603014  52                   push edx
// 00603015  8d4b1c               lea ecx, [ebx + 0x1c]
// 00603018  89442424             mov dword ptr [esp + 0x24], eax
// 0060301c  89742428             mov dword ptr [esp + 0x28], esi
// 00603020  e8dbfeffff           call 0x602f00
// 00603025  8bcf                 mov ecx, edi
// 00603027  e8e41cfbff           call 0x5b4d10
// 0060302c  8bf0                 mov esi, eax
// 0060302e  85f6                 test esi, esi
// 00603030  7583                 jne 0x602fb5
// 00603032  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00603035  57                   push edi
// 00603036  e855540000           call 0x608490
// 0060303b  53                   push ebx
// 0060303c  8bcf                 mov ecx, edi
// 0060303e  e8dd600000           call 0x609120
// 00603043  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00603047  5f                   pop edi
// 00603048  5e                   pop esi
// 00603049  64890d00000000       mov dword ptr fs:[0], ecx
// 00603050  5b                   pop ebx
// 00603051  8be5                 mov esp, ebp
// 00603053  5d                   pop ebp
// 00603054  c20400               ret 4

#include <set>
#include <map>
#include <vector>

namespace RBX {
class Primitive;
class Edge;
class Kernel;

class IStage {
public:
    virtual ~IStage();
    virtual int getStageType() = 0;
    virtual void stepWorld(int, int, bool);
    virtual Kernel* getKernel();
    IStage* upstream;                    // +4
    IStage* downstream;                  // +8
};

class IWorldStage : public IStage {
public:
    virtual void onEdgeAdded(Edge* e);           // slot 4
    virtual void onEdgeRemoving(Edge* e);        // slot 5 (+0x14)
    int pad0c;                                   // +0xc
};

class IPipelined {
public:
    virtual ~IPipelined();
    IStage* currentStage;                        // +4
};

class Edge : public IPipelined {
public:
    Primitive* prim0;                            // +8
    Primitive* prim1;                            // +0xc
    Primitive* otherPrimitive(const Primitive* p) const { return p == prim0 ? prim1 : prim0; }
    static void removeFromPipeline(Edge* e);     // 005b4710 (cdecl)
};

class Joint : public Edge {};

class Primitive : public IPipelined {
public:
    Joint* getFirstJoint();                      // 005b4d10
    void putInPipeline(IStage* stage);           // 00609120
};

class ClumpStage : public IWorldStage {
public:
    void onPrimitiveAdded(Primitive* p);         // 00608490
};

class JointStage : public IWorldStage {
public:
    void onPrimitiveAdded(Primitive* p);
private:
    std::set<Edge*> incompleteJoints;                   // +0x10
    std::multimap<Primitive*, Joint*> jointMap;         // +0x1c
    void insertToMap(Primitive* p, Joint* j)
    {
        if (p)
            jointMap.insert(std::make_pair(p, j));
    }
};

void JointStage::onPrimitiveAdded(Primitive* p)
{
    std::vector<Joint*> unused;
    while (Joint* j = p->getFirstJoint()) {
        static_cast<IWorldStage*>(downstream)->onEdgeRemoving(j);
        Edge::removeFromPipeline(j);
        incompleteJoints.insert(j);
        insertToMap(p, j);
        insertToMap(j->otherPrimitive(p), j);
    }
    static_cast<ClumpStage*>(downstream)->onPrimitiveAdded(p);
    p->putInPipeline(this);
}
}
