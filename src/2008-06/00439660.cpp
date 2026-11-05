// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_selectiongroupkeycopyad6d5bf51b76f222.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
struct Argument{char prefix[0x1c];void*key;};
extern boost::shared_ptr<Argument>sharedArgument(Argument*);
typedef std::vector<boost::shared_ptr<Argument> > Entries;
struct Group:std::map<void*,Entries>{void remove(Argument*);};
void Group::remove(Argument*argument){void*key=argument->key;iterator found=find(key);if(found!=end()){Entries::iterator current=std::find(found->second.begin(),found->second.end(),sharedArgument(argument));if(current!=found->second.end())found->second.erase(current);}}
