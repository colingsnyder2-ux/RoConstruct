#pragma once
// >>> native-status (generated) -- do not edit >>>
// VerbBinder | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src cb7a85be | roc native-status --write
#include <afxwin.h>
#include <map>

namespace RBX { class Name; }

// Original RTTI: VerbBinder<CRobloxDoc, CDocument> and
// VerbBinder<CRobloxView, CView>. Native command routing 00451690 and
// view initialization 0045a4a0 establish unsigned command-ID -> Name* entries.
// Not active until the containing classes and routing definitions are recovered.
// Binder 004598f0 passes its UINT command parameter directly to map::find.
template<class Derived> struct VerbCommandKey { typedef UINT type; };
class CRobloxView;
template<> struct VerbCommandKey<CRobloxView> { typedef UINT type; };

template<class Derived, class Base>
class VerbBinder : public Base {
protected:
    std::map<typename VerbCommandKey<Derived>::type, const RBX::Name*> commandNames;

public:
    VerbBinder() : Base() {}
    virtual BOOL OnCmdMsg(UINT, int, void*, AFX_CMDHANDLERINFO*);
};
