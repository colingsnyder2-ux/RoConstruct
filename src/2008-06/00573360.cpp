// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_manual_gui_5169e2e566c140cf.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Rect.h"
typedef RBX::Rect Rect;
typedef G3D::Vector2 Point;
struct Text {
    unsigned char padding[20];
    int length;
};

struct GuiTarget;
struct Renderer;

typedef void (__thiscall* DrawFunction)(
    Renderer*, Rect*, Text*, Point*, double,
    void*, unsigned long, int, int, int);

struct GuiTable {
    void* preceding[20];
    int (__thiscall* scale)(GuiTarget*);
};

struct RenderTable {
    void* preceding[13];
    DrawFunction draw;
};

struct Renderer {
    RenderTable* table;
};

extern float centerFactor;
extern float alignmentFactor;

struct GuiTarget {
    GuiTable* table;
    Rect bounds();
    void render(Renderer*, Text*, void*, unsigned long, int);
};

void GuiTarget::render(Renderer* renderer,Text* text,void* color,unsigned long size,int alignment) {
 if(text->length) {
  Rect rectangle=bounds();
  Point dimensions=rectangle.size();
  Point position=Point(rectangle.low.x+rectangle.high.x,rectangle.low.y+rectangle.high.y)*0.5f;
  switch(alignment) {
  case 0:position.x=rectangle.high.x-dimensions.x*0.1f;break;
  case 2:break;
  default:position.x=rectangle.low.x+dimensions.x*0.1f;break;
  }
  DrawFunction* draw=&renderer->table->draw;
  (*draw)(renderer,&rectangle,text,&position,double(table->scale(this)),color,size,alignment,2,0);
 }
}
