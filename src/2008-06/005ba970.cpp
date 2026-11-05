// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_soundserviceclosefe38e485dfd59780.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <algorithm>
#include "util/ContentProvider.h"
struct Sound;struct Channel;
typedef std::map<RBX::ContentId,boost::shared_ptr<Sound> > Sounds;
void visit(Sounds::value_type&);
extern "C" void* __stdcall resolveHandle(void*);
void releaseHandle(void*);
struct Service {
 char padding[0x134];void* handle;unsigned version;
 std::map<int,boost::shared_ptr<Channel> > stock;
 char padding2[0x24];Sounds second,third;
 void reset();void resetState();
};
void Service::reset() {
 stock.clear();resetState();
 std::for_each(second.begin(),second.end(),visit);
 std::for_each(third.begin(),third.end(),visit);
 second.clear();third.clear();
 if(handle){releaseHandle(resolveHandle(handle));handle=0;}
}
