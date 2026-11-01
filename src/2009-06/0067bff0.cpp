// from server: 100% by EspClaude
// roc 2009-06 0067bff0  unit: RBX::JointInstance  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067bff0
//
// 0067bff0  56                   push esi
// 0067bff1  8b742408             mov esi, dword ptr [esp + 8]
// 0067bff5  57                   push edi
// 0067bff6  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0067bff9  e8f2e4d8ff           call 0x40a4f0
// 0067bffe  50                   push eax
// 0067bfff  8bcf                 mov ecx, edi
// 0067c001  e86ac9f7ff           call 0x5f8970
// 0067c006  84c0                 test al, al
// 0067c008  751b                 jne 0x67c025
// 0067c00a  8b761c               mov esi, dword ptr [esi + 0x1c]
// 0067c00d  e85ee8f6ff           call 0x5ea870
// 0067c012  50                   push eax
// 0067c013  8bce                 mov ecx, esi
// 0067c015  e856c9f7ff           call 0x5f8970
// 0067c01a  84c0                 test al, al
// 0067c01c  7507                 jne 0x67c025
// 0067c01e  5f                   pop edi
// 0067c01f  33c0                 xor eax, eax
// 0067c021  5e                   pop esi
// 0067c022  c20400               ret 4
// 0067c025  5f                   pop edi
// 0067c026  b801000000           mov eax, 1
// 0067c02b  5e                   pop esi
// 0067c02c  c20400               ret 4
// copied from an identical function in another client (function ?matches@ns_ROCX000007@@YGHPAUObject@1@@Z)

namespace ns_ROCX000007 {
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
}
