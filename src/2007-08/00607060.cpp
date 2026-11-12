// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 00607060  unit: RBX::ClumpStage  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00607060
//
// 00607060  83ec24               sub esp, 0x24
// 00607063  53                   push ebx
// 00607064  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00607068  55                   push ebp
// 00607069  8be9                 mov ebp, ecx
// 0060706b  56                   push esi
// 0060706c  8bcb                 mov ecx, ebx
// 0060706e  e8bdd7faff           call 0x5b4830
// 00607073  85c0                 test eax, eax
// 00607075  7408                 je 0x60707f
// 00607077  53                   push ebx
// 00607078  8bcd                 mov ecx, ebp
// 0060707a  e8f1feffff           call 0x606f70
// 0060707f  8b4320               mov eax, dword ptr [ebx + 0x20]
// 00607082  8bcb                 mov ecx, ebx
// 00607084  8944240c             mov dword ptr [esp + 0xc], eax
// 00607088  e833ddfaff           call 0x5b4dc0
// 0060708d  8bf0                 mov esi, eax
// 0060708f  85f6                 test esi, esi
// 00607091  0f84d6000000         je 0x60716d
// 00607097  57                   push edi
// 00607098  8d7d44               lea edi, [ebp + 0x44]
// 0060709b  eb03                 jmp 0x6070a0
// 0060709d  8d4900               lea ecx, [ecx]
// 006070a0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006070a4  56                   push esi
// 006070a5  e8b64b0000           call 0x60bc60
// 006070aa  84c0                 test al, al
// 006070ac  56                   push esi
// 006070ad  741d                 je 0x6070cc
// 006070af  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006070b3  8bcf                 mov ecx, edi
// 006070b5  e8464e0000           call 0x60bf00
// 006070ba  56                   push esi
// 006070bb  56                   push esi
// 006070bc  8bcf                 mov ecx, edi
// 006070be  e83d410000           call 0x60b200
// 006070c3  8bc8                 mov ecx, eax
// 006070c5  e8364e0000           call 0x60bf00
// 006070ca  eb76                 jmp 0x607142
// 006070cc  8bcd                 mov ecx, ebp
// 006070ce  e83de9ffff           call 0x605a10
// 006070d3  84c0                 test al, al
// 006070d5  746b                 je 0x607142
// 006070d7  8d4c2414             lea ecx, [esp + 0x14]
// 006070db  51                   push ecx
// 006070dc  8bcf                 mov ecx, edi
// 006070de  89742418             mov dword ptr [esp + 0x18], esi
// 006070e2  e849eaffff           call 0x605b30
// 006070e7  85c0                 test eax, eax
// 006070e9  7557                 jne 0x607142
// 006070eb  8d542414             lea edx, [esp + 0x14]
// 006070ef  52                   push edx
// 006070f0  8d4d5c               lea ecx, [ebp + 0x5c]
// 006070f3  e838eaffff           call 0x605b30
// 006070f8  85c0                 test eax, eax
// 006070fa  7546                 jne 0x607142
// 006070fc  8b4530               mov eax, dword ptr [ebp + 0x30]
// 006070ff  8d4c2414             lea ecx, [esp + 0x14]
// 00607103  8d7d2c               lea edi, [ebp + 0x2c]
// 00607106  51                   push ecx
// 00607107  8d542424             lea edx, [esp + 0x24]
// 0060710b  52                   push edx
// 0060710c  8bcf                 mov ecx, edi
// 0060710e  8974241c             mov dword ptr [esp + 0x1c], esi
// 00607112  89442424             mov dword ptr [esp + 0x24], eax
// 00607116  e8e590f6ff           call 0x570200
// 0060711b  8bd8                 mov ebx, eax
// 0060711d  8b03                 mov eax, dword ptr [ebx]
// 0060711f  85c0                 test eax, eax
// 00607121  7404                 je 0x607127
// 00607123  3bc7                 cmp eax, edi
// 00607125  7406                 je 0x60712d
// 00607127  ff15d8e67700         call dword ptr [0x77e6d8]
// 0060712d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00607131  394304               cmp dword ptr [ebx + 4], eax
// 00607134  7408                 je 0x60713e
// 00607136  56                   push esi
// 00607137  8bcd                 mov ecx, ebp
// 00607139  e842ebffff           call 0x605c80
// 0060713e  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 00607142  8d4c2414             lea ecx, [esp + 0x14]
// 00607146  51                   push ecx
// 00607147  8d54242c             lea edx, [esp + 0x2c]
// 0060714b  8d7d44               lea edi, [ebp + 0x44]
// 0060714e  52                   push edx
// 0060714f  8bcf                 mov ecx, edi
// 00607151  8974241c             mov dword ptr [esp + 0x1c], esi
// 00607155  e856b8fdff           call 0x5e29b0
// 0060715a  56                   push esi
// 0060715b  8bcb                 mov ecx, ebx
// 0060715d  e87edcfaff           call 0x5b4de0
// 00607162  8bf0                 mov esi, eax
// 00607164  85f6                 test esi, esi
// 00607166  0f8534ffffff         jne 0x6070a0
// 0060716c  5f                   pop edi
// 0060716d  53                   push ebx
// 0060716e  8bcd                 mov ecx, ebp
// 00607170  e87be5ffff           call 0x6056f0
// 00607175  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00607179  53                   push ebx
// 0060717a  e8914d0000           call 0x60bf10
// 0060717f  5e                   pop esi
// 00607180  5d                   pop ebp
// 00607181  5b                   pop ebx
// 00607182  83c424               add esp, 0x24
// 00607185  c20400               ret 4

#include <set>
#include <map>

class Entity { };
class Primitive : public Entity { };

class Assembly {
public:
    bool contains(Primitive* p);
    void touch(Primitive* p);
    Assembly* split(Primitive* p);
    void finish(class Clump* c);
};

class Clump {
public:
    void* getRoot();
    Primitive* firstPrimitive();
    Primitive* nextPrimitive(Primitive* p);
    char pad[0x20];
    Assembly* assembly;
};

struct PendingEntry { void* a; void* b; };

class ClumpStage {
public:
    char pad[0x2c];
    std::map<Entity*, PendingEntry> pending;
    char pad2[0x44 - 0x2c - sizeof(std::map<Entity*, PendingEntry>)];
    std::set<Entity*> visited;
    char pad3[0x5c - 0x44 - sizeof(std::set<Entity*>)];
    std::set<Entity*> removed;

    void onRoot(Clump* c);
    bool isActive(Primitive* p);
    void markPending(Primitive* p);
    void finishClump(Clump* c);
    bool wasUnseen(Entity* e) { return !visited.erase(e) && !removed.erase(e); }
    void process(Clump* c);
};

void ClumpStage::process(Clump* c)
{
    if (c->getRoot())
        onRoot(c);
    Assembly* a = c->assembly;
    for (Primitive* p = c->firstPrimitive(); p; p = c->nextPrimitive(p)) {
        if (a->contains(p)) {
            a->touch(p);
            a->split(p)->touch(p);
        } else if (isActive(p)) {
            if (wasUnseen(p)) {
                if (pending.find(p) != pending.end())
                    markPending(p);
            }
        }
        visited.insert(p);
    }
    finishClump(c);
    a->finish(c);
}
