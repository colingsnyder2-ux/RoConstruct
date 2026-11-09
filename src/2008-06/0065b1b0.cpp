// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_d27c86ddb5aece61.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <utility>
#include <cstring>
#include <G3D/Array.h>

namespace RBX {

class World;
class ContactManager;
class Primitive;

struct ContactNode {
	void* data;
	ContactNode* next;              // 0x04
};

struct SpatialNode {
	unsigned short children[8];
	unsigned short level;
	unsigned char flag;
	Primitive* primitive;
	int index;
	int grid[3];
	SpatialNode* next;              // 0x28
};

typedef std::pair<ContactNode*, SpatialNode*> SpatialBucket;

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
	~SpatialHash();
};

SpatialHash::~SpatialHash()
{
	for (int level = 0; level < numSpatialLevels; level++) {
		if (levels[level].size() != 0) {
			for (unsigned int i = 0; i < (unsigned int) (0x10000 >> level); i++) {
				unsigned int j = i;
				if (levels[level][i].first != NULL) {
					while (levels[level][i].first != NULL) {
						ContactNode* temp = levels[level][i].first;

						levels[level][i].first = levels[level][j].first->next;

						delete temp;

						nodesOut--;
					}
				}

				unsigned int k = i;
				if (levels[level][i].second != NULL) {
{ bool more = true;
					while (more && levels[level][i].second != NULL) {
						SpatialNode* temp = levels[level][i].second;

						levels[level][i].second = levels[level][k].second->next;

						delete temp;
					}
}
				}
			}
		}
	}

	while (extraContacts != NULL) {
		ContactNode* temp = extraContacts;

		extraContacts = temp->next;

		delete temp;
	}

	while (extraContacts2 != NULL) {
		ContactNode* temp = extraContacts2;

		extraContacts2 = temp->next;

		delete temp;
	}

	while (extraNodes != NULL) {
		SpatialNode* temp = extraNodes;

		extraNodes = temp->next;

		delete temp;
	}
}

}

