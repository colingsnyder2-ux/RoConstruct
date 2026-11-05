// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_contentreadexceptionlog354fc7d4f8d46fad.cpp

// Candidate translation unit (score above; library headers required).
#include "util/StandardOut.h"
#include <sstream>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
void readContent(boost::function<void(void*,std::istream&)> callback,void* context,boost::shared_ptr<const std::string> text){try{std::istringstream input(*text);callback(context,input);}catch(std::exception& e){RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR,"ContentProvider callback exception: %s",e.what());}}
