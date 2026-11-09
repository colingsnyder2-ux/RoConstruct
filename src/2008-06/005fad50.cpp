// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_kernelindexoffset_1f119e5d97fd81c5.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#include "v8kernel/Connector.h"
#include "util/IndexArray.h"
struct KernelDataRecovered {
 char preceding[0x30];
 RBX::IndexArray<RBX::Connector,&RBX::Connector::getKernelIndex> connectors;
};
struct KernelRecovered {
 char preceding[0x10];
 KernelDataRecovered* kernelData;
 void insertConnector(RBX::Connector*);
};
void KernelRecovered::insertConnector(RBX::Connector*c){kernelData->connectors.fastAppend(c);}
