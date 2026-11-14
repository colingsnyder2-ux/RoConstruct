// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor RenderLib method; original 0053f444 calls this body at 0053f720.
#include "RenderLib/SceneManager2008.h"
#include <G3D/g3dmath.h>
#include <algorithm>
namespace RBX { namespace RenderBase {
static bool isFinite(const G3D::Matrix3& m)
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!G3D::isFinite(m[i][j])) {
				return false;
			}
		}
	}

	return true;
}

static bool isReasonable(const G3D::Vector3& v)
{
	if (!v.isFinite()) {
		return false;
	}

	for (int i = 0; i < 3; ++i) {
		if (G3D::abs(v[i]) > 1e10) {
			return false;
		}
	}

	return true;
}

// Original 0053f920 checks translation first, then rotation.
static bool isReasonable(const G3D::CoordinateFrame& cframe)
{
	return isReasonable(cframe.translation) && isFinite(cframe.rotation);
}

void AggregatingSceneManager::Bucket::addToQueue(const G3D::ReferenceCountedPointer<Chunk>& chunk)
{
	if (chunk->aggregate.createStrongPtr().notNull()) {
		return;
	}

	if (chunk->getMesh().isNull()) {
		return;
	}

	if (chunk->getMesh()->detailLevel(1.0f)->primitive != G3D::RenderDevice::QUADS) {
		return;
	}

	if (!isReasonable(chunk->cframe())) {
		return;
	}

	if (std::find(queue.begin(), queue.end(), chunk) != queue.end()) {
		return;
	}

	queue.push_back(chunk);
}

} }
