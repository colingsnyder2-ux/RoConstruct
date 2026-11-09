// from server: 100% by Yeetserama
// roc 2011-06 0048dd10  unit: CScriptEditor  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048dd10
//
// 0048dd10  83ec1c               sub esp, 0x1c
// 0048dd13  56                   push esi
// 0048dd14  57                   push edi
// 0048dd15  e8d6d2ffff           call 0x48aff0
// 0048dd1a  8bf0                 mov esi, eax
// 0048dd1c  6a01                 push 1
// 0048dd1e  8bce                 mov ecx, esi
// 0048dd20  e88bc8ffff           call 0x48a5b0
// 0048dd25  6a01                 push 1
// 0048dd27  8bce                 mov ecx, esi
// 0048dd29  8bf8                 mov edi, eax
// 0048dd2b  e8b0c8ffff           call 0x48a5e0
// 0048dd30  3bf8                 cmp edi, eax
// 0048dd32  754d                 jne 0x48dd81
// 0048dd34  83ff0c               cmp edi, 0xc
// 0048dd37  7e48                 jle 0x48dd81
// 0048dd39  48                   dec eax
// 0048dd3a  6a01                 push 1
// 0048dd3c  8d4c240c             lea ecx, [esp + 0xc]
// 0048dd40  89442410             mov dword ptr [esp + 0x10], eax
// 0048dd44  8d442418             lea eax, [esp + 0x18]
// 0048dd48  51                   push ecx
// 0048dd49  83c7f3               add edi, -0xd
// 0048dd4c  8bce                 mov ecx, esi
// 0048dd4e  897c2410             mov dword ptr [esp + 0x10], edi
// 0048dd52  89442418             mov dword ptr [esp + 0x18], eax
// 0048dd56  e8d5c9ffff           call 0x48a730
// 0048dd5b  8d542414             lea edx, [esp + 0x14]
// 0048dd5f  68d841a700           push 0xa741d8
// 0048dd64  52                   push edx
// 0048dd65  ff150c09a400         call dword ptr [0xa4090c]
// 0048dd6b  83c408               add esp, 8
// 0048dd6e  85c0                 test eax, eax
// 0048dd70  750f                 jne 0x48dd81
// 0048dd72  6a01                 push 1
// 0048dd74  68b441a700           push 0xa741b4
// 0048dd79  50                   push eax
// 0048dd7a  8bce                 mov ecx, esi
// 0048dd7c  e85fc7ffff           call 0x48a4e0
// 0048dd81  5f                   pop edi
// 0048dd82  5e                   pop esi
// 0048dd83  83c41c               add esp, 0x1c
// 0048dd86  c20400               ret 4
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
