// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_bdc55fa8f21ebff2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
typedef void (RBX::Instance::*BoundMethod)(boost::shared_ptr<RBX::Instance>, int);
boost::function<void(boost::shared_ptr<RBX::Instance>, int)> bindReceiver(BoundMethod method, RBX::Instance* object) { return boost::bind(method, object, _1, _2); }
