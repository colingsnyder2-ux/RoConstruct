// from server: 100% by EspClaude
// roc 2009-06 00626690  unit: RBX::VNetworkSettings::?$EnumPropDescriptor  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00626690
//
// 00626690  8b442408             mov eax, dword ptr [esp + 8]
// 00626694  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00626698  57                   push edi
// 00626699  8bf9                 mov edi, ecx
// 0062669b  7205                 jb 0x6266a2
// 0062669d  8b4004               mov eax, dword ptr [eax + 4]
// 006266a0  eb03                 jmp 0x6266a5
// 006266a2  83c004               add eax, 4
// 006266a5  56                   push esi
// 006266a6  8b7720               mov esi, dword ptr [edi + 0x20]
// 006266a9  8d4c2410             lea ecx, [esp + 0x10]
// 006266ad  51                   push ecx
// 006266ae  50                   push eax
// 006266af  e8cc72faff           call 0x5cd980
// 006266b4  83c404               add esp, 4
// 006266b7  50                   push eax
// 006266b8  8bce                 mov ecx, esi
// 006266ba  e8917efcff           call 0x5ee550
// 006266bf  5e                   pop esi
// 006266c0  84c0                 test al, al
// 006266c2  7422                 je 0x6266e6
// 006266c4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006266c8  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 006266cb  8954240c             mov dword ptr [esp + 0xc], edx
// 006266cf  8b01                 mov eax, dword ptr [ecx]
// 006266d1  8b400c               mov eax, dword ptr [eax + 0xc]
// 006266d4  8d54240c             lea edx, [esp + 0xc]
// 006266d8  52                   push edx
// 006266d9  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006266dd  52                   push edx
// 006266de  ffd0                 call eax
// 006266e0  b001                 mov al, 1
// 006266e2  5f                   pop edi
// 006266e3  c20800               ret 8
// 006266e6  32c0                 xor al, al
// 006266e8  5f                   pop edi
// 006266e9  c20800               ret 8
// copied from an identical function in another client (function ?setString@S@ns_ROCX000019@@QAE_NPAXABUString@2@@Z)

namespace ns_ROCX000019 {
struct String {
    unsigned int pad;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct Name;
extern const Name& __cdecl getName(const char*);

struct EnumDescriptor {
    bool lookup(const Name&, int&);
};

enum Value {
    ValueZero = 0
};

struct Property {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, const Value&);
};

struct S {
    char padding[0x1c];
    Property* property;
    EnumDescriptor* enumeration;

    bool setString(void*, const String&);
};

bool S::setString(void* object, const String& text)
{
    const char* characters =
        text.capacity >= 16 ? text.storage.pointer : text.storage.buffer;
    EnumDescriptor* descriptor = enumeration;
    int value;
    if (descriptor->lookup(getName(characters), value)) {
        reinterpret_cast<volatile int&>(value) = value;
        property->set(object, reinterpret_cast<const Value&>(value));
        return true;
    }
    return false;
}
}
