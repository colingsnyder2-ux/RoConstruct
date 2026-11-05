// from server: 100% by Yeetserama
// roc 2010-06 0040f4a0  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 314 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f4a0
//
// 0040f4a0  83ec14               sub esp, 0x14
// 0040f4a3  56                   push esi
// 0040f4a4  e8cd873900           call 0x7a7c76
// 0040f4a9  50                   push eax
// 0040f4aa  8d4c240c             lea ecx, [esp + 0xc]
// 0040f4ae  e8bd873900           call 0x7a7c70
// 0040f4b3  8d442404             lea eax, [esp + 4]
// 0040f4b7  50                   push eax
// 0040f4b8  68c804a000           push 0xa004c8
// 0040f4bd  6a17                 push 0x17
// 0040f4bf  6a00                 push 0
// 0040f4c1  6838baa000           push 0xa0ba38
// 0040f4c6  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040f4ce  ff15dcd09e00         call dword ptr [0x9ed0dc]
// 0040f4d4  8bf0                 mov esi, eax
// 0040f4d6  85f6                 test esi, esi
// 0040f4d8  747e                 je 0x40f558
// 0040f4da  8d4c2420             lea ecx, [esp + 0x20]
// 0040f4de  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0040f4e4  56                   push esi
// 0040f4e5  8d4c2424             lea ecx, [esp + 0x24]
// 0040f4e9  687823a000           push 0xa02378
// 0040f4ee  51                   push ecx
// 0040f4ef  ff15acce9e00         call dword ptr [0x9eceac]
// 0040f4f5  83c40c               add esp, 0xc
// 0040f4f8  56                   push esi
// 0040f4f9  8d4c2424             lea ecx, [esp + 0x24]
// 0040f4fd  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 0040f503  50                   push eax
// 0040f504  6878baa000           push 0xa0ba78
// 0040f509  e8c2570100           call 0x424cd0
// 0040f50e  83c40c               add esp, 0xc
// 0040f511  8d4c2420             lea ecx, [esp + 0x20]
// 0040f515  8bf0                 mov esi, eax
// 0040f517  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0040f51d  8b442404             mov eax, dword ptr [esp + 4]
// 0040f521  85c0                 test eax, eax
// 0040f523  7408                 je 0x40f52d
// 0040f525  8b10                 mov edx, dword ptr [eax]
// 0040f527  50                   push eax
// 0040f528  8b4208               mov eax, dword ptr [edx + 8]
// 0040f52b  ffd0                 call eax
// 0040f52d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040f531  85c0                 test eax, eax
// 0040f533  7407                 je 0x40f53c
// 0040f535  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040f539  894804               mov dword ptr [eax + 4], ecx
// 0040f53c  837c241400           cmp dword ptr [esp + 0x14], 0
// 0040f541  740c                 je 0x40f54f
// 0040f543  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040f547  52                   push edx
// 0040f548  6a00                 push 0
// 0040f54a  e815873900           call 0x7a7c64
// 0040f54f  8bc6                 mov eax, esi
// 0040f551  5e                   pop esi
// 0040f552  83c414               add esp, 0x14
// 0040f555  c20800               ret 8
// 0040f558  8b442404             mov eax, dword ptr [esp + 4]
// 0040f55c  8bf0                 mov esi, eax
// 0040f55e  85c0                 test eax, eax
// 0040f560  740c                 je 0x40f56e
// 0040f562  8b08                 mov ecx, dword ptr [eax]
// 0040f564  8b5104               mov edx, dword ptr [ecx + 4]
// 0040f567  50                   push eax
// 0040f568  ffd2                 call edx
// 0040f56a  8b442404             mov eax, dword ptr [esp + 4]
// 0040f56e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0040f572  57                   push edi
// 0040f573  85c9                 test ecx, ecx
// 0040f575  7507                 jne 0x40f57e
// 0040f577  bf03400080           mov edi, 0x80004003
// 0040f57c  eb14                 jmp 0x40f592
// 0040f57e  8931                 mov dword ptr [ecx], esi
// 0040f580  85f6                 test esi, esi
// 0040f582  740c                 je 0x40f590
// 0040f584  8b06                 mov eax, dword ptr [esi]
// 0040f586  8b4804               mov ecx, dword ptr [eax + 4]
// 0040f589  56                   push esi
// 0040f58a  ffd1                 call ecx
// 0040f58c  8b442408             mov eax, dword ptr [esp + 8]
// 0040f590  33ff                 xor edi, edi
// 0040f592  85f6                 test esi, esi
// 0040f594  740c                 je 0x40f5a2
// 0040f596  8b16                 mov edx, dword ptr [esi]
// 0040f598  8b4208               mov eax, dword ptr [edx + 8]
// 0040f59b  56                   push esi
// 0040f59c  ffd0                 call eax
// 0040f59e  8b442408             mov eax, dword ptr [esp + 8]
// 0040f5a2  85c0                 test eax, eax
// 0040f5a4  7408                 je 0x40f5ae
// 0040f5a6  8b08                 mov ecx, dword ptr [eax]
// 0040f5a8  8b5108               mov edx, dword ptr [ecx + 8]
// 0040f5ab  50                   push eax
// 0040f5ac  ffd2                 call edx
// 0040f5ae  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040f5b2  85c0                 test eax, eax
// 0040f5b4  7407                 je 0x40f5bd
// 0040f5b6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040f5ba  894804               mov dword ptr [eax + 4], ecx
// 0040f5bd  837c241800           cmp dword ptr [esp + 0x18], 0
// 0040f5c2  740c                 je 0x40f5d0
// 0040f5c4  8b542414             mov edx, dword ptr [esp + 0x14]
// 0040f5c8  52                   push edx
// 0040f5c9  6a00                 push 0
// 0040f5cb  e894863900           call 0x7a7c64
// 0040f5d0  8bc7                 mov eax, edi
// 0040f5d2  5f                   pop edi
// 0040f5d3  5e                   pop esi
// 0040f5d4  83c414               add esp, 0x14
// 0040f5d7  c20800               ret 8
// copied from an identical function in another client (function ?function@ns_ROCX00000e@@YGHPAXPAPAUObject@1@@Z)

namespace ns_ROCX00000e {
// from server: 100% by colin
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
