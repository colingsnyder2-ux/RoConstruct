// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Msg { void clear(); };
class Base {
public:
    void onEvent(void* a);
};
class C : public Base {
public:
    char pad[0x9c];
    Msg msg;
    char pad2[0xc4 - 0x9c - sizeof(Msg)];
    int value;
    void onEvent(void* a);
};
void C::onEvent(void* a)
{
    Base::onEvent(a);
    value = 0;
    msg.clear();
}
