// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2007-08 CutVerb ctor ("Cut"): base verb ctor takes (container-base*, owner*, std::string);
// container base sits at +0x14c of the owner (null-checked upcast).
#include <string>
struct OwnerHead { virtual ~OwnerHead(); char pad[0x148]; };
struct VerbContainer { virtual ~VerbContainer(); };
struct Owner : OwnerHead, VerbContainer {};
struct EditVerb { virtual ~EditVerb() {} EditVerb(VerbContainer* container, Owner* owner, std::string name); };
struct CutVerb : EditVerb { CutVerb(Owner* owner); };
CutVerb::CutVerb(Owner* owner) : EditVerb(owner, owner, "Cut") {}
