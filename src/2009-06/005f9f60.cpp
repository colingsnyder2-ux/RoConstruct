// from server: 100% by EspClaude
// from server: 98% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_6c4d0a2e0d3af110.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <map>
typedef boost::shared_ptr<void> Value;
typedef std::map<unsigned int,Value> Tree;
struct S{char unused[164];Tree tree;Value f(int);};
Value S::f(int key){Tree::iterator position=tree.find(key);if(position!=tree.end())return position->second;return Value();}
