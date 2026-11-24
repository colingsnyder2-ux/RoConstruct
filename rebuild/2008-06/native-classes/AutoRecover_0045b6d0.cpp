// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no Name header excerpt was provided, so the class is declared minimally here.
// INFERRED: the body is a bare tail jump to 0x45b160, which is probably the shared doDeclare
// thunk. It takes no arguments, so the call has no parameters.
namespace RBX {
    extern char* sControllerService;
}

extern "C" void fn_0045b160(void);

namespace RBX {
    class Name {
    public:
        template<char*& name>
        static void callDoDeclare();
    };

    template<>
    void Name::callDoDeclare<sControllerService>()
    {
        fn_0045b160();
    }
}
