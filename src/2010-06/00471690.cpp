// from server: 100% by Yeetserama
// roc 2010-06 00471690  unit: CScriptEditor  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471690
//
// 00471690  6aff                 push -1
// 00471692  68a9fe9700           push 0x97fea9
// 00471697  64a100000000         mov eax, dword ptr fs:[0]
// 0047169d  50                   push eax
// 0047169e  64892500000000       mov dword ptr fs:[0], esp
// 004716a5  51                   push ecx
// 004716a6  56                   push esi
// 004716a7  8bf1                 mov esi, ecx
// 004716a9  57                   push edi
// 004716aa  8d4c2408             lea ecx, [esp + 8]
// 004716ae  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 004716b4  6a01                 push 1
// 004716b6  8bce                 mov ecx, esi
// 004716b8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004716c0  e82bd0ffff           call 0x46e6f0
// 004716c5  8bc8                 mov ecx, eax
// 004716c7  e854cbffff           call 0x46e220
// 004716cc  85c0                 test eax, eax
// 004716ce  740f                 je 0x4716df
// 004716d0  6804e70000           push 0xe704
// 004716d5  8d4c240c             lea ecx, [esp + 0xc]
// 004716d9  ff15b8bf9e00         call dword ptr [0x9ebfb8]
// 004716df  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004716e3  8b3e                 mov edi, dword ptr [esi]
// 004716e5  8d4c2408             lea ecx, [esp + 8]
// 004716e9  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 004716ef  50                   push eax
// 004716f0  8b470c               mov eax, dword ptr [edi + 0xc]
// 004716f3  8bce                 mov ecx, esi
// 004716f5  ffd0                 call eax
// 004716f7  8d4c2408             lea ecx, [esp + 8]
// 004716fb  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00471701  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00471705  5f                   pop edi
// 00471706  5e                   pop esi
// 00471707  64890d00000000       mov dword ptr fs:[0], ecx
// 0047170e  83c410               add esp, 0x10
// 00471711  c20400               ret 4
// copied from an identical function in another client (function ?update@CScriptEditor@ns_ROCX000002@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX000002 {
// from server: 100% by colin
struct Text;

extern const char* (__thiscall *textData)(const Text*);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) int load(unsigned int);
    operator const char*() const;
};







inline Text::operator const char*() const
{
    return textData(this);
}

struct Command {
    virtual void enable(int);
    virtual void check(int);
    virtual void radio(int);
    virtual void setText(const char*);
};

struct Control {
    int query(int);
};

struct CScriptEditor {
    int* f();
    void update(Command*);
};

void CScriptEditor::update(Command* command)
{
    Text text;
    if (reinterpret_cast<Control*>(f())->query(1))
        text.load(0xe704);

    typedef void (__thiscall *SetText)(Command*, const char*);
    SetText* table = *reinterpret_cast<SetText**>(command);
    const char* value = text;
    table[3](command, value);
}
}
