// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_widgetshownslotsaf46923195e234cf.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "gui/GuiEvent.h"
#include "util/Rect.h"
namespace RBX {
class GuiItem {public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual G3D::Vector2 getPosition() const;
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual G3D::Vector2 getSize() const;
Rect getMyRect() const {G3D::Vector2 p=getPosition();return Rect::fromLowSize(p,getSize());}
};
class UnifiedWidget:public GuiItem {public:GuiResponse processShown_InTitle(const GuiEvent&);GuiResponse processShown_OutOfTitle(const GuiEvent&);GuiResponse processShown(const GuiEvent&);};
GuiResponse UnifiedWidget::processShown(const GuiEvent& event){Rect titleRect=getMyRect();if(titleRect.pointInRect(event.mousePosition))return processShown_InTitle(event);else return processShown_OutOfTitle(event);}
}
