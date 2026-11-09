// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_cc5f1fa5b17a4fd6.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/Gui.h"
struct Input {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual short x();
    virtual short y();
};

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void update(Input *);
};

typedef std::vector<boost::shared_ptr<RBX::Instance> > Children;
extern G3D::Vector2 canvasSize;
struct Root {
    char padding[0x108];
    Children *children;
    unsigned count();
    void update(Input *);
};

void Root::update(Input* input) {
 short y=input->y();
 short x=input->x();
 canvasSize=G3D::Vector2(x,y);
 for(unsigned i=0;i<count();++i) {
  RBX::Instance* child=(*children)[i].get();
  Item* item=reinterpret_cast<Item*>(dynamic_cast<RBX::GuiItem*>(child));
  if(item) item->update(input);
 }
}
