#pragma once
#include <afxwin.h>
#include <map>

namespace RBX { class Name; }

// Original RTTI: VerbBinder<CRobloxDoc, CDocument> and
// VerbBinder<CRobloxView, CView>. Native command routing 00451690 and
// view initialization 0045a4a0 establish unsigned command-ID -> Name* entries.
// Not active until the containing classes and routing definitions are recovered.
template<class Derived, class Base>
class VerbBinder : public Base {
protected:
    std::map<DWORD, const RBX::Name*> commandNames;

public:
    VerbBinder() : Base() {}
    __forceinline virtual ~VerbBinder() {}
    virtual BOOL OnCmdMsg(UINT, int, void*, AFX_CMDHANDLERINFO*);
};
