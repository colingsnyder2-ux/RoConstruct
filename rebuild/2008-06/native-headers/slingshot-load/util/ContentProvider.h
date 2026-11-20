#pragma once
// slingshot-load/util/ContentProvider.h: the donor tools/rbxgs App/include/util/ContentProvider.h plus the 2008
// ContentId::fromAssets(const char*) overload (?fromAssets@ContentId@RBX@@SA?AV12@PBD@Z, defined in
// native-classes/ContentIdAssets.cpp).
// This header forwards to that donor file by its own path instead of redefining ContentId / ContentProvider /
// MD5Hasher: most units reach the donor header first (v8xml/XmlElement.h includes "util/ContentProvider.h"), and
// util/MeshId.h includes this header afterwards, so a second copy of the classes was a C2011 redefinition
// (ViewNewPart.cpp, ViewNewPartSurfaceUpdate2008.cpp and the other SpecialShape.h / MeshId.h includers).
// #pragma once on the shared donor file keeps one definition whichever header comes first.
// When this header comes first (units with /I{headers}/slingshot-load, where "util/ContentProvider.h" resolves
// here), the extra overload is spliced into the donor class just before fromMD5Hash, the order of the former copy
// (fromAssets(const std::string&), fromAssets(const char*), fromMD5Hash). When the donor file was already included,
// the class is the donor's, exactly as those units compiled before util/MeshId.h existed.
#define fromMD5Hash fromAssets(const char* filePath); static ContentId fromMD5Hash
#include "../../../../../tools/rbxgs/Client/App/include/util/ContentProvider.h"
#undef fromMD5Hash
