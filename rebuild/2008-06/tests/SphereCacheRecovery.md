# Original global sphere-cache lifetime

The ordinary block renderer007ab0a0 calls native node slot113 at007aba1d and
007abae7 to cache the uploaded submesh's bounds sphere. Its node virtual table
0084d30c identifies setSphere00682350, getSphere00682040 and hasSphere00682100.
These methods use global0097dbc4, not the per-node transform map at228.

PlayerSphereCache reuses the existing00682040 map lookup/throw source and
006822e0 initialization. The setter's stored source was empty/unmatched, so its
find/insert/update operations were recovered from the actual instructions.
Map20, pair14 and Sphere10 sizes (hex) compile against genuine VS2008/Ogre types.
The target's map node stores key at0c and radius/center at10..1c. Initial insertion
uses the genuine default unit sphere, then assigns the supplied sphere. Updating
preserves the mapped value's address. Missing lookup throws "bsphere map error".
Remove00682150 returns false before allocation or when the key is absent.

The recorded setter extent was211 bytes, cutting the final short jump in half.
00682420 mov esi,[esi],00682422 jmp006823f0 followed by int3 padding proves
the full extent is212 bytes, ending00682424. This is recorded as local evidence;
no client registry/server extent was edited and no new exact credit is claimed.

Level destructor005489b0 first releases vertex references, then cleanup005486e0
destroys its +24 backend and removes the backend-address key at00548766. The
exercised owner now preserves that ordering. Renderer registration happens when
the backend's metadata is first created. Cache entries survive a retained MeshRef
and shared renderer users, then disappear on final Level destruction/factory purge.
Tests exercise insert/update/lookup/throw/erase and32 Level lifetimes, plus the
player's two9->8->0 removal/reload cycles. A remaining empty native singleton is
intentional; entry count zero does not mean all process-global heap bytes freed.

The +20 shared-index branch also removes a cache key at00548992 but remains
unintegrated. Its resource owner/slot lookup must be recovered before claiming
that branch. Native scene-node transform and visibility behavior, full scene
ownership/selection and metadata-parent replacement are separate remaining edges.
This cache change alone does not close P2.
