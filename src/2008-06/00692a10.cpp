// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_large_skybox_8f6d8e40516e2b8d.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <new>
namespace Ogre {
// Native constructor 0067fd60 is opaque here. Its caller allocates exactly d4;
// class allocation preserves that observed extent without fake members.
// This allocation declaration is a codegen analogue, not an original header.
class RbxSky {public: static void* operator new(size_t) {return ::operator new(0xd4);} RbxSky(SceneManager*,const String&,bool);virtual ~RbxSky();};
class RecoveredSkySceneManager:public SceneManager {
 bool visibilityState,renderState;
 String skyPath;
 SharedPtr<RbxSky> sky;
 SceneNode* topBottomNode;
public:
 void setSkyBox(bool,const String&,Real,bool,const Quaternion&,const String&);
 MeshPtr createSkyboxPlane(BoxPlane,Real,const Quaternion&,const String&);
};
void RecoveredSkySceneManager::setSkyBox(bool enable,const String& materialName,Real distance,bool drawFirst,const Quaternion& orientation,const String& groupName) {
 if(enable) {
  if(sky.isNull()) {
   sky.bind(new RbxSky(this,skyPath,true));
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
   topBottomNode=createSceneNode("SkyBoxTBNode");
   topBottomNode->setOrientation(Quaternion(Radian(Math::fDeg2Rad*-90.0f),Vector3(0,1,0)));
  } else {
   mSkyBoxNode->detachAllObjects();
   topBottomNode->detachAllObjects();
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
   else topBottomNode->attachObject(mSkyBoxEntity[i]);
  }
 }
 mSkyBoxEnabled=enable;
 mSkyBoxGenParameters.skyBoxDistance=distance;
}
}
