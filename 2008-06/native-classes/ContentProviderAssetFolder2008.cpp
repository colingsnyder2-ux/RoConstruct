// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr-len /I{headers}/std-noinline-string
// 2008-06 native (inactive): setAssetFolder 00560590, called with no this pointer from CRobloxApp::initializeSettings.
// Evidence: LDraw2Lua::originalAssetFolder() 0055c4c0 (result dropped), StandardOut "setAssetFolder %s", CPath checks
// ("The path '%s' is a relative path" / "does not exist" through G3D::format + std::runtime_error), AddBackslash, then the
// std::string at 009740f0 is assigned from the path.
// INFERRED: ContentProvider::setAssetFolder is static here and the target string a namespace-scope global (nativeAssetFolderPath);
// the exe's own symbol for either is unknown.
#include <atlbase.h>
#include <atlpath.h>
#include <shlwapi.h>
#include <G3D/format.h>
#include <stdexcept>
#include "util/ContentProvider.h"
#include "util/standardout.h"

namespace LDraw2Lua { std::string originalAssetFolder(); }

namespace RBX
{
	std::string nativeAssetFolderPath;   // 009740f0

	void ContentProvider::setAssetFolder(const char* sPath)
	{
		LDraw2Lua::originalAssetFolder();
		StandardOut::singleton()->print(MESSAGE_INFO, "setAssetFolder %s", sPath);
		ATL::CPath path(sPath);
		if (PathIsRelative(path))
			throw std::runtime_error(G3D::format("The path '%s' is a relative path", (const char*)path));
		if (!PathIsDirectory(path))
			throw std::runtime_error(G3D::format("The path '%s' does not exist", (const char*)path));
		path.AddBackslash();
		nativeAssetFolderPath = path;
	}
}
