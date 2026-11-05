#pragma once
class ExitCommand : public RBX::Verb {
    CRobloxDoc* doc;
public:
    __forceinline ExitCommand(CRobloxDoc* doc, RBX::VerbContainer* container)
        : Verb(container, "Exit"), doc(doc) {}
    virtual bool isEnabled() const { return true; }
    virtual void doIt(RBX::IDataState*);
};
