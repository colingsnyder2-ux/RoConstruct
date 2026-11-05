// from server: 100% by EspClaude
// roc 2007-08 00580bf0  RBX::StringConverter<int>::convertToValue (rbxgs util/Utilities.cpp body);
// boost::lexical_cast<int>(std::string) is out of line (0x580820).
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <typeinfo>
namespace boost {
class bad_lexical_cast : public std::bad_cast {
public:
    virtual ~bad_lexical_cast() throw();
};
template<typename Target, typename Source> Target lexical_cast(const Source& arg);
}
namespace RBX {
template<class T> class StringConverter {
public:
    static bool convertToValue(const std::string& text, T& value);
};

template<>
bool StringConverter<int>::convertToValue(const std::string& text, int& value)
{
    if (text.size() == 0)
        return false;

    try
    {
        value = boost::lexical_cast<int>(text);
        return true;
    }
    catch (boost::bad_lexical_cast&)
    {
        return false;
    }
}
}
