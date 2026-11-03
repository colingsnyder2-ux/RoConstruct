// from server: 100% by EspClaude
// roc 2007-08 005625f0  RBX::AllCanSelectCommand::doIt (2008-06 0057d8e0 shape, 2007 data-state handling)
struct Context;
extern bool __cdecl isLocked(Context*);
extern void __cdecl unlock(Context*);
static __declspec(noinline) void prepare(Context* c)
{
    if (isLocked(c))
        unlock(c);
}
struct Selection;
struct Context {
    char padding[0x188];
    Selection* selection;
};
extern void __cdecl setAllCanSelect(Selection*, bool);

class IDataState {
public:
    virtual void v0();
    virtual void setDirty(bool);
    int current;
    void trimAfter(int index);
};

struct AllCanSelectCommand {
    void* vtbl;
    void* a;
    void* b;
    Context* context;
    void doIt(IDataState* dataState);
};

void AllCanSelectCommand::doIt(IDataState* dataState)
{
    prepare(context);
    setAllCanSelect(context->selection, false);
    dataState->trimAfter(-1);
    dataState->current = -1;
    dataState->setDirty(true);
}
