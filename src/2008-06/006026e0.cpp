// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_widgetfactorynative37a04af9be39364c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
struct Widget : boost::enable_shared_from_this<Widget> { char data[0x144-sizeof(boost::enable_shared_from_this<Widget>)]; Widget(float,float); __declspec(dllimport) static void* operator new(unsigned); __declspec(dllimport) static void operator delete(void*); static void predelete(Widget*); };
struct Deleter { void operator()(Widget* p) { Widget::predelete(p); delete p; } };
boost::shared_ptr<Widget> createWidget(float x,float y) { return boost::shared_ptr<Widget>(new Widget(x,y),Deleter()); }
