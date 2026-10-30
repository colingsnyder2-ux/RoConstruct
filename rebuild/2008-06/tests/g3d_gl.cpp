#include "force_verified.h"
// G3D GLG3D rebuild test: GL-free pieces (lighting model, camera projection math).
#include <G3DAll.h>
#include <cstdio>
#undef main  // SDL.h renames main to SDL_main

int main()
{
    int failures = 0;
    G3D::LightingParameters noon(G3D::toSeconds(12, 0, 0, G3D::PM));
    if (!(noon.lightDirection.y < 0.0f || noon.lightDirection.y > 0.0f)) { std::printf("lighting\n"); ++failures; }
    G3D::GCamera camera;
    camera.setCoordinateFrame(G3D::CoordinateFrame(G3D::Vector3(0, 0, 10)));
    G3D::Ray ray = camera.worldRay(320, 240, G3D::Rect2D::xywh(0, 0, 640, 480));
    if (ray.direction.z > -0.99f) { std::printf("camera ray %g\n", ray.direction.z); ++failures; }
    std::printf("failures=%d\n", failures);
    return failures;
}
