// INFERRED names: 0067daf0 reads image globals 00962f64/68/6c/70. The original image
// initializes them to true, 2, 50 and 100; CRobloxWnd 0045cbf0 also writes 00962f68.
// Provider ownership and sharing with the client remain to be integrated.
bool nativeShadowThrottle = true;
int nativeShadowMode = 2;
float nativeLodLowMs = 50.0f;
float nativeLodHighMs = 100.0f;

// Name aliases for the link trial: older mined analogs reference these 2008 functions with public / free-function
// manglings; the registry names them with the native files' protected / static-member manglings (same address,
// same calling convention). Link-closure only.
#pragma comment(linker, "/alternatename:?createSkyboxPlane@RbxSceneManager@Ogre@@QAE?AVMeshPtr@2@W4BoxPlane@SceneManager@2@MABVQuaternion@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z=?createSkyboxPlane@RbxSceneManager@Ogre@@IAE?AVMeshPtr@2@W4BoxPlane@SceneManager@2@MABVQuaternion@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z")
#pragma comment(linker, "/alternatename:?createSkydomePlane@RbxSceneManager@Ogre@@QAE?AVMeshPtr@2@W4BoxPlane@SceneManager@2@MMMABVQuaternion@2@HHHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z=?createSkydomePlane@RbxSceneManager@Ogre@@IAE?AVMeshPtr@2@W4BoxPlane@SceneManager@2@MMMABVQuaternion@2@HHHABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z")
#pragma comment(linker, "/alternatename:?findLightsAffectingFrustum@RbxSceneManager@Ogre@@UAEXPBVCamera@2@@Z=?findLightsAffectingFrustum@RbxSceneManager@Ogre@@MAEXPBVCamera@2@@Z")
#pragma comment(linker, "/alternatename:?findShadowCastersForLight@RbxSceneManager@Ogre@@UAEABV?$vector@PAVShadowCaster@Ogre@@V?$allocator@PAVShadowCaster@Ogre@@@std@@@std@@PBVLight@2@PBVCamera@2@@Z=?findShadowCastersForLight@RbxSceneManager@Ogre@@MAEABV?$vector@PAVShadowCaster@Ogre@@V?$allocator@PAVShadowCaster@Ogre@@@std@@@std@@PBVLight@2@PBVCamera@2@@Z")
#pragma comment(linker, "/alternatename:?prepareShadowTextures@RbxSceneManager@Ogre@@UAEXPAVCamera@2@PAVViewport@2@@Z=?prepareShadowTextures@RbxSceneManager@Ogre@@MAEXPAVCamera@2@PAVViewport@2@@Z")
#pragma comment(linker, "/alternatename:?renderModulativeTextureShadowedQueueGroupObjects@RbxSceneManager@Ogre@@UAEXPAVRenderQueueGroup@2@W4OrganisationMode@QueuedRenderableCollection@2@@Z=?renderModulativeTextureShadowedQueueGroupObjects@RbxSceneManager@Ogre@@MAEXPAVRenderQueueGroup@2@W4OrganisationMode@QueuedRenderableCollection@2@@Z")
#pragma comment(linker, "/alternatename:?renderShadowVolumesToStencil@RbxSceneManager@Ogre@@UAEXPBVLight@2@PBVCamera@2@@Z=?renderShadowVolumesToStencil@RbxSceneManager@Ogre@@MAEXPBVLight@2@PBVCamera@2@@Z")
#pragma comment(linker, "/alternatename:?renderVisibleObjectsCustomSequence@RbxSceneManager@Ogre@@UAEXPAVRenderQueueInvocationSequence@2@@Z=?renderVisibleObjectsCustomSequence@RbxSceneManager@Ogre@@MAEXPAVRenderQueueInvocationSequence@2@@Z")
#pragma comment(linker, "/alternatename:?initializeSpheres@Ogre@@YAXXZ=?initializeSpheres@RbxSceneNode@Ogre@@KAXXZ")
