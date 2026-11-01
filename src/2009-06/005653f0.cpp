// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost {
namespace detail {
template<class Target, class Source, bool Unlimited, class CharT>
Target lexical_cast(Source arg, CharT* buf, std::size_t src_len);
template<class Source> struct lcast_src_length { static const std::size_t value = 2 + 9 * 2; static void check_coverage() {} };
}
template<class Target, class Source>
inline Target lexical_cast(const Source& arg)
{
    typedef detail::lcast_src_length<Source> lcast_src_length;
    std::size_t const src_len = lcast_src_length::value;
    char buf[src_len + 1];
    lcast_src_length::check_coverage();
    return detail::lexical_cast<Target, Source, !src_len>(arg, buf, src_len);
}
template std::string lexical_cast<std::string, int>(const int&);
}
