// from server: 100% by Yeetserama
// roc 2012-06 004a08b0  unit: CScriptEditor  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a08b0
//
// 004a08b0  6aff                 push -1
// 004a08b2  68d9aea900           push 0xa9aed9
// 004a08b7  64a100000000         mov eax, dword ptr fs:[0]
// 004a08bd  50                   push eax
// 004a08be  64892500000000       mov dword ptr fs:[0], esp
// 004a08c5  51                   push ecx
// 004a08c6  56                   push esi
// 004a08c7  57                   push edi
// 004a08c8  e8c3330500           call 0x4f3c90
// 004a08cd  8bf0                 mov esi, eax
// 004a08cf  6a01                 push 1
// 004a08d1  8bce                 mov ecx, esi
// 004a08d3  e858c1ffff           call 0x49ca30
// 004a08d8  6a01                 push 1
// 004a08da  50                   push eax
// 004a08db  8bce                 mov ecx, esi
// 004a08dd  e87eccffff           call 0x49d560
// 004a08e2  6a01                 push 1
// 004a08e4  50                   push eax
// 004a08e5  8bce                 mov ecx, esi
// 004a08e7  e844d1ffff           call 0x49da30
// 004a08ec  8bf0                 mov esi, eax
// 004a08ee  81e6ff0f0000         and esi, 0xfff
// 004a08f4  8d4c2408             lea ecx, [esp + 8]
// 004a08f8  81ee00040000         sub esi, 0x400
// 004a08fe  ff158447b200         call dword ptr [0xb24784]
// 004a0904  56                   push esi
// 004a0905  8d44240c             lea eax, [esp + 0xc]
// 004a0909  68c9000000           push 0xc9
// 004a090e  50                   push eax
// 004a090f  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004a0917  ff150043b200         call dword ptr [0xb24300]
// 004a091d  8b742428             mov esi, dword ptr [esp + 0x28]
// 004a0921  8b3e                 mov edi, dword ptr [esi]
// 004a0923  83c40c               add esp, 0xc
// 004a0926  8d4c2408             lea ecx, [esp + 8]
// 004a092a  ff159847b200         call dword ptr [0xb24798]
// 004a0930  8b570c               mov edx, dword ptr [edi + 0xc]
// 004a0933  50                   push eax
// 004a0934  8bce                 mov ecx, esi
// 004a0936  ffd2                 call edx
// 004a0938  8d4c2408             lea ecx, [esp + 8]
// 004a093c  ff15d047b200         call dword ptr [0xb247d0]
// 004a0942  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a0946  5f                   pop edi
// 004a0947  5e                   pop esi
// 004a0948  64890d00000000       mov dword ptr fs:[0], ecx
// 004a094f  83c410               add esp, 0x10
// 004a0952  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000004_00464300@CScriptEditor@ns_ROCX000004@@QAEXPAUOutput@2@@Z)

namespace ns_ROCX000004 {
// from server: 100% by colin
struct Control {
    int fn_ROCX000004_00460120(int);
    int fn_ROCX000004_00460c10(int, int);
    int fn_ROCX000004_004610e0(int, int);
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
    int* fn_ROCX000004_004613d0();
    void fn_ROCX000004_00464300(Output*);
};

void CScriptEditor::fn_ROCX000004_00464300(Output* output)
{
    Control* control = reinterpret_cast<Control*>(fn_ROCX000004_004613d0());
    int value = control->fn_ROCX000004_00460120(1);
    value = control->fn_ROCX000004_00460c10(value, 1);
    value = control->fn_ROCX000004_004610e0(value, 1);
    value = (value & 0xfff) - 0x400;

    Text text;
    text_format(&text, 201, value);
    output->set(text_data(&text));
}
}
