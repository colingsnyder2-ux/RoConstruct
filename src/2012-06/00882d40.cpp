// roc-cl: 21022
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll roc_espeon_dhtmlnativefunction034ab6d87e50f0c3f.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
class CLuaHtmlView {public:void callback();};
struct A {virtual ~A();}; struct B {virtual ~B();};
class DHTMLWindowService : public A,public B {
 public: void run(boost::function<void(CLuaHtmlView*)>);
 void append();
};
boost::shared_ptr<DHTMLWindowService> __cdecl sharedFrom(DHTMLWindowService*);
class Queue {public:void invoke(boost::function0<void>);};
extern Queue* queue;
void DHTMLWindowService::append() {
 queue->invoke(boost::bind(&DHTMLWindowService::run,sharedFrom(this),&CLuaHtmlView::callback));
}
