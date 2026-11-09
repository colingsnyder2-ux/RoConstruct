// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /I"C:\Users\colin\RoConstruct\tools\libs\boost_1_34_1"

#include <string>
#include <boost/function.hpp>

template class boost::function<std::pair<std::string, std::string>(const std::string&), std::allocator<boost::function_base>>;