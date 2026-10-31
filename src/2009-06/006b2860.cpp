// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e310  unit: RBX::BlockBlockContact  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e310
//
// 0060e310  6aff                 push -1
// 0060e312  68a88d7d00           push 0x7d8da8
// 0060e317  64a100000000         mov eax, dword ptr fs:[0]
// 0060e31d  50                   push eax
// 0060e31e  64892500000000       mov dword ptr fs:[0], esp
// 0060e325  83ec0c               sub esp, 0xc
// 0060e328  33c0                 xor eax, eax
// 0060e32a  56                   push esi
// 0060e32b  8bf1                 mov esi, ecx
// 0060e32d  89442408             mov dword ptr [esp + 8], eax
// 0060e331  8944240c             mov dword ptr [esp + 0xc], eax
// 0060e335  89442404             mov dword ptr [esp + 4], eax
// 0060e339  89442418             mov dword ptr [esp + 0x18], eax
// 0060e33d  8d442404             lea eax, [esp + 4]
// 0060e341  50                   push eax
// 0060e342  8d4e08               lea ecx, [esi + 8]
// 0060e345  51                   push ecx
// 0060e346  e8e5070000           call 0x60eb30
// 0060e34b  8b5628               mov edx, dword ptr [esi + 0x28]
// 0060e34e  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060e352  52                   push edx
// 0060e353  50                   push eax
// 0060e354  8d4c2414             lea ecx, [esp + 0x14]
// 0060e358  51                   push ecx
// 0060e359  e802270000           call 0x610a60
// 0060e35e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0060e362  52                   push edx
// 0060e363  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 0060e36b  e8b099efff           call 0x507d20
// 0060e370  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0060e374  83c418               add esp, 0x18
// 0060e377  5e                   pop esi
// 0060e378  64890d00000000       mov dword ptr fs:[0], ecx
// 0060e37f  83c418               add esp, 0x18
// 0060e382  c20400               ret 4

void __cdecl alignedFree(void*);

struct Array {
    void* data;
    int count;
    int capacity;

    Array();
    ~Array();
};

inline Array::Array()
{
    count = 0;
    capacity = 0;
    data = 0;
}

inline Array::~Array()
{
    alignedFree(data);
}

void __cdecl gather(void*, Array*);
void __cdecl process(Array*, void*, void*);

struct Contact {
    char padding[8];
    char state[32];
    void* value;

    void update(void*);
};

void Contact::update(void* argument)
{
    Array temporary;
    gather(state, &temporary);
    process(&temporary, argument, value);
}
