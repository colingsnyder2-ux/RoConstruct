// from server: 100% by Yeetserama
// roc 2007-08 00460360  unit: CScriptEditor  size: 177 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460360
//
// 00460360  6aff                 push -1
// 00460362  6849d87300           push 0x73d849
// 00460367  64a100000000         mov eax, dword ptr fs:[0]
// 0046036d  50                   push eax
// 0046036e  51                   push ecx
// 0046036f  56                   push esi
// 00460370  57                   push edi
// 00460371  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460376  33c4                 xor eax, esp
// 00460378  50                   push eax
// 00460379  8d442410             lea eax, [esp + 0x10]
// 0046037d  64a300000000         mov dword ptr fs:[0], eax
// 00460383  e8a8ceffff           call 0x45d230
// 00460388  8bf0                 mov esi, eax
// 0046038a  6a01                 push 1
// 0046038c  8bce                 mov ecx, esi
// 0046038e  e8cdbbffff           call 0x45bf60
// 00460393  6a01                 push 1
// 00460395  50                   push eax
// 00460396  8bce                 mov ecx, esi
// 00460398  e8b3c6ffff           call 0x45ca50
// 0046039d  6a01                 push 1
// 0046039f  50                   push eax
// 004603a0  8bce                 mov ecx, esi
// 004603a2  e879cbffff           call 0x45cf20
// 004603a7  8bf0                 mov esi, eax
// 004603a9  81e6ff0f0000         and esi, 0xfff
// 004603af  8d4c240c             lea ecx, [esp + 0xc]
// 004603b3  81ee00040000         sub esi, 0x400
// 004603b9  ff15acdd7700         call dword ptr [0x77ddac]
// 004603bf  56                   push esi
// 004603c0  8d442410             lea eax, [esp + 0x10]
// 004603c4  68c9000000           push 0xc9
// 004603c9  50                   push eax
// 004603ca  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004603d2  ff15a4d57700         call dword ptr [0x77d5a4]
// 004603d8  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 004603dc  8b3e                 mov edi, dword ptr [esi]
// 004603de  83c40c               add esp, 0xc
// 004603e1  8d4c240c             lea ecx, [esp + 0xc]
// 004603e5  ff1598dd7700         call dword ptr [0x77dd98]
// 004603eb  8b570c               mov edx, dword ptr [edi + 0xc]
// 004603ee  50                   push eax
// 004603ef  8bce                 mov ecx, esi
// 004603f1  ffd2                 call edx
// 004603f3  8d4c240c             lea ecx, [esp + 0xc]
// 004603f7  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004603fd  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00460401  64890d00000000       mov dword ptr fs:[0], ecx
// 00460408  59                   pop ecx
// 00460409  5f                   pop edi
// 0046040a  5e                   pop esi
// 0046040b  83c410               add esp, 0x10
// 0046040e  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000f_00464300@CScriptEditor@ns_ROCX00000f@@QAEXPAUOutput@2@@Z)

namespace ns_ROCX00000f {
// from server: 100% by colin
struct Control {
    int fn_ROCX00000f_00460120(int);
    int fn_ROCX00000f_00460c10(int, int);
    int fn_ROCX00000f_004610e0(int, int);
};

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
};

extern void (__cdecl* text_format)(Text*, unsigned int, ...);
extern const char* (__thiscall* text_data)(Text*);





struct Output {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void set(const char*) = 0;
};

struct CScriptEditor {
    int* fn_ROCX00000f_004613d0();
    void fn_ROCX00000f_00464300(Output*);
};

void CScriptEditor::fn_ROCX00000f_00464300(Output* output)
{
    Control* control = reinterpret_cast<Control*>(fn_ROCX00000f_004613d0());
    int value = control->fn_ROCX00000f_00460120(1);
    value = control->fn_ROCX00000f_00460c10(value, 1);
    value = control->fn_ROCX00000f_004610e0(value, 1);
    value = (value & 0xfff) - 0x400;

    Text text;
    text_format(&text, 201, value);
    output->set(text_data(&text));
}
}
