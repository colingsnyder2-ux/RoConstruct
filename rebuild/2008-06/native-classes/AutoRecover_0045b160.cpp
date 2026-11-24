// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: Name header path unknown, so a minimal local declaration is used.
// INFERRED: the original pushes the literal address (0x9510b4), so the body uses the
// string literal rather than loading sControllerService.
namespace RBX {

extern char* sControllerService;

class Name {
public:
    static const Name& declare(const char* name, int index);
    template<char*& S>
    static const Name& doDeclare();
};

template<char*& S>
const Name& Name::doDeclare()
{
    static const Name& n = Name::declare("ControllerService", -1);
    return n;
}

template const Name& Name::doDeclare<sControllerService>();

} // namespace RBX
