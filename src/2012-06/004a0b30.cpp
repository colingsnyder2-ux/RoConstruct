// from server: 100% by Xemicl
// roc 2012-06 004a0b30  unit: CScriptEditor  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0b30
//
// 004a0b30  83ec20               sub esp, 0x20
// 004a0b33  56                   push esi
// 004a0b34  e857310500           call 0x4f3c90
// 004a0b39  8bf0                 mov esi, eax
// 004a0b3b  ff15e83bb200         call dword ptr [0xb23be8]
// 004a0b41  50                   push eax
// 004a0b42  e81f1b4e00           call 0x982666
// 004a0b47  85c0                 test eax, eax
// 004a0b49  0f84b3000000         je 0x4a0c02
// 004a0b4f  8b4020               mov eax, dword ptr [eax + 0x20]
// 004a0b52  85f6                 test esi, esi
// 004a0b54  7504                 jne 0x4a0b5a
// 004a0b56  33c9                 xor ecx, ecx
// 004a0b58  eb03                 jmp 0x4a0b5d
// 004a0b5a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 004a0b5d  3bc1                 cmp eax, ecx
// 004a0b5f  0f859d000000         jne 0x4a0c02
// 004a0b65  57                   push edi
// 004a0b66  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004a0b6a  8b470c               mov eax, dword ptr [edi + 0xc]
// 004a0b6d  83e807               sub eax, 7
// 004a0b70  8944242c             mov dword ptr [esp + 0x2c], eax
// 004a0b74  85c0                 test eax, eax
// 004a0b76  c744240800000000     mov dword ptr [esp + 8], 0
// 004a0b7e  8d44242c             lea eax, [esp + 0x2c]
// 004a0b82  7f04                 jg 0x4a0b88
// 004a0b84  8d442408             lea eax, [esp + 8]
// 004a0b88  8b00                 mov eax, dword ptr [eax]
// 004a0b8a  6a01                 push 1
// 004a0b8c  8bce                 mov ecx, esi
// 004a0b8e  89442410             mov dword ptr [esp + 0x10], eax
// 004a0b92  e869beffff           call 0x49ca00
// 004a0b97  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004a0b9a  83c107               add ecx, 7
// 004a0b9d  8944242c             mov dword ptr [esp + 0x2c], eax
// 004a0ba1  3bc1                 cmp eax, ecx
// 004a0ba3  894c2408             mov dword ptr [esp + 8], ecx
// 004a0ba7  8d44242c             lea eax, [esp + 0x2c]
// 004a0bab  7c04                 jl 0x4a0bb1
// 004a0bad  8d442408             lea eax, [esp + 8]
// 004a0bb1  8b08                 mov ecx, dword ptr [eax]
// 004a0bb3  6a01                 push 1
// 004a0bb5  8d442410             lea eax, [esp + 0x10]
// 004a0bb9  894c2414             mov dword ptr [esp + 0x14], ecx
// 004a0bbd  8d54241c             lea edx, [esp + 0x1c]
// 004a0bc1  50                   push eax
// 004a0bc2  8bce                 mov ecx, esi
// 004a0bc4  8954241c             mov dword ptr [esp + 0x1c], edx
// 004a0bc8  e893c8ffff           call 0x49d460
// 004a0bcd  8d4c2418             lea ecx, [esp + 0x18]
// 004a0bd1  51                   push ecx
// 004a0bd2  ff15842ab200         call dword ptr [0xb22a84]
// 004a0bd8  8d54241c             lea edx, [esp + 0x1c]
// 004a0bdc  68ac07b600           push 0xb607ac
// 004a0be1  52                   push edx
// 004a0be2  ff159829b200         call dword ptr [0xb22998]
// 004a0be8  83c40c               add esp, 0xc
// 004a0beb  85c0                 test eax, eax
// 004a0bed  7412                 je 0x4a0c01
// 004a0bef  8b470c               mov eax, dword ptr [edi + 0xc]
// 004a0bf2  6a01                 push 1
// 004a0bf4  68d46cb400           push 0xb46cd4
// 004a0bf9  50                   push eax
// 004a0bfa  8bce                 mov ecx, esi
// 004a0bfc  e87fcdffff           call 0x49d980
// 004a0c01  5f                   pop edi
// 004a0c02  5e                   pop esi
// 004a0c03  83c420               add esp, 0x20
// 004a0c06  c20400               ret 4
// copied from an identical function in another client (function ?f@CScriptEditor@ns_ROCX000012@@QAEXPAUEvent@2@@Z)

namespace ns_ROCX000012 {
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