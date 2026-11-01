// from server: 100% by Espeon
// from server: 98% by colin
// roc 2008-06 005bd680  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd680
//
// 005bd680  8b442404             mov eax, dword ptr [esp + 4]
// 005bd684  56                   push esi
// 005bd685  57                   push edi
// 005bd686  8bf1                 mov esi, ecx
// 005bd688  85c0                 test eax, eax
// 005bd68a  7405                 je 0x5bd691
// 005bd68c  8d78ec               lea edi, [eax - 0x14]
// 005bd68f  eb02                 jmp 0x5bd693
// 005bd691  33ff                 xor edi, edi
// 005bd693  8b4608               mov eax, dword ptr [esi + 8]
// 005bd696  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bd69a  d902                 fld dword ptr [edx]
// 005bd69c  8d0c38               lea ecx, [eax + edi]
// 005bd69f  d819                 fcomp dword ptr [ecx]
// 005bd6a1  dfe0                 fnstsw ax
// 005bd6a3  f6c444               test ah, 0x44
// 005bd6a6  7b21                 jnp 0x5bd6c9
// 005bd6a8  d902                 fld dword ptr [edx]
// 005bd6aa  d919                 fstp dword ptr [ecx]
// 005bd6ac  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bd6af  85c0                 test eax, eax
// 005bd6b1  740b                 je 0x5bd6be
// 005bd6b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005bd6b6  51                   push ecx
// 005bd6b7  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bd6ba  03cf                 add ecx, edi
// 005bd6bc  ffd0                 call eax
// 005bd6be  8b5604               mov edx, dword ptr [esi + 4]
// 005bd6c1  52                   push edx
// 005bd6c2  8bcf                 mov ecx, edi
// 005bd6c4  e83704e5ff           call 0x40db00
// 005bd6c9  5f                   pop edi
// 005bd6ca  5e                   pop esi
// 005bd6cb  c20800               ret 8

// from server: 94% by king_originala
// roc 2008-06 005bd680  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bd680
//
// 005bd680  8b442404             mov eax, dword ptr [esp + 4]
// 005bd684  56                   push esi
// 005bd685  57                   push edi
// 005bd686  8bf1                 mov esi, ecx
// 005bd688  85c0                 test eax, eax
// 005bd68a  7405                 je 0x5bd691
// 005bd68c  8d78ec               lea edi, [eax - 0x14]
// 005bd68f  eb02                 jmp 0x5bd693
// 005bd691  33ff                 xor edi, edi
// 005bd693  8b4608               mov eax, dword ptr [esi + 8]
// 005bd696  8b542410             mov edx, dword ptr [esp + 0x10]
// 005bd69a  d902                 fld dword ptr [edx]
// 005bd69c  8d0c38               lea ecx, [eax + edi]
// 005bd69f  d819                 fcomp dword ptr [ecx]
// 005bd6a1  dfe0                 fnstsw ax
// 005bd6a3  f6c444               test ah, 0x44
// 005bd6a6  7b21                 jnp 0x5bd6c9
// 005bd6a8  d902                 fld dword ptr [edx]
// 005bd6aa  d919                 fstp dword ptr [ecx]
// 005bd6ac  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bd6af  85c0                 test eax, eax
// 005bd6b1  740b                 je 0x5bd6be
// 005bd6b3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005bd6b6  51                   push ecx
// 005bd6b7  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005bd6ba  03cf                 add ecx, edi
// 005bd6bc  ffd0                 call eax
// 005bd6be  8b5604               mov edx, dword ptr [esi + 4]
// 005bd6c1  52                   push edx
// 005bd6c2  8bcf                 mov ecx, edi
// 005bd6c4  e83704e5ff           call 0x40db00
// 005bd6c9  5f                   pop edi
// 005bd6ca  5e                   pop esi
// 005bd6cb  c20800               ret 8

struct Prefix {
    char padding[20];
};

struct Interface {
    char padding[4];
};

struct Object : Prefix, Interface {
    void notify(void* property);
};

struct BoundProp {
    void* vtable;
    void* property;
    float Object::* offset;
    int unused;
    void (Object::*changed)(void*);

    void set(Interface* instance, const float& value) const;
};

#pragma float_control(precise, off, push)

void BoundProp::set(Interface* instance, const float& value) const
{
    Object* object = instance ? static_cast<Object*>(instance) : 0;

    if (object->*offset != value) {
        object->*offset = value;
        if (changed)
            (object->*changed)(property);
        object->notify(property);
    }
}

#pragma float_control(pop)
