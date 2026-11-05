// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_memberiterator0e47bbba3f8357a4.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
struct Value{unsigned* descriptor;void* instance;Value(unsigned* d,void* i):descriptor(d),instance(i){}};
struct Iterator{void* instance;std::vector<unsigned*>::const_iterator iter;Value operator*()const{return Value(*iter,instance);}bool operator==(const Iterator& b)const{return iter==b.iter;}bool operator!=(const Iterator& b)const{return iter!=b.iter;}Iterator& operator++(){++iter;return *this;}};
struct Function{void(__cdecl* callback)(void*,void*,const Value*);void* first;void* second;void operator()(const Value& v)const{callback(first,second,&v);}};
Function process(Iterator first,Iterator last,Function function){return std::for_each(first,last,function);}
