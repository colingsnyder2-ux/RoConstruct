// >>> native-status (generated) -- do not edit >>>
// CRenderSettings | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 71eb9d9a | roc native-status --write
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
#include <GLG3D/DXCaps.h>
#include <boost/thread/recursive_mutex.hpp>

namespace RBX {

// 00412d50 (CRenderSettings instance): create the item on first use and parent it to the
// GlobalSettings service; the item's constructor publishes itself through sing.
template<typename Class, const char* ClassName>
Class& GlobalSettingsItem<Class, ClassName>::singleton()
{
    boost::recursive_mutex::scoped_lock lock(GlobalSettings::mutex);
    if (!sing) {
        boost::shared_ptr<Class> item = Creatable<Instance>::create<Class>();
        item->setParent(GlobalSettings::singleton().get());
    }
    return *static_cast<Class*>(sing);
}

// 00445c10 (complete) / 00445da0 (deleting).
template<typename Class, const char* ClassName>
GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
{
    sing = NULL;
}

} // namespace RBX

template CRenderSettings& RBX::GlobalSettingsItem<CRenderSettings, sRenderSettings>::singleton();

G3D::Vector2int16 CRenderSettings::getFullscreenSize() const
{
    return fullscreenSize;
}

using RBX::Reflection::EnumPropDescriptor;
using RBX::Reflection::PropDescriptor;
using RBX::Reflection::BoundProp;
using RBX::Reflection::PropertyDescriptor;

