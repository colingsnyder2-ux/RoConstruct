// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_documentverbbindernovtable_6a3403b001989ae9.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <set>
#include <boost/scoped_ptr.hpp>
struct Inner74 {char d[4];~Inner74();};
struct Inner90 {char d[4];~Inner90();};
struct Base {virtual ~Base();char preceding[0x50];};
struct Member54 {char d[0x20];~Member54();};
struct __declspec(novtable) VerbBinder : Base {std::set<void*> m54;__forceinline virtual ~VerbBinder() {}};
struct VCRobloxDoc : VerbBinder {
 boost::scoped_ptr<Inner74> p74;
 std::vector<void*> values;
 Inner90* p90;
 virtual ~VCRobloxDoc();
};
VCRobloxDoc::~VCRobloxDoc(){delete p90;}
