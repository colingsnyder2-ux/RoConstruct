// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0063dd00  unit: VAuthoringSettings::?$BoundPropGetSet  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063dd00
//
// 0063dd00  8b442404             mov eax, dword ptr [esp + 4]
// 0063dd04  56                   push esi
// 0063dd05  57                   push edi
// 0063dd06  8bf1                 mov esi, ecx
// 0063dd08  85c0                 test eax, eax
// 0063dd0a  7405                 je 0x63dd11
// 0063dd0c  8d78ec               lea edi, [eax - 0x14]
// 0063dd0f  eb02                 jmp 0x63dd13
// 0063dd11  33ff                 xor edi, edi
// 0063dd13  8b4608               mov eax, dword ptr [esi + 8]
// 0063dd16  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0063dd1a  8a09                 mov cl, byte ptr [ecx]
// 0063dd1c  03c7                 add eax, edi
// 0063dd1e  3808                 cmp byte ptr [eax], cl
// 0063dd20  741f                 je 0x63dd41
// 0063dd22  8808                 mov byte ptr [eax], cl
// 0063dd24  8b4610               mov eax, dword ptr [esi + 0x10]
// 0063dd27  85c0                 test eax, eax
// 0063dd29  740b                 je 0x63dd36
// 0063dd2b  8b5604               mov edx, dword ptr [esi + 4]
// 0063dd2e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0063dd31  52                   push edx
// 0063dd32  03cf                 add ecx, edi
// 0063dd34  ffd0                 call eax
// 0063dd36  8b4604               mov eax, dword ptr [esi + 4]
// 0063dd39  50                   push eax
// 0063dd3a  8bcf                 mov ecx, edi
// 0063dd3c  e8bffddcff           call 0x40db00
// 0063dd41  5f                   pop edi
// 0063dd42  5e                   pop esi
// 0063dd43  c20800               ret 8

struct Base1 {};
struct Base2 {};

struct __multiple_inheritance Object : Base1, Base2
{
    void notify(void* property);
};

struct S
{
    int reserved0;
    void* property;
    int offset;
    int reserved1;
    void (Object::*changed)(void*);

    void setValue(void* instance, const bool& value);
};

void S::setValue(void* instance, const bool& value)
{
    Object* object = instance
        ? reinterpret_cast<Object*>(static_cast<char*>(instance) - 20)
        : 0;

    bool& field = *reinterpret_cast<bool*>(
        reinterpret_cast<char*>(object) + offset);

    if (field != value)
    {
        field = value;
        if (changed)
            (object->*changed)(property);
        object->notify(property);
    }
}
