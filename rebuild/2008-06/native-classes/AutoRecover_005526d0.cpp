// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: <locale> is not included, because its inline definition of
// codecvt_base::do_always_noconv would conflict with this out-of-line one.
// The class is declared minimally here (no locale::facet base) because the
// mangled name only needs the class name and the method signature.
// INFERRED: the original bytes have an unoptimized frame (push ebp / push ecx /
// store this), so optimization is turned off for this one function.
namespace std {

class codecvt_base
{
protected:
    virtual bool do_always_noconv() const throw();
};

#pragma optimize("", off)
bool codecvt_base::do_always_noconv() const throw()
{
    return true;
}
#pragma optimize("", on)

}
