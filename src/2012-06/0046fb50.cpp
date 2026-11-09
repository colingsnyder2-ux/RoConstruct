// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 roc_unit_f02b83ce03c85e2d.cpp

// Candidate translation unit (score above; library headers required).
#include "stdafx.h"

class CRocAtlModule : public CAtlModule
{
public:
	HRESULT AddCommonRGSReplacements(IRegistrarBase* /*pRegistrar*/) throw()
	{
		return S_OK;
	}
};

CAtlModule* RocNewAtlModule()
{
	return new CRocAtlModule;
}
