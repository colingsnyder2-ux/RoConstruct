// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}
struct Context {
    char padding[456];
    char selection;
};
struct Verb {
    virtual void execute();
    unsigned int data[2];
    Verb(void *, std::string);
};
struct PasteVerb : Verb {
    Context *context;
    bool pasteInto;
    virtual void execute();
    PasteVerb(Context *, bool);
};
PasteVerb::PasteVerb(Context *owner, bool into)
    : Verb(owner ? &owner->selection : 0,
           std::string(into ? "PasteInto" : "Paste")),
      context(owner),
      pasteInto(into)
{
}
