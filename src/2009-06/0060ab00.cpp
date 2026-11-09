// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
namespace RBX {
class VerbContainer;
struct Workspace { unsigned char padding[0xd0]; VerbContainer* containerBase; };
class Verb {
public:
    Verb(void* container, std::string name);
    virtual void slot();
};
class ForceAssertionCommand : public Verb {
public:
    ForceAssertionCommand(Workspace* w);
    virtual void slot();
};
ForceAssertionCommand::ForceAssertionCommand(Workspace* w)
    : Verb(w ? &w->containerBase : 0, "ForceAssertion")
{
}
}
