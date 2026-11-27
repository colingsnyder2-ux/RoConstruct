// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /GR
namespace RBX {
class Instance { public: virtual void v(); };
class Script { public: virtual void w(); };
}
bool __stdcall Function007d48f0(RBX::Instance* value) { return dynamic_cast<RBX::Script*>(value) == 0; }