// Dynamic initializers 007ef430..007ef7a0, in definition order.
static EnumPropDescriptor<CRenderSettings, CRenderSettings::GraphicsMode> prop_graphicsMode("graphicsMode", "General", &CRenderSettings::getGraphicsMode, &CRenderSettings::setGraphicsMode, PropertyDescriptor::STANDARD);
static EnumPropDescriptor<CRenderSettings, CRenderSettings::FrameRateManagerMode> prop_frameRateManager("frameRateManager", "General", &CRenderSettings::getFrameRateManagerMode, &CRenderSettings::setFrameRateManagerMode, PropertyDescriptor::STANDARD);
static EnumPropDescriptor<CRenderSettings, CRenderSettings::BevelMode> prop_bevels("Bevels", "General", &CRenderSettings::getBevelMode, &CRenderSettings::setBevelMode, PropertyDescriptor::STANDARD);
static EnumPropDescriptor<CRenderSettings, CRenderSettings::ShadowMode> prop_shadow("Shadow", "General", &CRenderSettings::getShadowMode, &CRenderSettings::setShadowMode, PropertyDescriptor::STANDARD);
static EnumPropDescriptor<CRenderSettings, CRenderSettings::AntialiasingMode> prop_antialiasing("Antialiasing", "General", &CRenderSettings::getAntialiasingMode, &CRenderSettings::setAntialiasingMode, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, G3D::Vector2int16> prop_windowSize("WindowSize", "Screen", &CRenderSettings::getWindowSize, &CRenderSettings::setWindowSize, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, G3D::Vector2int16> prop_fullscreenSize("FullscreenSize", "Screen", &CRenderSettings::getFullscreenSize, &CRenderSettings::setFullscreenSize, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, float> prop_minShadingQuality("minShadingQuality", "Qaulity", &CRenderSettings::getMinShadingQuality, &CRenderSettings::setMinShadingQuality, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, float> prop_maxShadingQuality("maxShadingQuality", "Qaulity", &CRenderSettings::getMaxShadingQuality, &CRenderSettings::setMaxShadingQuality, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, float> prop_minMeshDetail("minMeshDetail", "Qaulity", &CRenderSettings::getMinMeshDetail, &CRenderSettings::setMinMeshDetail, PropertyDescriptor::STANDARD);
static PropDescriptor<CRenderSettings, float> prop_maxMeshDetail("maxMeshDetail", "Qaulity", &CRenderSettings::getMaxMeshDetail, &CRenderSettings::setMaxMeshDetail, PropertyDescriptor::STANDARD);
// RTTI of the getset at 00815ca4: GetSetImpl<int getter, int setter> of PropDescriptor<CRenderSettings, float>.
static PropDescriptor<CRenderSettings, float> prop_aggregateSize("_AggregateSize", "Performance", &CRenderSettings::getAggregateSize, &CRenderSettings::setAggregateSize, PropertyDescriptor::STANDARD);
static EnumPropDescriptor<CRenderSettings, CRenderSettings::AASamples> prop_aaSamples("AASamples", "Qaulity", &CRenderSettings::getAASamples, &CRenderSettings::setAASamples, PropertyDescriptor::STANDARD);
static BoundProp<bool, 1> prop_delaySwapBuffer("delaySwapBuffer", "Performance", &CRenderSettings::delaySwapBuffer, PropertyDescriptor::STANDARD);
static BoundProp<std::string, 1> prop_profileName("profileName", "Qaulity", &CRenderSettings::profileName, PropertyDescriptor::STREAMING);

// Default full-screen size by video memory, constructed in place in the constructor below.
static G3D::Vector2int16 defaultFullscreenSize()
{
    if ((unsigned int)G3D::DXCaps::videoMemorySize() >= 16000000)
        return G3D::Vector2int16(1024, 768);
    else
        return G3D::Vector2int16(800, 600);
}

// 00448c60.
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

// 00449180.
void CRenderSettings::setGraphicsMode(GraphicsMode value)
{
    if (value != graphicsMode) {
        graphicsMode = value;
        raisePropertyChanged(prop_graphicsMode);
    }
}

// 004491e0.
void CRenderSettings::setBevelMode(BevelMode value)
{
    if (value != bevelMode) {
        bevelMode = value;
        raisePropertyChanged(prop_bevels);
    }
}

// 00449210.
void CRenderSettings::setAntialiasingMode(AntialiasingMode value)
{
    if (value != antialiasingMode) {
        antialiasingMode = value;
        raisePropertyChanged(prop_antialiasing);
    }
}

// 00449240.
void CRenderSettings::setShadowMode(ShadowMode value)
{
    if (value != shadowMode) {
        shadowMode = value;
        raisePropertyChanged(prop_shadow);
    }
}

// 004491b0.
void CRenderSettings::setFrameRateManagerMode(FrameRateManagerMode value)
{
    if (value != frameRateManagerMode) {
        frameRateManagerMode = value;
        raisePropertyChanged(prop_frameRateManager);
    }
}

// 00448ed0.
void CRenderSettings::setAASamples(AASamples value)
{
    if (value != aaSamples) {
        aaSamples = value;
        raisePropertyChanged(prop_aaSamples);
    }
}

// 00448f00.
void CRenderSettings::setFullscreenSize(G3D::Vector2int16 value)
{
    if (value != fullscreenSize) {
        fullscreenSize = value;
        raisePropertyChanged(prop_fullscreenSize);
    }
}

// 00448f20.
void CRenderSettings::setWindowSize(G3D::Vector2int16 value)
{
    if (value != windowSize) {
        windowSize = value;
        raisePropertyChanged(prop_windowSize);
    }
}

// 00449120.
void CRenderSettings::setAggregateSize(int value)
{
    value = std::min(1000, std::max(1, value));
    if (value != aggregateSize) {
        aggregateSize = value;
        raisePropertyChanged(prop_aggregateSize);
    }
}

// 00448f40.
void CRenderSettings::setMinShadingQuality(float value)
{
    if (value > maxShadingQuality)
        setMaxShadingQuality(value);
    value = std::min(maxShadingQuality, value);
    value = std::max(0.0f, value);
    if (value != minShadingQuality) {
        minShadingQuality = value;
        raisePropertyChanged(prop_minShadingQuality);
    }
}

// 00448fd0.
void CRenderSettings::setMaxShadingQuality(float value)
{
    if (value < minShadingQuality)
        setMinShadingQuality(value);
    value = std::max(minShadingQuality, value);
    value = std::min(100.0f, value);
    if (value != maxShadingQuality) {
        maxShadingQuality = value;
        raisePropertyChanged(prop_maxShadingQuality);
    }
}

// 00449060.
void CRenderSettings::setMinMeshDetail(float value)
{
    value = std::min(maxMeshDetail, std::max(0.0f, value));
    if (value != minMeshDetail) {
        minMeshDetail = value;
        raisePropertyChanged(prop_minMeshDetail);
    }
}

// 004490c0.
void CRenderSettings::setMaxMeshDetail(float value)
{
    value = std::min(100.0f, std::max(minMeshDetail, value));
    if (value != maxMeshDetail) {
        maxMeshDetail = value;
        raisePropertyChanged(prop_maxMeshDetail);
    }
}

const float CRenderSettings::defaultShadingQuality = 20.0f;
const float CRenderSettings::defaultMeshDetail = 50.0f;
