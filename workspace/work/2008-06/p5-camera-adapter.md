# P5 character camera adapter

The existing local-player path attaches the DataModel Camera to the character's
Humanoid; 005db4c0 supports the character-camera subject relationship. The
`--p5-native-camera` adapter copies that camera's coordinate frame to Ogre each
frame, converts its horizontal field of view to Ogre vertical FOV at the current
viewport aspect, and propagates clip distances. It enables the staged default
sky for this mode. `--p5-camera-turn-test` exercises the existing controller's
camera pan; focused live testing sends W and Left to the player window.

This is an adapter around existing donor/reconstructed camera code. In
particular glue_camera.cpp's character focus and occlusion are behavioral
reconstructions, not byte-verified. Original camera/occlusion parity, mouse
input, normal launch, and the recovered frame loop remain open. The sky uses
the existing reconstructed skybox with staged local assets.
