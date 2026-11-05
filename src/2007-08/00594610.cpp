// from server: 100% by colin
struct DataModel;
struct Workspace;

struct MouseCommand {
    static const char* name();
};

struct Verb {
    virtual ~Verb();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual bool isSelected() const;
    virtual void getText() const;
    virtual void doIt(void*);
};

struct RunStateVerb : Verb {
};

struct TToolVerb : RunStateVerb {
    bool toggle;
    bool isEnabled() const;
};

extern "C" void* __cdecl sub_631392(void*);
extern "C" bool (__thiscall *sub_77e708)(void*, void*);

bool TToolVerb::isEnabled() const {
    DataModel* dm = *(DataModel**)((char*)this + 0xc);
    Workspace* ws = *(Workspace**)((char*)dm + 0x188);
    void* p = *(void**)((char*)ws + 0x318);
    if (p) {
        void* q = sub_631392(p);
        return sub_77e708((void*)0x8a4ed4, q);
    }
    return false;
}
