// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
struct _ATL_REGMAP_ENTRY;
namespace ATL {
class CAtlModule {
public:
    long __stdcall UpdateRegistryFromResourceS(unsigned int nResID, int bRegister, _ATL_REGMAP_ENTRY* pMapEntries = 0) throw();
};
extern CAtlModule* _pAtlModule;
}
class CRobloxAuth {
public:
    static long __stdcall UpdateRegistry(int bRegister) throw()
    { return ATL::_pAtlModule->UpdateRegistryFromResourceS(110, bRegister); }
};
long (__stdcall *g_upd)(int) = &CRobloxAuth::UpdateRegistry;
