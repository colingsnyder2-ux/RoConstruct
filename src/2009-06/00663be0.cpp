// from server: 100% by EspClaude
// roc 2009-06 00663be0  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663be0
//
// 00663be0  8b442408             mov eax, dword ptr [esp + 8]
// 00663be4  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00663be8  53                   push ebx
// 00663be9  56                   push esi
// 00663bea  8bd9                 mov ebx, ecx
// 00663bec  7205                 jb 0x663bf3
// 00663bee  8b7004               mov esi, dword ptr [eax + 4]
// 00663bf1  eb03                 jmp 0x663bf6
// 00663bf3  8d7004               lea esi, [eax + 4]
// 00663bf6  57                   push edi
// 00663bf7  6800f75e00           push 0x5ef700
// 00663bfc  68eca4a400           push 0xa4a4ec
// 00663c01  e80adbd9ff           call 0x401710
// 00663c06  83c408               add esp, 8
// 00663c09  e892baf8ff           call 0x5ef6a0
// 00663c0e  8bf8                 mov edi, eax
// 00663c10  8d442414             lea eax, [esp + 0x14]
// 00663c14  50                   push eax
// 00663c15  56                   push esi
// 00663c16  e8659df6ff           call 0x5cd980
// 00663c1b  83c404               add esp, 4
// 00663c1e  50                   push eax
// 00663c1f  8bcf                 mov ecx, edi
// 00663c21  e82aa9f8ff           call 0x5ee550
// 00663c26  5f                   pop edi
// 00663c27  84c0                 test al, al
// 00663c29  741b                 je 0x663c46
// 00663c2b  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 00663c2e  8b11                 mov edx, dword ptr [ecx]
// 00663c30  8b520c               mov edx, dword ptr [edx + 0xc]
// 00663c33  8d442410             lea eax, [esp + 0x10]
// 00663c37  50                   push eax
// 00663c38  8b442410             mov eax, dword ptr [esp + 0x10]
// 00663c3c  50                   push eax
// 00663c3d  ffd2                 call edx
// 00663c3f  5e                   pop esi
// 00663c40  b001                 mov al, 1
// 00663c42  5b                   pop ebx
// 00663c43  c20800               ret 8
// 00663c46  5e                   pop esi
// 00663c47  32c0                 xor al, al
// 00663c49  5b                   pop ebx
// 00663c4a  c20800               ret 8
// copied from an identical function in another client (function ?setString@Descriptor@ns_ROCX000015@@QAE_NPAXABUText@2@@Z)

namespace ns_ROCX000015 {
struct Text {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

struct EnumTable {
    bool lookup(unsigned int key, int* value);
};

struct Setter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(void* instance, const int* value) = 0;
};

extern unsigned char registrationState;
extern void __cdecl initialize();
extern void __cdecl registerInitializer(void (__cdecl* callback)(), void* state);
extern EnumTable* __cdecl getEnumTable();
extern unsigned int __cdecl stringKey(const char* text);

struct Descriptor {
    unsigned char padding[28];
    Setter* setter;

    bool setString(void* instance, const Text& text);
};

bool Descriptor::setString(void* instance, const Text& text)
{
    const char* characters =
        text.capacity >= 16 ? text.pointer : text.buffer;

    registerInitializer(initialize, &registrationState);
    EnumTable* table = getEnumTable();

    int value;
    if (table->lookup(stringKey(characters), &value)) {
        setter->set(instance, &value);
        return true;
    }
    return false;
}
}
