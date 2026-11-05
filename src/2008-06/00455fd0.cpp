// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 00455fd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00455fd0
//
// 00455fd0  64a100000000         mov eax, dword ptr fs:[0]
// 00455fd6  6aff                 push -1
// 00455fd8  6894fa7b00           push 0x7bfa94
// 00455fdd  50                   push eax
// 00455fde  64892500000000       mov dword ptr fs:[0], esp
// 00455fe5  8b442410             mov eax, dword ptr [esp + 0x10]
// 00455fe9  53                   push ebx
// 00455fea  56                   push esi
// 00455feb  57                   push edi
// 00455fec  50                   push eax
// 00455fed  8bf1                 mov esi, ecx
// 00455fef  e8acf22600           call 0x6c52a0
// 00455ff4  83f8ff               cmp eax, -1
// 00455ff7  7516                 jne 0x45600f
// 00455ff9  0bc0                 or eax, eax
// 00455ffb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00455fff  64890d00000000       mov dword ptr fs:[0], ecx
// 00456006  5f                   pop edi
// 00456007  5e                   pop esi
// 00456008  5b                   pop ebx
// 00456009  83c40c               add esp, 0xc
// 0045600c  c20400               ret 4
// 0045600f  8b16                 mov edx, dword ptr [esi]
// 00456011  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 00456017  8bce                 mov ecx, esi
// 00456019  ffd0                 call eax
// 0045601b  8bf0                 mov esi, eax
// 0045601d  33db                 xor ebx, ebx
// 0045601f  8bce                 mov ecx, esi
// 00456021  899eb8010000         mov dword ptr [esi + 0x1b8], ebx
// 00456027  e8e4682700           call 0x6cc910
// 0045602c  8b16                 mov edx, dword ptr [esi]
// 0045602e  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 00456034  8bce                 mov ecx, esi
// 00456036  ffd0                 call eax
// 00456038  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0045603e  899888000000         mov dword ptr [eax + 0x88], ebx
// 00456044  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0045604a  89587c               mov dword ptr [eax + 0x7c], ebx
// 0045604d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00456053  6a01                 push 1
// 00456055  e836082800           call 0x6d6890
// 0045605a  68c4000000           push 0xc4
// 0045605f  e8bca82400           call 0x6a0920
// 00456064  83c404               add esp, 4
// 00456067  8944241c             mov dword ptr [esp + 0x1c], eax
// 0045606b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0045606f  3bc3                 cmp eax, ebx
// 00456071  741c                 je 0x45608f
// 00456073  6a01                 push 1
// 00456075  6a01                 push 1
// 00456077  6aff                 push -1
// 00456079  6a01                 push 1
// 0045607b  68c8000000           push 0xc8
// 00456080  68ccf78000           push 0x80f7cc
// 00456085  53                   push ebx
// 00456086  8bc8                 mov ecx, eax
// 00456088  e8e3ea2700           call 0x6d4b70
// 0045608d  eb02                 jmp 0x456091
// 0045608f  33c0                 xor eax, eax
// 00456091  50                   push eax
// 00456092  8bce                 mov ecx, esi
// 00456094  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0045609c  e85f352700           call 0x6c9600
// 004560a1  8bf8                 mov edi, eax
// 004560a3  6a01                 push 1
// 004560a5  8bcf                 mov ecx, edi
// 004560a7  e8d4e82700           call 0x6d4980
// 004560ac  68c4000000           push 0xc4
// 004560b1  899fb0000000         mov dword ptr [edi + 0xb0], ebx
// 004560b7  e864a82400           call 0x6a0920
// 004560bc  83c404               add esp, 4
// 004560bf  8944241c             mov dword ptr [esp + 0x1c], eax
// 004560c3  c744241401000000     mov dword ptr [esp + 0x14], 1
// 004560cb  3bc3                 cmp eax, ebx
// 004560cd  741d                 je 0x4560ec
// 004560cf  6a01                 push 1
// 004560d1  6a01                 push 1
// 004560d3  6aff                 push -1
// 004560d5  6a01                 push 1
// 004560d7  68c8000000           push 0xc8
// 004560dc  6878848100           push 0x818478
// 004560e1  6a01                 push 1
// 004560e3  8bc8                 mov ecx, eax
// 004560e5  e886ea2700           call 0x6d4b70
// 004560ea  eb02                 jmp 0x4560ee
// 004560ec  33c0                 xor eax, eax
// 004560ee  50                   push eax
// 004560ef  8bce                 mov ecx, esi
// 004560f1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004560f9  e802352700           call 0x6c9600
// 004560fe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00456102  5f                   pop edi
// 00456103  8998b0000000         mov dword ptr [eax + 0xb0], ebx
// 00456109  5e                   pop esi
// 0045610a  33c0                 xor eax, eax
// 0045610c  64890d00000000       mov dword ptr fs:[0], ecx
// 00456113  5b                   pop ebx
// 00456114  83c40c               add esp, 0xc
// 00456117  c20400               ret 4

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
