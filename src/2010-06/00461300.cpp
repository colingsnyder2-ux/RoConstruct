// from server: 100% by Yeetserama
// roc 2010-06 00461300  unit: CRobloxReportPaneView  size: 330 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00461300
//
// 00461300  64a100000000         mov eax, dword ptr fs:[0]
// 00461306  6aff                 push -1
// 00461308  6894359800           push 0x983594
// 0046130d  50                   push eax
// 0046130e  64892500000000       mov dword ptr fs:[0], esp
// 00461315  8b442410             mov eax, dword ptr [esp + 0x10]
// 00461319  53                   push ebx
// 0046131a  56                   push esi
// 0046131b  57                   push edi
// 0046131c  50                   push eax
// 0046131d  8bf1                 mov esi, ecx
// 0046131f  e8ecb43600           call 0x7cc810
// 00461324  83f8ff               cmp eax, -1
// 00461327  7516                 jne 0x46133f
// 00461329  0bc0                 or eax, eax
// 0046132b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046132f  64890d00000000       mov dword ptr fs:[0], ecx
// 00461336  5f                   pop edi
// 00461337  5e                   pop esi
// 00461338  5b                   pop ebx
// 00461339  83c40c               add esp, 0xc
// 0046133c  c20400               ret 4
// 0046133f  8b16                 mov edx, dword ptr [esi]
// 00461341  8b8294010000         mov eax, dword ptr [edx + 0x194]
// 00461347  8bce                 mov ecx, esi
// 00461349  ffd0                 call eax
// 0046134b  8bf0                 mov esi, eax
// 0046134d  33db                 xor ebx, ebx
// 0046134f  8bce                 mov ecx, esi
// 00461351  899eb8010000         mov dword ptr [esi + 0x1b8], ebx
// 00461357  e8642b3700           call 0x7d3ec0
// 0046135c  8b16                 mov edx, dword ptr [esi]
// 0046135e  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 00461364  8bce                 mov ecx, esi
// 00461366  ffd0                 call eax
// 00461368  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0046136e  899888000000         mov dword ptr [eax + 0x88], ebx
// 00461374  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 0046137a  89587c               mov dword ptr [eax + 0x7c], ebx
// 0046137d  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00461383  6a01                 push 1
// 00461385  e8b6ca3700           call 0x7dde40
// 0046138a  68c4000000           push 0xc4
// 0046138f  e80c663400           call 0x7a79a0
// 00461394  83c404               add esp, 4
// 00461397  8944241c             mov dword ptr [esp + 0x1c], eax
// 0046139b  895c2414             mov dword ptr [esp + 0x14], ebx
// 0046139f  3bc3                 cmp eax, ebx
// 004613a1  741c                 je 0x4613bf
// 004613a3  6a01                 push 1
// 004613a5  6a01                 push 1
// 004613a7  6aff                 push -1
// 004613a9  6a01                 push 1
// 004613ab  68c8000000           push 0xc8
// 004613b0  68a039a000           push 0xa039a0
// 004613b5  53                   push ebx
// 004613b6  8bc8                 mov ecx, eax
// 004613b8  e863ad3700           call 0x7dc120
// 004613bd  eb02                 jmp 0x4613c1
// 004613bf  33c0                 xor eax, eax
// 004613c1  50                   push eax
// 004613c2  8bce                 mov ecx, esi
// 004613c4  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004613cc  e84ff73600           call 0x7d0b20
// 004613d1  8bf8                 mov edi, eax
// 004613d3  6a01                 push 1
// 004613d5  8bcf                 mov ecx, edi
// 004613d7  e854ab3700           call 0x7dbf30
// 004613dc  68c4000000           push 0xc4
// 004613e1  899fb0000000         mov dword ptr [edi + 0xb0], ebx
// 004613e7  e8b4653400           call 0x7a79a0
// 004613ec  83c404               add esp, 4
// 004613ef  8944241c             mov dword ptr [esp + 0x1c], eax
// 004613f3  c744241401000000     mov dword ptr [esp + 0x14], 1
// 004613fb  3bc3                 cmp eax, ebx
// 004613fd  741d                 je 0x46141c
// 004613ff  6a01                 push 1
// 00461401  6a01                 push 1
// 00461403  6aff                 push -1
// 00461405  6a01                 push 1
// 00461407  68c8000000           push 0xc8
// 0046140c  684ce4a000           push 0xa0e44c
// 00461411  6a01                 push 1
// 00461413  8bc8                 mov ecx, eax
// 00461415  e806ad3700           call 0x7dc120
// 0046141a  eb02                 jmp 0x46141e
// 0046141c  33c0                 xor eax, eax
// 0046141e  50                   push eax
// 0046141f  8bce                 mov ecx, esi
// 00461421  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00461429  e8f2f63600           call 0x7d0b20
// 0046142e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00461432  5f                   pop edi
// 00461433  8998b0000000         mov dword ptr [eax + 0xb0], ebx
// 00461439  5e                   pop esi
// 0046143a  33c0                 xor eax, eax
// 0046143c  64890d00000000       mov dword ptr fs:[0], ecx
// 00461443  5b                   pop ebx
// 00461444  83c40c               add esp, 0xc
// 00461447  c20400               ret 4
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