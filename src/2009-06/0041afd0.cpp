// from server: 100% by EspClaude
// roc 2009-06 0041afd0  unit: rbx::signals::connection::slot  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041afd0
//
// 0041afd0  6aff                 push -1
// 0041afd2  6888e08400           push 0x84e088
// 0041afd7  64a100000000         mov eax, dword ptr fs:[0]
// 0041afdd  50                   push eax
// 0041afde  64892500000000       mov dword ptr fs:[0], esp
// 0041afe5  51                   push ecx
// 0041afe6  56                   push esi
// 0041afe7  57                   push edi
// 0041afe8  8bf9                 mov edi, ecx
// 0041afea  897c2408             mov dword ptr [esp + 8], edi
// 0041afee  c7070c008b00         mov dword ptr [edi], 0x8b000c
// 0041aff4  8b7758               mov esi, dword ptr [edi + 0x58]
// 0041aff7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0041afff  85f6                 test esi, esi
// 0041b001  742a                 je 0x41b02d
// 0041b003  8d4604               lea eax, [esi + 4]
// 0041b006  83c9ff               or ecx, 0xffffffff
// 0041b009  f00fc108             lock xadd dword ptr [eax], ecx
// 0041b00d  751e                 jne 0x41b02d
// 0041b00f  8b16                 mov edx, dword ptr [esi]
// 0041b011  8b4204               mov eax, dword ptr [edx + 4]
// 0041b014  8bce                 mov ecx, esi
// 0041b016  ffd0                 call eax
// 0041b018  8d4e08               lea ecx, [esi + 8]
// 0041b01b  83caff               or edx, 0xffffffff
// 0041b01e  f00fc111             lock xadd dword ptr [ecx], edx
// 0041b022  7509                 jne 0x41b02d
// 0041b024  8b06                 mov eax, dword ptr [esi]
// 0041b026  8b5008               mov edx, dword ptr [eax + 8]
// 0041b029  8bce                 mov ecx, esi
// 0041b02b  ffd2                 call edx
// 0041b02d  8bcf                 mov ecx, edi
// 0041b02f  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0041b037  e8f4503300           call 0x750130
// 0041b03c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041b040  5f                   pop edi
// 0041b041  5e                   pop esi
// 0041b042  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b049  83c410               add esp, 0x10
// 0041b04c  c3                   ret 
// copied from an identical function in another client (function ??1CInstanceExplorer@ns_ROCX00005e@@UAE@XZ)

namespace ns_ROCX00005e {
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
