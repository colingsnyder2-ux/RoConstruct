// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdexcept>

// INFERRED: derived class of std::logic_error (vtable 0x80b11c); ctor takes a string ref.
struct DerivedLogicError : public std::logic_error {
    DerivedLogicError(const std::string& msg);
};

DerivedLogicError::DerivedLogicError(const std::string& msg) : std::logic_error(msg) {}

extern "C" DerivedLogicError* __fastcall fn_00402480(DerivedLogicError* self, int unusedEdx, const std::string& msg) {
    return new (self) DerivedLogicError(msg);
}
