// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <streambuf>
#include <typeinfo>
namespace boost {
class bad_lexical_cast : public std::bad_cast {
public:
    bad_lexical_cast() : source(&typeid(void)), target(&typeid(void)) {}
    bad_lexical_cast(const std::type_info& s, const std::type_info& t) : source(&s), target(&t) {}
    const std::type_info& source_type() const { return *source; }
    virtual const char* what() const throw() { return "bad lexical cast: source type value could not be interpreted as target"; }
    virtual ~bad_lexical_cast() throw() {}
private:
    const std::type_info* source;
    const std::type_info* target;
};
template<class E> __declspec(noreturn) void throw_exception(E const& e);
namespace detail {
template<class CharT, class Base, class Traits>
class lexical_stream_limited_src : public Base {
    CharT* start;
    CharT* finish;
public:
    lexical_stream_limited_src(CharT* sta, CharT* fin) : start(sta), finish(fin) {}
    bool operator<<(std::basic_string<CharT, Traits> const& str)
    {
        start = const_cast<CharT*>(str.data());
        finish = start + str.length();
        return true;
    }
    template<class InputStreamable> bool operator>>(InputStreamable& output);
};
template<class Target, class Source, bool Unlimited, class CharT>
Target lexical_cast(Source const& arg, CharT* buf, std::size_t src_len)
{
    typedef std::char_traits<CharT> traits;
    lexical_stream_limited_src<CharT, std::basic_streambuf<CharT, traits>, traits> interpreter(buf, buf + src_len);
    Target result;
    if (!(interpreter << arg && interpreter >> result))
        throw_exception(bad_lexical_cast(typeid(Source), typeid(Target)));
    return result;
}
}
template<class Target, class Source>
inline Target lexical_cast(const Source& arg)
{
    char buf[2];
    return detail::lexical_cast<Target, Source, false>(arg, buf, 1);
}
}
template __int64 boost::lexical_cast<__int64, std::string>(const std::string&);
