// 2008-06 native RunStateVerb / EditSelectionVerb destructors (0057dfd0, 0057e050), split out of Verb.cpp.
// They sit beside RunStateVerb's constructor (0057e330) and the stats verbs (0057d9f0..0057db90, Commands.cpp), far
// from Verb::~Verb (005832c0, v8tree/Verb.cpp). Each calls ~Verb out of line; in a unit that also defines ~Verb MSVC
// inlines it in every definition order, so they were compiled in a separate original file.
#include "../native-headers/v8tree/Verb.h"
#include "StandardVerbs.h"

RBX::RunStateVerb::~RunStateVerb() {}
RBX::EditSelectionVerb::~EditSelectionVerb() {}
