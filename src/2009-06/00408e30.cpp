// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Triple {
    std::string first;
    std::string second;
    std::string third;
    ~Triple();
};
Triple::~Triple() {}
