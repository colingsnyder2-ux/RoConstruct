// from server: 100% by EspClaude
// from server: 94% by colin
// roc 2008-06 0063b260  unit: RBX::N$1?sDoubleValue::V?$Value::?$BoundPropGetSet  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063b260
//
// 0063b260  8b442404             mov eax, dword ptr [esp + 4]
// 0063b264  56                   push esi
// 0063b265  57                   push edi
// 0063b266  8bf1                 mov esi, ecx
// 0063b268  85c0                 test eax, eax
// 0063b26a  7405                 je 0x63b271
// 0063b26c  8d78ec               lea edi, [eax - 0x14]
// 0063b26f  eb02                 jmp 0x63b273
// 0063b271  33ff                 xor edi, edi
// 0063b273  8b4608               mov eax, dword ptr [esi + 8]
// 0063b276  8b542410             mov edx, dword ptr [esp + 0x10]
// 0063b27a  dd02                 fld qword ptr [edx]
// 0063b27c  8d0c38               lea ecx, [eax + edi]
// 0063b27f  dc19                 fcomp qword ptr [ecx]
// 0063b281  dfe0                 fnstsw ax
// 0063b283  f6c444               test ah, 0x44
// 0063b286  7b21                 jnp 0x63b2a9
// 0063b288  dd02                 fld qword ptr [edx]
// 0063b28a  dd19                 fstp qword ptr [ecx]
// 0063b28c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0063b28f  85c0                 test eax, eax
// 0063b291  740b                 je 0x63b29e
// 0063b293  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063b296  51                   push ecx
// 0063b297  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0063b29a  03cf                 add ecx, edi
// 0063b29c  ffd0                 call eax
// 0063b29e  8b5604               mov edx, dword ptr [esi + 4]
// 0063b2a1  52                   push edx
// 0063b2a2  8bcf                 mov ecx, edi
// 0063b2a4  e85728ddff           call 0x40db00
// 0063b2a9  5f                   pop edi
// 0063b2aa  5e                   pop esi
// 0063b2ab  c20800               ret 8

// from server: 91% by colin
// roc 2008-06 0063b260  unit: RBX::N$1?sDoubleValue::V?$Value::?$BoundPropGetSet  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063b260
//
// 0063b260  8b442404             mov eax, dword ptr [esp + 4]
// 0063b264  56                   push esi
// 0063b265  57                   push edi
// 0063b266  8bf1                 mov esi, ecx
// 0063b268  85c0                 test eax, eax
// 0063b26a  7405                 je 0x63b271
// 0063b26c  8d78ec               lea edi, [eax - 0x14]
// 0063b26f  eb02                 jmp 0x63b273
// 0063b271  33ff                 xor edi, edi
// 0063b273  8b4608               mov eax, dword ptr [esi + 8]
// 0063b276  8b542410             mov edx, dword ptr [esp + 0x10]
// 0063b27a  dd02                 fld qword ptr [edx]
// 0063b27c  8d0c38               lea ecx, [eax + edi]
// 0063b27f  dc19                 fcomp qword ptr [ecx]
// 0063b281  dfe0                 fnstsw ax
// 0063b283  f6c444               test ah, 0x44
// 0063b286  7b21                 jnp 0x63b2a9
// 0063b288  dd02                 fld qword ptr [edx]
// 0063b28a  dd19                 fstp qword ptr [ecx]
// 0063b28c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0063b28f  85c0                 test eax, eax
// 0063b291  740b                 je 0x63b29e
// 0063b293  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063b296  51                   push ecx
// 0063b297  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0063b29a  03cf                 add ecx, edi
// 0063b29c  ffd0                 call eax
// 0063b29e  8b5604               mov edx, dword ptr [esi + 4]
// 0063b2a1  52                   push edx
// 0063b2a2  8bcf                 mov ecx, edi
// 0063b2a4  e85728ddff           call 0x40db00
// 0063b2a9  5f                   pop edi
// 0063b2aa  5e                   pop esi
// 0063b2ab  c20800               ret 8

struct Owner;
typedef double Owner::* Member;
typedef void (Owner::* Handler)(int);
struct __multiple_inheritance Owner;
struct OwnerA { int a; };
struct OwnerB { int b; };
struct Owner : OwnerA, OwnerB { void changed(int); };
struct S {
    char pad0[4];
    int field4;
    Member member;
    char padC[4];
    Handler handler;
    void set(void* object, double* value);
};
void S::set(void* object, double* value)
{
    Owner* base = object ? reinterpret_cast<Owner*>(static_cast<char*>(object) - 20) : 0;
    if (base->*member != *value) {
        base->*member = *value;
        if (handler)
            (base->*handler)(field4);
        base->changed(field4);
    }
}
