// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_valueforeachdispatchcb5eb71b9baa1901.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
struct Value { unsigned a,b; void* content; bool operator<(const Value&) const; };
struct Tag { char value; };
struct Context { void* receiver; void invoke(Tag,void**,const Value*const*,int); };
struct Callback { void* function; Context context; Callback();
 void operator()(const Value& value) { const Value* p=&value; Tag tag={0}; context.invoke(tag,&function,&p,0); }
};
Callback f(std::set<Value>::iterator first,std::set<Value>::iterator last,Callback callback) { return std::for_each(first,last,callback); }
