#include "CRenderSettings.h"
#include "reflection/enumconverter.h"
#include <GLG3D/DXCaps.h>
#include <boost/thread/recursive_mutex.hpp>

namespace RBX {

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

void CRenderSettings::setGraphicsMode(GraphicsMode value)
{
    if (value != graphicsMode) {
        graphicsMode = value;
        raisePropertyChanged(prop_graphicsMode);
    }
}

void CRenderSettings::setBevelMode(BevelMode value)
{
    if (value != bevelMode) {
        bevelMode = value;
        raisePropertyChanged(prop_bevels);
    }
}

void CRenderSettings::setAntialiasingMode(AntialiasingMode value)
{
    if (value != antialiasingMode) {
        antialiasingMode = value;
        raisePropertyChanged(prop_antialiasing);
    }
}

void CRenderSettings::setShadowMode(ShadowMode value)
{
    if (value != shadowMode) {
        shadowMode = value;
        raisePropertyChanged(prop_shadow);
    }
}

void CRenderSettings::setFrameRateManagerMode(FrameRateManagerMode value)
{
    if (value != frameRateManagerMode) {
        frameRateManagerMode = value;
        raisePropertyChanged(prop_frameRateManager);
    }
}

void CRenderSettings::setAASamples(AASamples value)
{
    if (value != aaSamples) {
        aaSamples = value;
        raisePropertyChanged(prop_aaSamples);
    }
}

void CRenderSettings::setFullscreenSize(G3D::Vector2int16 value)
{
    if (value != fullscreenSize) {
        fullscreenSize = value;
        raisePropertyChanged(prop_fullscreenSize);
    }
}

void CRenderSettings::setWindowSize(G3D::Vector2int16 value)
{
    if (value != windowSize) {
        windowSize = value;
        raisePropertyChanged(prop_windowSize);
    }
}

void CRenderSettings::setAggregateSize(int value)
{
    value = std::min(1000, std::max(1, value));
    if (value != aggregateSize) {
        aggregateSize = value;
        raisePropertyChanged(prop_aggregateSize);
    }
}

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

void CRenderSettings::setMinMeshDetail(float value)
{
    value = std::min(maxMeshDetail, std::max(0.0f, value));
    if (value != minMeshDetail) {
        minMeshDetail = value;
        raisePropertyChanged(prop_minMeshDetail);
    }
}

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

template class RBX::Reflection::EnumDesc<enum CRenderSettings::AASamples>;
template class RBX::Reflection::EnumDesc<enum CRenderSettings::AntialiasingMode>;
template class RBX::Reflection::EnumDesc<enum CRenderSettings::BevelMode>;
template class RBX::Reflection::EnumDesc<enum CRenderSettings::FrameRateManagerMode>;
template class RBX::Reflection::EnumDesc<enum CRenderSettings::GraphicsMode>;
template class RBX::Reflection::EnumDesc<enum CRenderSettings::ShadowMode>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::AASamples>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::AntialiasingMode>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::BevelMode>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::FrameRateManagerMode>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::GraphicsMode>;
template class RBX::Reflection::TypedPropertyDescriptor<enum CRenderSettings::ShadowMode>;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::AASamples> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::AntialiasingMode> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::BevelMode> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::FrameRateManagerMode> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::GraphicsMode> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum CRenderSettings::ShadowMode> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AASamples> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AntialiasingMode> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::BevelMode> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::FrameRateManagerMode> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::GraphicsMode> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::ShadowMode> > >;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AASamples,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AASamples> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AntialiasingMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AntialiasingMode> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::BevelMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::BevelMode> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::FrameRateManagerMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::FrameRateManagerMode> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::GraphicsMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::GraphicsMode> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::ShadowMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::ShadowMode> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AASamples,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AASamples> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AntialiasingMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AntialiasingMode> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::BevelMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::BevelMode> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::FrameRateManagerMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::FrameRateManagerMode> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::GraphicsMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::GraphicsMode> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::ShadowMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::ShadowMode> >,0> >;
template class std::_Vector_val<RBX::Name const *,std::allocator<RBX::Name const *> >;
template class std::_Vector_val<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >;
template class std::_Vector_val<enum CRenderSettings::AASamples,std::allocator<enum CRenderSettings::AASamples> >;
template class std::_Vector_val<enum CRenderSettings::AntialiasingMode,std::allocator<enum CRenderSettings::AntialiasingMode> >;
template class std::_Vector_val<enum CRenderSettings::BevelMode,std::allocator<enum CRenderSettings::BevelMode> >;
template class std::_Vector_val<enum CRenderSettings::FrameRateManagerMode,std::allocator<enum CRenderSettings::FrameRateManagerMode> >;
template class std::_Vector_val<enum CRenderSettings::GraphicsMode,std::allocator<enum CRenderSettings::GraphicsMode> >;
template class std::_Vector_val<enum CRenderSettings::ShadowMode,std::allocator<enum CRenderSettings::ShadowMode> >;
template class std::_Vector_val<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class std::_Vector_val<unsigned int,std::allocator<unsigned int> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AASamples,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AASamples> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::AntialiasingMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AntialiasingMode> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::BevelMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::BevelMode> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::FrameRateManagerMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::FrameRateManagerMode> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::GraphicsMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::GraphicsMode> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum CRenderSettings::ShadowMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::ShadowMode> >,0> >::_Node *>;
template class std::map<RBX::Name const *,enum CRenderSettings::AASamples,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AASamples> > >;
template class std::map<RBX::Name const *,enum CRenderSettings::AntialiasingMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::AntialiasingMode> > >;
template class std::map<RBX::Name const *,enum CRenderSettings::BevelMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::BevelMode> > >;
template class std::map<RBX::Name const *,enum CRenderSettings::FrameRateManagerMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::FrameRateManagerMode> > >;
template class std::map<RBX::Name const *,enum CRenderSettings::GraphicsMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::GraphicsMode> > >;
template class std::map<RBX::Name const *,enum CRenderSettings::ShadowMode,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum CRenderSettings::ShadowMode> > >;
template class std::vector<enum CRenderSettings::AASamples,std::allocator<enum CRenderSettings::AASamples> >;
template class std::vector<enum CRenderSettings::AntialiasingMode,std::allocator<enum CRenderSettings::AntialiasingMode> >;
template class std::vector<enum CRenderSettings::BevelMode,std::allocator<enum CRenderSettings::BevelMode> >;
template class std::vector<enum CRenderSettings::FrameRateManagerMode,std::allocator<enum CRenderSettings::FrameRateManagerMode> >;
template class std::vector<enum CRenderSettings::GraphicsMode,std::allocator<enum CRenderSettings::GraphicsMode> >;
template class std::vector<enum CRenderSettings::ShadowMode,std::allocator<enum CRenderSettings::ShadowMode> >;
