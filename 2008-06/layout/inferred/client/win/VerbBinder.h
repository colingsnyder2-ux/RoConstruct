#pragma once
#include <afxwin.h>
#include <map>

namespace RBX { class Name; }

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
