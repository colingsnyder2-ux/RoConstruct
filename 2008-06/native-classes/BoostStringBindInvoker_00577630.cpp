// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-function-pod-vtable
// 2008-06 boost::function0<void> holding bind(string(*)(string), string): invoke thunks 00577630 / 00577670.
#include <string>
#include <boost/bind.hpp>
#include <boost/function.hpp>

std::string rbxStringFnA(std::string s);
std::string rbxStringFnB(std::string s);

void assignStringBindA(boost::function0<void>& f, const std::string& s)
{
	f = boost::bind(&rbxStringFnA, s);
}

void assignStringBindB(boost::function0<void>& f, const std::string& s)
{
	f = boost::bind(&rbxStringFnB, s);
}
