// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S;
bool __cdecl check(S*, int);
struct Result {
    int data[3];
};
struct Handler {
    void invoke(Result*, int*);
};
struct Receiver {
    void invoke(int);
};
struct S {
    char padding[0x1f8];
    bool disabled;
    char alignment[3];
    Handler handler;
    char pad2[0x21c - 0x200];
    Receiver* receiver;
    void f(int);
};
void S::f(int value)
{
    if (check(this, 1) && !disabled) {
        Result result;
        handler.invoke(&result, &value);
    } else {
        receiver->invoke(value);
    }
}
