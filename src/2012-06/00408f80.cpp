// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 roc_unit_a08aafcd04544bd2.cpp

// Candidate translation unit (score above; library headers required).
#include "stdafx.h"

class CRocRegistry
{
public:
	static HRESULT WINAPI UpdateRegistry(BOOL bRegister) throw()
	{
		return ATL::_pAtlModule->UpdateRegistryFromResource(110, bRegister);
	}
};

HRESULT (WINAPI *RocUpdateRegistry)(BOOL) = &CRocRegistry::UpdateRegistry;
