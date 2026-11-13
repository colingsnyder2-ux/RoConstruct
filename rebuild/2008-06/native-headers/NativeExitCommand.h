#pragma once
// >>> native-status (generated) -- do not edit >>>
// NativeExitCommand | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7c8cb85b | roc native-status --write
class ExitCommand : public RBX::Verb {
    CRobloxDoc* doc;
public:
    __forceinline ExitCommand(CRobloxDoc* doc, RBX::VerbContainer* container)
        : Verb(container, "Exit"), doc(doc) {}
    virtual bool isEnabled() const { return true; }
    virtual void doIt(RBX::IDataState*);
};
