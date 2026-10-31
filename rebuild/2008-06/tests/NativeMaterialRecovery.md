# Native material ownership prerequisite

Build `p2-texture-interop`, then `p2-native-material`, with `ROC_TEXTURE_STRIP`
pointing to the identified real SurfacesStrip.png (see TextureAtlasRecovery.md).
The clean interop target supplies actual GLG3D texture implementations without
selecting the older cached verified_sinks object. Only unrelated SDL GApp.cpp is
excluded; the GL-free interop test does not validate a legacy GL context.

PlayerNativeMaterial.h uses the original RTTI hierarchy, observed allocations,
member types, offsets and virtual tables. Compile assertions check Material18,
Level38, TextureProxyBase30, TextureProxy60, MegaTextureProxy64, Factory10 and
Cache4c (hexadecimal). Sources retarget existing material/proxy implementations;
they are not new server-verified exact matches.

Native tables: Material874ac0, Level874ae4, TextureProxyBase82d168,
TextureProxy82d18c, Mega874bd8. MSVC reverses overloaded virtual declaration
groups: declaration order must be reversed to emit native Material slots2/3
(plain/textured) and Level slots2/3 (resolve/context-free proxy). The independent
PE/map audit checks all five tables and captures the original RTTI base lists.
The C++ test also invokes these four slots by their original slot numbers.
Class-valued member results require ECX=this plus hidden result on stack; the
first test's free-function aggregate-return typedef used a different ABI and
crashed. Explicit hidden result pointers correct the test without altering code.

P2NativeMaterialTest resolves an actual atlas through MegaTextureProxy. Its
legacy G3D TextureRef result remains null, as in the original; the Ogre texture
is the loaded side effect. Thirty-two factory lifetimes test filtered mega-cache
keys, weak ownership, level growth before backend binding, empty/transparent
levels, material unregistration and texture GC. The target's Level copy shares
the backend reference but every destructor unregisters the manager entry.
An explicit test preserves this unusual original behavior; do not replace it
with invented move/last-reference semantics.

Generic file/shade resolver source is retained, including its observed opaque
engine accesses. Those branches have not been runtime validated. No fabricated
VisualEngine layout is declared. Ordinary mega resolution needs no such access.
GPU allocation failure/downsize branches remain unexercised.

This standalone test does not close P2. The published recovered player remains
unchanged. Next wire native material creation from007ab0a0, then original lighting
setup007a9d30 using evidenced scene values instead of the mined padded analog.
Full scene/cache/selector integration and final player controls remain open.
