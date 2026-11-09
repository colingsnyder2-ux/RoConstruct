// from server: 100% by king_originala
struct State {
    void* previous;
    State* link;
    void* allocation;
    int owned;

    State(void*);
};

struct Text {
    unsigned value;
};

extern "C" void* __cdecl currentState();
extern "C" void __stdcall releaseState(int, void*);
extern "C" void __cdecl processText(const char*);

typedef Text* (__thiscall *TextConstruct)(Text*, unsigned);
typedef const char* (__thiscall *TextAccess)(Text*);
typedef void (__thiscall *TextDestroy)(Text*);

extern TextConstruct constructText;
extern TextAccess accessText;
extern TextDestroy destroyText;

int __stdcall function(int, unsigned value)
{
    State state(currentState());

    Text* text = constructText(reinterpret_cast<Text*>(&value), value);
    processText(accessText(text));
    destroyText(reinterpret_cast<Text*>(&value));

    if (state.link)
        state.link->link = static_cast<State*>(state.previous);

    if (state.owned)
        releaseState(0, state.allocation);

    return 0;
}
