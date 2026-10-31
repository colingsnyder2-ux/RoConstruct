// Model-side API of the 2008-06 Ogre player (see PlayerScene.cpp for the
// original-address trace this reproduces).
#pragma once

#ifdef __cplusplus
#include "../PlayerBlockMesh.h"
#undef main
extern "C" {
#endif

typedef struct SceneModel
{
    const void* id;
    PlayerBlockMesh::BlockMesh* geometry; // Borrowed until next scene update; renderer retains it.
    float rotation[9]; // R00,R01,R02,R10,R11,R12,R20,R21,R22
    float position[3];
    float size[3];
    float color[3];
} SceneModel;

int  SceneAttach(void);
int  SceneBeginFrame(void);
int  SceneModelCount(void);
int  SceneModelGet(int index, SceneModel* out);
void SceneDetach(void);

#ifdef __cplusplus
}
#endif
