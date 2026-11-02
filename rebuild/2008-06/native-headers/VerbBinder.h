#pragma once
#include <afxwin.h>
#include <map>

namespace RBX { class Name; }

// Original RTTI: VerbBinder<CRobloxDoc, CDocument> and
// VerbBinder<CRobloxView, CView>. Native command routing 00451690 and
// view initialization 0045a4a0 establish unsigned command-ID -> Name* entries.
// Not active until the containing classes and routing definitions are recovered.
// The view's 0045a4a0 only reproduces with an unsigned long key; the document keeps unsigned int.
template<class Derived> struct VerbCommandKey { typedef UINT type; };
class CRobloxView;
template<> struct VerbCommandKey<CRobloxView> { typedef DWORD type; };

template<class Derived, class Base>
class VerbBinder : public Base {
protected:
    std::map<typename VerbCommandKey<Derived>::type, const RBX::Name*> commandNames;

public:
    VerbBinder() : Base() {}
    virtual BOOL OnCmdMsg(UINT, int, void*, AFX_CMDHANDLERINFO*);
};
