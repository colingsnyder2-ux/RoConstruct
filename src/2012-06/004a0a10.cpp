// from server: 100% by Yeetserama
// roc 2012-06 004a0a10  unit: CScriptEditor  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0a10
//
// 004a0a10  83ec1c               sub esp, 0x1c
// 004a0a13  56                   push esi
// 004a0a14  57                   push edi
// 004a0a15  e876320500           call 0x4f3c90
// 004a0a1a  8bf0                 mov esi, eax
// 004a0a1c  6a01                 push 1
// 004a0a1e  8bce                 mov ecx, esi
// 004a0a20  e8bbc8ffff           call 0x49d2e0
// 004a0a25  6a01                 push 1
// 004a0a27  8bce                 mov ecx, esi
// 004a0a29  8bf8                 mov edi, eax
// 004a0a2b  e8e0c8ffff           call 0x49d310
// 004a0a30  3bf8                 cmp edi, eax
// 004a0a32  754d                 jne 0x4a0a81
// 004a0a34  83ff0c               cmp edi, 0xc
// 004a0a37  7e48                 jle 0x4a0a81
// 004a0a39  48                   dec eax
// 004a0a3a  6a01                 push 1
// 004a0a3c  8d4c240c             lea ecx, [esp + 0xc]
// 004a0a40  89442410             mov dword ptr [esp + 0x10], eax
// 004a0a44  8d442418             lea eax, [esp + 0x18]
// 004a0a48  51                   push ecx
// 004a0a49  83c7f3               add edi, -0xd
// 004a0a4c  8bce                 mov ecx, esi
// 004a0a4e  897c2410             mov dword ptr [esp + 0x10], edi
// 004a0a52  89442418             mov dword ptr [esp + 0x18], eax
// 004a0a56  e805caffff           call 0x49d460
// 004a0a5b  8d542414             lea edx, [esp + 0x14]
// 004a0a5f  689807b600           push 0xb60798
// 004a0a64  52                   push edx
// 004a0a65  ff152829b200         call dword ptr [0xb22928]
// 004a0a6b  83c408               add esp, 8
// 004a0a6e  85c0                 test eax, eax
// 004a0a70  750f                 jne 0x4a0a81
// 004a0a72  6a01                 push 1
// 004a0a74  687407b600           push 0xb60774
// 004a0a79  50                   push eax
// 004a0a7a  8bce                 mov ecx, esi
// 004a0a7c  e88fc7ffff           call 0x49d210
// 004a0a81  5f                   pop edi
// 004a0a82  5e                   pop esi
// 004a0a83  83c41c               add esp, 0x1c
// 004a0a86  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000006_00464460@CScriptEditor@ns_ROCX000006@@QAEXH@Z)

namespace ns_ROCX000006 {
// from server: 100% by king_originala
extern "C" int (__cdecl* _stricmp)(const char*, const char*);
extern const char comparisonText[];
extern const char replacementText[];

struct TextRange
{
    int start;
    int end;
    char* text;
};

struct Control
{
    int selectionStart(int direct);
    int selectionEnd(int direct);
    int getTextRange(TextRange* range, int direct);
    int replaceSelection(int unused, const char* text, int direct);
};

struct CScriptEditor
{
    Control* getControl();
    void fn_ROCX000006_00464460(int unused);
};

void CScriptEditor::fn_ROCX000006_00464460(int unused)
{
    Control* control = getControl();
    int start = control->selectionStart(1);
    int end = control->selectionEnd(1);

    if (start == end && start > 12)
    {
        TextRange range;
        char text[16];

        range.end = end - 1;
        range.start = start - 13;
        range.text = text;
        control->getTextRange(&range, 1);

        if (_stricmp(text, comparisonText) == 0)
            control->replaceSelection(0, replacementText, 1);
    }
}
}
