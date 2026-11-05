// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_88a75b4c54bbca54.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
#include <list>
struct Quad { float values[12]; };
void addQuad(std::list<Quad>& quads, const Quad& quad) { quads.push_back(quad); quads.push_front(quad); quads.insert(++quads.begin(), quad); }
