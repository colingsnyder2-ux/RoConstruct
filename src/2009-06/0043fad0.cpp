// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063b210  unit: RBX::Reflection::Metadata::VClass::?$BoundPropGetSet  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063b210
//
// 0063b210  8b442404             mov eax, dword ptr [esp + 4]
// 0063b214  56                   push esi
// 0063b215  57                   push edi
// 0063b216  8bf1                 mov esi, ecx
// 0063b218  85c0                 test eax, eax
// 0063b21a  7405                 je 0x63b221
// 0063b21c  8d78ec               lea edi, [eax - 0x14]
// 0063b21f  eb02                 jmp 0x63b223
// 0063b221  33ff                 xor edi, edi
// 0063b223  8b4608               mov eax, dword ptr [esi + 8]
// 0063b226  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063b22a  8b09                 mov ecx, dword ptr [ecx]
// 0063b22c  03c7                 add eax, edi
// 0063b22e  3908                 cmp dword ptr [eax], ecx
// 0063b230  741f                 je 0x63b251
// 0063b232  8908                 mov dword ptr [eax], ecx
// 0063b234  8b4610               mov eax, dword ptr [esi + 0x10]
// 0063b237  85c0                 test eax, eax
// 0063b239  740b                 je 0x63b246
// 0063b23b  8b5604               mov edx, dword ptr [esi + 4]
// 0063b23e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0063b241  52                   push edx
// 0063b242  03cf                 add ecx, edi
// 0063b244  ffd0                 call eax
// 0063b246  8b4604               mov eax, dword ptr [esi + 4]
// 0063b249  50                   push eax
// 0063b24a  8bcf                 mov ecx, edi
// 0063b24c  e8af28ddff           call 0x40db00
// 0063b251  5f                   pop edi
// 0063b252  5e                   pop esi
// 0063b253  c20800               ret 8

struct Object {
    void notify(void* property);
};

typedef void (__thiscall *Callback)(void* object, void* property);

struct S {
    int unknown0;
    void* property;
    int valueOffset;
    int unknown12;
    Callback callback;
    int callbackAdjustment;

    void set(void* object, const int& value);
};

void S::set(void* object, const int& value)
{
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    int* destination = reinterpret_cast<int*>(base + valueOffset);

    if (*destination != value) {
        *destination = value;
        if (callback)
            callback(base + callbackAdjustment, property);
        reinterpret_cast<Object*>(base)->notify(property);
    }
}
