// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Ogre::RbxSky as compiled into the June 2008 client (inactive native recovery; Roblox's exe-local sky object for its
// Ogre 1.4.5 fork, the image block 0067f170..00681190 between VisualEngine and RbxSceneNode).
//
// Evidence (original Roblox.exe):
//   * RTTI vtable 0084e56c .?AVRbxSky@Ogre@@, no base classes, one slot: ??_G 0067fd40 (calls the destructor 0067fb50).
//   * size 0xd4: RbxSceneManager::setSkyBox 00692a10 pushes 0xd4 to operator new and calls the constructor 0067fd60
//     (ret 0xc: SceneManager*, const String& path, bool enabled).
//   * constructor 0067fd60 / destructor 0067fb50: TexturePtr at +0x04 / +0x10 / +0x1c / +0x28 (the ctor loads
//     path + "sun.jpg" into +0x04, "moon.jpg" into +0x10 and "sun-rays.jpg" into +0x28; +0x1c is constructed and
//     destroyed only), BillboardSet* sun / moon / sun rays at +0x34 / +0x38 / +0x3c, SceneNode* sun / moon / stars /
//     sky at +0x40 / +0x44 / +0x48 / +0x4c, MaterialPtr at +0x54 / +0x60 / +0x6c / +0x78 (sunMatl, sunRaysMatl,
//     moonMatl, starsMatl<n>), bool +0x84 = false (sun rays shown), std::vector<Vector3> +0x88 (star positions) and
//     std::vector<float> +0xa0 (star intensities), bool +0xb8 = enabled; +0x85 (stars shown) is a bool set by
//     0067f230 and read by update 0067f850; Vector3 sun / moon positions +0xbc / +0xc8 (0067f550 / 0067f230, read by
//     update).
//   * +0x50..+0x53 is NOT derived: no instruction in the client reads, writes, constructs or destroys it (the
//     constructor initialises the pointers +0x34..+0x4c by assignment and never touches +0x50). The class therefore
//     has no native declaration yet (no placeholder members); its bodies below are pending-build-only.
//
// Built from the current headers (counted): the std::vector<Ogre::Vector3> / std::vector<float> COMDATs of this block,
// from explicit instantiation (resize 0067fc70, erase 0067fa80, the destructor 0067fb10, _Copy_opt 0067f170,
// _Copy_backward_opt 0067f1d0, _Fill 0067f7c0).
// Pending-build-only (NATIVE_OGRE_RBX_SKY_PENDING, with the proposal header that tests/record_native_ogre_rbx_sky.py
// generates under rebuild/2008-06/out/): the RbxSky members.
#include <vector>
#include <OgreVector3.h>

template class std::vector<Ogre::Vector3>;
template class std::vector<float>;

