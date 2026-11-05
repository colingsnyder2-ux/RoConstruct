// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_boxselectionmovef757cf3e656a3845.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <G3D/Vector2int16.h>
#include <G3D/Rect2D.h>
struct Event {int reserved[2];G3D::Vector2int16 position;};
struct Command {char reserved[40];bool mode;G3D::Vector2int16 start,end;void update(Event*);void collect(std::set<void*>*,Event*,const G3D::Rect2D&);void applyFirst(std::set<void*>*);void applySecond(std::set<void*>*);};
void Command::update(Event*event){end=event->position;std::set<void*>collection;collect(&collection,event,G3D::Rect2D::xyxy(start.x,start.y,end.x,end.y));if(mode)applyFirst(&collection);else applySecond(&collection);}
