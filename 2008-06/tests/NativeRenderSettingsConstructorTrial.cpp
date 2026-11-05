#include "CRenderSettings.h"
#include <GLG3D/DXCaps.h>

static G3D::Vector2int16 defaultFullscreenSize()
{
    if ((unsigned int)G3D::DXCaps::videoMemorySize() >= 16000000)
        return G3D::Vector2int16(1024, 768);
    return G3D::Vector2int16(800, 600);
}

CRenderSettings::CRenderSettings()
    : graphicsMode(AutoGraphicsMode),
      bevelMode(BevelModeAuto),
      antialiasingMode(AntialiasingOff),
      shadowMode(ShadowModeAuto),
      frameRateManagerMode(FrameRateManagerAuto),
      minShadingQuality(defaultShadingQuality),
      maxShadingQuality(defaultShadingQuality),
      minMeshDetail(defaultMeshDetail),
      maxMeshDetail(defaultMeshDetail),
      delaySwapBuffer(true),
      fullscreenSize(defaultFullscreenSize()),
      windowSize(defaultWindowSize)
{
    setName("Rendering");
    aggregateSize = 1;
}

const float CRenderSettings::defaultShadingQuality = 20.0f;
const float CRenderSettings::defaultMeshDetail = 50.0f;
