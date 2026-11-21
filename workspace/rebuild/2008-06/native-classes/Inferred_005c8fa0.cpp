// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /FIwinsock2.h /I{headers}/../../../tools/rbxgs/Client/Network
// 005c8fa0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "Replicator.h"
#include "util/Log.h"
#include "util/Name.h"

namespace RBX {

template<>
void Stats::Item::formatValue<G3D::Stopwatch>(const G3D::Stopwatch& sw)
{
	val = sw.smoothElapsedTime();
	if (sw.smoothElapsedTime() > 0) {
		std::string t = Log::formatTime(sw.smoothElapsedTime());
		sValue = G3D::format("%s (%.3gfps)", t.c_str(), 1.0 / sw.smoothElapsedTime());
	} else {
		sValue = Log::formatTime(sw.smoothElapsedTime());
	}
}

}
