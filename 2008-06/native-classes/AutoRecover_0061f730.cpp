// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>

// INFERRED: the element type of the shared_ptr is unknown; the type_info at 0x935980 identifies it.
struct InferredHeld;

// INFERRED: boost::any_cast<boost::shared_ptr<T> >(any&) returning the shared_ptr by value through a
// hidden first argument (cdecl). C linkage forbids returning a C++ class, so the hidden out-pointer
// is declared explicitly and the result is copy-constructed into it. The out-pointer is returned in eax.
extern "C" boost::shared_ptr<InferredHeld>* fn_0061f730(boost::shared_ptr<InferredHeld>* out, boost::any* operand)
{
    return new (out) boost::shared_ptr<InferredHeld>(
        boost::any_cast< boost::shared_ptr<InferredHeld>& >(*operand));
}
