// from server: 100% by EspClaude
// roc 2009-06 0041ab80  unit: rbx::signals::connection::slot  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041ab80
//
// 0041ab80  64a100000000         mov eax, dword ptr fs:[0]
// 0041ab86  6aff                 push -1
// 0041ab88  688ad38400           push 0x84d38a
// 0041ab8d  50                   push eax
// 0041ab8e  64892500000000       mov dword ptr fs:[0], esp
// 0041ab95  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041ab99  56                   push esi
// 0041ab9a  50                   push eax
// 0041ab9b  8bf1                 mov esi, ecx
// 0041ab9d  e86e2c3200           call 0x73d810
// 0041aba2  83f8ff               cmp eax, -1
// 0041aba5  7514                 jne 0x41abbb
// 0041aba7  0bc0                 or eax, eax
// 0041aba9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041abad  64890d00000000       mov dword ptr fs:[0], ecx
// 0041abb4  5e                   pop esi
// 0041abb5  83c40c               add esp, 0xc
// 0041abb8  c20400               ret 4
// 0041abbb  8b16                 mov edx, dword ptr [esi]
// 0041abbd  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0041abc3  8bce                 mov ecx, esi
// 0041abc5  ffd0                 call eax
// 0041abc7  8bf0                 mov esi, eax
// 0041abc9  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0041abcf  c7808800000001000000 mov dword ptr [eax + 0x88], 1
// 0041abd9  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0041abdf  c7407c00000000       mov dword ptr [eax + 0x7c], 0
// 0041abe6  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0041abec  6a01                 push 1
// 0041abee  e80d443300           call 0x74f000
// 0041abf3  68c4000000           push 0xc4
// 0041abf8  e83bde2f00           call 0x718a38
// 0041abfd  83c404               add esp, 4
// 0041ac00  89442414             mov dword ptr [esp + 0x14], eax
// 0041ac04  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0041ac0c  85c0                 test eax, eax
// 0041ac0e  741d                 je 0x41ac2d
// 0041ac10  6a01                 push 1
// 0041ac12  6a01                 push 1
// 0041ac14  6aff                 push -1
// 0041ac16  6a01                 push 1
// 0041ac18  682c010000           push 0x12c
// 0041ac1d  68f8ff8a00           push 0x8afff8
// 0041ac22  6a00                 push 0
// 0041ac24  8bc8                 mov ecx, eax
// 0041ac26  e8b5263300           call 0x74d2e0
// 0041ac2b  eb02                 jmp 0x41ac2f
// 0041ac2d  33c0                 xor eax, eax
// 0041ac2f  50                   push eax
// 0041ac30  8bce                 mov ecx, esi
// 0041ac32  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0041ac3a  e8c16f3200           call 0x741c00
// 0041ac3f  8bf0                 mov esi, eax
// 0041ac41  6a01                 push 1
// 0041ac43  8bce                 mov ecx, esi
// 0041ac45  e8a6243300           call 0x74d0f0
// 0041ac4a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041ac4e  c786b000000000000000 mov dword ptr [esi + 0xb0], 0
// 0041ac58  33c0                 xor eax, eax
// 0041ac5a  64890d00000000       mov dword ptr fs:[0], ecx
// 0041ac61  5e                   pop esi
// 0041ac62  83c40c               add esp, 0xc
// 0041ac65  c20400               ret 4
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