// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00449270  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449270
//
// 00449270  8b442404             mov eax, dword ptr [esp + 4]
// 00449274  53                   push ebx
// 00449275  56                   push esi
// 00449276  57                   push edi
// 00449277  8bf1                 mov esi, ecx
// 00449279  85c0                 test eax, eax
// 0044927b  7405                 je 0x449282
// 0044927d  8d78ec               lea edi, [eax - 0x14]
// 00449280  eb02                 jmp 0x449284
// 00449282  33ff                 xor edi, edi
// 00449284  8b4608               mov eax, dword ptr [esi + 8]
// 00449287  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0044928b  03c7                 add eax, edi
// 0044928d  53                   push ebx
// 0044928e  50                   push eax
// 0044928f  ff15d8238000         call dword ptr [0x8023d8]
// 00449295  83c408               add esp, 8
// 00449298  84c0                 test al, al
// 0044929a  7429                 je 0x4492c5
// 0044929c  8b4e08               mov ecx, dword ptr [esi + 8]
// 0044929f  53                   push ebx
// 004492a0  03cf                 add ecx, edi
// 004492a2  ff150c248000         call dword ptr [0x80240c]
// 004492a8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004492ab  85c0                 test eax, eax
// 004492ad  740b                 je 0x4492ba
// 004492af  8b4e04               mov ecx, dword ptr [esi + 4]
// 004492b2  51                   push ecx
// 004492b3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004492b6  03cf                 add ecx, edi
// 004492b8  ffd0                 call eax
// 004492ba  8b5604               mov edx, dword ptr [esi + 4]
// 004492bd  52                   push edx
// 004492be  8bcf                 mov ecx, edi
// 004492c0  e83b48fcff           call 0x40db00
// 004492c5  5f                   pop edi
// 004492c6  5e                   pop esi
// 004492c7  5b                   pop ebx
// 004492c8  c20800               ret 8

struct String {};

extern bool (__cdecl *stringNotEqual)(const String&, const String&);
extern String& (__thiscall *stringAssign)(String*, const String&);

struct Object {
    void changed(void*);
};

struct Property {
    int reserved;
    void* descriptor;
    int valueOffset;
    int unused;
    void (__thiscall *notify)(void*, void*);
    int notifyOffset;

    void set(void* instance, const String& value);
};

void Property::set(void* instance, const String& value)
{
    Object* object = instance
        ? reinterpret_cast<Object*>(static_cast<char*>(instance) - 20)
        : 0;

    if (stringNotEqual(
            *reinterpret_cast<String*>(
                reinterpret_cast<char*>(object) + valueOffset),
            value)) {
        stringAssign(
            reinterpret_cast<String*>(
                reinterpret_cast<char*>(object) + valueOffset),
            value);

        if (notify)
            notify(reinterpret_cast<char*>(object) + notifyOffset,
                   descriptor);

        object->changed(descriptor);
    }
}
