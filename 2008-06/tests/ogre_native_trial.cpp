// Link test for the Ogre module trial (rebuild/2008-06/modules/ogre-native-rbx-trial.json).
// Forces every exact Ogre function the module swaps in (force_verified.h, written by roc/rebuild.py build_module).
#include "force_verified.h"

// Test fixture, not product code. RbxEntity (Ogre::RbxEntity::collect 0067e2f0 / func_0067daf0) reads four render
// settings that the original keeps as globals at 0x962f64..0x962f70 and that CRobloxWnd's initialisation writes
// (0045cbf0, 0045df10, 0045e3f0). They belong to the view unit, so this module's test supplies them like any other
// external; the placeholder names are INFERRED (owner rule 2026-11-11).
bool nativeShadowThrottle = false;   // 0x962f64
int nativeShadowMode = 0;            // 0x962f68
float nativeLodLowMs = 0.0f;         // 0x962f6c
float nativeLodHighMs = 0.0f;        // 0x962f70

int main() { return 0; }
