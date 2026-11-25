// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include <string>
#include <boost/lexical_cast.hpp>
#include <windows.h>

namespace RBX {
namespace Render {

static __declspec(noinline) std::string getMaxRes()
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	std::string w = boost::lexical_cast<std::string>(width);
	std::string h = boost::lexical_cast<std::string>(height);
	// INFERRED: the separator literal at 0x80f0cc is "x"
	return w + "x" + h;
}

}
}

// INFERRED: thin caller so MSVC compiles static getMaxRes with internal-linkage IPA matching RenderSpecData.cpp.
std::string Local_005019f0_keep()
{
	return RBX::Render::getMaxRes();
}
