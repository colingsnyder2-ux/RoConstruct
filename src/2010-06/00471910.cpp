// from server: 100% by Yeetserama
// roc 2010-06 00471910  unit: CScriptEditor  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471910
//
// 00471910  83ec1c               sub esp, 0x1c
// 00471913  56                   push esi
// 00471914  57                   push edi
// 00471915  e8d6cdffff           call 0x46e6f0
// 0047191a  8bf0                 mov esi, eax
// 0047191c  6a01                 push 1
// 0047191e  8bce                 mov ecx, esi
// 00471920  e87bc3ffff           call 0x46dca0
// 00471925  6a01                 push 1
// 00471927  8bce                 mov ecx, esi
// 00471929  8bf8                 mov edi, eax
// 0047192b  e8a0c3ffff           call 0x46dcd0
// 00471930  3bf8                 cmp edi, eax
// 00471932  754d                 jne 0x471981
// 00471934  83ff0c               cmp edi, 0xc
// 00471937  7e48                 jle 0x471981
// 00471939  48                   dec eax
// 0047193a  6a01                 push 1
// 0047193c  8d4c240c             lea ecx, [esp + 0xc]
// 00471940  89442410             mov dword ptr [esp + 0x10], eax
// 00471944  8d442418             lea eax, [esp + 0x18]
// 00471948  51                   push ecx
// 00471949  83c7f3               add edi, -0xd
// 0047194c  8bce                 mov ecx, esi
// 0047194e  897c2410             mov dword ptr [esp + 0x10], edi
// 00471952  89442418             mov dword ptr [esp + 0x18], eax
// 00471956  e8c5c4ffff           call 0x46de20
// 0047195b  8d542414             lea edx, [esp + 0x14]
// 0047195f  68640ea100           push 0xa10e64
// 00471964  52                   push edx
// 00471965  ff15a4a79e00         call dword ptr [0x9ea7a4]
// 0047196b  83c408               add esp, 8
// 0047196e  85c0                 test eax, eax
// 00471970  750f                 jne 0x471981
// 00471972  6a01                 push 1
// 00471974  68400ea100           push 0xa10e40
// 00471979  50                   push eax
// 0047197a  8bce                 mov ecx, esi
// 0047197c  e84fc2ffff           call 0x46dbd0
// 00471981  5f                   pop edi
// 00471982  5e                   pop esi
// 00471983  83c41c               add esp, 0x1c
// 00471986  c20400               ret 4
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
