// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_eebc4a1b846fb837.cpp

// Candidate translation unit (score above; library headers required).
#include "gui/Gui.h"
typedef G3D::Vector2 Vec2;
typedef RBX::Rect Rect;
typedef RBX::GuiEvent Event;
struct Result { int handled; void* value; };
struct Child {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void stop();
};

struct Holder {
    Child* object;
    void* control;
    void clear();
};

struct ChatEnter {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual Vec2 position();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual Vec2 size();
    virtual void slot24();
    virtual void changed();

    char reserved0[0x130];
    Holder holder;
    char reserved1[8];
    int state;

    Result process(Event* event);
};

Result ChatEnter::process(Event* event)
{
    if (holder.object)
        holder.object->stop();
    holder.clear();

    Vec2 p = position();
    Rect bounds(p,p+size());

    Result result;
    if (bounds.pointInRect(event->mousePosition)) {
        switch (event->eventType) {
        case 3:
        case 4:
            if (state != 2) {
                state = 2;
                changed();
            }
            result.value = 0;
            result.handled = 1;
            return result;

        case 5:
            if (state != 1) {
                state = 1;
                changed();
            }
            result.handled = 1;
            result.value = 0;
            return result;
        }
    } else if (state != 0) {
        state = 0;
        changed();
    }

    result.handled = 0;
    result.value = 0;
    return result;
}
