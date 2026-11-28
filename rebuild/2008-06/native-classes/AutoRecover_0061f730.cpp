// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

// INFERRED: boost::any_cast<shared_ptr<T> >(any&) returning by value through a hidden
// first argument.  C linkage cannot return a C++ class, so the hidden out pointer is explicit.
struct InferredHeld;
typedef boost::shared_ptr<InferredHeld> Shared_0061f730;

extern "C" void fn_0061f730(Shared_0061f730* out, boost::any* operand)
{
    Shared_0061f730* held = boost::any_cast<Shared_0061f730>(operand);
    if (!held)
        boost::throw_exception(boost::bad_any_cast());
    new (out) Shared_0061f730(*held);
}
