// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_scriptqueuenativec5a9301390856b8c.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
struct Script;
struct A {virtual void a();};struct B {virtual void b();};
struct S : A,B {char padding[0x188-sizeof(A)-sizeof(B)];std::vector<boost::shared_ptr<Script> > queue;char padding2[0x1ac-0x188-sizeof(std::vector<boost::shared_ptr<Script> >)];bool disabled;void callback(boost::shared_ptr<Script>);void f();};
void S::f(){if(!disabled){std::vector<boost::shared_ptr<Script> > copy(queue);queue.erase(queue.begin(),queue.end());std::for_each(copy.begin(),copy.end(),boost::bind(&S::callback,this,_1));}}
