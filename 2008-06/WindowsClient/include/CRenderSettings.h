#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRenderSettings | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d462e83a | roc native-status --write
#include "v8datamodel/GlobalSettings.h"
#include <G3D/Vector2int16.h>
#include <string>

// Inactive layout recovery. RTTI .?AVCRenderSettings@@ (global namespace) via
// GlobalSettingsItem<CRenderSettings, sRenderSettings> (class name "RenderSettings", 00815bd4).
// Creatable<Instance>::create<CRenderSettings> 00408ed0 allocates 0x17c; constructor 00448c60 and
// destructor 00448e60 (std::string member at +0x158 destroyed before the base) give the members below.
// Property descriptors from dynamic initializers 007ef430..007ef7a0 (name, category, getter, setter):
//   +0x130 "graphicsMode"      General     565e30 (folded) / 449180
//   +0x134 "Bevels"            General     445220 (folded) / 4491e0
//   +0x138 "Antialiasing"      General     6a6ee0 (folded) / 449210
//   +0x13c "Shadow"            General     445230 / 449240
//   +0x140 "frameRateManager"  General     609a30 (folded) / 4491b0
//   +0x144 "minShadingQuality" Qaulity     4451e0 / 448f40   (category spelled so in the binary)
//   +0x148 "maxShadingQuality" Qaulity     4451f0 / 448fd0
//   +0x14c "minMeshDetail"     Qaulity     445200 / 449060
//   +0x150 "maxMeshDetail"     Qaulity     445210 / 4490c0
//   +0x154 "delaySwapBuffer"   Performance BoundProp
//   +0x158 "profileName"       Qaulity     BoundProp (flags STREAMING)
//   +0x174 "FullscreenSize"    Screen      445250 / 448f00
//   +0x178 "WindowSize"        Screen      445260 (folded) / 448f20
//   global 00930668 "AASamples"      Qaulity     445240 / 448ed0
//   global 00942df8 "_AggregateSize" Performance 445270 / 449120 (clamped to [1, 1000])
// Enum values from the EnumDesc constructors 00447060..00447800.
extern char sRenderSettings[];

class CRenderSettings : public RBX::GlobalSettingsItem<CRenderSettings, sRenderSettings> {
public:
    enum AASamples { NONE = 1, AA4 = 4, AA8 = 8 };
    enum GraphicsMode { AutoGraphicsMode = 1, Direct3D11 = 2, Direct3D9 = 3, OpenGL = 4, NoGraphics = 5 };
    enum FrameRateManagerMode { FrameRateManagerAuto = 0, FrameRateManagerOn = 1, FrameRateManagerOff = 2 };
    enum AntialiasingMode { AntialiasingAuto = 0, AntialiasingOn = 1, AntialiasingOff = 2 };
    enum BevelMode { BevelModeAuto = 0, BevelModeOn = 1, BevelModeOff = 2 };
    enum ShadowMode { ShadowModeAuto = 0, ShadowModeOn = 1, ShadowModeOff = 2 };

    // Access of the data members is unknown; they are public so the layout test can name them.
    GraphicsMode graphicsMode;                 // +0x130
    BevelMode bevelMode;                       // +0x134
    AntialiasingMode antialiasingMode;         // +0x138
    ShadowMode shadowMode;                     // +0x13c
    FrameRateManagerMode frameRateManagerMode; // +0x140
    float minShadingQuality;                   // +0x144
    float maxShadingQuality;                   // +0x148
    float minMeshDetail;                       // +0x14c
    float maxMeshDetail;                       // +0x150
    bool delaySwapBuffer;                      // +0x154
    std::string profileName;                   // +0x158
    G3D::Vector2int16 fullscreenSize;          // +0x174
    G3D::Vector2int16 windowSize;              // +0x178

    // Data-initialized globals read and written by the AASamples/_AggregateSize/WindowSize code above.
    static AASamples aaSamples;                // 00930668 (initial 1)
    static G3D::Vector2int16 defaultWindowSize;// 0093066c (initial 800x600)
    static int aggregateSize;                  // 00942df8 (initial 40)
    // Read-only floats the constructor loads by address before every store (not folded literals).
    static const float defaultShadingQuality;  // 00815bc0 (20.0)
    static const float defaultMeshDetail;      // 00815bc8 (50.0)

    CRenderSettings();

    GraphicsMode getGraphicsMode() const { return graphicsMode; }
    void setGraphicsMode(GraphicsMode value);
    BevelMode getBevelMode() const { return bevelMode; }
    void setBevelMode(BevelMode value);
    AntialiasingMode getAntialiasingMode() const { return antialiasingMode; }
    void setAntialiasingMode(AntialiasingMode value);
    ShadowMode getShadowMode() const { return shadowMode; }
    void setShadowMode(ShadowMode value);
    FrameRateManagerMode getFrameRateManagerMode() const { return frameRateManagerMode; }
    void setFrameRateManagerMode(FrameRateManagerMode value);
    AASamples getAASamples() const { return aaSamples; }
    void setAASamples(AASamples value);

    float getMinShadingQuality() const { return minShadingQuality; }
    void setMinShadingQuality(float value);
    float getMaxShadingQuality() const { return maxShadingQuality; }
    void setMaxShadingQuality(float value);
    float getMinMeshDetail() const { return minMeshDetail; }
    void setMinMeshDetail(float value);
    float getMaxMeshDetail() const { return maxMeshDetail; }
    void setMaxMeshDetail(float value);

    G3D::Vector2int16 getFullscreenSize() const;
    void setFullscreenSize(G3D::Vector2int16 value);
    G3D::Vector2int16 getWindowSize() const { return windowSize; }
    void setWindowSize(G3D::Vector2int16 value);

    int getAggregateSize() const { return aggregateSize; }
    void setAggregateSize(int value);
};
