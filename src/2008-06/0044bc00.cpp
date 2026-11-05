// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_contextiteratorlocals0fc4ea6bbe798a87.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
struct Value {unsigned value,context;Value(unsigned v,unsigned c):value(v),context(c){}Value(const Value&o):value(o.value),context(o.context){}};
struct Iterator {unsigned context;std::vector<unsigned>::iterator it;bool operator!=(const Iterator&o)const{return it!=o.it;}Iterator&operator++(){++it;return *this;}Value operator*()const{return Value(*it,context);}};
typedef void(*Callback)(Value);
Callback visit(Iterator a,Iterator b,Callback c){Iterator current=a,end=b;for(;current!=end;++current){unsigned value=*current.it;c(Value(value,current.context));}return c;}
