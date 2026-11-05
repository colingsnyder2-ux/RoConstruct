// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_guidispatchresultea1708f7b4466753.cpp

// Candidate translation unit (score above; library headers required).
struct Result{int response;void*target;Result():target(0){response=0;}static Result notUsed(){return Result();}};
struct Event {int type;};
struct Whole;
struct Table{void*slots[21];bool(__thiscall*enabled)(Whole*);};
struct Whole {Table*table;Result normal(Event*);Result hover(Event*);Result pressed(Event*);};
struct Part{char pad[0x14];int mode;Result f(Event*);};
Result Part::f(Event*event){
 Whole*self=reinterpret_cast<Whole*>(reinterpret_cast<char*>(this)-0x130);
 if(self->table->enabled(self)&&event->type>=1&&event->type<=7){
  switch(mode){case 0:return self->normal(event);case 1:return self->hover(event);case 2:case 3:return self->pressed(event);}
 }
 return Result::notUsed();
}
