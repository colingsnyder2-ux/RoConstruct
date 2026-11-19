#include "CRenderSettings.h"
#include "reflection/enumconverter.h"

template class RBX::Reflection::EnumDesc<CRenderSettings::GraphicsMode>;

template class RBX::Reflection::EnumDesc<CRenderSettings::FrameRateManagerMode>;

template class RBX::Reflection::EnumDesc<CRenderSettings::AntialiasingMode>;

#include "util/Sound.h"

template class RBX::Reflection::EnumDesc<RBX::Soundscape::ReverbType>;

#include "v8datamodel/Camera.h"

template class RBX::Reflection::EnumDesc<RBX::Camera::CameraType>;

#include "v8datamodel/Feature.h"

template class RBX::Reflection::EnumDesc<RBX::Feature::LeftRight>;

template class RBX::Reflection::EnumDesc<RBX::Feature::InOut>;
