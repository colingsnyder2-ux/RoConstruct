// from server: 100% by Yeetserama
// roc 2007-08 00462e50  unit: CSettingsExplorer  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00462e50
//
// 00462e50  6aff                 push -1
// 00462e52  68582d7400           push 0x742d58
// 00462e57  64a100000000         mov eax, dword ptr fs:[0]
// 00462e5d  50                   push eax
// 00462e5e  51                   push ecx
// 00462e5f  56                   push esi
// 00462e60  a188518b00           mov eax, dword ptr [0x8b5188]
// 00462e65  33c4                 xor eax, esp
// 00462e67  50                   push eax
// 00462e68  8d44240c             lea eax, [esp + 0xc]
// 00462e6c  64a300000000         mov dword ptr fs:[0], eax
// 00462e72  8bf1                 mov esi, ecx
// 00462e74  8b442420             mov eax, dword ptr [esp + 0x20]
// 00462e78  6a00                 push 0
// 00462e7a  6804878800           push 0x888704
// 00462e7f  684c1f8800           push 0x881f4c
// 00462e84  6a00                 push 0
// 00462e86  50                   push eax
// 00462e87  c744242800000000     mov dword ptr [esp + 0x28], 0
// 00462e8f  e8a2de1c00           call 0x630d36
// 00462e94  83c414               add esp, 0x14
// 00462e97  85c0                 test eax, eax
// 00462e99  7458                 je 0x462ef3
// 00462e9b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00462e9f  83ec10               sub esp, 0x10
// 00462ea2  8bc4                 mov eax, esp
// 00462ea4  8908                 mov dword ptr [eax], ecx
// 00462ea6  8b542434             mov edx, dword ptr [esp + 0x34]
// 00462eaa  895004               mov dword ptr [eax + 4], edx
// 00462ead  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00462eb1  85c9                 test ecx, ecx
// 00462eb3  89642418             mov dword ptr [esp + 0x18], esp
// 00462eb7  740c                 je 0x462ec5
// 00462eb9  83c104               add ecx, 4
// 00462ebc  ba01000000           mov edx, 1
// 00462ec1  f00fc111             lock xadd dword ptr [ecx], edx
// 00462ec5  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00462ec9  894808               mov dword ptr [eax + 8], ecx
// 00462ecc  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00462ed0  89500c               mov dword ptr [eax + 0xc], edx
// 00462ed3  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00462ed7  85c0                 test eax, eax
// 00462ed9  740c                 je 0x462ee7
// 00462edb  83c004               add eax, 4
// 00462ede  b901000000           mov ecx, 1
// 00462ee3  f00fc108             lock xadd dword ptr [eax], ecx
// 00462ee7  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00462eeb  52                   push edx
// 00462eec  8bce                 mov ecx, esi
// 00462eee  e89db2fbff           call 0x41e190
// 00462ef3  8d4c2420             lea ecx, [esp + 0x20]
// 00462ef7  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00462eff  e8fcaafbff           call 0x41da00
// 00462f04  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00462f08  64890d00000000       mov dword ptr fs:[0], ecx
// 00462f0f  59                   pop ecx
// 00462f10  5e                   pop esi
// 00462f11  83c410               add esp, 0x10
// 00462f14  c21400               ret 0x14
// copied from an identical function in another client (function ?process@CSettingsExplorer@ns_ROCX000002@@QAEXHUPair@2@@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern char instanceType;
extern char itemType;
extern "C" void* __cdecl dynamicCast(void*, long, void*, void*, int);

__forceinline void incrementReference(volatile long* count) {
    _InterlockedExchangeAdd(count, 1);
}

struct Reference {
    long reserved;
    volatile long count;
};

struct Pair {
    void* first;
    Reference* firstReference;
    void* second;
    Reference* secondReference;

    Pair(const Pair&);
    ~Pair();
};

__forceinline Pair::Pair(const Pair& other) {
    first = other.first;
    firstReference = other.firstReference;
    if (firstReference)
        incrementReference(&firstReference->count);
    second = other.second;
    secondReference = other.secondReference;
    if (secondReference)
        incrementReference(&secondReference->count);
}

struct CSettingsExplorer {
    void forward(int, Pair);
    void process(int, Pair);
};

void CSettingsExplorer::process(int value, Pair objects) {
    if (dynamicCast(objects.first, 0, &instanceType, &itemType, 0))
        forward(value, objects);
}
}
