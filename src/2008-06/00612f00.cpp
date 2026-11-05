// from server: 100% by EspClaude
// from server: 45% by atomic.potato
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a2e39c72583e1b36.cpp

// Candidate translation unit (score above; library headers required).
#include <new>
#include <boost/shared_ptr.hpp>
struct Owner {boost::shared_ptr<int> counter;bool active;Owner(const boost::shared_ptr<int>*);};
struct B1 { int a, b, c; };
struct B2 { int d; };
struct D : B1, B2 { };
void __cdecl construct_owner(B2* where, const boost::shared_ptr<int>* other)
{
    void* p = static_cast<D*>(where);
    ::new (p) Owner(other);
}
