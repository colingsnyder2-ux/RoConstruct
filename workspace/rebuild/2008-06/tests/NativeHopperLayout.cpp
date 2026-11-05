// Layout probes for the inactive native Hopper.h / Tool.h; tests/record_native_hopper.py checks each function body is
// `mov eax, imm32; ret` with the value from the binary (allocation sizes passed to new, constructor field stores).
#include <stddef.h>
#include "v8datamodel/Tool.h"

struct NativeHopperLayout
{
	static size_t hopperSize() { return sizeof(RBX::Hopper); }                       // 0x168 (Hopper fields end)
	static size_t starterPackSize() { return sizeof(RBX::StarterPackService); }      // 0x168 (0048ea00)
	static size_t legacyHopperSize() { return sizeof(RBX::LegacyHopperService); }    // 0x168 (0048ec70)
	static size_t backpackItemSize() { return sizeof(RBX::BackpackItem); }           // 0x1a0
	static size_t guiImageDraw() { return offsetof(RBX::BackpackItem, guiImageDraw); } // 0x148 (005d0c10)
	static size_t textureId() { return offsetof(RBX::BackpackItem, textureId); }       // 0x180 (005d0c10, 005cf160)
	static size_t hopperBinSize() { return sizeof(RBX::HopperBin); }                 // 0x1a8 (0048e790)
	static size_t binType() { return offsetof(RBX::HopperBin, binType); }            // 0x1a0 (005d15a0)
	static size_t active() { return offsetof(RBX::HopperBin, active); }              // 0x1a4 (005d15a0, 005d1670)
	static size_t toolSize() { return sizeof(RBX::Tool); }                           // 0x270 (00578400)
	static size_t backendToolState() { return offsetof(RBX::Tool, backendToolState); }               // 0x1c4
	static size_t frontendActivationState() { return offsetof(RBX::Tool, frontendActivationState); } // 0x1c8
	static size_t grip() { return offsetof(RBX::Tool, grip); }                       // 0x1cc
	static size_t enabled() { return offsetof(RBX::Tool, enabled); }                 // 0x1fc
	static size_t toolMouseCommand() { return offsetof(RBX::Tool, toolMouseCommand); } // 0x200
	static size_t handleTouched() { return offsetof(RBX::Tool, handleTouched); }     // 0x204
	static size_t torsoChildRemoved() { return offsetof(RBX::Tool, torsoChildRemoved); } // 0x254
};

size_t nativeHopperSize() { return NativeHopperLayout::hopperSize(); }
size_t nativeStarterPackSize() { return NativeHopperLayout::starterPackSize(); }
size_t nativeLegacyHopperSize() { return NativeHopperLayout::legacyHopperSize(); }
size_t nativeBackpackItemSize() { return NativeHopperLayout::backpackItemSize(); }
size_t nativeBackpackItemGuiImageDraw() { return NativeHopperLayout::guiImageDraw(); }
size_t nativeBackpackItemTextureId() { return NativeHopperLayout::textureId(); }
size_t nativeHopperBinSize() { return NativeHopperLayout::hopperBinSize(); }
size_t nativeHopperBinBinType() { return NativeHopperLayout::binType(); }
size_t nativeHopperBinActive() { return NativeHopperLayout::active(); }
size_t nativeToolSize() { return NativeHopperLayout::toolSize(); }
size_t nativeToolBackendToolState() { return NativeHopperLayout::backendToolState(); }
size_t nativeToolFrontendActivationState() { return NativeHopperLayout::frontendActivationState(); }
size_t nativeToolGrip() { return NativeHopperLayout::grip(); }
size_t nativeToolEnabled() { return NativeHopperLayout::enabled(); }
size_t nativeToolMouseCommand() { return NativeHopperLayout::toolMouseCommand(); }
size_t nativeToolHandleTouched() { return NativeHopperLayout::handleTouched(); }
size_t nativeToolTorsoChildRemoved() { return NativeHopperLayout::torsoChildRemoved(); }
