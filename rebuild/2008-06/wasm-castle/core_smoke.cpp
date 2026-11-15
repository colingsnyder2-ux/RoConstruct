#include "OgreVector3.h"
#include "OgreQuaternion.h"
#include "OgreMatrix4.h"
#include <cmath>
#include <cstdio>

int main()
{
    Ogre::Vector3 normal = Ogre::Vector3::UNIT_X.crossProduct(Ogre::Vector3::UNIT_Y);
    if (normal != Ogre::Vector3::UNIT_Z) return 1;
    Ogre::Quaternion rotation(Ogre::Radian(Ogre::Math::HALF_PI), Ogre::Vector3::UNIT_Y);
    Ogre::Matrix4 transform;
    transform.makeTransform(Ogre::Vector3(3, 4, 5), Ogre::Vector3(2, 2, 2), rotation);
    Ogre::Vector3 point = transform * Ogre::Vector3::UNIT_X;
    if ((point - Ogre::Vector3(3, 4, 3)).length() > 0.0001f) return 2;
    if ((transform.inverse() * point - Ogre::Vector3::UNIT_X).length() > 0.0001f) return 3;
    std::puts("Ogre 1.4.5 Wasm: vector, quaternion, transform, inverse PASS");
}
