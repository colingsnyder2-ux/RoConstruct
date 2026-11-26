// from server: 100% by Xemicl
// roc 2012-06 00428200  unit: CInstanceExplorer  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00428200
//
// 00428200  64a100000000         mov eax, dword ptr fs:[0]
// 00428206  6aff                 push -1
// 00428208  680aada900           push 0xa9ad0a
// 0042820d  50                   push eax
// 0042820e  64892500000000       mov dword ptr fs:[0], esp
// 00428215  8b442410             mov eax, dword ptr [esp + 0x10]
// 00428219  56                   push esi
// 0042821a  50                   push eax
// 0042821b  8bf1                 mov esi, ecx
// 0042821d  e8dee55700           call 0x9a6800
// 00428222  83f8ff               cmp eax, -1
// 00428225  7514                 jne 0x42823b
// 00428227  0bc0                 or eax, eax
// 00428229  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042822d  64890d00000000       mov dword ptr fs:[0], ecx
// 00428234  5e                   pop esi
// 00428235  83c40c               add esp, 0xc
// 00428238  c20400               ret 4
// 0042823b  8b16                 mov edx, dword ptr [esi]
// 0042823d  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 00428243  8bce                 mov ecx, esi
// 00428245  ffd0                 call eax
// 00428247  8bf0                 mov esi, eax
// 00428249  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0042824f  c7808800000001000000 mov dword ptr [eax + 0x88], 1
// 00428259  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0042825f  c7407c00000000       mov dword ptr [eax + 0x7c], 0
// 00428266  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0042826c  6a01                 push 1
// 0042826e  e86dda5800           call 0x9b5ce0
// 00428273  68c4000000           push 0xc4
// 00428278  e89d9e5500           call 0x98211a
// 0042827d  83c404               add esp, 4
// 00428280  89442414             mov dword ptr [esp + 0x14], eax
// 00428284  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042828c  85c0                 test eax, eax
// 0042828e  741d                 je 0x4282ad
// 00428290  6a01                 push 1
// 00428292  6a01                 push 1
// 00428294  6aff                 push -1
// 00428296  6a01                 push 1
// 00428298  682c010000           push 0x12c
// 0042829d  6844dfb400           push 0xb4df44
// 004282a2  6a00                 push 0
// 004282a4  8bc8                 mov ecx, eax
// 004282a6  e835055800           call 0x9a87e0
// 004282ab  eb02                 jmp 0x4282af
// 004282ad  33c0                 xor eax, eax
// 004282af  50                   push eax
// 004282b0  8bce                 mov ecx, esi
// 004282b2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004282ba  e8810f5800           call 0x9a9240
// 004282bf  8bf0                 mov esi, eax
// 004282c1  6a01                 push 1
// 004282c3  8bce                 mov ecx, esi
// 004282c5  e826035800           call 0x9a85f0
// 004282ca  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004282ce  c786b000000000000000 mov dword ptr [esi + 0xb0], 0
// 004282d8  33c0                 xor eax, eax
// 004282da  64890d00000000       mov dword ptr fs:[0], ecx
// 004282e1  5e                   pop esi
// 004282e2  83c40c               add esp, 0xc
// 004282e5  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEHH@Z)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Column {
    char pad0[0xb0];
    int field_b0;
    char pad1[0x10];

    Column(int, const char*, int, int, int, int, int);
    void setVisible(int);
};

struct Header {
    char pad0[0x7c];
    int field_7c;
    char pad1[8];
    volatile int field_88;

    void setMode(int);
};

struct Report {
    char pad0[0x288];
    Header* volatile header;

    Column* addColumn(Column*);
};

struct S;

struct VTable {
    char pad0[0x194];
    Report* (__thiscall *getReport)(S*);
};

struct S {
    VTable* vtable;

    int baseInitialize(int);
    int f(int);
};

int S::f(int a1)
{
    int result = baseInitialize(a1);
    if (result == -1)
        return result;

    Report* report = vtable->getReport(this);

    Header* header = report->header;
    header->field_88 = 1;
    Header* mode = report->header;
    mode->field_7c = 0;
    report->header->setMode(1);

    Column* column = report->addColumn(
        new Column(0, "Name", 300, 1, -1, 1, 1));
    column->setVisible(1);
    column->field_b0 = 0;
    return 0;
}