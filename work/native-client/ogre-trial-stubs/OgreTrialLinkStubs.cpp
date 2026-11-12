// TRIAL-ONLY link stubs (never committed to a live module): seven functions/globals native files call but nobody has
// recovered yet. They let the Ogre trial measure whether everything else links. Each must become real native code.
#include <map>
#include <string>
namespace Ogre {
class SubMesh; class Camera;
class FrameHistory { public: int getCount() const; };
int FrameHistory::getCount() const { return 0; }
class TwoDManager { void createVertexBuffer(unsigned int); };
void TwoDManager::createVertexBuffer(unsigned int) {}
std::map<SubMesh*, std::string>* subMeshNames = 0;
long subMeshNamesOnce = 0;
void initializeSubMeshNames() {}
}
