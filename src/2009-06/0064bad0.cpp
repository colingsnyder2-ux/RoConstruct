// from server: 87% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace detail {
int lexical_cast_impl(const std::string& arg, char* buf, unsigned int src_len);
}
inline int lexical_cast_int(const std::string& arg)
{
	char buf[4];
	return detail::lexical_cast_impl(arg, buf, 1);
}

bool getValue(const std::string& s, int* result)
{
	if (s.size())
	{
		try
		{
			*result = lexical_cast_int(s);
			return true;
		}
		catch (...)
		{
		}
	}
	return false;
}
