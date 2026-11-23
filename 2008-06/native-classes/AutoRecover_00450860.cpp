// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no header excerpt was found, so ServiceProvider is declared locally.
// The body is a single tail jump to 0x0044f3c0, probably doGetClassIndex<RunService>.
namespace RBX {
class RunService;

extern "C" void fn_0044f3c0(void);

class ServiceProvider {
public:
    template<class T> static void callDoGetClassIndex();
};

template<class T>
void ServiceProvider::callDoGetClassIndex()
{
    fn_0044f3c0();
}

template void ServiceProvider::callDoGetClassIndex<RunService>();
}
