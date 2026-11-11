// Ogre::TwoDManager method bodies (inactive native recovery, June 2008 client); see OgreRbxNode/TwoDManager2008.h.
// Bodies 00682560..006843e6 except render 006832b0. Built with the Ogre 1.4.5 client headers (/fp:fast);
// record_native_ogre_rbx_node.py verifies them.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// OgreRbxNodeTwoDManager | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 24b27030 | roc native-status --write
#include "OgreRbxNode/TwoDManager2008.h"
#include <OgreRoot.h>
#include <OgreRenderSystem.h>
#include <OgreSceneManager.h>
#include <OgreTextureManager.h>

namespace Ogre
{
	// 006831d0
	TwoDManager::TwoDManager()
	{
	}

	// 00683240
	TwoDManager::~TwoDManager()
	{
	}

	// 00682560
	void TwoDManager::setup(SceneManager* sceneManager, RenderTarget* target, uint8 queueId, bool afterQueue, bool flag)
	{
		this->afterQueue = afterQueue;
		this->queueId = queueId;
		this->sceneManager = sceneManager;
		this->target = target;
		this->flag = flag;
		vertexBuffer.setNull();
		sceneManager->addRenderQueueListener(this);
	}

	// 00682d60
	void TwoDManager::addQuad(String textureName, const G3D::Color4& color, Real left, Real top, Real right,
	                          Real bottom, Real u0, Real v0, Real u1, Real v1)
	{
		TexturePtr texture;

		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		quad.u0 = u0;
		quad.v0 = v0;
		quad.u1 = u1;
		quad.v1 = v1;

		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.operationType = RenderOperation::OT_TRIANGLE_LIST;
		quad.mode = 0;

		if (textureName != "")
		{
			texture = TextureManager::getSingleton().getByName(textureName);
			if (texture.isNull())
				texture = TextureManager::getSingleton().load(textureName, "General");

			if (!texture.isNull())
			{
				quad.texture = texture.getPointer()->getHandle();
				if ((left == right) && (top == bottom))
				{
					texture.getPointer()->getWidth();
					texture.getPointer()->getHeight();
				}
			}
			else
				quad.texture = 0;
		}
		else
			quad.texture = 0;

		quads.push_back(quad);
	}

	// 00683000
	void TwoDManager::primitive(RenderOperation::OperationType operationType, Real left, Real top, Real right,
	                            Real bottom, const G3D::Color4& color)
	{
		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.texture = 0;
		quad.operationType = operationType;
		quad.mode = 0;
		quads.push_back(quad);
	}

	// 006830b0
	void TwoDManager::outlineRectangle(Real left, Real top, Real right, Real bottom, const G3D::Color4& color)
	{
		Quad quad;
		quad.left = left;
		quad.top = top;
		quad.right = right;
		quad.bottom = bottom;
		RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
		renderSystem->convertColourValue(ColourValue(color.r, color.g, color.b, color.a), &quad.colour);
		quad.texture = 0;
		quad.operationType = RenderOperation::OT_LINE_LIST;
		quad.mode = 1;
		quads.push_back(quad);
	}

	// 006843b0
	void TwoDManager::renderQueueStarted(uint8 queueGroupId, const String& invocation, bool& skipThisInvocation)
	{
		if (!afterQueue && queueGroupId == queueId)
			render();
	}

	// 006843d0
	void TwoDManager::renderQueueEnded(uint8 queueGroupId, const String& invocation, bool& repeatThisInvocation)
	{
		if (afterQueue && queueGroupId == queueId)
			render();
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::TwoDManager::Quad> >;
template class std::allocator<Ogre::TwoDManager::Quad>;
template class std::allocator<std::_List_nod<Ogre::TwoDManager::Quad,std::allocator<Ogre::TwoDManager::Quad> >::_Node *>;
