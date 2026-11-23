// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native file-cache freshness helper (inactive). 005ef7a0 (146 B, registry placeholder func_005ef7a0): __cdecl,
// two const std::string& arguments; _stat64i32 (0x802770) on the first path (returns false when it fails), _stat on the
// second, compares the two st_mtime values (64-bit) and returns true while the first file is not older than the second;
// otherwise _unlink(first) (0x802634) and returns false. Only caller 005ef840 (6698 B, the image converter that
// handles "image/png" / "image/jpeg" / "image/bmp" / "image/tga" content and the "0xdecafbad" tag; reached from
// ViewNew::Part::getMaterial 004eb56c / 004eb71e), which calls it with (cachedPath, sourcePath).
// INFERRED: the function name; the binary records none and no 2007 analog exists (openrbx has no _stat / _unlink use).
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

namespace RBX
{
	// 005ef7a0
	bool isCachedFileCurrent(const std::string& cachedFile, const std::string& sourceFile)
	{
		struct _stat cachedStat;
		if (_stat(cachedFile.c_str(), &cachedStat) != 0)
			return false;

		struct _stat sourceStat;
		_stat(sourceFile.c_str(), &sourceStat);

		bool current = cachedStat.st_mtime >= sourceStat.st_mtime;
		if (!current)
			_unlink(cachedFile.c_str());
		return current;
	}
}
