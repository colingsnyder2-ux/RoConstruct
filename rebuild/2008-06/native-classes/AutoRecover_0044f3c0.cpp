// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local declarations; no class header was found for ServiceProvider.
namespace RBX {

class RunService;

class ServiceProvider {
public:
    static unsigned int newIndex();
    template<class T>
    static unsigned int doGetClassIndex();
};

template<class T>
unsigned int ServiceProvider::doGetClassIndex()
{
    static unsigned int index = newIndex();
    return index;
}

template unsigned int ServiceProvider::doGetClassIndex<RunService>();

}
