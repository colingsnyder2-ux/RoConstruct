// from server: 100% by Yeetserama
// roc 2010-06 0041b040  unit: rbx::signals::connection::slot  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b040
//
// 0041b040  64a100000000         mov eax, dword ptr fs:[0]
// 0041b046  6aff                 push -1
// 0041b048  68aaee9700           push 0x97eeaa
// 0041b04d  50                   push eax
// 0041b04e  64892500000000       mov dword ptr fs:[0], esp
// 0041b055  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041b059  56                   push esi
// 0041b05a  50                   push eax
// 0041b05b  8bf1                 mov esi, ecx
// 0041b05d  e8ae173b00           call 0x7cc810
// 0041b062  83f8ff               cmp eax, -1
// 0041b065  7514                 jne 0x41b07b
// 0041b067  0bc0                 or eax, eax
// 0041b069  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041b06d  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b074  5e                   pop esi
// 0041b075  83c40c               add esp, 0xc
// 0041b078  c20400               ret 4
// 0041b07b  8b16                 mov edx, dword ptr [esi]
// 0041b07d  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0041b083  8bce                 mov ecx, esi
// 0041b085  ffd0                 call eax
// 0041b087  8bf0                 mov esi, eax
// 0041b089  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0041b08f  c7808800000001000000 mov dword ptr [eax + 0x88], 1
// 0041b099  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0041b09f  c7407c00000000       mov dword ptr [eax + 0x7c], 0
// 0041b0a6  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0041b0ac  6a01                 push 1
// 0041b0ae  e88d2d3c00           call 0x7dde40
// 0041b0b3  68c4000000           push 0xc4
// 0041b0b8  e8e3c83800           call 0x7a79a0
// 0041b0bd  83c404               add esp, 4
// 0041b0c0  89442414             mov dword ptr [esp + 0x14], eax
// 0041b0c4  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0041b0cc  85c0                 test eax, eax
// 0041b0ce  741d                 je 0x41b0ed
// 0041b0d0  6a01                 push 1
// 0041b0d2  6a01                 push 1
// 0041b0d4  6aff                 push -1
// 0041b0d6  6a01                 push 1
// 0041b0d8  682c010000           push 0x12c
// 0041b0dd  68a039a000           push 0xa039a0
// 0041b0e2  6a00                 push 0
// 0041b0e4  8bc8                 mov ecx, eax
// 0041b0e6  e835103c00           call 0x7dc120
// 0041b0eb  eb02                 jmp 0x41b0ef
// 0041b0ed  33c0                 xor eax, eax
// 0041b0ef  50                   push eax
// 0041b0f0  8bce                 mov ecx, esi
// 0041b0f2  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0041b0fa  e8215a3b00           call 0x7d0b20
// 0041b0ff  8bf0                 mov esi, eax
// 0041b101  6a01                 push 1
// 0041b103  8bce                 mov ecx, esi
// 0041b105  e8260e3c00           call 0x7dbf30
// 0041b10a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041b10e  c786b000000000000000 mov dword ptr [esi + 0xb0], 0
// 0041b118  33c0                 xor eax, eax
// 0041b11a  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b121  5e                   pop esi
// 0041b122  83c40c               add esp, 0xc
// 0041b125  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEHH@Z)

// from server: 100% by colin
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