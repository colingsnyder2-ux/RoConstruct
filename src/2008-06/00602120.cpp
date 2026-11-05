// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_widgetcreatablenative55117a1c09f5ed3c.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/enable_shared_from_this.hpp>
#include "util/object.h"
struct Widget;
struct Prefix:RBX::Creatable<Widget>{char prefix[0xe0];};
struct Widget:Prefix,boost::enable_shared_from_this<Widget>{char rest[0x78];Widget(const std::string&,std::string);virtual ~Widget();static void predelete(Widget*);};
template boost::shared_ptr<Widget> RBX::Creatable<Widget>::create<Widget,std::string,std::string>(std::string,std::string);
