// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace std {
template<class T> struct char_traits;
template<> struct char_traits<char> {};
template<class T> class allocator;
template<> class allocator<char> {};

// INFERRED: Virtual inheritance selects the imported vbase destructor.
class Local_00416870_base {};

template<class C, class T = char_traits<C>, class A = allocator<C> >
class basic_stringstream : virtual public Local_00416870_base {
public:
    __declspec(dllimport) ~basic_stringstream();
};
}

// INFERRED: A cdecl argument supplies the object whose stream starts at offset 0xc.
// The disassembly instead receives this pointer in ECX; this definition is not byte-exact.
extern "C" void __fastcall fn_00416870(void* self, int)
{
    reinterpret_cast<std::basic_stringstream<char>*>(
        static_cast<char*>(self) + 0xc)->~basic_stringstream();
}
