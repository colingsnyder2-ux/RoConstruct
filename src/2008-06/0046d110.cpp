// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_colormaptransform473e8fa01f9ad70e.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <algorithm>
#include <ctype.h>
struct ColorMap{int lookup(const std::string&);int find(const std::string&);};
int ColorMap::find(const std::string& value){std::string copy(value);std::transform(copy.begin(),copy.end(),copy.begin(),::tolower);return lookup(copy);}
