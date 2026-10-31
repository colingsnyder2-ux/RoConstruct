// from server: 100% by EspClaude
// roc 2009-06 00465400  unit: CScriptEditor  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00465400
//
// 00465400  83ec20               sub esp, 0x20
// 00465403  56                   push esi
// 00465404  e837ccffff           call 0x462040
// 00465409  8bf0                 mov esi, eax
// 0046540b  ff1578ee8900         call dword ptr [0x89ee78]
// 00465411  50                   push eax
// 00465412  e8eb382b00           call 0x718d02
// 00465417  85c0                 test eax, eax
// 00465419  0f84b3000000         je 0x4654d2
// 0046541f  8b4020               mov eax, dword ptr [eax + 0x20]
// 00465422  85f6                 test esi, esi
// 00465424  7504                 jne 0x46542a
// 00465426  33c9                 xor ecx, ecx
// 00465428  eb03                 jmp 0x46542d
// 0046542a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0046542d  3bc1                 cmp eax, ecx
// 0046542f  0f859d000000         jne 0x4654d2
// 00465435  57                   push edi
// 00465436  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0046543a  8b470c               mov eax, dword ptr [edi + 0xc]
// 0046543d  83e807               sub eax, 7
// 00465440  8944242c             mov dword ptr [esp + 0x2c], eax
// 00465444  85c0                 test eax, eax
// 00465446  c744240800000000     mov dword ptr [esp + 8], 0
// 0046544e  8d44242c             lea eax, [esp + 0x2c]
// 00465452  7f04                 jg 0x465458
// 00465454  8d442408             lea eax, [esp + 8]
// 00465458  8b00                 mov eax, dword ptr [eax]
// 0046545a  6a01                 push 1
// 0046545c  8bce                 mov ecx, esi
// 0046545e  89442410             mov dword ptr [esp + 0x10], eax
// 00465462  e8f9b8ffff           call 0x460d60
// 00465467  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0046546a  83c107               add ecx, 7
// 0046546d  8944242c             mov dword ptr [esp + 0x2c], eax
// 00465471  3bc1                 cmp eax, ecx
// 00465473  894c2408             mov dword ptr [esp + 8], ecx
// 00465477  8d44242c             lea eax, [esp + 0x2c]
// 0046547b  7c04                 jl 0x465481
// 0046547d  8d442408             lea eax, [esp + 8]
// 00465481  8b08                 mov ecx, dword ptr [eax]
// 00465483  6a01                 push 1
// 00465485  8d442410             lea eax, [esp + 0x10]
// 00465489  894c2414             mov dword ptr [esp + 0x14], ecx
// 0046548d  8d54241c             lea edx, [esp + 0x1c]
// 00465491  50                   push eax
// 00465492  8bce                 mov ecx, esi
// 00465494  8954241c             mov dword ptr [esp + 0x1c], edx
// 00465498  e8e3c2ffff           call 0x461780
// 0046549d  8d4c2418             lea ecx, [esp + 0x18]
// 004654a1  51                   push ecx
// 004654a2  ff151ce88900         call dword ptr [0x89e81c]
// 004654a8  8d54241c             lea edx, [esp + 0x1c]
// 004654ac  6874bc8b00           push 0x8bbc74
// 004654b1  52                   push edx
// 004654b2  ff1504e98900         call dword ptr [0x89e904]
// 004654b8  83c40c               add esp, 0xc
// 004654bb  85c0                 test eax, eax
// 004654bd  7412                 je 0x4654d1
// 004654bf  8b470c               mov eax, dword ptr [edi + 0xc]
// 004654c2  6a01                 push 1
// 004654c4  6868bc8b00           push 0x8bbc68
// 004654c9  50                   push eax
// 004654ca  8bce                 mov ecx, esi
// 004654cc  e8cfc7ffff           call 0x461ca0
// 004654d1  5f                   pop edi
// 004654d2  5e                   pop esi
// 004654d3  83c420               add esp, 0x20
// 004654d6  c20400               ret 4
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
