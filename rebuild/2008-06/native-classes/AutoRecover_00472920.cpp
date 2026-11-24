// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <exception>
#include <string>

// INFERRED: an exception type derived from std::exception with three std::string
// members at +0x0c, +0x28 and +0x44. The real class name is unknown.
struct FuncException_00472920 : public std::exception
{
    std::string m_a; // +0x0c
    std::string m_b; // +0x28
    std::string m_c; // +0x44

    virtual ~FuncException_00472920() {}
};

extern "C" void __fastcall fn_00472920(FuncException_00472920* self, int unusedEdx)
{
    // Non-deleting destructor body: destroys m_c, m_b, m_a, then the std::exception base.
    self->FuncException_00472920::~FuncException_00472920();
}
