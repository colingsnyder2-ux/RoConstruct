// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_dispatchboundearlyreturn0f5e49173a845214.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
typedef boost::shared_ptr<void> Shared;
struct Receiver {void invoke(boost::function<void()>);};
extern void callback(Shared,Shared);
void dispatch(Shared first,boost::shared_ptr<Receiver> receiver,int operation,Shared second){if(operation!=1)return;receiver->invoke(boost::bind(callback,first,second));}
