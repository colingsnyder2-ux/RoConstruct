// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern const char event_00975770[];
extern const char event_00973d54[];

struct Pair {
    const char* first;
    int second;

    __forceinline Pair(const char* a, int b);
    __forceinline Pair(const Pair& other);
};

__forceinline Pair::Pair(const char* a, int b)
{
    first = a;
    second = b;
}

__forceinline Pair::Pair(const Pair& other)
{
    second = other.second;
    first = other.first;
}

struct CScriptEditor {
    void f(int, Pair);
    void func_00465110(int id, const char* event, volatile int value);
};

void CScriptEditor::func_00465110(int id, const char* event, volatile int value)
{
    if (event == event_00975770) {
        f(id, Pair(event, value));
    } else if (event == event_00973d54) {
        f(id, Pair(event, value));
    }
}