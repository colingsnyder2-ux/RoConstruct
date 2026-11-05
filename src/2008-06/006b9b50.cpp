// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_dc4f94de3a5733d7.cpp

// Candidate translation unit (score above; library headers required).
#include <utility>
typedef std::pair<unsigned long, unsigned long> TwoWordResult;
struct SubobjectView { TwoWordResult get() const; };
struct OwnerView { TwoWordResult get() const; };
TwoWordResult OwnerView::get() const
{
    // Target adds0x30 to ECX; callee6b9a30 fills the two-word hidden result and ret4.
    // Original owner, subobject and result class names are unknown.
    return reinterpret_cast<const SubobjectView*>(reinterpret_cast<const char*>(this) + 0x30)->get();
}
