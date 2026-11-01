// from server: 100% by colin
// roc 2007-03 00499000  unit: seg_00490000  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00499000
//
// 00499000  55                   push ebp
// 00499001  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00499005  3b6c240c             cmp ebp, dword ptr [esp + 0xc]
// 00499009  746d                 je 0x499078
// 0049900b  53                   push ebx
// 0049900c  56                   push esi
// 0049900d  57                   push edi
// 0049900e  8d7d08               lea edi, [ebp + 8]
// 00499011  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00499015  8b08                 mov ecx, dword ptr [eax]
// 00499017  894d00               mov dword ptr [ebp], ecx
// 0049901a  8b5004               mov edx, dword ptr [eax + 4]
// 0049901d  8957fc               mov dword ptr [edi - 4], edx
// 00499020  8b5808               mov ebx, dword ptr [eax + 8]
// 00499023  3b1f                 cmp ebx, dword ptr [edi]
// 00499025  7442                 je 0x499069
// 00499027  85db                 test ebx, ebx
// 00499029  740c                 je 0x499037
// 0049902b  8d4304               lea eax, [ebx + 4]
// 0049902e  b901000000           mov ecx, 1
// 00499033  f00fc108             lock xadd dword ptr [eax], ecx
// 00499037  8b37                 mov esi, dword ptr [edi]
// 00499039  85f6                 test esi, esi
// 0049903b  742a                 je 0x499067
// 0049903d  8d5604               lea edx, [esi + 4]
// 00499040  83c8ff               or eax, 0xffffffff
// 00499043  f00fc102             lock xadd dword ptr [edx], eax
// 00499047  751e                 jne 0x499067
// 00499049  8b16                 mov edx, dword ptr [esi]
// 0049904b  8b4204               mov eax, dword ptr [edx + 4]
// 0049904e  8bce                 mov ecx, esi
// 00499050  ffd0                 call eax
// 00499052  8d4e08               lea ecx, [esi + 8]
// 00499055  83caff               or edx, 0xffffffff
// 00499058  f00fc111             lock xadd dword ptr [ecx], edx
// 0049905c  7509                 jne 0x499067
// 0049905e  8b06                 mov eax, dword ptr [esi]
// 00499060  8b5008               mov edx, dword ptr [eax + 8]
// 00499063  8bce                 mov ecx, esi
// 00499065  ffd2                 call edx
// 00499067  891f                 mov dword ptr [edi], ebx
// 00499069  83c50c               add ebp, 0xc
// 0049906c  83c70c               add edi, 0xc
// 0049906f  3b6c2418             cmp ebp, dword ptr [esp + 0x18]
// 00499073  759c                 jne 0x499011
// 00499075  5f                   pop edi
// 00499076  5e                   pop esi
// 00499077  5b                   pop ebx
// 00499078  5d                   pop ebp
// 00499079  c3                   ret 
// copied from an identical function in another client (function ?fill@@YAXPAURecord@@0ABU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Record {
    unsigned long first;
    unsigned long second;
    Control* control;
};

void __cdecl fill(Record* first, Record* last, const Record& value)
{
    if (first != last) {
        Control** slot = &first->control;
        do {
            first->first = value.first;
            reinterpret_cast<unsigned long*>(slot)[-1] = value.second;

            Control* incoming = value.control;
            if (incoming != *slot) {
                if (incoming)
                    _InterlockedIncrement(&incoming->strong);

                Control* outgoing = *slot;
                if (outgoing) {
                    if (_InterlockedDecrement(&outgoing->strong) == 0) {
                        outgoing->dispose();
                        if (_InterlockedDecrement(&outgoing->weak) == 0)
                            outgoing->destroy();
                    }
                }
                *slot = incoming;
            }

            ++first;
            slot += 3;
        } while (first != last);
    }
}