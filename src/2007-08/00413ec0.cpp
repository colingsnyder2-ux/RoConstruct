// from server: 100% by EspClaude
// from server: 80% by colin
// roc 2007-08 00413ec0  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413ec0
//
// 00413ec0  8b442404             mov eax, dword ptr [esp + 4]
// 00413ec4  56                   push esi
// 00413ec5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00413ec9  85f6                 test esi, esi
// 00413ecb  57                   push edi
// 00413ecc  8bf9                 mov edi, ecx
// 00413ece  8907                 mov dword ptr [edi], eax
// 00413ed0  897704               mov dword ptr [edi + 4], esi
// 00413ed3  740c                 je 0x413ee1
// 00413ed5  8d4e04               lea ecx, [esi + 4]
// 00413ed8  ba01000000           mov edx, 1
// 00413edd  f00fc111             lock xadd dword ptr [ecx], edx
// 00413ee1  85f6                 test esi, esi
// 00413ee3  8b442414             mov eax, dword ptr [esp + 0x14]
// 00413ee7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00413eeb  894708               mov dword ptr [edi + 8], eax
// 00413eee  894f0c               mov dword ptr [edi + 0xc], ecx
// 00413ef1  742a                 je 0x413f1d
// 00413ef3  8d5604               lea edx, [esi + 4]
// 00413ef6  83c8ff               or eax, 0xffffffff
// 00413ef9  f00fc102             lock xadd dword ptr [edx], eax
// 00413efd  751e                 jne 0x413f1d
// 00413eff  8b16                 mov edx, dword ptr [esi]
// 00413f01  8b4204               mov eax, dword ptr [edx + 4]
// 00413f04  8bce                 mov ecx, esi
// 00413f06  ffd0                 call eax
// 00413f08  8d4e08               lea ecx, [esi + 8]
// 00413f0b  83caff               or edx, 0xffffffff
// 00413f0e  f00fc111             lock xadd dword ptr [ecx], edx
// 00413f12  7509                 jne 0x413f1d
// 00413f14  8b06                 mov eax, dword ptr [esi]
// 00413f16  8b5008               mov edx, dword ptr [eax + 8]
// 00413f19  8bce                 mov ecx, esi
// 00413f1b  ffd2                 call edx
// 00413f1d  8bc7                 mov eax, edi
// 00413f1f  5f                   pop edi
// 00413f20  5e                   pop esi
// 00413f21  c21000               ret 0x10

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct S {
    void* p0;
    void* p4;
    int p8;
    int pC;
    S* assign(void* a, void* b, int c, int d);
};

S* S::assign(void* a, void* b, int c, int d)
{
    p0 = a;
    p4 = b;
    if (b != 0) {
        _InterlockedIncrement((volatile long*)((char*)b + 4));
    }
    p8 = c;
    pC = d;
    if (b != 0) {
        if (_InterlockedDecrement((volatile long*)((char*)b + 4)) == 0) {
            void** vt = *(void***)b;
            ((void (__thiscall*)(void*))vt[1])(b);
            if (_InterlockedDecrement((volatile long*)((char*)b + 8)) == 0) {
                void** vt2 = *(void***)b;
                ((void (__thiscall*)(void*))vt2[2])(b);
            }
        }
    }
    return this;
}
