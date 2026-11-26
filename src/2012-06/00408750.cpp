// from server: 100% by Xemicl
// roc 2012-06 00408750  unit: VCApp::?$CComAggObject  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00408750
//
// 00408750  6aff                 push -1
// 00408752  688ba3a900           push 0xa9a38b
// 00408757  64a100000000         mov eax, dword ptr fs:[0]
// 0040875d  50                   push eax
// 0040875e  64892500000000       mov dword ptr fs:[0], esp
// 00408765  51                   push ecx
// 00408766  56                   push esi
// 00408767  8bf1                 mov esi, ecx
// 00408769  89742404             mov dword ptr [esp + 4], esi
// 0040876d  c706103bb400         mov dword ptr [esi], 0xb43b10
// 00408773  c74604010000c0       mov dword ptr [esi + 4], 0xc0000001
// 0040877a  8b0dc463e100         mov ecx, dword ptr [0xe163c4]
// 00408780  8b01                 mov eax, dword ptr [ecx]
// 00408782  8b5008               mov edx, dword ptr [eax + 8]
// 00408785  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040878d  ffd2                 call edx
// 0040878f  8d4e08               lea ecx, [esi + 8]
// 00408792  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0040879a  e841cbffff           call 0x4052e0
// 0040879f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004087a3  5e                   pop esi
// 004087a4  64890d00000000       mov dword ptr fs:[0], ecx
// 004087ab  83c410               add esp, 0x10
// 004087ae  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX00000a@@UAE@XZ)

namespace ns_ROCX00000a {
struct Global
{
    virtual void first();
    virtual void second();
    virtual unsigned long release();
};

extern Global* global;

struct Member
{
    ~Member();
};

struct S
{
    virtual ~S();
    unsigned long references;
    Member member;
};

S::~S()
{
    references = 0xC0000001UL;
    global->release();
}
}
