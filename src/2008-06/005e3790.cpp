// from server: 100% by Espeon
// from server: 79% by colin
// roc 2008-06 005e3790  unit: RBX::JointInstance  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e3790
//
// 005e3790  56                   push esi
// 005e3791  8b742408             mov esi, dword ptr [esp + 8]
// 005e3795  57                   push edi
// 005e3796  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 005e3799  e8e275e2ff           call 0x40ad80
// 005e379e  50                   push eax
// 005e379f  8bcf                 mov ecx, edi
// 005e37a1  e86ac6f8ff           call 0x56fe10
// 005e37a6  84c0                 test al, al
// 005e37a8  751b                 jne 0x5e37c5
// 005e37aa  8b761c               mov esi, dword ptr [esi + 0x1c]
// 005e37ad  e83e90fbff           call 0x59c7f0
// 005e37b2  50                   push eax
// 005e37b3  8bce                 mov ecx, esi
// 005e37b5  e856c6f8ff           call 0x56fe10
// 005e37ba  84c0                 test al, al
// 005e37bc  7507                 jne 0x5e37c5
// 005e37be  5f                   pop edi
// 005e37bf  33c0                 xor eax, eax
// 005e37c1  5e                   pop esi
// 005e37c2  c20400               ret 4
// 005e37c5  5f                   pop edi
// 005e37c6  b801000000           mov eax, 1
// 005e37cb  5e                   pop esi
// 005e37cc  c20400               ret 4

struct Descriptor {
    bool equals(const Descriptor& other) const;
};

const Descriptor& __cdecl firstDescriptor();
const Descriptor& __cdecl secondDescriptor();

struct Object {
    char padding[28];
    Descriptor* descriptor;
};

int __stdcall matches(Object* object)
{
    Descriptor* d = object->descriptor;
    if (!d->equals(firstDescriptor())) {
        d=object->descriptor;
        if (!d->equals(secondDescriptor())) return 0;
    }
    return 1;
}
