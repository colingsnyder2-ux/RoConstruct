// from server: 100% by Yeetserama
// roc 2007-08 0041de90  unit: CInstanceExplorer  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041de90
//
// 0041de90  6aff                 push -1
// 0041de92  6898b77300           push 0x73b798
// 0041de97  64a100000000         mov eax, dword ptr fs:[0]
// 0041de9d  50                   push eax
// 0041de9e  51                   push ecx
// 0041de9f  56                   push esi
// 0041dea0  57                   push edi
// 0041dea1  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041dea6  33c4                 xor eax, esp
// 0041dea8  50                   push eax
// 0041dea9  8d442410             lea eax, [esp + 0x10]
// 0041dead  64a300000000         mov dword ptr fs:[0], eax
// 0041deb3  8bf9                 mov edi, ecx
// 0041deb5  897c240c             mov dword ptr [esp + 0xc], edi
// 0041deb9  c707ec7e7800         mov dword ptr [edi], 0x787eec
// 0041debf  8b7758               mov esi, dword ptr [edi + 0x58]
// 0041dec2  85f6                 test esi, esi
// 0041dec4  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041decc  742a                 je 0x41def8
// 0041dece  8d4604               lea eax, [esi + 4]
// 0041ded1  83c9ff               or ecx, 0xffffffff
// 0041ded4  f00fc108             lock xadd dword ptr [eax], ecx
// 0041ded8  751e                 jne 0x41def8
// 0041deda  8b16                 mov edx, dword ptr [esi]
// 0041dedc  8b4204               mov eax, dword ptr [edx + 4]
// 0041dedf  8bce                 mov ecx, esi
// 0041dee1  ffd0                 call eax
// 0041dee3  8d4e08               lea ecx, [esi + 8]
// 0041dee6  83caff               or edx, 0xffffffff
// 0041dee9  f00fc111             lock xadd dword ptr [ecx], edx
// 0041deed  7509                 jne 0x41def8
// 0041deef  8b06                 mov eax, dword ptr [esi]
// 0041def1  8b5008               mov edx, dword ptr [eax + 8]
// 0041def4  8bce                 mov ecx, esi
// 0041def6  ffd2                 call edx
// 0041def8  8bcf                 mov ecx, edi
// 0041defa  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0041df02  e8a93f2400           call 0x661eb0
// 0041df07  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041df0b  64890d00000000       mov dword ptr fs:[0], ecx
// 0041df12  59                   pop ecx
// 0041df13  5f                   pop edi
// 0041df14  5e                   pop esi
// 0041df15  83c410               add esp, 0x10
// 0041df18  c3                   ret 
// copied from an identical function in another client (function ??1CInstanceExplorer@ns_ROCX000014@@UAE@XZ)

namespace ns_ROCX000014 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Base
{
    virtual ~Base();
    char padding[0x50];
};

struct CInstanceExplorer : Base
{
    void* object;
    Control* control;
    virtual ~CInstanceExplorer();
};

CInstanceExplorer::~CInstanceExplorer()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0)
    {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}
}
