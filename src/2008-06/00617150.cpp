// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_boxselectctornative1efa35e85b337ddd.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <boost/shared_ptr.hpp>
#include <G3D/Vector2int16.h>
struct Workspace;
struct Primary{virtual ~Primary();};struct Secondary{virtual ~Secondary();};
struct Base:Primary,Secondary{char padding[20];Base(Workspace*);virtual ~Base();};
struct BoxSelect:Base{Workspace* workspace;boost::shared_ptr<void> selected;bool dragging;G3D::Vector2int16 down,current;std::set<void*> items;BoxSelect(Workspace*);virtual ~BoxSelect();};
BoxSelect::BoxSelect(Workspace*w):Base(w),workspace(w){}
