// from server: 100% by EspClaude
// from server: 44% by tester
// roc 2007-08 00442560  unit: CPropGrid  size: 335 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00442560
//
// 00442560  6aff                 push -1
// 00442562  685cf37300           push 0x73f35c
// 00442567  64a100000000         mov eax, dword ptr fs:[0]
// 0044256d  50                   push eax
// 0044256e  51                   push ecx
// 0044256f  53                   push ebx
// 00442570  56                   push esi
// 00442571  57                   push edi
// 00442572  a188518b00           mov eax, dword ptr [0x8b5188]
// 00442577  33c4                 xor eax, esp
// 00442579  50                   push eax
// 0044257a  8d442414             lea eax, [esp + 0x14]
// 0044257e  64a300000000         mov dword ptr fs:[0], eax
// 00442584  8bf1                 mov esi, ecx
// 00442586  89742410             mov dword ptr [esp + 0x10], esi
// 0044258a  e8311c2400           call 0x6841c0
// 0044258f  33db                 xor ebx, ebx
// 00442591  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00442595  c7867c01000044837800 mov dword ptr [esi + 0x17c], 0x788344
// 0044259f  8d8e80010000         lea ecx, [esi + 0x180]
// 004425a5  c644241c01           mov byte ptr [esp + 0x1c], 1
// 004425aa  c7061cf47800         mov dword ptr [esi], 0x78f41c
// 004425b0  c7867c0100000cf47800 mov dword ptr [esi + 0x17c], 0x78f40c
// 004425ba  e841312e00           call 0x725700
// 004425bf  899e88010000         mov dword ptr [esi + 0x188], ebx
// 004425c5  899e90010000         mov dword ptr [esi + 0x190], ebx
// 004425cb  899e94010000         mov dword ptr [esi + 0x194], ebx
// 004425d1  899e98010000         mov dword ptr [esi + 0x198], ebx
// 004425d7  8dbe9c010000         lea edi, [esi + 0x19c]
// 004425dd  8bcf                 mov ecx, edi
// 004425df  c644241c03           mov byte ptr [esp + 0x1c], 3
// 004425e4  e8c70f1400           call 0x5835b0
// 004425e9  894704               mov dword ptr [edi + 4], eax
// 004425ec  c6401501             mov byte ptr [eax + 0x15], 1
// 004425f0  8b4704               mov eax, dword ptr [edi + 4]
// 004425f3  894004               mov dword ptr [eax + 4], eax
// 004425f6  8b4704               mov eax, dword ptr [edi + 4]
// 004425f9  8900                 mov dword ptr [eax], eax
// 004425fb  8b4704               mov eax, dword ptr [edi + 4]
// 004425fe  894008               mov dword ptr [eax + 8], eax
// 00442601  895f08               mov dword ptr [edi + 8], ebx
// 00442604  8dbea8010000         lea edi, [esi + 0x1a8]
// 0044260a  8bcf                 mov ecx, edi
// 0044260c  c644241c04           mov byte ptr [esp + 0x1c], 4
// 00442611  e89a0f1400           call 0x5835b0
// 00442616  894704               mov dword ptr [edi + 4], eax
// 00442619  c6401501             mov byte ptr [eax + 0x15], 1
// 0044261d  8b4704               mov eax, dword ptr [edi + 4]
// 00442620  894004               mov dword ptr [eax + 4], eax
// 00442623  8b4704               mov eax, dword ptr [edi + 4]
// 00442626  8900                 mov dword ptr [eax], eax
// 00442628  8b4704               mov eax, dword ptr [edi + 4]
// 0044262b  894008               mov dword ptr [eax + 8], eax
// 0044262e  895f08               mov dword ptr [edi + 8], ebx
// 00442631  8dbeb8010000         lea edi, [esi + 0x1b8]
// 00442637  8bcf                 mov ecx, edi
// 00442639  c644241c05           mov byte ptr [esp + 0x1c], 5
// 0044263e  889eb4010000         mov byte ptr [esi + 0x1b4], bl
// 00442644  889eb5010000         mov byte ptr [esi + 0x1b5], bl
// 0044264a  e8616d1600           call 0x5a93b0
// 0044264f  894704               mov dword ptr [edi + 4], eax
// 00442652  c6401101             mov byte ptr [eax + 0x11], 1
// 00442656  8b4704               mov eax, dword ptr [edi + 4]
// 00442659  894004               mov dword ptr [eax + 4], eax
// 0044265c  8b4704               mov eax, dword ptr [edi + 4]
// 0044265f  8900                 mov dword ptr [eax], eax
// 00442661  8b4704               mov eax, dword ptr [edi + 4]
// 00442664  894008               mov dword ptr [eax + 8], eax
// 00442667  895f08               mov dword ptr [edi + 8], ebx
// 0044266a  8dbec4010000         lea edi, [esi + 0x1c4]
// 00442670  8bcf                 mov ecx, edi
// 00442672  c644241c06           mov byte ptr [esp + 0x1c], 6
// 00442677  e8c45f0900           call 0x4d8640
// 0044267c  894704               mov dword ptr [edi + 4], eax
// 0044267f  c6402101             mov byte ptr [eax + 0x21], 1
// 00442683  8b4704               mov eax, dword ptr [edi + 4]
// 00442686  894004               mov dword ptr [eax + 4], eax
// 00442689  8b4704               mov eax, dword ptr [edi + 4]
// 0044268c  8900                 mov dword ptr [eax], eax
// 0044268e  8b4704               mov eax, dword ptr [edi + 4]
// 00442691  894008               mov dword ptr [eax + 8], eax
// 00442694  895f08               mov dword ptr [edi + 8], ebx
// 00442697  895e5c               mov dword ptr [esi + 0x5c], ebx
// 0044269a  8bc6                 mov eax, esi
// 0044269c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004426a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004426a7  59                   pop ecx
// 004426a8  5f                   pop edi
// 004426a9  5e                   pop esi
// 004426aa  5b                   pop ebx
// 004426ab  83c410               add esp, 0x10
// 004426ae  c3                   ret 

