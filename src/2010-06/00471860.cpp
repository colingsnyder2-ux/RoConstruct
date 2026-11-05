// from server: 100% by Yeetserama
// roc 2010-06 00471860  unit: CScriptEditor  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471860
//
// 00471860  6aff                 push -1
// 00471862  68a9fe9700           push 0x97fea9
// 00471867  64a100000000         mov eax, dword ptr fs:[0]
// 0047186d  50                   push eax
// 0047186e  64892500000000       mov dword ptr fs:[0], esp
// 00471875  51                   push ecx
// 00471876  53                   push ebx
// 00471877  56                   push esi
// 00471878  57                   push edi
// 00471879  e872ceffff           call 0x46e6f0
// 0047187e  8bf0                 mov esi, eax
// 00471880  6a01                 push 1
// 00471882  8bce                 mov ecx, esi
// 00471884  e8a7bbffff           call 0x46d430
// 00471889  8bf8                 mov edi, eax
// 0047188b  6a01                 push 1
// 0047188d  57                   push edi
// 0047188e  8bce                 mov ecx, esi
// 00471890  e88bc6ffff           call 0x46df20
// 00471895  6a01                 push 1
// 00471897  57                   push edi
// 00471898  8bce                 mov ecx, esi
// 0047189a  8bd8                 mov ebx, eax
// 0047189c  e8bfc3ffff           call 0x46dc60
// 004718a1  8d4c240c             lea ecx, [esp + 0xc]
// 004718a5  8bf0                 mov esi, eax
// 004718a7  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 004718ad  57                   push edi
// 004718ae  56                   push esi
// 004718af  53                   push ebx
// 004718b0  8d442418             lea eax, [esp + 0x18]
// 004718b4  68c7000000           push 0xc7
// 004718b9  50                   push eax
// 004718ba  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004718c2  ff1550c39e00         call dword ptr [0x9ec350]
// 004718c8  8b742434             mov esi, dword ptr [esp + 0x34]
// 004718cc  8b3e                 mov edi, dword ptr [esi]
// 004718ce  83c414               add esp, 0x14
// 004718d1  8d4c240c             lea ecx, [esp + 0xc]
// 004718d5  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 004718db  8b570c               mov edx, dword ptr [edi + 0xc]
// 004718de  50                   push eax
// 004718df  8bce                 mov ecx, esi
// 004718e1  ffd2                 call edx
// 004718e3  8d4c240c             lea ecx, [esp + 0xc]
// 004718e7  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 004718ed  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004718f1  5f                   pop edi
// 004718f2  5e                   pop esi
// 004718f3  5b                   pop ebx
// 004718f4  64890d00000000       mov dword ptr fs:[0], ecx
// 004718fb  83c410               add esp, 0x10
// 004718fe  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX000005@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX000005 {
// from server: 100% by colin
struct Text;

extern void (__cdecl *formatText)(Text*, unsigned int, ...);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) const char* get() const;
};







struct Control {
    int query(int);
    int column(int, int);
    int line(int, int);
};

struct Target;

struct TargetTable {
    void (__thiscall *slot0)(Target*);
    void (__thiscall *slot1)(Target*);
    void (__thiscall *slot2)(Target*);
    void (__thiscall *setText)(Target*, const char*);
};

struct Target {
    TargetTable* table;
};

struct S {
    int* f();
    void update(Target*);
};

void S::update(Target* target)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->query(1);
    int column = control->column(position, 1);
    int line = control->line(position, 1);
    Text text;
    formatText(&text, 199, column, line, position);
    TargetTable* table = target->table;
    const char* value = text.get();
    table->setText(target, value);
}
}
