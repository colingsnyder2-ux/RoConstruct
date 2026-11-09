// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_large_shadow_02e53319fe5284dd.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <OgreSpotShadowFadePng.h>
#include <OgreShadowVolumeExtrudeProgram.h>
using namespace Ogre;
struct HeaderRecovery : Ogre::SceneManager { void recover_initShadowVolumeMaterials(void); };
void HeaderRecovery::recover_initShadowVolumeMaterials(void) {
    /* This should have been set in the SceneManager constructor, but if you
       created the SceneManager BEFORE the Root object, you will need to call
       SceneManager::_setDestinationRenderSystem manually.
     */
    assert( mDestRenderSystem );

    if (mShadowMaterialInitDone)
        return;

    if (!mShadowDebugPass)
    {
        MaterialPtr matDebug = 
            MaterialManager::getSingleton().getByName("Ogre/Debug/ShadowVolumes");
        if (matDebug.isNull())
        {
            // Create
            matDebug = MaterialManager::getSingleton().create(
                "Ogre/Debug/ShadowVolumes", 
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowDebugPass = matDebug->getTechnique(0)->getPass(0);
            mShadowDebugPass->setSceneBlending(SBT_ADD); 
            mShadowDebugPass->setLightingEnabled(false);
            mShadowDebugPass->setDepthWriteEnabled(false);
            TextureUnitState* t = mShadowDebugPass->createTextureUnitState();
            t->setColourOperationEx(LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, 
                ColourValue(0.7, 0.0, 0.2));
            mShadowDebugPass->setCullingMode(CULL_NONE);

            if (mDestRenderSystem->getCapabilities()->hasCapability(
                RSC_VERTEX_PROGRAM))
            {
                ShadowVolumeExtrudeProgram::initialise();

                // Enable the (infinite) point light extruder for now, just to get some params
                mShadowDebugPass->setVertexProgram(
                    ShadowVolumeExtrudeProgram::programNames[ShadowVolumeExtrudeProgram::POINT_LIGHT]);
                mInfiniteExtrusionParams = 
                    mShadowDebugPass->getVertexProgramParameters();
                mInfiniteExtrusionParams->setAutoConstant(0, 
                    GpuProgramParameters::ACT_WORLDVIEWPROJ_MATRIX);
                mInfiniteExtrusionParams->setAutoConstant(4, 
                    GpuProgramParameters::ACT_LIGHT_POSITION_OBJECT_SPACE);
            }	
            matDebug->compile();

        }
        else
        {
            mShadowDebugPass = matDebug->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM))
            {
                mInfiniteExtrusionParams = mShadowDebugPass->getVertexProgramParameters();
            }
        }
    }

    if (!mShadowStencilPass)
    {

        MaterialPtr matStencil = MaterialManager::getSingleton().getByName(
            "Ogre/StencilShadowVolumes");
        if (matStencil.isNull())
        {
            // Init
            matStencil = MaterialManager::getSingleton().create(
                "Ogre/StencilShadowVolumes",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowStencilPass = matStencil->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(
                RSC_VERTEX_PROGRAM))
            {

                // Enable the finite point light extruder for now, just to get some params
                mShadowStencilPass->setVertexProgram(
                    ShadowVolumeExtrudeProgram::programNames[ShadowVolumeExtrudeProgram::POINT_LIGHT_FINITE]);
                mFiniteExtrusionParams = 
                    mShadowStencilPass->getVertexProgramParameters();
                mFiniteExtrusionParams->setAutoConstant(0, 
                    GpuProgramParameters::ACT_WORLDVIEWPROJ_MATRIX);
                mFiniteExtrusionParams->setAutoConstant(4, 
                    GpuProgramParameters::ACT_LIGHT_POSITION_OBJECT_SPACE);
                // Note extra parameter
                mFiniteExtrusionParams->setAutoConstant(5, 
                    GpuProgramParameters::ACT_SHADOW_EXTRUSION_DISTANCE);
            }
            matStencil->compile();
            // Nothing else, we don't use this like a 'real' pass anyway,
            // it's more of a placeholder
        }
        else
        {
            mShadowStencilPass = matStencil->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM))
            {
                mFiniteExtrusionParams = mShadowStencilPass->getVertexProgramParameters();
            }
        }
    }




    if (!mShadowModulativePass)
    {

        MaterialPtr matModStencil = MaterialManager::getSingleton().getByName(
            "Ogre/StencilShadowModulationPass");
        if (matModStencil.isNull())
        {
            // Init
            matModStencil = MaterialManager::getSingleton().create(
                "Ogre/StencilShadowModulationPass",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowModulativePass = matModStencil->getTechnique(0)->getPass(0);
            mShadowModulativePass->setSceneBlending(SBF_DEST_COLOUR, SBF_ZERO); 
            mShadowModulativePass->setLightingEnabled(false);
            mShadowModulativePass->setDepthWriteEnabled(false);
            mShadowModulativePass->setDepthCheckEnabled(false);
            TextureUnitState* t = mShadowModulativePass->createTextureUnitState();
            t->setColourOperationEx(LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, 
                mShadowColour);
            mShadowModulativePass->setCullingMode(CULL_NONE);
        }
        else
        {
            mShadowModulativePass = matModStencil->getTechnique(0)->getPass(0);
        }
    }

    // Also init full screen quad while we're at it
    if (!mFullScreenQuad)
    {
        mFullScreenQuad = new Rectangle2D();
        mFullScreenQuad->setCorners(-1,1,1,-1);
    }

    // Also init shadow caster material for texture shadows
    if (!mShadowCasterPlainBlackPass)
    {
        MaterialPtr matPlainBlack = MaterialManager::getSingleton().getByName(
            "Ogre/TextureShadowCaster");
        if (matPlainBlack.isNull())
        {
            matPlainBlack = MaterialManager::getSingleton().create(
                "Ogre/TextureShadowCaster",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowCasterPlainBlackPass = matPlainBlack->getTechnique(0)->getPass(0);
            // Lighting has to be on, because we need shadow coloured objects
            // Note that because we can't predict vertex programs, we'll have to
            // bind light values to those, and so we bind White to ambient
            // reflectance, and we'll set the ambient colour to the shadow colour
            mShadowCasterPlainBlackPass->setAmbient(ColourValue::White);
            mShadowCasterPlainBlackPass->setDiffuse(ColourValue::Black);
            mShadowCasterPlainBlackPass->setSelfIllumination(ColourValue::Black);
            mShadowCasterPlainBlackPass->setSpecular(ColourValue::Black);
			// Override fog
			mShadowCasterPlainBlackPass->setFog(true, FOG_NONE);
            // no textures or anything else, we will bind vertex programs
            // every so often though
        }
        else
        {
            mShadowCasterPlainBlackPass = matPlainBlack->getTechnique(0)->getPass(0);
        }
    }

    if (!mShadowReceiverPass)
    {
        MaterialPtr matShadRec = MaterialManager::getSingleton().getByName(
            "Ogre/TextureShadowReceiver");
        if (matShadRec.isNull())			
        {
            matShadRec = MaterialManager::getSingleton().create(
                "Ogre/TextureShadowReceiver",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowReceiverPass = matShadRec->getTechnique(0)->getPass(0);
			// Don't set lighting and blending modes here, depends on additive / modulative
            TextureUnitState* t = mShadowReceiverPass->createTextureUnitState();
            t->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
        }
        else
        {
            mShadowReceiverPass = matShadRec->getTechnique(0)->getPass(0);
        }
    }

    // Set up spot shadow fade texture (loaded from code data block)
    TexturePtr spotShadowFadeTex = 
        TextureManager::getSingleton().getByName("spot_shadow_fade.png");
    if (spotShadowFadeTex.isNull())
    {
        // Load the manual buffer into an image (don't destroy memory!
        DataStreamPtr stream(
			new MemoryDataStream(SPOT_SHADOW_FADE_PNG, SPOT_SHADOW_FADE_PNG_SIZE, false));
        Image img;
        img.load(stream, "png");
        spotShadowFadeTex = 
            TextureManager::getSingleton().loadImage(
			"spot_shadow_fade.png", ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME, 
			img, TEX_TYPE_2D);
    }

    mShadowMaterialInitDone = true;
}
