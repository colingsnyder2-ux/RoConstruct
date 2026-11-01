// from server: 100% by colin
// roc 2007-08 0061dd30  unit: RBX::ScoreHud  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061dd30
//
// 0061dd30  56                   push esi
// 0061dd31  8b742410             mov esi, dword ptr [esp + 0x10]
// 0061dd35  85f6                 test esi, esi
// 0061dd37  742a                 je 0x61dd63
// 0061dd39  8d4604               lea eax, [esi + 4]
// 0061dd3c  83c9ff               or ecx, 0xffffffff
// 0061dd3f  f00fc108             lock xadd dword ptr [eax], ecx
// 0061dd43  751e                 jne 0x61dd63
// 0061dd45  8b16                 mov edx, dword ptr [esi]
// 0061dd47  8b4204               mov eax, dword ptr [edx + 4]
// 0061dd4a  8bce                 mov ecx, esi
// 0061dd4c  ffd0                 call eax
// 0061dd4e  8d4e08               lea ecx, [esi + 8]
// 0061dd51  83caff               or edx, 0xffffffff
// 0061dd54  f00fc111             lock xadd dword ptr [ecx], edx
// 0061dd58  7509                 jne 0x61dd63
// 0061dd5a  8b06                 mov eax, dword ptr [esi]
// 0061dd5c  8b5008               mov edx, dword ptr [eax + 8]
// 0061dd5f  8bce                 mov ecx, esi
// 0061dd61  ffd2                 call edx
// 0061dd63  5e                   pop esi
// 0061dd64  c20c00               ret 0xc
// copied from an identical function in another client (function ?release@@YGXPAX0PAUControl@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

void __stdcall release(void*, void*, Control* control)
{
    if (control) {
        if (_InterlockedDecrement(&control->strong) == 0) {
            control->dispose();
            if (_InterlockedDecrement(&control->weak) == 0)
                control->destroy();
        }
    }
}