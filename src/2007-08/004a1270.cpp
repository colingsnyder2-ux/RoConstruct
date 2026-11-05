// from server: 100% by colin
// roc 2007-08 004a1270  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a1270
//
// 004a1270  55                   push ebp
// 004a1271  8b6c2408             mov ebp, dword ptr [esp + 8]
// 004a1275  3b6c240c             cmp ebp, dword ptr [esp + 0xc]
// 004a1279  746d                 je 0x4a12e8
// 004a127b  53                   push ebx
// 004a127c  56                   push esi
// 004a127d  57                   push edi
// 004a127e  8d7d08               lea edi, [ebp + 8]
// 004a1281  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a1285  8b08                 mov ecx, dword ptr [eax]
// 004a1287  894d00               mov dword ptr [ebp], ecx
// 004a128a  8b5004               mov edx, dword ptr [eax + 4]
// 004a128d  8957fc               mov dword ptr [edi - 4], edx
// 004a1290  8b5808               mov ebx, dword ptr [eax + 8]
// 004a1293  3b1f                 cmp ebx, dword ptr [edi]
// 004a1295  7442                 je 0x4a12d9
// 004a1297  85db                 test ebx, ebx
// 004a1299  740c                 je 0x4a12a7
// 004a129b  8d4304               lea eax, [ebx + 4]
// 004a129e  b901000000           mov ecx, 1
// 004a12a3  f00fc108             lock xadd dword ptr [eax], ecx
// 004a12a7  8b37                 mov esi, dword ptr [edi]
// 004a12a9  85f6                 test esi, esi
// 004a12ab  742a                 je 0x4a12d7
// 004a12ad  8d5604               lea edx, [esi + 4]
// 004a12b0  83c8ff               or eax, 0xffffffff
// 004a12b3  f00fc102             lock xadd dword ptr [edx], eax
// 004a12b7  751e                 jne 0x4a12d7
// 004a12b9  8b16                 mov edx, dword ptr [esi]
// 004a12bb  8b4204               mov eax, dword ptr [edx + 4]
// 004a12be  8bce                 mov ecx, esi
// 004a12c0  ffd0                 call eax
// 004a12c2  8d4e08               lea ecx, [esi + 8]
// 004a12c5  83caff               or edx, 0xffffffff
// 004a12c8  f00fc111             lock xadd dword ptr [ecx], edx
// 004a12cc  7509                 jne 0x4a12d7
// 004a12ce  8b06                 mov eax, dword ptr [esi]
// 004a12d0  8b5008               mov edx, dword ptr [eax + 8]
// 004a12d3  8bce                 mov ecx, esi
// 004a12d5  ffd2                 call edx
// 004a12d7  891f                 mov dword ptr [edi], ebx
// 004a12d9  83c50c               add ebp, 0xc
// 004a12dc  83c70c               add edi, 0xc
// 004a12df  3b6c2418             cmp ebp, dword ptr [esp + 0x18]
// 004a12e3  759c                 jne 0x4a1281
// 004a12e5  5f                   pop edi
// 004a12e6  5e                   pop esi
// 004a12e7  5b                   pop ebx
// 004a12e8  5d                   pop ebp
// 004a12e9  c3                   ret 
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