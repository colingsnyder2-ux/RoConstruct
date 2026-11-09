// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_anchorboolhelper639899bf7232a483.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Part;struct Input;
int countAnchored(Part*);
inline bool shouldAnchor(Part* p){if(p)return countAnchored(p)==0;return false;}
struct AnchorTool{char prefix[0x1c];boost::shared_ptr<Part> target;bool anchor;void updateTarget(Input*);void move(Input*);};
void AnchorTool::move(Input* input){boost::shared_ptr<Part> previous=target;updateTarget(input);if(previous!=target)anchor=shouldAnchor(target.get());}
