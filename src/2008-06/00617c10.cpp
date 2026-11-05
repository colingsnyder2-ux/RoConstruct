// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_boxselectdown31b3d1b23ac4bd3e.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <G3D/Vector2int16.h>
struct Input {virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual bool keyDown(int);};
struct Event {int type;Input* input;G3D::Vector2int16 position;};
struct Selection {void clear();};
struct Service {char data[12];Selection* get(bool);};
struct Command {
 virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void capture();
 char padding[24];Service selection;bool reverse;G3D::Vector2int16 down,current;std::set<void*> previous;
 Command* onDown(const Event&);
};
Command* Command::onDown(const Event& event) {
 previous.clear();capture();Input* input=event.input;
 reverse=input->keyDown(0x12f)||input->keyDown(0x130);
 if(!reverse)selection.get(true)->clear();
 down=event.position;current=event.position;return this;
}
