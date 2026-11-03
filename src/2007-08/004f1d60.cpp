// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_dbc7706f943c458e.cpp

// Candidate translation unit (score above; library headers required).
#define go(x) go(x); template<class Iterator> void addSamples(Iterator _Iter, Iterator _End)
#include "Rendering/RenderLib/Clusterer.h"
#undef go

namespace RBX {
namespace Render {

template<class Iterator>
void Clusterer::addSamples(Iterator _Iter, Iterator _End)
{
	unsigned int index = 0;
	for (; _Iter != _End; ++_Iter) {
		Sample* sample = *_Iter;
		clusters[index].samples.push_back(sample);
		sampleSize++;
		index = (index + 1) % clusterCount;
	}
}

template void Clusterer::addSamples<std::vector<Chunk*>::iterator>(std::vector<Chunk*>::iterator, std::vector<Chunk*>::iterator);

} // namespace Render
} // namespace RBX
