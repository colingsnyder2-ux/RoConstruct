// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_mapvalue56_5344e1f58b847187.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Value {char data[56];Value();Value(const Value&);~Value();};
typedef std::map<unsigned,Value> Map;
Value& lookup(Map& map,const unsigned& key) {return map[key];}
