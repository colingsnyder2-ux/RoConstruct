// from server: 100% by EspClaude
// roc 2009-06 00664140  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664140
//
// 00664140  8b442408             mov eax, dword ptr [esp + 8]
// 00664144  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00664148  53                   push ebx
// 00664149  56                   push esi
// 0066414a  8bd9                 mov ebx, ecx
// 0066414c  7205                 jb 0x664153
// 0066414e  8b7004               mov esi, dword ptr [eax + 4]
// 00664151  eb03                 jmp 0x664156
// 00664153  8d7004               lea esi, [eax + 4]
// 00664156  57                   push edi
// 00664157  6830f25e00           push 0x5ef230
// 0066415c  68c0a4a400           push 0xa4a4c0
// 00664161  e8aad5d9ff           call 0x401710
// 00664166  83c408               add esp, 8
// 00664169  e862b0f8ff           call 0x5ef1d0
// 0066416e  8bf8                 mov edi, eax
// 00664170  8d442414             lea eax, [esp + 0x14]
// 00664174  50                   push eax
// 00664175  56                   push esi
// 00664176  e80598f6ff           call 0x5cd980
// 0066417b  83c404               add esp, 4
// 0066417e  50                   push eax
// 0066417f  8bcf                 mov ecx, edi
// 00664181  e8caa3f8ff           call 0x5ee550
// 00664186  5f                   pop edi
// 00664187  84c0                 test al, al
// 00664189  741b                 je 0x6641a6
// 0066418b  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 0066418e  8b11                 mov edx, dword ptr [ecx]
// 00664190  8b520c               mov edx, dword ptr [edx + 0xc]
// 00664193  8d442410             lea eax, [esp + 0x10]
// 00664197  50                   push eax
// 00664198  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066419c  50                   push eax
// 0066419d  ffd2                 call edx
// 0066419f  5e                   pop esi
// 006641a0  b001                 mov al, 1
// 006641a2  5b                   pop ebx
// 006641a3  c20800               ret 8
// 006641a6  5e                   pop esi
// 006641a7  32c0                 xor al, al
// 006641a9  5b                   pop ebx
// 006641aa  c20800               ret 8
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
