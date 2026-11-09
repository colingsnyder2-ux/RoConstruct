// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_collectapplyvectore86896c79dea34c3.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <vector>
#include <boost/shared_ptr.hpp>
#include <G3D/Vector3.h>
struct Object;
typedef std::vector<boost::shared_ptr<Object> > Items;
struct S {void collect(void*,void*,Items*);void apply(Items*,G3D::Vector3,bool);void f(void*,void*);};
void S::f(void*a,void*b){Items items;collect(a,b,&items);if(items.size()){apply(&items,G3D::Vector3::zero(),true);}}
