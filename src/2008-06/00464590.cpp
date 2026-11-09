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
