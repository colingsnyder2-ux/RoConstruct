// from server: 100% by EspClaude
// roc 2009-06 0040f310  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f310
//
// 0040f310  83ec14               sub esp, 0x14
// 0040f313  56                   push esi
// 0040f314  e8f5993000           call 0x718d0e
// 0040f319  50                   push eax
// 0040f31a  8d4c240c             lea ecx, [esp + 0xc]
// 0040f31e  e8e5993000           call 0x718d08
// 0040f323  8d442404             lea eax, [esp + 4]
// 0040f327  50                   push eax
// 0040f328  68e8cd8a00           push 0x8acde8
// 0040f32d  6a17                 push 0x17
// 0040f32f  6a00                 push 0
// 0040f331  68f8698b00           push 0x8b69f8
// 0040f336  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040f33e  ff1500038a00         call dword ptr [0x8a0300]
// 0040f344  8bf0                 mov esi, eax
// 0040f346  85f6                 test esi, esi
// 0040f348  747e                 je 0x40f3c8
// 0040f34a  8d4c2420             lea ecx, [esp + 0x20]
// 0040f34e  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0040f354  56                   push esi
// 0040f355  8d4c2424             lea ecx, [esp + 0x24]
// 0040f359  6838eb8a00           push 0x8aeb38
// 0040f35e  51                   push ecx
// 0040f35f  ff15c4fc8900         call dword ptr [0x89fcc4]
// 0040f365  83c40c               add esp, 0xc
// 0040f368  56                   push esi
// 0040f369  8d4c2424             lea ecx, [esp + 0x24]
// 0040f36d  ff15d0fc8900         call dword ptr [0x89fcd0]
// 0040f373  50                   push eax
// 0040f374  68386a8b00           push 0x8b6a38
// 0040f379  e8824c0100           call 0x424000
// 0040f37e  83c40c               add esp, 0xc
// 0040f381  8d4c2420             lea ecx, [esp + 0x20]
// 0040f385  8bf0                 mov esi, eax
// 0040f387  ff1510fd8900         call dword ptr [0x89fd10]
// 0040f38d  8b442404             mov eax, dword ptr [esp + 4]
// 0040f391  85c0                 test eax, eax
// 0040f393  7408                 je 0x40f39d
// 0040f395  8b10                 mov edx, dword ptr [eax]
// 0040f397  50                   push eax
// 0040f398  8b4208               mov eax, dword ptr [edx + 8]
// 0040f39b  ffd0                 call eax
// 0040f39d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040f3a1  85c0                 test eax, eax
// 0040f3a3  7407                 je 0x40f3ac
// 0040f3a5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040f3a9  894804               mov dword ptr [eax + 4], ecx
// 0040f3ac  837c241400           cmp dword ptr [esp + 0x14], 0
// 0040f3b1  740c                 je 0x40f3bf
// 0040f3b3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040f3b7  52                   push edx
// 0040f3b8  6a00                 push 0
// 0040f3ba  e83d993000           call 0x718cfc
// 0040f3bf  8bc6                 mov eax, esi
// 0040f3c1  5e                   pop esi
// 0040f3c2  83c414               add esp, 0x14
// 0040f3c5  c20800               ret 8
// 0040f3c8  8b442404             mov eax, dword ptr [esp + 4]
// 0040f3cc  8bf0                 mov esi, eax
// 0040f3ce  85c0                 test eax, eax
// 0040f3d0  740c                 je 0x40f3de
// 0040f3d2  8b08                 mov ecx, dword ptr [eax]
// 0040f3d4  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f3d7  50                   push eax
// 0040f3d8  ffd2                 call edx
// 0040f3da  8b442404             mov eax, dword ptr [esp + 4]
// 0040f3de  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0040f3e2  57                   push edi
// 0040f3e3  85c9                 test ecx, ecx
// 0040f3e5  7507                 jne 0x40f3ee
// 0040f3e7  bf03400080           mov edi, 0x80004003
// 0040f3ec  eb14                 jmp 0x40f402
// 0040f3ee  8931                 mov dword ptr [ecx], esi
// 0040f3f0  85f6                 test esi, esi
// 0040f3f2  740c                 je 0x40f400
// 0040f3f4  8b06                 mov eax, dword ptr [esi]
// 0040f3f6  8b4804               mov ecx, dword ptr [eax + 4]
// 0040f3f9  56                   push esi
// 0040f3fa  ffd1                 call ecx
// 0040f3fc  8b442408             mov eax, dword ptr [esp + 8]
// 0040f400  33ff                 xor edi, edi
// 0040f402  85f6                 test esi, esi
// 0040f404  740c                 je 0x40f412
// 0040f406  8b16                 mov edx, dword ptr [esi]
// 0040f408  8b4208               mov eax, dword ptr [edx + 8]
// 0040f40b  56                   push esi
// 0040f40c  ffd0                 call eax
// 0040f40e  8b442408             mov eax, dword ptr [esp + 8]
// 0040f412  85c0                 test eax, eax
// 0040f414  7408                 je 0x40f41e
// 0040f416  8b08                 mov ecx, dword ptr [eax]
// 0040f418  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f41b  50                   push eax
// 0040f41c  ffd2                 call edx
// 0040f41e  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040f422  85c0                 test eax, eax
// 0040f424  7407                 je 0x40f42d
// 0040f426  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040f42a  894804               mov dword ptr [eax + 4], ecx
// 0040f42d  837c241800           cmp dword ptr [esp + 0x18], 0
// 0040f432  740c                 je 0x40f440
// 0040f434  8b542414             mov edx, dword ptr [esp + 0x14]
// 0040f438  52                   push edx
// 0040f439  6a00                 push 0
// 0040f43b  e8bc983000           call 0x718cfc
// 0040f440  8bc7                 mov eax, edi
// 0040f442  5f                   pop edi
// 0040f443  5e                   pop esi
// 0040f444  83c414               add esp, 0x14
// 0040f447  c20800               ret 8
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
