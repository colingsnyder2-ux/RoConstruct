// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_scriptsourcenativec8a782e0c8fa1c0f.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
struct Descriptor; extern Descriptor sourceProperty;
struct Script { char prefix[0x130]; boost::shared_ptr<const std::string> source; void raisePropertyChanged(const Descriptor&); void setSource(const std::string&); };
void Script::setSource(const std::string& value) { if(*source!=value) { source.reset(new std::string(value)); raisePropertyChanged(sourceProperty); } }
