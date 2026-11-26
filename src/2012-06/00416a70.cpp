// from server: 100% by Xemicl
// roc 2012-06 00416a70  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416a70
//
// 00416a70  83ec14               sub esp, 0x14
// 00416a73  56                   push esi
// 00416a74  e86bb95600           call 0x9823e4
// 00416a79  50                   push eax
// 00416a7a  8d4c240c             lea ecx, [esp + 0xc]
// 00416a7e  e85bb95600           call 0x9823de
// 00416a83  8d442404             lea eax, [esp + 4]
// 00416a87  50                   push eax
// 00416a88  681838b400           push 0xb43818
// 00416a8d  6a17                 push 0x17
// 00416a8f  6a00                 push 0
// 00416a91  685c94b500           push 0xb5945c
// 00416a96  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00416a9e  ff151851b200         call dword ptr [0xb25118]
// 00416aa4  8bf0                 mov esi, eax
// 00416aa6  85f6                 test esi, esi
// 00416aa8  747e                 je 0x416b28
// 00416aaa  8d4c2420             lea ecx, [esp + 0x20]
// 00416aae  ff158447b200         call dword ptr [0xb24784]
// 00416ab4  56                   push esi
// 00416ab5  8d4c2424             lea ecx, [esp + 0x24]
// 00416ab9  686c5eb400           push 0xb45e6c
// 00416abe  51                   push ecx
// 00416abf  ff158847b200         call dword ptr [0xb24788]
// 00416ac5  83c40c               add esp, 0xc
// 00416ac8  56                   push esi
// 00416ac9  8d4c2424             lea ecx, [esp + 0x24]
// 00416acd  ff159847b200         call dword ptr [0xb24798]
// 00416ad3  50                   push eax
// 00416ad4  68bc94b500           push 0xb594bc
// 00416ad9  e862be0100           call 0x432940
// 00416ade  83c40c               add esp, 0xc
// 00416ae1  8d4c2420             lea ecx, [esp + 0x20]
// 00416ae5  8bf0                 mov esi, eax
// 00416ae7  ff15d047b200         call dword ptr [0xb247d0]
// 00416aed  8b442404             mov eax, dword ptr [esp + 4]
// 00416af1  85c0                 test eax, eax
// 00416af3  7408                 je 0x416afd
// 00416af5  8b10                 mov edx, dword ptr [eax]
// 00416af7  50                   push eax
// 00416af8  8b4208               mov eax, dword ptr [edx + 8]
// 00416afb  ffd0                 call eax
// 00416afd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00416b01  85c0                 test eax, eax
// 00416b03  7407                 je 0x416b0c
// 00416b05  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00416b09  894804               mov dword ptr [eax + 4], ecx
// 00416b0c  837c241400           cmp dword ptr [esp + 0x14], 0
// 00416b11  740c                 je 0x416b1f
// 00416b13  8b542410             mov edx, dword ptr [esp + 0x10]
// 00416b17  52                   push edx
// 00416b18  6a00                 push 0
// 00416b1a  e8b9b85600           call 0x9823d8
// 00416b1f  8bc6                 mov eax, esi
// 00416b21  5e                   pop esi
// 00416b22  83c414               add esp, 0x14
// 00416b25  c20800               ret 8
// 00416b28  8b442404             mov eax, dword ptr [esp + 4]
// 00416b2c  8bf0                 mov esi, eax
// 00416b2e  85c0                 test eax, eax
// 00416b30  740c                 je 0x416b3e
// 00416b32  8b08                 mov ecx, dword ptr [eax]
// 00416b34  8b5104               mov edx, dword ptr [ecx + 4]
// 00416b37  50                   push eax
// 00416b38  ffd2                 call edx
// 00416b3a  8b442404             mov eax, dword ptr [esp + 4]
// 00416b3e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00416b42  57                   push edi
// 00416b43  85c9                 test ecx, ecx
// 00416b45  7507                 jne 0x416b4e
// 00416b47  bf03400080           mov edi, 0x80004003
// 00416b4c  eb14                 jmp 0x416b62
// 00416b4e  8931                 mov dword ptr [ecx], esi
// 00416b50  85f6                 test esi, esi
// 00416b52  740c                 je 0x416b60
// 00416b54  8b06                 mov eax, dword ptr [esi]
// 00416b56  8b4804               mov ecx, dword ptr [eax + 4]
// 00416b59  56                   push esi
// 00416b5a  ffd1                 call ecx
// 00416b5c  8b442408             mov eax, dword ptr [esp + 8]
// 00416b60  33ff                 xor edi, edi
// 00416b62  85f6                 test esi, esi
// 00416b64  740c                 je 0x416b72
// 00416b66  8b16                 mov edx, dword ptr [esi]
// 00416b68  8b4208               mov eax, dword ptr [edx + 8]
// 00416b6b  56                   push esi
// 00416b6c  ffd0                 call eax
// 00416b6e  8b442408             mov eax, dword ptr [esp + 8]
// 00416b72  85c0                 test eax, eax
// 00416b74  7408                 je 0x416b7e
// 00416b76  8b08                 mov ecx, dword ptr [eax]
// 00416b78  8b5108               mov edx, dword ptr [ecx + 8]
// 00416b7b  50                   push eax
// 00416b7c  ffd2                 call edx
// 00416b7e  8b442410             mov eax, dword ptr [esp + 0x10]
// 00416b82  85c0                 test eax, eax
// 00416b84  7407                 je 0x416b8d
// 00416b86  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00416b8a  894804               mov dword ptr [eax + 4], ecx
// 00416b8d  837c241800           cmp dword ptr [esp + 0x18], 0
// 00416b92  740c                 je 0x416ba0
// 00416b94  8b542414             mov edx, dword ptr [esp + 0x14]
// 00416b98  52                   push edx
// 00416b99  6a00                 push 0
// 00416b9b  e838b85600           call 0x9823d8
// 00416ba0  8bc7                 mov eax, edi
// 00416ba2  5f                   pop edi
// 00416ba3  5e                   pop esi
// 00416ba4  83c414               add esp, 0x14
// 00416ba7  c20800               ret 8
// copied from an identical function in another client (function ?function@ns_ROCX000010@@YGHPAXPAPAUObject@1@@Z)

