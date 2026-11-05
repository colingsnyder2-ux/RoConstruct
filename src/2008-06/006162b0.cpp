// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_setforeachinline46daec9aeb84889b.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
struct Output {void append(void*);};
struct Function {Output* output;Function(Output* p):output(p){}void operator()(void* value){output->append(value);}};
Function run(std::set<void*>::iterator first,std::set<void*>::iterator last,Function function) {for(;first!=last;++first) function(*first); return function;}
