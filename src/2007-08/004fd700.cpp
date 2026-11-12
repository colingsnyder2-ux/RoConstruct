// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 004fd700  unit: RBX::Render::AggregateChunk  size: 223 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fd700
//
// 004fd700  6aff                 push -1
// 004fd702  68d3e87400           push 0x74e8d3
// 004fd707  64a100000000         mov eax, dword ptr fs:[0]
// 004fd70d  50                   push eax
// 004fd70e  51                   push ecx
// 004fd70f  56                   push esi
// 004fd710  57                   push edi
// 004fd711  a188518b00           mov eax, dword ptr [0x8b5188]
// 004fd716  33c4                 xor eax, esp
// 004fd718  50                   push eax
// 004fd719  8d442410             lea eax, [esp + 0x10]
// 004fd71d  64a300000000         mov dword ptr fs:[0], eax
// 004fd723  8bf1                 mov esi, ecx
// 004fd725  8974240c             mov dword ptr [esp + 0xc], esi
// 004fd729  8b4608               mov eax, dword ptr [esi + 8]
// 004fd72c  85c0                 test eax, eax
// 004fd72e  8b3de8d27700         mov edi, dword ptr [0x77d2e8]
// 004fd734  c744241801000000     mov dword ptr [esp + 0x18], 1
// 004fd73c  7428                 je 0x4fd766
// 004fd73e  83c004               add eax, 4
// 004fd741  50                   push eax
// 004fd742  ffd7                 call edi
// 004fd744  85c0                 test eax, eax
// 004fd746  7517                 jne 0x4fd75f
// 004fd748  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd74b  e880a6f5ff           call 0x457dd0
// 004fd750  8b4e08               mov ecx, dword ptr [esi + 8]
// 004fd753  85c9                 test ecx, ecx
// 004fd755  7408                 je 0x4fd75f
// 004fd757  8b01                 mov eax, dword ptr [ecx]
// 004fd759  8b10                 mov edx, dword ptr [eax]
// 004fd75b  6a01                 push 1
// 004fd75d  ffd2                 call edx
// 004fd75f  c7460800000000       mov dword ptr [esi + 8], 0
// 004fd766  8b4604               mov eax, dword ptr [esi + 4]
// 004fd769  85c0                 test eax, eax
// 004fd76b  c644241800           mov byte ptr [esp + 0x18], 0
// 004fd770  7428                 je 0x4fd79a
// 004fd772  83c004               add eax, 4
// 004fd775  50                   push eax
// 004fd776  ffd7                 call edi
// 004fd778  85c0                 test eax, eax
// 004fd77a  7517                 jne 0x4fd793
// 004fd77c  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fd77f  e84ca6f5ff           call 0x457dd0
// 004fd784  8b4e04               mov ecx, dword ptr [esi + 4]
// 004fd787  85c9                 test ecx, ecx
// 004fd789  7408                 je 0x4fd793
// 004fd78b  8b01                 mov eax, dword ptr [ecx]
// 004fd78d  8b10                 mov edx, dword ptr [eax]
// 004fd78f  6a01                 push 1
// 004fd791  ffd2                 call edx
// 004fd793  c7460400000000       mov dword ptr [esi + 4], 0
// 004fd79a  8b06                 mov eax, dword ptr [esi]
// 004fd79c  85c0                 test eax, eax
// 004fd79e  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004fd7a6  7425                 je 0x4fd7cd
// 004fd7a8  83c004               add eax, 4
// 004fd7ab  50                   push eax
// 004fd7ac  ffd7                 call edi
// 004fd7ae  85c0                 test eax, eax
// 004fd7b0  7515                 jne 0x4fd7c7
// 004fd7b2  8b0e                 mov ecx, dword ptr [esi]
// 004fd7b4  e817a6f5ff           call 0x457dd0
// 004fd7b9  8b0e                 mov ecx, dword ptr [esi]
// 004fd7bb  85c9                 test ecx, ecx
// 004fd7bd  7408                 je 0x4fd7c7
// 004fd7bf  8b01                 mov eax, dword ptr [ecx]
// 004fd7c1  8b10                 mov edx, dword ptr [eax]
// 004fd7c3  6a01                 push 1
// 004fd7c5  ffd2                 call edx
// 004fd7c7  c70600000000         mov dword ptr [esi], 0
// 004fd7cd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fd7d1  64890d00000000       mov dword ptr fs:[0], ecx
// 004fd7d8  59                   pop ecx
// 004fd7d9  5f                   pop edi
// 004fd7da  5e                   pop esi
// 004fd7db  83c410               add esp, 0x10
// 004fd7de  c3                   ret 

// Destructor of a class holding three intrusive ref pointers at +0, +4, +8
// (destroyed 8, 4, 0). Pointee: vptr (vt[0] = scalar deleting dtor, push 1),
// refcount at +4 decremented through the IAT, thiscall 0x457dd0 before delete.

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class Counted {
public:
    virtual ~Counted();
    long refs;
    void lastRelease();
};

template<class T> class RefPtr {
public:
    T* p;
    ~RefPtr()
    {
        if (p) {
            if (InterlockedDecrement(&p->refs) == 0) {
                p->lastRelease();
                delete p;
            }
            p = 0;
        }
    }
};

class AggregateChunk {
public:
    RefPtr<Counted> a;
    RefPtr<Counted> b;
    RefPtr<Counted> c;
    ~AggregateChunk();
};

AggregateChunk::~AggregateChunk()
{
}
