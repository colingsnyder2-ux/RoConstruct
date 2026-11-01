// from server: 100% by king_originala
// from server: 66% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_unit_aa49747d7f898d5b.cpp

// Candidate translation unit (score above; library headers required).
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>

class RocAtlModule : public ATL::CAtlModule
{
public:
    virtual HRESULT AddCommonRGSReplacements(IRegistrarBase*) throw()
    {
        return S_OK;
    }
};

static RocAtlModule roc_atl_module;

void roc_atl_module_term()
{
    roc_atl_module.Term();
}
