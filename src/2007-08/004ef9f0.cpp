// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 004ef9f0  unit: RBX::Render::VChunk::?$WeakReferenceCountedPointer  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef9f0
//
// 004ef9f0  6aff                 push -1
// 004ef9f2  68a8d37400           push 0x74d3a8
// 004ef9f7  64a100000000         mov eax, dword ptr fs:[0]
// 004ef9fd  50                   push eax
// 004ef9fe  51                   push ecx
// 004ef9ff  56                   push esi
// 004efa00  a188518b00           mov eax, dword ptr [0x8b5188]
// 004efa05  33c4                 xor eax, esp
// 004efa07  50                   push eax
// 004efa08  8d44240c             lea eax, [esp + 0xc]
// 004efa0c  64a300000000         mov dword ptr fs:[0], eax
// 004efa12  8bf1                 mov esi, ecx
// 004efa14  89742408             mov dword ptr [esp + 8], esi
// 004efa18  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004efa1c  8a08                 mov cl, byte ptr [eax]
// 004efa1e  880e                 mov byte ptr [esi], cl
// 004efa20  8a5001               mov dl, byte ptr [eax + 1]
// 004efa23  885601               mov byte ptr [esi + 1], dl
// 004efa26  d94004               fld dword ptr [eax + 4]
// 004efa29  d95e04               fstp dword ptr [esi + 4]
// 004efa2c  8d4e08               lea ecx, [esi + 8]
// 004efa2f  c70100000000         mov dword ptr [ecx], 0
// 004efa35  8b4008               mov eax, dword ptr [eax + 8]
// 004efa38  50                   push eax
// 004efa39  e83255f8ff           call 0x474f70
// 004efa3e  8b542420             mov edx, dword ptr [esp + 0x20]
// 004efa42  8d4e0c               lea ecx, [esi + 0xc]
// 004efa45  c70100000000         mov dword ptr [ecx], 0
// 004efa4b  8b02                 mov eax, dword ptr [edx]
// 004efa4d  50                   push eax
// 004efa4e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004efa56  e81555f8ff           call 0x474f70
// 004efa5b  8bc6                 mov eax, esi
// 004efa5d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004efa61  64890d00000000       mov dword ptr fs:[0], ecx
// 004efa68  59                   pop ecx
// 004efa69  5e                   pop esi
// 004efa6a  83c410               add esp, 0x10
// 004efa6d  c20800               ret 8

struct Obj;

class WeakPtr {
public:
    Obj* p;
    WeakPtr(const WeakPtr& o) : p(0) { assign(o.p); }
    ~WeakPtr();
    void assign(Obj* o);
};

struct Box {
    char a;
    char b;
    float c;
    WeakPtr d;
};

struct Chunk {
    char a;
    char b;
    float c;
    WeakPtr d;
    WeakPtr e;
    Chunk(const Box& box, const WeakPtr& w);
};

Chunk::Chunk(const Box& box, const WeakPtr& w)
    : a(box.a), b(box.b), c(box.c), d(box.d), e(w)
{
}
