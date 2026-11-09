// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_acceptchildvector_da8eb4f77548d594.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
struct S;typedef std::vector<boost::shared_ptr<S> >::iterator Iterator;struct S{virtual void slot0();virtual void slot1();virtual bool accepts(S*);virtual bool acceptedBy(S*);char padding[256];S*parent;bool ancestorOf(S*);bool f(Iterator,Iterator);};bool S::f(Iterator first,Iterator last){for(;first!=last;++first){S*object=first->get();if(!object||object->ancestorOf(this)||object->parent==this||(!accepts(object)&&!object->acceptedBy(this)))return false;}return true;}
