// from server: 100% by colin
struct VerbContainer;

struct Verb {
    char m_pad0[0xc];
    VerbContainer* m_container;
};

struct MouseCommand {
    char m_pad0[0x188];
    void* m_workspace;
};

struct DataModel {
    char m_pad0[0x318];
    void* m_something;
};

struct TToolVerb {
    char m_pad0[0xc];
    DataModel* m_dataModel;
    bool isEnabled() const;
};

extern "C" void* __cdecl sub_631392(void*);
extern "C" bool (__thiscall *sub_77e708)(void*, void*);

bool TToolVerb::isEnabled() const
{
    MouseCommand* mc = *(MouseCommand**)((char*)m_dataModel + 0x188);
    void* p = *(void**)((char*)mc + 0x318);
    if (p) {
        void* q = sub_631392(p);
        return sub_77e708((void*)0x8a4d94, q);
    }
    return false;
}