#ifdef NATIVE_OGRE_RBX_SKY_PENDING
#include "OgreRbxSky/RbxSkyPending2008.h"
#include <OgreSceneManager.h>
#include <OgreBillboardSet.h>
#include <OgreBillboard.h>
#include <OgreManualObject.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreMeshManager.h>
#include <OgreMesh.h>
#include <OgreSubMesh.h>
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <OgreTextureUnitState.h>
#include <OgreStringConverter.h>
#include <OgreStringVector.h>
#include <OgreCamera.h>
#include <OgreRenderQueue.h>
#include <OgreRenderQueueSortingGrouping.h>
#include <OgreViewport.h>
#include <G3D/BinaryInput.h>
#include <G3D/fileutils.h>
#include <G3D/Vector3.h>
#include <G3D/Color3.h>
#include <G3D/Color4.h>
#include <G3D/g3dmath.h>
#include <GLG3D/LightingParameters.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace Ogre
{

RbxSky::RbxSky(SceneManager* sceneManager, const String& path, bool enabled)
	: mSunRaysVisible(false), mEnabled(enabled)
{
	if (mEnabled)
	{
		mMoonTexture = TextureManager::getSingleton().load(path + "moon.jpg", "General");
		mSunTexture = TextureManager::getSingleton().load(path + "sun.jpg", "General");
		mSunRaysTexture = TextureManager::getSingleton().load(path + "sun-rays.jpg", "General");
		const String& prefix = sceneManager->getName();

		mSunMaterial = MaterialManager::getSingleton().create(prefix + "sunMatl", "General");
		mSunMaterial->setSceneBlending(SBF_ONE, SBF_ONE);
		TextureUnitState* texture = mSunMaterial->getTechnique(0)->getPass(0)->createTextureUnitState();
		texture->setColourOperationEx(LBX_MODULATE, LBS_TEXTURE, LBS_CURRENT);
		texture->setAlphaOperation(LBX_MODULATE, LBS_TEXTURE, LBS_CURRENT);
		texture->setTextureName(mSunTexture->getName());
		mSunMaterial->setDepthWriteEnabled(false);
		mSunMaterial->setLightingEnabled(false);
		mSunRaysMaterial = mSunMaterial->clone(prefix + "sunRaysMatl");
		mSunRaysMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(mSunRaysTexture->getName());

		mMoonMaterial = MaterialManager::getSingleton().create(prefix + "moonMatl", "General");
		mMoonMaterial->setSceneBlending(SBF_SOURCE_ALPHA, SBF_ONE);
		texture = mMoonMaterial->getTechnique(0)->getPass(0)->createTextureUnitState();
		texture->setColourOperationEx(LBX_MODULATE, LBS_TEXTURE, LBS_CURRENT);
		texture->setAlphaOperation(LBX_MODULATE, LBS_TEXTURE, LBS_CURRENT);
		texture->setTextureName(mMoonTexture->getName());
		texture->setTextureName(mMoonTexture->getName());
		mMoonMaterial->setDepthWriteEnabled(false);
		mMoonMaterial->setLightingEnabled(false);

		mSun = sceneManager->createBillboardSet(prefix + "sun", 1);
		mSun->setDefaultDimensions(1000.0f, 1000.0f);
		mSun->createBillboard(Vector3::ZERO);
		mSun->createBillboard(Vector3::ZERO);
		mSun->createBillboard(Vector3::ZERO);
		mSun->setMaterialName(prefix + "sunMatl");
		mSunRays = sceneManager->createBillboardSet(prefix + "sunRays", 1);
		mSunRays->setDefaultDimensions(1000.0f, 1000.0f);
		mSunRays->createBillboard(Vector3::ZERO);
		mSunRays->setMaterialName(prefix + "sunRaysMatl");
		mMoon = sceneManager->createBillboardSet(prefix + "moon", 1);
		mMoon->setDefaultDimensions(500.0f, 500.0f);
		mMoon->createBillboard(Vector3::ZERO);
		mMoon->setMaterialName(prefix + "moonMatl");
		mSkyNode = sceneManager->createSceneNode(prefix + "skyNode");
		mSunNode = mSkyNode->createChildSceneNode(prefix + "sunNode");
		mMoonNode = mSkyNode->createChildSceneNode(prefix + "moonNode");
		mSunNode->attachObject(mSun);
		mSunNode->attachObject(mSunRays);
		mMoonNode->attachObject(mMoon);
		mSun->setCastShadows(false);
		mSunRays->setCastShadows(false);
		mMoon->setCastShadows(false);

		int i;
		if (G3D::fileExists(path + "real.str"))
		{
			G3D::BinaryInput input(path + "real.str", G3D::G3D_LITTLE_ENDIAN, true);
			String header = input.readString(5);
			int count = input.readInt16();
			mStarPositions.resize(count);
			mStarIntensities.resize(count);
			for (i = 0; i < count; ++i)
			{
				float x = (2.0f * input.readInt16() + 1.0f) / 65535.0f;
				float y = (2.0f * input.readInt16() + 1.0f) / 65535.0f;
				float z = (2.0f * input.readInt16() + 1.0f) / 65535.0f;
				mStarPositions[i] = Vector3(x, y, z) * 1000.0f;
				double intensity = (2.0f * input.readInt16() + 1.0f) / 65535.0f;
				mStarIntensities[i] = intensity * intensity + 0.3f;
			}
		}
		else
		{
			mStarPositions.resize(3000);
			mStarIntensities.resize(mStarPositions.size());
			for (i = mStarPositions.size() - 1; i >= 0; --i)
			{
				G3D::Vector3 point = G3D::Vector3::random();
				mStarPositions[i] = Vector3(point.x * 1000.0f, point.y * 1000.0f, point.z * 1000.0f);
				double intensity = std::rand() / (float)RAND_MAX;
				mStarIntensities[i] = intensity * intensity + 0.3f;
			}
		}
		mStarsNode = sceneManager->createSceneNode(prefix + "starsNode");
		for (int size = 1; size <= 3; ++size)
		{
			mStarsMaterial = MaterialManager::getSingleton().create(
				prefix + "starsMatl" + StringConverter::toString(size), "General");
			mStarsMaterial->setDepthWriteEnabled(false);
			mStarsMaterial->setLightingEnabled(false);
			mStarsMaterial->setPointSize(size + 0.2f);
			String objectName = prefix + "st" + StringConverter::toString(size);
			ManualObject* stars = new ManualObject(objectName);
			stars->begin(mStarsMaterial->getName(), RenderOperation::OT_POINT_LIST);
			for (int i = 0; i < (int)mStarPositions.size(); ++i)
			{
				if (mStarIntensities[i] * 3.0f > size - 1 && mStarIntensities[i] * 3.0f <= size)
					stars->position(mStarPositions[i][0], mStarPositions[i][1], mStarPositions[i][2]);
			}
			stars->end();
			stars->setMaterialName(0, mStarsMaterial->getName());
			mStarsNode->attachObject(stars);
			stars->setCastShadows(false);
		}
	}
}

RbxSky::~RbxSky()
{
}

void RbxSky::update(Camera* camera, RenderQueue* queue, RenderQueueGroupID)
{
	Vector3 position = camera->getDerivedPosition();
	mMoonNode->setPosition(mMoonPosition + position);
	mSunNode->setPosition(mSunPosition + position);
	mStarsNode->setPosition(position);
	queue->getQueueGroup(RENDER_QUEUE_1)->setShadowsEnabled(false);
	queue->getQueueGroup(RENDER_QUEUE_2)->setShadowsEnabled(false);
	mMoon->setRenderQueueGroup(RENDER_QUEUE_1);
	mMoon->_notifyCurrentCamera(camera);
	mMoon->_updateRenderQueue(queue);
	mSun->setRenderQueueGroup(RENDER_QUEUE_2);
	mSun->_notifyCurrentCamera(camera);
	mSun->_updateRenderQueue(queue);
	if (mSunRaysVisible)
	{
		mSunRays->setRenderQueueGroup(RENDER_QUEUE_2);
		mSunRays->_notifyCurrentCamera(camera);
		mSunRays->_updateRenderQueue(queue);
	}
	if (mStarsVisible)
	{
		SceneNode::ObjectIterator i = mStarsNode->getAttachedObjectIterator();
		while (i.hasMoreElements())
		{
			ManualObject* stars = dynamic_cast<ManualObject*>(i.getNext());
			stars->setRenderQueueGroup(RENDER_QUEUE_1);
			stars->_notifyCurrentCamera(camera);
			stars->_updateRenderQueue(queue);
		}
	}
}

void RbxSky::setLighting(VisualEngine* engine, const G3D::LightingParameters& lighting)
{
	engine->viewport->setBackgroundColour(
		ColourValue(lighting.skyAmbient.r, lighting.skyAmbient.g, lighting.skyAmbient.b, 1.0f));
	if (mEnabled)
	{
		updateMoonAndStars(engine, lighting);
		updateSun(engine, lighting);
	}
}

void RbxSky::updateMoonAndStars(VisualEngine*, const G3D::LightingParameters& lighting)
{
	if (lighting.moonPosition.y > -.3f)
	{
		mStarsVisible = true;
		MeshPtr mesh(MeshManager::getSingleton().getByName("starsMesh"));
		if (!mesh.isNull())
		{
			if (0.3f < lighting.skyAmbient.r && lighting.skyAmbient.r < .7f)
			{
				for (int i = 0; i < 3; ++i)
				{
					MaterialManager& manager = MaterialManager::getSingleton();
					MaterialPtr material(manager.getByName(mesh->getSubMesh((unsigned short)i)->getMaterialName()));
					material->setSceneBlending(SBF_ONE_MINUS_DEST_COLOUR, SBF_ZERO);
				}
			}
			else
			{
				for (int i = 0; i < 3; ++i)
				{
					MaterialManager& manager = MaterialManager::getSingleton();
					MaterialPtr material(manager.getByName(mesh->getSubMesh((unsigned short)i)->getMaterialName()));
					material->setSceneBlending(SBT_REPLACE);
				}
			}
		}
	}
	else
		mStarsVisible = false;
	G3D::Vector3 moon = lighting.physicallyCorrect ? lighting.trueMoonPosition : lighting.moonPosition;
	float alpha = std::min(1.f - lighting.skyAmbient.g + .1f, 1.f);
	G3D::Vector3 world = moon * 2700.f;
	mMoonNode->setPosition(world.x, world.y, world.z);
	mMoon->getBillboard(0)->setColour(ColourValue(alpha, alpha, alpha, 1.f));
	mMoonPosition = Vector3(world.x, world.y, world.z);
}

void RbxSky::updateSun(VisualEngine*, const G3D::LightingParameters& lighting)
{
	G3D::Vector3 sun = lighting.physicallyCorrect ? lighting.trueSunPosition : lighting.sunPosition;
	G3D::Color3 color = lighting.emissiveScale * 0.8f;
	if (sun.y < 0)
	{
		float factor = G3D::max(0.0f, (sun.y + 0.1f) * 10.0f);
		color *= factor;
	}
	sun *= 2700.0f;
	mSunNode->setPosition(sun.x, sun.y, sun.z);
	mSun->getBillboard(0)->setColour(ColourValue(color.r, color.g, color.b));
	mSun->getBillboard(1)->setColour(ColourValue(color.r, color.g, color.b));
	mSun->getBillboard(2)->setColour(ColourValue(color.r, color.g, color.b));
	mSunPosition = Vector3(sun.x, sun.y, sun.z);
	if (0 < sun.x && sun.y >= -0.1)
	{
		float brightness = static_cast<float>(0.25599999237060506 *
			G3D::max(0.0f, G3D::min(1.0f, 1.0f - sun.y / static_cast<float>(sqrt(2.0)) * 2.0f)));
		G3D::Color4 rays = G3D::Color4(1, 1, 1, 1) * brightness;
		mSunRays->getBillboard(0)->setColour(ColourValue(rays.r, rays.g, rays.b, rays.a));
		mSunRaysVisible = true;
	}
	else
		mSunRaysVisible = false;
}

}
#endif

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::Vector3> >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> >,std::iterator<std::random_access_iterator_tag,Ogre::Vector3,int,Ogre::Vector3 const *,Ogre::Vector3 const &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> >,std::iterator<std::random_access_iterator_tag,Ogre::Vector3,int,Ogre::Vector3 *,Ogre::Vector3 &> >;
template class std::_Vector_const_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> >;
template class std::_Vector_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> >;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::Vector3,std::allocator<Ogre::Vector3> > >;
