// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_d59f942cdf7214a1.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/Gui.h"
typedef G3D::Vector2 Vec;
typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;
struct S {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual Vec position();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual Vec size();

    char pad0[260];
    Children* children;
    char pad1[72];
    int axis;

    unsigned int count();
    Vec f(S* child);
};

Vec S::f(S* child) {
 Vec result=position();
 Vec ownSize=size();
 for(unsigned i=0;i<count();++i) {
  RBX::Instance* instance=(*children)[i].get();
  S* item=reinterpret_cast<S*>(dynamic_cast<RBX::GuiItem*>(instance));
  if(item) {
   Vec childSize=item->size();
   if(item==child) {
    int other=(axis+1)%2;
    result[other]+=(ownSize[other]-childSize[other])*0.5f;
    return result;
   }
   switch(axis) {
   case 0:
   case 1:
    result[axis]+=item->size()[axis];
    break;
   }
  }
 }
 return result;
}