#include <vector>
#include <map>
#include <set>

// Primary base: out-of-line ctor at 0x6841c0, 0x17c bytes (second base vptr at +0x17c).
class CPropGridBase {
public:
    CPropGridBase();
    virtual ~CPropGridBase();
    char pad4[0x58];
    int m_5c;                       // zeroed in the derived ctor body
    char pad60[0x17c - 0x60];
};

// Second base: vptr only, inline ctor stores its own vtable first (0x788344).
class IPropGridSink {
public:
    virtual ~IPropGridSink() {}
};

// 8-byte member with out-of-line ctor (0x725700) and a destructor (unwind state 2).
class Lock8 {
public:
    Lock8();
    ~Lock8();
private:
    void* m_a;
    int m_b;
};

struct Value14 { int v[4]; };       // map node isnil at +0x21 => pair is 0x14 bytes

class CPropGrid : public CPropGridBase, public IPropGridSink {
public:
    CPropGrid();
    virtual ~CPropGrid();
private:
    Lock8 m_lock;                       // +0x180
    void* m_188;                        // +0x188
    std::vector<int> m_vec;             // +0x18c
    std::map<int, int> m_map1;          // +0x19c  (isnil +0x15)
    std::map<int, int> m_map2;          // +0x1a8
    bool m_1b4;                         // +0x1b4
    bool m_1b5;                         // +0x1b5
    std::set<int> m_set;                // +0x1b8  (isnil +0x11)
    std::map<int, Value14> m_map4;      // +0x1c4  (isnil +0x21)
};

CPropGrid::CPropGrid()
    : m_188(0), m_1b4(false), m_1b5(false)
{
    m_5c = 0;
}
