// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class C {
public:
    char pad[0x54];
    float depth;
    void a();
    void b();
    int f();
};
int C::f()
{
    a();
    b();
    return depth <= 0.0f;
}
