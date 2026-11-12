// Layout probes for the inactive native RBX::ViewNew::ViewG3D (2008-06; native-headers/ViewG3D2008/ViewG3D2008.h).
// Each probe compiles to `mov eax, imm32; ret`; tests/record_native_viewg3d2008.py compares the immediates with the
// offsets read from the original (ctor 004dbbe0 / dtor 004dc270 stores, invalidateLighting 004db610 and the render body
// 004db690). The +0x4c map is not declared (types not derived); its size evidence is checked on the original only.
#include "ViewG3D2008/ViewG3D2008.h"
#include "v8datamodel/DataModel.h"
#include <stddef.h>

struct NativeViewG3D2008Layout
{
	typedef RBX::ViewNew::ViewG3D V;
	static int viewG3DSky() { return offsetof(V, sky); }
	static int viewBaseLightingValid() { return offsetof(V, lightingValid); }
	static int viewBaseDataModel() { return offsetof(V, dataModel); }
	static int dataModelWorkspace() { return offsetof(RBX::DataModel, workspace); }
};

#define PROBE(name) int native##name() { return NativeViewG3D2008Layout::name(); }
PROBE(viewG3DSky)
PROBE(viewBaseLightingValid) PROBE(viewBaseDataModel) PROBE(dataModelWorkspace)
