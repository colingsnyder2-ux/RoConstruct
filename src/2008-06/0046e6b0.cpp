// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_maproot_04099ff9183cd499.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
typedef std::string String;
struct MapRoot {
 virtual ~MapRoot();
 String firstName,secondName,thirdName;
 int value;
 std::vector<void*> entries;
 MapRoot(String,String,String,int);
};
MapRoot::MapRoot(String a,String b,String c,int n):firstName(a),secondName(b),thirdName(c),value(n),entries() {}
