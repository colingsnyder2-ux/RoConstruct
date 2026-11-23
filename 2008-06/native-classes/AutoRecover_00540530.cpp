// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided, so Wml::MTVertex and Wml::UnorderedSet are
// declared locally. The mangled name of GetQuantity should match the callee name
// given in the disassembly.
namespace Wml {
class MTVertex;

template <class T>
class UnorderedSet {
public:
    int GetQuantity() const;  // defined elsewhere
};
}

extern "C" int __fastcall fn_005412b0(void* self, int unusedEdx, int a1);

// INFERRED: this looks like a constructor-style function. It takes a pointer to an
// UnorderedSet<MTVertex>, passes its quantity to fn_005412b0, and returns `this`.
extern "C" void* __fastcall fn_00540530(void* self, int unusedEdx, const Wml::UnorderedSet<Wml::MTVertex>* set)
{
    int quantity = set->GetQuantity();
    fn_005412b0(self, 0, quantity);
    return self;
}
