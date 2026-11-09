// from server: 100% by Yeetserama
// roc 2007-08 004127d0  unit: VCContent::?$CComAggObject  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004127d0
//
// 004127d0  6aff                 push -1
// 004127d2  680ba57300           push 0x73a50b
// 004127d7  64a100000000         mov eax, dword ptr fs:[0]
// 004127dd  50                   push eax
// 004127de  51                   push ecx
// 004127df  56                   push esi
// 004127e0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004127e5  33c4                 xor eax, esp
// 004127e7  50                   push eax
// 004127e8  8d44240c             lea eax, [esp + 0xc]
// 004127ec  64a300000000         mov dword ptr fs:[0], eax
// 004127f2  8bf1                 mov esi, ecx
// 004127f4  89742408             mov dword ptr [esp + 8], esi
// 004127f8  c706406f7800         mov dword ptr [esi], 0x786f40
// 004127fe  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 00412805  8b0d44ae8b00         mov ecx, dword ptr [0x8bae44]
// 0041280b  8b01                 mov eax, dword ptr [ecx]
// 0041280d  8b5008               mov edx, dword ptr [eax + 8]
// 00412810  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00412818  ffd2                 call edx
// 0041281a  8d4e14               lea ecx, [esi + 0x14]
// 0041281d  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00412825  ff1578e67700         call dword ptr [0x77e678]
// 0041282b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041282f  64890d00000000       mov dword ptr fs:[0], ecx
// 00412836  59                   pop ecx
// 00412837  5e                   pop esi
// 00412838  83c410               add esp, 0x10
// 0041283b  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000009@@UAE@XZ)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
extern void (__thiscall *destroyStream)(void *);

struct Stream
{
    ~Stream() { destroyStream(this); }
};

struct Module
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

extern Module *module;

struct S
{
    virtual ~S();

    unsigned long references;
    unsigned char reserved[12];
    Stream stream;
};

S::~S()
{
    references = 0xC0000001UL;
    module->release();
}
}
