// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace boost { namespace program_options {
template<class charT> class basic_option {
public:
    basic_option();
    basic_option(const basic_option& o);
    ~basic_option();
    basic_option& operator=(const basic_option& o);
    char data[0x60];
};
}}
template void std::vector<boost::program_options::basic_option<char> >::push_back(const boost::program_options::basic_option<char>&);
