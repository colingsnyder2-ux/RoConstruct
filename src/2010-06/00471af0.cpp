// from server: 100% by Yeetserama
// roc 2010-06 00471af0  unit: CScriptEditor  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471af0
//
// 00471af0  83ec20               sub esp, 0x20
// 00471af3  56                   push esi
// 00471af4  e8f7cbffff           call 0x46e6f0
// 00471af9  8bf0                 mov esi, eax
// 00471afb  ff1580ba9e00         call dword ptr [0x9eba80]
// 00471b01  50                   push eax
// 00471b02  e863613300           call 0x7a7c6a
// 00471b07  85c0                 test eax, eax
// 00471b09  0f84b3000000         je 0x471bc2
// 00471b0f  8b4020               mov eax, dword ptr [eax + 0x20]
// 00471b12  85f6                 test esi, esi
// 00471b14  7504                 jne 0x471b1a
// 00471b16  33c9                 xor ecx, ecx
// 00471b18  eb03                 jmp 0x471b1d
// 00471b1a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00471b1d  3bc1                 cmp eax, ecx
// 00471b1f  0f859d000000         jne 0x471bc2
// 00471b25  57                   push edi
// 00471b26  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00471b2a  8b470c               mov eax, dword ptr [edi + 0xc]
// 00471b2d  83e807               sub eax, 7
// 00471b30  8944242c             mov dword ptr [esp + 0x2c], eax
// 00471b34  85c0                 test eax, eax
// 00471b36  c744240800000000     mov dword ptr [esp + 8], 0
// 00471b3e  8d44242c             lea eax, [esp + 0x2c]
// 00471b42  7f04                 jg 0x471b48
// 00471b44  8d442408             lea eax, [esp + 8]
// 00471b48  8b00                 mov eax, dword ptr [eax]
// 00471b4a  6a01                 push 1
// 00471b4c  8bce                 mov ecx, esi
// 00471b4e  89442410             mov dword ptr [esp + 0x10], eax
// 00471b52  e8a9b8ffff           call 0x46d400
// 00471b57  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00471b5a  83c107               add ecx, 7
// 00471b5d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00471b61  3bc1                 cmp eax, ecx
// 00471b63  894c2408             mov dword ptr [esp + 8], ecx
// 00471b67  8d44242c             lea eax, [esp + 0x2c]
// 00471b6b  7c04                 jl 0x471b71
// 00471b6d  8d442408             lea eax, [esp + 8]
// 00471b71  8b08                 mov ecx, dword ptr [eax]
// 00471b73  6a01                 push 1
// 00471b75  8d442410             lea eax, [esp + 0x10]
// 00471b79  894c2414             mov dword ptr [esp + 0x14], ecx
// 00471b7d  8d54241c             lea edx, [esp + 0x1c]
// 00471b81  50                   push eax
// 00471b82  8bce                 mov ecx, esi
// 00471b84  8954241c             mov dword ptr [esp + 0x1c], edx
// 00471b88  e893c2ffff           call 0x46de20
// 00471b8d  8d4c2418             lea ecx, [esp + 0x18]
// 00471b91  51                   push ecx
// 00471b92  ff1560a79e00         call dword ptr [0x9ea760]
// 00471b98  8d54241c             lea edx, [esp + 0x1c]
// 00471b9c  68940ea100           push 0xa10e94
// 00471ba1  52                   push edx
// 00471ba2  ff1530a79e00         call dword ptr [0x9ea730]
// 00471ba8  83c40c               add esp, 0xc
// 00471bab  85c0                 test eax, eax
// 00471bad  7412                 je 0x471bc1
// 00471baf  8b470c               mov eax, dword ptr [edi + 0xc]
// 00471bb2  6a01                 push 1
// 00471bb4  68880ea100           push 0xa10e88
// 00471bb9  50                   push eax
// 00471bba  8bce                 mov ecx, esi
// 00471bbc  e87fc7ffff           call 0x46e340
// 00471bc1  5f                   pop edi
// 00471bc2  5e                   pop esi
// 00471bc3  83c420               add esp, 0x20
// 00471bc6  c20400               ret 4
// copied from an identical function in another client (function ?f@CScriptEditor@ns_ROCX000009@@QAEXPAUEvent@2@@Z)

namespace ns_ROCX000009 {
// from server: 100% by king_originala
struct TextRange {
    int first;
    int last;
    char* text;
};

struct Control {
    char padding[32];
    void* window;
    int length(int direct);
    int getText(TextRange* range, int direct);
    void insertText(int position, const char* text, int direct);
};

struct Event {
    char padding[12];
    int position;
};

struct CScriptEditor {
    int* control();
    void f(Event* event);
};

extern "C" {
    extern void* (__stdcall *GetFocus)();
    extern char* (__cdecl *_strupr)(char*);
    extern char* (__cdecl *strstr)(const char*, const char*);
}

extern Control* __stdcall fromHandle(void* window);
extern const char authorText[];
extern const char replacementText[];

template<class T>
const T& minimum(const T& a, const T& b)
{
    return a < b ? a : b;
}

template<class T>
const T& maximum(const T& a, const T& b)
{
    return a > b ? a : b;
}

void CScriptEditor::f(Event* event)
{
    Control* editor = reinterpret_cast<Control*>(control());
    Control* focused = fromHandle(GetFocus());
    if (!focused)
        return;

    void* focusedWindow = focused->window;
    void* editorWindow;
    if (!editor)
        editorWindow = 0;
    else
        editorWindow = editor->window;

    if (focusedWindow == editorWindow) {
        char text[16];
        TextRange range;
        range.first = maximum(event->position - 7, 0);
        int length = editor->length(1);
        range.last = minimum(length, event->position + 7);
        range.text = text;
        editor->getText(&range, 1);
        _strupr(text);
        if (strstr(text, authorText))
            editor->insertText(event->position, replacementText, 1);
    }
}
}
