// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /MD
struct Elem { int value(); };
struct Arr {
    Elem& at(int i);
    int valueAt(int i);
};
int Arr::valueAt(int i)
{
    return at(i).value();
}
