// from server: 100% by nuck16
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <list>
struct Argument {char pad[28];std::list<int>::iterator position;};
struct Service{char pad[16];std::list<int> values;int get(const Argument*);};
int Service::get(const Argument*argument){std::list<int>::iterator i=argument->position;++i;return i==values.end()?values.front():*i;}
