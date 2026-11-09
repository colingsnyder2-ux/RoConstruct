#pragma once
// Force private/protected members public to work around VS2008
// template friendship limitations with IndexArray<IRenderable, &IRenderable::indexFunc2d>
// in rbxgs IRenderable.h / IRenderableBucket. Needed for buggy-but-playable native build.
#define private public
#define protected public
