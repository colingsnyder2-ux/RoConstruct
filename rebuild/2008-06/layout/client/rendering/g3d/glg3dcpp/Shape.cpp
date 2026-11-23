// =============================================================================
// Shape.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/Shape.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
