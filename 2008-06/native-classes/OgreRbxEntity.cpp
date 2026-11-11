// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreRbxEntity | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src cddb2cdb | roc native-status --write
#include "OgreRbx/RbxEntity2008.h"
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include <OgreSubEntity.h>
#include <OgreSubMesh.h>

namespace Ogre
{
	RbxEntity::RbxEntity()
	{
		mLodBudget = 20.0f;
		mInitialised = true;
		mHistory = 0;
		mVisibilityCulling = true;
		mRecordHistory = true;
		mMinimumLod = 888;
	}

	RbxEntity::~RbxEntity()
	{
		for (int i = 0; i < (int)getNumSubEntities(); ++i)
		{
			RbxSubEntity* subEntity = dynamic_cast<RbxSubEntity*>(mSubEntityList[i]);
			if (subEntity)
				delete subEntity;
		}
		mSubEntityList.clear();
	}

	// 0067c6a0: slot 54 of vtable 0084e45c.  The name remains an address
	// placeholder; receiver, bool argument, base SubEntityList iteration and
	// virtual setVisible call are all target-derived.
	void RbxEntity::func_0067c6a0(bool visible)
	{
		for (int i = 0; i < (int)mSubEntityList.size(); ++i)
			mSubEntityList[i]->setVisible(visible);
	}

	SubEntity* RbxEntity::createSubEntity(SubMesh* subMesh, unsigned int lod)
	{
		RbxSubEntity* subEntity = new RbxSubEntity(this, subMesh, lod);
		if (subMesh->isMatInitialised())
			subEntity->setMaterialName(subMesh->getMaterialName());
		mSubEntityList.push_back(subEntity);
		return subEntity;
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template unsigned char * std::vector<unsigned char,class std::allocator<unsigned char> >::_Ucopy<unsigned char const *>(unsigned char const *,unsigned char const *,unsigned char *);
template unsigned char * std::vector<unsigned char,class std::allocator<unsigned char> >::_Umove<unsigned char *>(unsigned char *,unsigned char *,unsigned char *);
