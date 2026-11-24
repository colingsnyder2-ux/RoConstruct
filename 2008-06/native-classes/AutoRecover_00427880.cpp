// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original 0x00427880 is only the linker-generated import thunk
// (jmp dword ptr [mfc90 ordinal 601]) for the CString destructor exported by
// mfc90.dll. To get the same `jmp [imp]` from C++, the destructor makes a
// single tail call to a dllimport function with the same register signature
// (this in ecx). The compiler then emits only the indirect jmp.

template <typename BaseType, class StringTraits>
class StrTraitMFC_DLL;

namespace ATL {

template <typename BaseType>
class ChTraitsCRT;

template <typename BaseType, class StringTraits>
class CStringT
{
public:
    ~CStringT() throw();
private:
    BaseType* m_pszData;
};

} // namespace ATL

// INFERRED: stand-in for mfc90 export #601 (CStringT<char>::~CStringT).
extern "C" __declspec(dllimport) void __fastcall mfc90_ord601(void* self);

template <>
ATL::CStringT<char, StrTraitMFC_DLL<char, ATL::ChTraitsCRT<char> > >::~CStringT() throw()
{
    mfc90_ord601(this);
}
