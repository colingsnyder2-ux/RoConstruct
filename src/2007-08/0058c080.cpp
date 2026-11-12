// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 54% by colin
// roc 2007-08 0058c080  unit: SoundServiceStatsItem  size: 293 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0058c080
//
// 0058c080  64a100000000         mov eax, dword ptr fs:[0]
// 0058c086  6aff                 push -1
// 0058c088  6879be7500           push 0x75be79
// 0058c08d  50                   push eax
// 0058c08e  64892500000000       mov dword ptr fs:[0], esp
// 0058c095  83ec24               sub esp, 0x24
// 0058c098  56                   push esi
// 0058c099  8bf1                 mov esi, ecx
// 0058c09b  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058c0a1  83b8ec00000000       cmp dword ptr [eax + 0xec], 0
// 0058c0a8  0f84a5000000         je 0x58c153
// 0058c0ae  8b80f0000000         mov eax, dword ptr [eax + 0xf0]
// 0058c0b4  85c0                 test eax, eax
// 0058c0b6  50                   push eax
// 0058c0b7  8944240c             mov dword ptr [esp + 0xc], eax
// 0058c0bb  db44240c             fild dword ptr [esp + 0xc]
// 0058c0bf  6840f37a00           push 0x7af340
// 0058c0c4  7d06                 jge 0x58c0cc
// 0058c0c6  dc0530b17800         fadd qword ptr [0x78b130]
// 0058c0cc  83ec08               sub esp, 8
// 0058c0cf  dd1c24               fstp qword ptr [esp]
// 0058c0d2  56                   push esi
// 0058c0d3  e808aa0000           call 0x596ae0
// 0058c0d8  83c414               add esp, 0x14
// 0058c0db  8d442408             lea eax, [esp + 8]
// 0058c0df  50                   push eax
// 0058c0e0  8d4c2408             lea ecx, [esp + 8]
// 0058c0e4  51                   push ecx
// 0058c0e5  e8663b0a00           call 0x62fc50
// 0058c0ea  85c0                 test eax, eax
// 0058c0ec  7514                 jne 0x58c102
// 0058c0ee  8b542404             mov edx, dword ptr [esp + 4]
// 0058c0f2  8b442408             mov eax, dword ptr [esp + 8]
// 0058c0f6  899614010000         mov dword ptr [esi + 0x114], edx
// 0058c0fc  898618010000         mov dword ptr [esi + 0x118], eax
// 0058c102  53                   push ebx
// 0058c103  57                   push edi
// 0058c104  8dbe20010000         lea edi, [esi + 0x120]
// 0058c10a  8d9e1c010000         lea ebx, [esi + 0x11c]
// 0058c110  8bb610010000         mov esi, dword ptr [esi + 0x110]
// 0058c116  57                   push edi
// 0058c117  8d8e20010000         lea ecx, [esi + 0x120]
// 0058c11d  53                   push ebx
// 0058c11e  c70700000000         mov dword ptr [edi], 0
// 0058c124  51                   push ecx
// 0058c125  c70300000000         mov dword ptr [ebx], 0
// 0058c12b  e8a0caffff           call 0x588bd0
// 0058c130  57                   push edi
// 0058c131  53                   push ebx
// 0058c132  81c62c010000         add esi, 0x12c
// 0058c138  56                   push esi
// 0058c139  e892caffff           call 0x588bd0
// 0058c13e  83c418               add esp, 0x18
// 0058c141  5f                   pop edi
// 0058c142  5b                   pop ebx
// 0058c143  5e                   pop esi
// 0058c144  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058c148  64890d00000000       mov dword ptr fs:[0], ecx
// 0058c14f  83c430               add esp, 0x30
// 0058c152  c3                   ret 
// 0058c153  6834f37a00           push 0x7af334
// 0058c158  8d4c2410             lea ecx, [esp + 0x10]
// 0058c15c  ff1598e67700         call dword ptr [0x77e698]
// 0058c162  d9ee                 fldz 
// 0058c164  8d54240c             lea edx, [esp + 0xc]
// 0058c168  dd9ee8000000         fstp qword ptr [esi + 0xe8]
// 0058c16e  52                   push edx
// 0058c16f  8d8ef0000000         lea ecx, [esi + 0xf0]
// 0058c175  c744243400000000     mov dword ptr [esp + 0x34], 0
// 0058c17d  ff1590e67700         call dword ptr [0x77e690]
// 0058c183  8d4c240c             lea ecx, [esp + 0xc]
// 0058c187  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 0058c18f  ff15ace67700         call dword ptr [0x77e6ac]
// 0058c195  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0058c199  5e                   pop esi
// 0058c19a  64890d00000000       mov dword ptr fs:[0], ecx
// 0058c1a1  83c430               add esp, 0x30
// 0058c1a4  c3                   ret 
#include <string>

struct SoundServiceData {
    char pad[0xec];
    int enabled;
    unsigned int value;
    char pad2[0x120 - 0xf4];
    char groupA[0x12c - 0x120];
    char groupB[4];
};

struct Stats_Item {
    char pad[0xe8];
    double value;
    std::string text;
    void __cdecl formatValue(double v, const char* fmt, ...);
    void setValue(double v, const std::string& s) { value = v; text = s; }
};

extern "C" int __stdcall FMOD_Memory_GetStats(int* currentalloced, int* maxalloced);
void __cdecl accumulate(void* group, unsigned int* a, unsigned int* b);

struct SoundServiceStatsItem : Stats_Item {
    SoundServiceData* service;
    unsigned int currentalloced;
    unsigned int maxalloced;
    unsigned int countA;
    unsigned int countB;
    void update();
};

void SoundServiceStatsItem::update()
{
    if (service->enabled) {
        unsigned int v = service->value;
        formatValue(v, "fmod %08x", v);
        int a, b;
        if (FMOD_Memory_GetStats(&a, &b) == 0) {
            currentalloced = a;
            maxalloced = b;
        }
        unsigned int* pb = &countB;
        unsigned int* pa = &countA;
        SoundServiceData* s = service;
        *pb = 0;
        *pa = 0;
        accumulate(s->groupA, pa, pb);
        accumulate(s->groupB, pa, pb);
    } else {
        setValue(0, "-disabled-");
    }
}
