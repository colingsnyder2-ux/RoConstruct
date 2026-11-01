// from server: 100% by EspClaude
// roc 2009-06 006553a0  unit: RBX::VArrowTool::?$TToolVerb  size: 70 bytes
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct MouseCommand;
struct Workspace {
    void setNullMouseCommand();
    void setMouseCommand(MouseCommand* c);
};
struct Owner { char pad[0x20c]; Workspace* workspace; };
struct IDataState;

struct Verb {
    virtual ~Verb();
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual bool isSelected() const;
    virtual void doIt(IDataState*);
    virtual MouseCommand* newMouseCommand();
    char pad[8];
    Owner* owner;
};

struct TToolVerb : Verb {
    char pad2[0xc];
    bool toggle;
    void doIt(IDataState*);
};

void TToolVerb::doIt(IDataState*) {
    if (isSelected() && toggle)
        owner->workspace->setNullMouseCommand();
    else {
        Workspace* w = owner->workspace;
        w->setMouseCommand(newMouseCommand());
    }
}
