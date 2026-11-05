// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_9332e769ecffde93.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <cstring>
#include <G3D/Array.h>

namespace RBX {

class World;
class ContactManager;
class Primitive;
struct SpatialNode;
struct ContactNode;

struct SpatialBucket {
	ContactNode* contacts;
	SpatialNode* nodes;
};

extern int numSpatialLevels;

class SpatialHash {
public:
	int field0;
	World* world;
	ContactManager* contactManager;
	std::vector<SpatialBucket> levels[4];   // 0x0c
	ContactNode* extraContacts;             // 0x6c
	ContactNode* extraContacts2;            // 0x70
	SpatialNode* extraNodes;                // 0x74
	int nodesOut;                           // 0x78
	int maxBucket;                          // 0x7c
	G3D::Array<Primitive*> found;           // 0x80

	SpatialHash(World* world, ContactManager* contactManager);
};

SpatialHash::SpatialHash(World* world, ContactManager* contactManager)
	: field0(0), world(world), contactManager(contactManager),
	  extraContacts(NULL), extraContacts2(NULL), extraNodes(NULL), nodesOut(0), maxBucket(0)
{
	for (int i = 0; i < numSpatialLevels; i++) {
		levels[i].resize(0x10000 >> i);
		memset(&levels[i][0], 0, levels[i].size() * sizeof(SpatialBucket));
	}
}

}
