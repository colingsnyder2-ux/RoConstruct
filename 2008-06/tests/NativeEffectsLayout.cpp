// Layout probe for the inactive native Message/Hint, Sky and Sparkles/Effect headers;
// tests/record_native_effects.py checks each function body is `mov eax, imm32; ret` with the binary's value:
//   sizeof(Message)/sizeof(Hint)  0x15c  create<Message> 004a3850, create<Hint> 004a4d40 allocate 0x15c
//   sizeof(Sky)                   0x1f8  create<Sky> 004d8c90
//   sizeof(Sparkles)              0x148  create<Sparkles> 005c32f0
//   sizeof(Effect)                4      constructor 00665670 / destructor 00665680 only store the vptr
//   Message: IRenderable base +0x130 (constructor 005dd120 vptr store), text +0x140 (setText 005dd280)
//   Sky: skyUp..skyDn +0x130..+0x1d0 step 0x20, drawCelestialBodies +0x1f0, numStars +0x1f4 (constructor
//        005eb640, BoundProp initializers 007f6e80..007f6fd0)
//   Sparkles: IRenderable +0x130, Effect +0x140 (constructor 0063da90); enabled +0x144 is private, proven by
//        the exact constructor and prop_Enabled initializer 007f8be0 (member offset 0x144).
#include <stddef.h>
#include "v8datamodel/Message.h"
#include "v8datamodel/Sky.h"
#include "v8datamodel/Sparkles.h"

struct NativeEffectsMessageProbe : RBX::Message
{
	static size_t textOffset() { return offsetof(NativeEffectsMessageProbe, text); }
};

size_t nativeMessageSize() { return sizeof(RBX::Message); }
size_t nativeHintSize() { return sizeof(RBX::Hint); }
size_t nativeSkySize() { return sizeof(RBX::Sky); }
size_t nativeSparklesSize() { return sizeof(RBX::Sparkles); }
size_t nativeEffectSize() { return sizeof(RBX::Effect); }
size_t nativeMessageRenderable() { return (size_t)static_cast<RBX::IRenderable*>((RBX::Message*)0x1000) - 0x1000; }
size_t nativeMessageText() { return NativeEffectsMessageProbe::textOffset(); }
size_t nativeSkyUp() { return offsetof(RBX::Sky, skyUp); }
size_t nativeSkyLf() { return offsetof(RBX::Sky, skyLf); }
size_t nativeSkyRt() { return offsetof(RBX::Sky, skyRt); }
size_t nativeSkyBk() { return offsetof(RBX::Sky, skyBk); }
size_t nativeSkyFt() { return offsetof(RBX::Sky, skyFt); }
size_t nativeSkyDn() { return offsetof(RBX::Sky, skyDn); }
size_t nativeSkyCelestial() { return offsetof(RBX::Sky, drawCelestialBodies); }
size_t nativeSkyStars() { return offsetof(RBX::Sky, numStars); }
size_t nativeSparklesRenderable() { return (size_t)static_cast<RBX::IRenderable*>((RBX::Sparkles*)0x1000) - 0x1000; }
size_t nativeSparklesEffect() { return (size_t)static_cast<RBX::Effect*>((RBX::Sparkles*)0x1000) - 0x1000; }
