// from server: 100% by Yeetserama
// roc 2011-06 0048da90  unit: CScriptEditor  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048da90
//
// 0048da90  6aff                 push -1
// 0048da92  68395f9d00           push 0x9d5f39
// 0048da97  64a100000000         mov eax, dword ptr fs:[0]
// 0048da9d  50                   push eax
// 0048da9e  64892500000000       mov dword ptr fs:[0], esp
// 0048daa5  51                   push ecx
// 0048daa6  56                   push esi
// 0048daa7  8bf1                 mov esi, ecx
// 0048daa9  57                   push edi
// 0048daaa  8d4c2408             lea ecx, [esp + 8]
// 0048daae  ff15b42da400         call dword ptr [0xa42db4]
// 0048dab4  6a01                 push 1
// 0048dab6  8bce                 mov ecx, esi
// 0048dab8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0048dac0  e82bd5ffff           call 0x48aff0
// 0048dac5  8bc8                 mov ecx, eax
// 0048dac7  e864d0ffff           call 0x48ab30
// 0048dacc  85c0                 test eax, eax
// 0048dace  740f                 je 0x48dadf
// 0048dad0  6804e70000           push 0xe704
// 0048dad5  8d4c240c             lea ecx, [esp + 0xc]
// 0048dad9  ff157c1fa400         call dword ptr [0xa41f7c]
// 0048dadf  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0048dae3  8b3e                 mov edi, dword ptr [esi]
// 0048dae5  8d4c2408             lea ecx, [esp + 8]
// 0048dae9  ff15c82da400         call dword ptr [0xa42dc8]
// 0048daef  50                   push eax
// 0048daf0  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048daf3  8bce                 mov ecx, esi
// 0048daf5  ffd0                 call eax
// 0048daf7  8d4c2408             lea ecx, [esp + 8]
// 0048dafb  ff15082ea400         call dword ptr [0xa42e08]
// 0048db01  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048db05  5f                   pop edi
// 0048db06  5e                   pop esi
// 0048db07  64890d00000000       mov dword ptr fs:[0], ecx
// 0048db0e  83c410               add esp, 0x10
// 0048db11  c20400               ret 4
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
