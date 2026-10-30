#include <OgrePlane.h>
#include <vector>
#include <OgreShadowTextureManager.h>
#include <OgreSceneQuery.h>
int main() {
 std::vector<Ogre::ShadowTextureConfig> shadows; Ogre::ShadowTextureConfig cfg; cfg.width=128; cfg.height=256; shadows.push_back(cfg); shadows.resize(4,cfg);
 if(shadows.size()!=4 || shadows[0].width!=128 || shadows[3].height!=256) return 1;
 shadows.erase(shadows.begin()+1); if(shadows.size()!=3) return 2;
 std::vector<Ogre::RaySceneQueryResultEntry> results; Ogre::RaySceneQueryResultEntry ray; ray.distance=3.5f; ray.movable=0; ray.worldFragment=0; results.push_back(ray); results.resize(3,ray);
 if(results.size()!=3 || results[2].distance!=3.5f || results[0].movable) return 3;
 std::vector<Ogre::TexturePtr> textures; textures.push_back(Ogre::TexturePtr()); textures.resize(3); textures.erase(textures.begin());
 if(textures.size()!=2 || !textures[0].isNull()) return 4;
 std::vector<Ogre::Plane> planes; Ogre::Plane plane; plane.normal=Ogre::Vector3(1,2,3); plane.d=4; planes.push_back(plane); planes.resize(4,plane);
 if(planes.size()!=4 || planes[3].d!=4 || planes[0].normal.y!=2) return 5;
 planes.erase(planes.begin()+1); if(planes.size()!=3) return 6;
 return 0;
}
