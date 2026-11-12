// from server: 75% by EspClaude
// from server: 55% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_0af90481baca55ea.cpp

// Candidate translation unit (score above; library headers required).
#include <map>

namespace RBX { class Name; }
class CRobloxDoc;

// Stand-in for the MFC base: the target destroys the command map at this+0x54
// and then calls the MFC80 base destructor import.
class CDocument {
public:
    virtual ~CDocument();
private:
    char base_0x04[0x50];
};

template<class Derived, class Base>
class __declspec(novtable) VerbBinder : public Base {
protected:
    std::map<unsigned int, const RBX::Name*> commandNames; // 0x54

public:
    VerbBinder() : Base() {}
    ~VerbBinder() {}
};

template class VerbBinder<CRobloxDoc, CDocument>;
