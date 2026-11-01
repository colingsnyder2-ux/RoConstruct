// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_c41d67013d7404dc.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <algorithm>
template std::string* std::find<std::string*,std::string>(std::string*,std::string*,const std::string&);
template const std::string* std::find<const std::string*,std::string>(const std::string*,const std::string*,const std::string&);
template std::vector<std::string>::iterator std::find<std::vector<std::string>::iterator,std::string>(std::vector<std::string>::iterator,std::vector<std::string>::iterator,const std::string&);
template std::vector<std::string>::const_iterator std::find<std::vector<std::string>::const_iterator,std::string>(std::vector<std::string>::const_iterator,std::vector<std::string>::const_iterator,const std::string&);
