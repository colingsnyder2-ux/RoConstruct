// from server: 100% by Yeetserama
// roc 2011-06 0048ddc0  unit: CScriptEditor  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048ddc0
//
// 0048ddc0  83ec20               sub esp, 0x20
// 0048ddc3  56                   push esi
// 0048ddc4  e827d2ffff           call 0x48aff0
// 0048ddc9  8bf0                 mov esi, eax
// 0048ddcb  ff15f819a400         call dword ptr [0xa419f8]
// 0048ddd1  50                   push eax
// 0048ddd2  e851c53700           call 0x80a328
// 0048ddd7  85c0                 test eax, eax
// 0048ddd9  0f84b3000000         je 0x48de92
// 0048dddf  8b4020               mov eax, dword ptr [eax + 0x20]
// 0048dde2  85f6                 test esi, esi
// 0048dde4  7504                 jne 0x48ddea
// 0048dde6  33c9                 xor ecx, ecx
// 0048dde8  eb03                 jmp 0x48dded
// 0048ddea  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0048dded  3bc1                 cmp eax, ecx
// 0048ddef  0f859d000000         jne 0x48de92
// 0048ddf5  57                   push edi
// 0048ddf6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048ddfa  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048ddfd  83e807               sub eax, 7
// 0048de00  8944242c             mov dword ptr [esp + 0x2c], eax
// 0048de04  85c0                 test eax, eax
// 0048de06  c744240800000000     mov dword ptr [esp + 8], 0
// 0048de0e  8d44242c             lea eax, [esp + 0x2c]
// 0048de12  7f04                 jg 0x48de18
// 0048de14  8d442408             lea eax, [esp + 8]
// 0048de18  8b00                 mov eax, dword ptr [eax]
// 0048de1a  6a01                 push 1
// 0048de1c  8bce                 mov ecx, esi
// 0048de1e  89442410             mov dword ptr [esp + 0x10], eax
// 0048de22  e8a9beffff           call 0x489cd0
// 0048de27  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0048de2a  83c107               add ecx, 7
// 0048de2d  8944242c             mov dword ptr [esp + 0x2c], eax
// 0048de31  3bc1                 cmp eax, ecx
// 0048de33  894c2408             mov dword ptr [esp + 8], ecx
// 0048de37  8d44242c             lea eax, [esp + 0x2c]
// 0048de3b  7c04                 jl 0x48de41
// 0048de3d  8d442408             lea eax, [esp + 8]
// 0048de41  8b08                 mov ecx, dword ptr [eax]
// 0048de43  6a01                 push 1
// 0048de45  8d442410             lea eax, [esp + 0x10]
// 0048de49  894c2414             mov dword ptr [esp + 0x14], ecx
// 0048de4d  8d54241c             lea edx, [esp + 0x1c]
// 0048de51  50                   push eax
// 0048de52  8bce                 mov ecx, esi
// 0048de54  8954241c             mov dword ptr [esp + 0x1c], edx
// 0048de58  e8d3c8ffff           call 0x48a730
// 0048de5d  8d4c2418             lea ecx, [esp + 0x18]
// 0048de61  51                   push ecx
// 0048de62  ff154807a400         call dword ptr [0xa40748]
// 0048de68  8d54241c             lea edx, [esp + 0x1c]
// 0048de6c  68ec41a700           push 0xa741ec
// 0048de71  52                   push edx
// 0048de72  ff158009a400         call dword ptr [0xa40980]
// 0048de78  83c40c               add esp, 0xc
// 0048de7b  85c0                 test eax, eax
// 0048de7d  7412                 je 0x48de91
// 0048de7f  8b470c               mov eax, dword ptr [edi + 0xc]
// 0048de82  6a01                 push 1
// 0048de84  68e4e7a500           push 0xa5e7e4
// 0048de89  50                   push eax
// 0048de8a  8bce                 mov ecx, esi
// 0048de8c  e8bfcdffff           call 0x48ac50
// 0048de91  5f                   pop edi
// 0048de92  5e                   pop esi
// 0048de93  83c420               add esp, 0x20
// 0048de96  c20400               ret 4
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
