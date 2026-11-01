// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Arg;
struct Slot;
void invokeSlot(const Slot& slot, Arg* arg, bool* result);
struct Invoker {
    void (*fn)(const Slot&, Arg*, bool*);
    Arg* arg;
    bool* result;
};
class Signal {
public:
    void call(const Invoker& inv);
    bool operator()(Arg* arg);
};
bool Signal::operator()(Arg* arg)
{
    bool result = true;
    Invoker inv = { &invokeSlot, arg, &result };
    call(inv);
    return result;
}
