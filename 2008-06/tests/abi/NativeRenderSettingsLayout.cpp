#include <stddef.h>
#include "CRenderSettings.h"
// Size from Creatable<Instance>::create<CRenderSettings> 00408ed0 (malloc 0x17c); offsets from the
// constructor 00448c60 stores, the destructor 00448e60 (std::string at +0x158), getters 004451e0..00445260
// and setters 00448ed0..00449240.
typedef char InstanceSize[sizeof(RBX::Instance) == 0x130 ? 1 : -1];
typedef char ItemSize[sizeof(RBX::GlobalSettings::Item) == 0x130 ? 1 : -1];
typedef char RenderSettingsSize[sizeof(CRenderSettings) == 0x17c ? 1 : -1];
typedef char RenderSettingsGraphicsMode[offsetof(CRenderSettings, graphicsMode) == 0x130 ? 1 : -1];
typedef char RenderSettingsBevelMode[offsetof(CRenderSettings, bevelMode) == 0x134 ? 1 : -1];
typedef char RenderSettingsAntialiasingMode[offsetof(CRenderSettings, antialiasingMode) == 0x138 ? 1 : -1];
typedef char RenderSettingsShadowMode[offsetof(CRenderSettings, shadowMode) == 0x13c ? 1 : -1];
typedef char RenderSettingsFrameRateManagerMode[offsetof(CRenderSettings, frameRateManagerMode) == 0x140 ? 1 : -1];
typedef char RenderSettingsMinShadingQuality[offsetof(CRenderSettings, minShadingQuality) == 0x144 ? 1 : -1];
typedef char RenderSettingsMaxShadingQuality[offsetof(CRenderSettings, maxShadingQuality) == 0x148 ? 1 : -1];
typedef char RenderSettingsMinMeshDetail[offsetof(CRenderSettings, minMeshDetail) == 0x14c ? 1 : -1];
typedef char RenderSettingsMaxMeshDetail[offsetof(CRenderSettings, maxMeshDetail) == 0x150 ? 1 : -1];
typedef char RenderSettingsDelaySwapBuffer[offsetof(CRenderSettings, delaySwapBuffer) == 0x154 ? 1 : -1];
typedef char RenderSettingsProfileName[offsetof(CRenderSettings, profileName) == 0x158 ? 1 : -1];
typedef char RenderSettingsFullscreenSize[offsetof(CRenderSettings, fullscreenSize) == 0x174 ? 1 : -1];
typedef char RenderSettingsWindowSize[offsetof(CRenderSettings, windowSize) == 0x178 ? 1 : -1];
