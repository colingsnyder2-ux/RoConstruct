// from server: 100% by Yeetserama
// roc 2011-06 0047f390  unit: CRobloxReportPaneView  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0047f390
//
// 0047f390  64a100000000         mov eax, dword ptr fs:[0]
// 0047f396  6aff                 push -1
// 0047f398  68544e9d00           push 0x9d4e54
// 0047f39d  50                   push eax
// 0047f39e  64892500000000       mov dword ptr fs:[0], esp
// 0047f3a5  8b442410             mov eax, dword ptr [esp + 0x10]
// 0047f3a9  53                   push ebx
// 0047f3aa  56                   push esi
// 0047f3ab  57                   push edi
// 0047f3ac  50                   push eax
// 0047f3ad  8bf1                 mov esi, ecx
// 0047f3af  e84cee3a00           call 0x82e200
// 0047f3b4  83f8ff               cmp eax, -1
// 0047f3b7  7516                 jne 0x47f3cf
// 0047f3b9  0bc0                 or eax, eax
// 0047f3bb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047f3bf  64890d00000000       mov dword ptr fs:[0], ecx
// 0047f3c6  5f                   pop edi
// 0047f3c7  5e                   pop esi
// 0047f3c8  5b                   pop ebx
// 0047f3c9  83c40c               add esp, 0xc
// 0047f3cc  c20400               ret 4
// 0047f3cf  8b16                 mov edx, dword ptr [esi]
// 0047f3d1  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 0047f3d7  8bce                 mov ecx, esi
// 0047f3d9  ffd0                 call eax
// 0047f3db  8bf0                 mov esi, eax
// 0047f3dd  33db                 xor ebx, ebx
// 0047f3df  8bce                 mov ecx, esi
// 0047f3e1  899eb8010000         mov dword ptr [esi + 0x1b8], ebx
// 0047f3e7  e8644c3b00           call 0x834050
// 0047f3ec  8b16                 mov edx, dword ptr [esi]
// 0047f3ee  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 0047f3f4  8bce                 mov ecx, esi
// 0047f3f6  ffd0                 call eax
// 0047f3f8  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0047f3fe  899888000000         mov dword ptr [eax + 0x88], ebx
// 0047f404  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0047f40a  89587c               mov dword ptr [eax + 0x7c], ebx
// 0047f40d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 0047f413  6a01                 push 1
// 0047f415  e8a6e23b00           call 0x83d6c0
// 0047f41a  68c4000000           push 0xc4
// 0047f41f  e83aac3800           call 0x80a05e
// 0047f424  83c404               add esp, 4
// 0047f427  8944241c             mov dword ptr [esp + 0x1c], eax
// 0047f42b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0047f42f  3bc3                 cmp eax, ebx
// 0047f431  741c                 je 0x47f44f
// 0047f433  6a01                 push 1
// 0047f435  6a01                 push 1
// 0047f437  6aff                 push -1
// 0047f439  6a01                 push 1
// 0047f43b  68c8000000           push 0xc8
// 0047f440  688448a600           push 0xa64884
// 0047f445  53                   push ebx
// 0047f446  8bc8                 mov ecx, eax
// 0047f448  e8a30d3b00           call 0x8301f0
// 0047f44d  eb02                 jmp 0x47f451
// 0047f44f  33c0                 xor eax, eax
// 0047f451  50                   push eax
// 0047f452  8bce                 mov ecx, esi
// 0047f454  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0047f45c  e8ef173b00           call 0x830c50
// 0047f461  8bf8                 mov edi, eax
// 0047f463  6a01                 push 1
// 0047f465  8bcf                 mov ecx, edi
// 0047f467  e8940b3b00           call 0x830000
// 0047f46c  68c4000000           push 0xc4
// 0047f471  899fb0000000         mov dword ptr [edi + 0xb0], ebx
// 0047f477  e8e2ab3800           call 0x80a05e
// 0047f47c  83c404               add esp, 4
// 0047f47f  8944241c             mov dword ptr [esp + 0x1c], eax
// 0047f483  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0047f48b  3bc3                 cmp eax, ebx
// 0047f48d  741d                 je 0x47f4ac
// 0047f48f  6a01                 push 1
// 0047f491  6a01                 push 1
// 0047f493  6aff                 push -1
// 0047f495  6a01                 push 1
// 0047f497  68c8000000           push 0xc8
// 0047f49c  680819a700           push 0xa71908
// 0047f4a1  6a01                 push 1
// 0047f4a3  8bc8                 mov ecx, eax
// 0047f4a5  e8460d3b00           call 0x8301f0
// 0047f4aa  eb02                 jmp 0x47f4ae
// 0047f4ac  33c0                 xor eax, eax
// 0047f4ae  50                   push eax
// 0047f4af  8bce                 mov ecx, esi
// 0047f4b1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0047f4b9  e892173b00           call 0x830c50
// 0047f4be  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047f4c2  5f                   pop edi
// 0047f4c3  8998b0000000         mov dword ptr [eax + 0xb0], ebx
// 0047f4c9  5e                   pop esi
// 0047f4ca  33c0                 xor eax, eax
// 0047f4cc  64890d00000000       mov dword ptr fs:[0], ecx
// 0047f4d3  5b                   pop ebx
// 0047f4d4  83c40c               add esp, 0xc
// 0047f4d7  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEHH@Z)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;

struct Table {
    void* reserved0[89];
    void (__thiscall *reset)(S*);
    void* reserved1[11];
    S* (__thiscall *getControl)(S*);
};

struct Options {
    char reserved0[0x7c];
    int field7c;
    char reserved1[8];
    int field88;

    void setEnabled(int);
};

struct Column {
    char reserved0[0xb0];
    int fieldb0;
    char reserved1[0x10];

    Column(int, const char*, int, int, int, int, int);
    void setFlag(int);
};

struct S {
    Table* table;
    char reserved0[0x1b4];
    int field1b8;
    char reserved1[0xcc];
    Options* options;

    int base(int);
    void initialize();
    Column* addColumn(Column*);
    int f(int);
};

int S::f(int argument)
{
    int result = base(argument);
    if (result == -1)
        return result;

    S* control = table->getControl(this);
    control->field1b8 = 0;
    control->initialize();
    control->table->reset(control);
    Options* options88 = control->options;
    options88->field88 = 0;
    Options* options7c = control->options;
    options7c->field7c = 0;
    control->options->setEnabled(1);

    Column* column = control->addColumn(
        new Column(0, "Name", 200, 1, -1, 1, 1));
    column->setFlag(1);
    column->fieldb0 = 0;

    control->addColumn(
        new Column(1, "Value", 200, 1, -1, 1, 1))->fieldb0 = 0;

    return 0;
}