namespace ns_ROCX000010 {
struct Link {
    void* unused;
    void* previous;
};

struct State {
    void* previous;
    Link* link;
    void* context;
    int active;

    State(void*);
};

struct Object;

struct ObjectTable {
    int (__stdcall* query)(Object*, const void*, void**);
    unsigned long (__stdcall* addRef)(Object*);
    unsigned long (__stdcall* release)(Object*);
};

struct Object {
    ObjectTable* table;
};

struct String {
    void* data;
};

extern "C" void* __cdecl get_state();
extern "C" void __stdcall release_state(int, void*);
extern "C" int (__stdcall* CoCreateInstance)(
    const void*, Object*, unsigned long, const void*, void**);

extern const unsigned char classId[];
extern const unsigned char interfaceId[];
extern const char errorFormat[];
extern const char logContext[];

extern void (__thiscall* constructString)(String*);
extern void (__cdecl* formatString)(String*, const char*, ...);
extern const char* (__thiscall* stringText)(String*);
extern void (__thiscall* destroyString)(String*);

extern void __cdecl logMessage(int, int, int);

int __stdcall function(void*, Object** output)
{
    State state(get_state());
    Object* object = 0;

    int result = CoCreateInstance(
        classId, 0, 23, interfaceId, reinterpret_cast<void**>(&object));

    if (result) {
        constructString(reinterpret_cast<String*>(&output));
        formatString(reinterpret_cast<String*>(&output), errorFormat, result);

        result = reinterpret_cast<int (__cdecl*)(int, int, int)>(logMessage)(
            reinterpret_cast<int>(logContext),
            reinterpret_cast<int>(
                stringText(reinterpret_cast<String*>(&output))),
            result);

        destroyString(reinterpret_cast<String*>(&output));

        if (object)
            object->table->release(object);

        if (state.link)
            state.link->previous = state.previous;

        if (state.active)
            release_state(0, state.context);

        return result;
    }

    Object* temporary = object;
    if (object)
        object->table->addRef(object);

    Object* current = object;
    int copied;
    if (!output) {
        copied = static_cast<int>(0x80004003UL);
    } else {
        *output = temporary;
        if (temporary) {
            temporary->table->addRef(temporary);
            current = object;
        }
        copied = 0;
    }

    if (temporary) {
        temporary->table->release(temporary);
        current = object;
    }

    if (current)
        current->table->release(current);

    if (state.link)
        state.link->previous = state.previous;

    if (state.active)
        release_state(0, state.context);

    return copied;
}
}