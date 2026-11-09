// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_10b56f6cfacdfb5b.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <map>
#include <G3D/ReferenceCount.h>
namespace RBX {
namespace Render {
class AggregatingSceneManager {
public:
	class Bucket : public G3D::ReferenceCountedObject { };
	struct BucketKey
	{
		int materialId;
		float polygonOffset;
		float sortKey;
		bool castsShadows;
		bool operator<(const BucketKey& other) const
		{
			if (materialId < other.materialId)
				return true;
			if (materialId > other.materialId)
				return false;
			if (polygonOffset < other.polygonOffset)
				return true;
			if (polygonOffset > other.polygonOffset)
				return false;
			return sortKey < other.sortKey;
		}
	};
};
}
}
typedef RBX::Render::AggregatingSceneManager ASM;
typedef std::map<ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket> > BucketMap;
template std::pair<BucketMap::iterator, bool> std::_Tree<std::_Tmap_traits<ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket>, std::less<ASM::BucketKey>, std::allocator<std::pair<const ASM::BucketKey, G3D::ReferenceCountedPointer<ASM::Bucket> > >, false> >::insert(const BucketMap::value_type&);
