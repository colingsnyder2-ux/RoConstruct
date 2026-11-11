// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreRbxSceneManagerSkybox2008 | 2008-06 | 6 byte-exact, inactive (not link-selected)
// 6/6 mapped addresses byte-exact | 0 unproved | no mapped strings | by auto (+2) (mixed 2)
// <<< native-status | src 945c5509 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include <Ogre.h>
#include "OgreRbx/RbxSceneManager2008.h"
// INFERRED: fork field names from documented native offsets; source location from exact donor.
namespace Ogre {
void RbxSceneManager::setSkyBox(bool enable,const String& materialName,Real distance,bool drawFirst,const Quaternion& orientation,const String& groupName) {
 if(enable) {
  if(mRbxSky.isNull()) {
   mRbxSky.bind(new RbxSky(this,mRbxSkyName,true));
  }
  MaterialPtr m=MaterialManager::getSingleton().getByName(materialName);
  if(m.isNull()) {
#line 1430 ".\\RbxSceneManager.cpp"
   OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,"Sky box material '"+materialName+"' not found.","RbxSceneManager::setSkyBox");
  }
  m->setDepthWriteEnabled(false);
  m->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setNumMipmaps(0);
  m->load();
  m->getBestTechnique()->getPass(0)->getTextureUnitState(0)->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
  mSkyBoxDrawFirst=drawFirst;
  if(!mSkyBoxNode) {
   mSkyBoxNode=createSceneNode("SkyBoxNode");
   mRbxSkyNode=createSceneNode("SkyBoxTBNode");
   mRbxSkyNode->setOrientation(Quaternion(Radian(Math::fDeg2Rad*-90.0f),Vector3(0,1,0)));
  } else {
   mSkyBoxNode->detachAllObjects();
   mRbxSkyNode->detachAllObjects();
  }
  MaterialManager& matMgr=MaterialManager::getSingleton();
  for(int i=0;i<6;++i) {
   MeshPtr planeMesh=createSkyboxPlane((BoxPlane)i,distance,orientation,groupName);
   String entName=mName+"SkyBoxPlane"+StringConverter::toString(i);
   if(mSkyBoxEntity[i]) destroyEntity(entName);
   mSkyBoxEntity[i]=createEntity(entName,planeMesh->getName());
   mSkyBoxEntity[i]->setCastShadows(false);
   MaterialPtr boxMat=matMgr.getByName(entName);
   if(boxMat.isNull()) boxMat=m->clone(entName);
   else m->copyDetailsTo(boxMat);
   boxMat->setDepthWriteEnabled(false);
   boxMat->setSceneBlending(SBT_MODULATE);
   boxMat->load();
   Material::TechniqueIterator ti=boxMat->getSupportedTechniqueIterator();
   while(ti.hasMoreElements()) ti.getNext()->getPass(0)->getTextureUnitState(0)->setCurrentFrame(i);
   mSkyBoxEntity[i]->setMaterialName(boxMat->getName());
   if(i<4) mSkyBoxNode->attachObject(mSkyBoxEntity[i]);
   else mRbxSkyNode->attachObject(mSkyBoxEntity[i]);
  }
 }
 mSkyBoxEnabled=enable;
 mSkyBoxGenParameters.skyBoxDistance=distance;
}
}
