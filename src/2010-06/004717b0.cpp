// from server: 100% by Yeetserama
// roc 2010-06 004717b0  unit: CScriptEditor  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004717b0
//
// 004717b0  6aff                 push -1
// 004717b2  68a9fe9700           push 0x97fea9
// 004717b7  64a100000000         mov eax, dword ptr fs:[0]
// 004717bd  50                   push eax
// 004717be  64892500000000       mov dword ptr fs:[0], esp
// 004717c5  51                   push ecx
// 004717c6  56                   push esi
// 004717c7  57                   push edi
// 004717c8  e823cfffff           call 0x46e6f0
// 004717cd  8bf0                 mov esi, eax
// 004717cf  6a01                 push 1
// 004717d1  8bce                 mov ecx, esi
// 004717d3  e858bcffff           call 0x46d430
// 004717d8  6a01                 push 1
// 004717da  50                   push eax
// 004717db  8bce                 mov ecx, esi
// 004717dd  e83ec7ffff           call 0x46df20
// 004717e2  6a01                 push 1
// 004717e4  50                   push eax
// 004717e5  8bce                 mov ecx, esi
// 004717e7  e804ccffff           call 0x46e3f0
// 004717ec  8bf0                 mov esi, eax
// 004717ee  81e6ff0f0000         and esi, 0xfff
// 004717f4  8d4c2408             lea ecx, [esp + 8]
// 004717f8  81ee00040000         sub esi, 0x400
// 004717fe  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 00471804  56                   push esi
// 00471805  8d44240c             lea eax, [esp + 0xc]
// 00471809  68c9000000           push 0xc9
// 0047180e  50                   push eax
// 0047180f  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00471817  ff1550c39e00         call dword ptr [0x9ec350]
// 0047181d  8b742428             mov esi, dword ptr [esp + 0x28]
// 00471821  8b3e                 mov edi, dword ptr [esi]
// 00471823  83c40c               add esp, 0xc
// 00471826  8d4c2408             lea ecx, [esp + 8]
// 0047182a  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 00471830  8b570c               mov edx, dword ptr [edi + 0xc]
// 00471833  50                   push eax
// 00471834  8bce                 mov ecx, esi
// 00471836  ffd2                 call edx
// 00471838  8d4c2408             lea ecx, [esp + 8]
// 0047183c  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00471842  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00471846  5f                   pop edi
// 00471847  5e                   pop esi
// 00471848  64890d00000000       mov dword ptr fs:[0], ecx
// 0047184f  83c410               add esp, 0x10
// 00471852  c20400               ret 4
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
