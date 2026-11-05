// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_rbxscene_sky_plane_line_234565f8e0d3b9ea.cpp

// Candidate translation unit (score above; library headers required).
#define RbxSceneManager RbxSceneManagerBase
#include "roc_fork_ea71c50b47f88007.cpp"
#undef RbxSceneManager

namespace Ogre {

class RbxSceneManager : public RbxSceneManagerBase {
public:
    virtual void setSkyPlane(bool enable, const Plane& plane,
                             const String& materialName, Real gscale,
                             Real tiling, bool drawFirst, Real bow,
                             int xsegments, int ysegments,
                             const String& groupName);
};

#line 1329 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setSkyPlane(bool enable, const Plane& plane,
                                  const String& materialName, Real gscale,
                                  Real tiling, bool drawFirst, Real bow,
                                  int xsegments, int ysegments,
                                  const String& groupName)
{
    if (enable)
    {
        String meshName = mName + "SkyPlane";
        mSkyPlane = plane;

        MaterialPtr material =
            MaterialManager::getSingleton().getByName(materialName);
        if (material.isNull())
        {
#line 1338 ".\\RbxSceneManager.cpp"
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
                        "Sky plane material '" + materialName + "' not found.",
                        "RbxSceneManager::setSkyPlane");
        }
        material->setDepthWriteEnabled(false);
        material->load();

        mSkyPlaneDrawFirst = drawFirst;

        MeshPtr planeMesh = MeshManager::getSingleton().getByName(meshName);
        if (!planeMesh.isNull())
        {
            MeshManager::getSingleton().remove(planeMesh->getHandle());
        }

        Vector3 up = plane.normal.crossProduct(Vector3::UNIT_X);
        if (up == Vector3::ZERO)
            up = plane.normal.crossProduct(-Vector3::UNIT_Z);

        if (bow > 0)
        {
            planeMesh = MeshManager::getSingleton().createCurvedPlane(
                meshName, groupName, plane, gscale * 100, gscale * 100,
                gscale * bow * 100, xsegments, ysegments, false, 1,
                tiling, tiling, up);
        }
        else
        {
            planeMesh = MeshManager::getSingleton().createPlane(
                meshName, groupName, plane, gscale * 100, gscale * 100,
                xsegments, ysegments, false, 1, tiling, tiling, up);
        }

        if (mSkyPlaneEntity)
        {
            destroyEntity(meshName);
        }
        mSkyPlaneEntity = createEntity(meshName, meshName);
        mSkyPlaneEntity->setMaterialName(materialName);
        mSkyPlaneEntity->setCastShadows(false);

        if (!mSkyPlaneNode)
        {
            mSkyPlaneNode = createSceneNode(meshName + "Node");
        }
        else
        {
            mSkyPlaneNode->detachAllObjects();
        }
        mSkyPlaneNode->attachObject(mSkyPlaneEntity);
    }

    mSkyPlaneEnabled = enable;
    mSkyPlaneGenParameters.skyPlaneBow = bow;
    mSkyPlaneGenParameters.skyPlaneScale = gscale;
    mSkyPlaneGenParameters.skyPlaneTiling = tiling;
    mSkyPlaneGenParameters.skyPlaneXSegments = xsegments;
    mSkyPlaneGenParameters.skyPlaneYSegments = ysegments;
}

}
