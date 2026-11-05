/**
  @file PosedModel.cpp
  
  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-11-15
  @edited  2006-02-24
 */ 

#include "GLG3D/PosedModel.h"
#include "GLG3D/RenderDevice.h"
#include "G3D/Sphere.h"
#include "G3D/Box.h"

namespace G3D {

class ModelSorter {
public:
    double                  sortKey;
    PosedModelRef           model;

    ModelSorter() {}

    ModelSorter(const PosedModelRef& m, const Vector3& axis) : model(m) {
        static Sphere s;
        m->getWorldSpaceBoundingSphere(s);
        sortKey = axis.dot(s.center);
    }

    inline bool operator>(const ModelSorter& s) const {
        return sortKey > s.sortKey;
    }

    inline bool operator<(const ModelSorter& s) const {
        return sortKey < s.sortKey;
    }
};


void PosedModel::sort(
    const Array<PosedModelRef>& inModels, 
    const Vector3&              wsLook,
    Array<PosedModelRef>&       opaque,
    Array<PosedModelRef>&       transparent) {

    Array<ModelSorter> op;
    Array<ModelSorter> tr;
    
    for (int m = 0; m < inModels.size(); ++m) {
        if (inModels[m]->hasTransparency()) {
            tr.append(ModelSorter(inModels[m], wsLook));
        } else {
            op.append(ModelSorter(inModels[m], wsLook));
        }
    }

    // Sort
    tr.sort(SORT_DECREASING);
    op.sort(SORT_INCREASING);

    transparent.resize(tr.size(), DONT_SHRINK_UNDERLYING_ARRAY);
    for (int m = 0; m < tr.size(); ++m) {
        transparent[m] = tr[m].model;
    }

    opaque.resize(op.size(), DONT_SHRINK_UNDERLYING_ARRAY);
    for (int m = 0; m < op.size(); ++m) {
        opaque[m] = op[m].model;
    }
}


void PosedModel::sort(
    const Array<PosedModelRef>& inModels, 
    const Vector3&              wsLook,
    Array<PosedModelRef>&       opaque) { 

    if (&inModels == &opaque) {
        // The user is trying to sort in place.  Make a separate array for them.
        Array<PosedModelRef> temp = inModels;
        sort(temp, wsLook, opaque);
        return;
    }

    Array<ModelSorter> op;
    
    for (int m = 0; m < inModels.size(); ++m) {
        op.append(ModelSorter(inModels[m], wsLook));
    }

    // Sort
    op.sort(SORT_INCREASING);

    opaque.resize(op.size(), DONT_SHRINK_UNDERLYING_ARRAY);
    for (int m = 0; m < op.size(); ++m) {
        opaque[m] = op[m].model;
    }
}


void PosedModel::getWorldSpaceGeometry(MeshAlg::Geometry& geometry) const {
    CoordinateFrame c;
    getCoordinateFrame(c);

    const MeshAlg::Geometry& osgeometry = objectSpaceGeometry();
    c.pointToWorldSpace(osgeometry.vertexArray, geometry.vertexArray);
    c.normalToWorldSpace(osgeometry.normalArray, geometry.normalArray);
}


CoordinateFrame PosedModel::coordinateFrame() const {
    CoordinateFrame c;
    getCoordinateFrame(c);
    return c;
}


Sphere PosedModel::objectSpaceBoundingSphere() const {
    Sphere s;
    getObjectSpaceBoundingSphere(s);
    return s;
}


void PosedModel::getWorldSpaceBoundingSphere(Sphere& s) const {
    CoordinateFrame C;
    getCoordinateFrame(C);
    getObjectSpaceBoundingSphere(s);
    s = C.toWorldSpace(s);
}


Sphere PosedModel::worldSpaceBoundingSphere() const {
    Sphere s;
    getWorldSpaceBoundingSphere(s);
    return s;
}


Box PosedModel::objectSpaceBoundingBox() const {
    Box b;
    getObjectSpaceBoundingBox(b);
    return b;
}


void PosedModel::getWorldSpaceBoundingBox(Box& box) const {
    CoordinateFrame C;
    getCoordinateFrame(C);
    getObjectSpaceBoundingBox(box);
    box = C.toWorldSpace(box);
}


Box PosedModel::worldSpaceBoundingBox() const {
    Box b;
    getWorldSpaceBoundingBox(b);
    return b;
}


void PosedModel::getObjectSpaceFaceNormals(Array<Vector3>& faceNormals, bool normalize) const {
    const MeshAlg::Geometry& geometry = objectSpaceGeometry();
    const Array<MeshAlg::Face>& faceArray = faces();

    MeshAlg::computeFaceNormals(geometry.vertexArray, faceArray, faceNormals, normalize);
}


void PosedModel::getWorldSpaceFaceNormals(Array<Vector3>& faceNormals, bool normalize) const {
    MeshAlg::Geometry geometry;
    getWorldSpaceGeometry(geometry);

    const Array<MeshAlg::Face>& faceArray = faces();

    MeshAlg::computeFaceNormals(geometry.vertexArray, faceArray, faceNormals, normalize);
}


void PosedModel::renderNonShadowed(
    RenderDevice* rd,
    const LightingRef& lighting) const {

    rd->pushState();
        if (rd->colorWrite()) {
            rd->setAmbientLightColor(lighting->ambientTop);
            Color3 C = lighting->ambientBottom - lighting->ambientTop;

            int shift = 0;
            if ((C.r != 0) || (C.g != 0) || (C.b != 0)) {
                rd->setLight(0, GLight::directional(-Vector3::unitY(), C, false));
                ++shift;
            }

            for (int L = 0; L < iMin(7, lighting->lightArray.size()); ++L) {
                rd->setLight(L + shift, lighting->lightArray[L]);
            }
            rd->enableLighting();
        }
        render(rd);
    rd->popState();
}


void PosedModel::renderShadowedLightPass(
    RenderDevice* rd, 
    const GLight& light) const {

    rd->pushState();
        rd->enableLighting();
        rd->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE);
        rd->setLight(0, light);
        rd->setAmbientLightColor(Color3::black());
        render(rd);
    rd->popState();
}


void PosedModel::renderShadowMappedLightPass(
    RenderDevice* rd, 
    const GLight& light,
    const Matrix4& lightMVP,
    const TextureRef& shadowMap) const {

    rd->pushState();
        rd->setBlendFunc(RenderDevice::BLEND_ONE, RenderDevice::BLEND_ONE);
        rd->configureShadowMap(1, lightMVP, shadowMap);
        rd->setLight(0, light);
        rd->enableLighting();
        rd->setAmbientLightColor(Color3::black());
        render(rd);
    rd->popState();
}

   
void PosedModel::defaultRender(RenderDevice* rd) const {
    const MeshAlg::Geometry& geometry = objectSpaceGeometry();

    VARAreaRef area = VARArea::create(sizeof(Vector3)*2*geometry.vertexArray.size() + 16);

    rd->pushState();
        rd->setObjectToWorldMatrix(coordinateFrame());
        rd->beginIndexedPrimitives();
            rd->setNormalArray(VAR(geometry.normalArray, area));
            rd->setVertexArray(VAR(geometry.vertexArray, area));
            rd->sendIndices(RenderDevice::TRIANGLES, triangleIndices());
        rd->endIndexedPrimitives();
    rd->popState();
}


void PosedModel::render(RenderDevice* rd) const {
    defaultRender(rd);
}

////////////////////////////////////////////////////////////////////////////////////////



std::string PosedModelWrapper::name() const {
    return model->name();
}


void PosedModelWrapper::getCoordinateFrame(CoordinateFrame& c) const {
    model->getCoordinateFrame(c);
}


CoordinateFrame PosedModelWrapper::coordinateFrame() const {
    return model->coordinateFrame();
}


const MeshAlg::Geometry& PosedModelWrapper::objectSpaceGeometry() const {
    return model->objectSpaceGeometry();
}


void PosedModelWrapper::getWorldSpaceGeometry(MeshAlg::Geometry& geometry) const {
    model->getWorldSpaceGeometry(geometry);
}


void PosedModelWrapper::getObjectSpaceFaceNormals(Array<Vector3>& faceNormals, bool normalize) const {
    model->getObjectSpaceFaceNormals(faceNormals, normalize);
}


void PosedModelWrapper::getWorldSpaceFaceNormals(Array<Vector3>& faceNormals, bool normalize) const {
    model->getWorldSpaceFaceNormals(faceNormals, normalize);
}

const Array<Vector3>& PosedModelWrapper::objectSpaceFaceNormals(bool normalize) const {
	return model->objectSpaceFaceNormals(normalize);
}



const Array<MeshAlg::Face>& PosedModelWrapper::faces() const {
    return model->faces();
}


const Array<MeshAlg::Edge>& PosedModelWrapper::edges() const {
    return model->edges();
}


const Array<MeshAlg::Vertex>& PosedModelWrapper::vertices() const {
    return model->vertices();
}


const Array<Vector2>& PosedModelWrapper::texCoords() const {
    return model->texCoords();
}


bool PosedModelWrapper::hasTexCoords() const {
	return model->hasTexCoords();
}


const Array<MeshAlg::Face>& PosedModelWrapper::weldedFaces() const {
    return model->weldedFaces();
}


const Array<MeshAlg::Edge>& PosedModelWrapper::weldedEdges() const {
    return model->weldedEdges();
}


const Array<MeshAlg::Vertex>& PosedModelWrapper::weldedVertices() const {
    return model->weldedVertices();
}


const Array<int>& PosedModelWrapper::triangleIndices() const {
    return model->triangleIndices();
}


void PosedModelWrapper::getObjectSpaceBoundingSphere(Sphere& s) const {
    model->getObjectSpaceBoundingSphere(s);
}


Sphere PosedModelWrapper::objectSpaceBoundingSphere() const {
    return model->objectSpaceBoundingSphere();
}


void PosedModelWrapper::getWorldSpaceBoundingSphere(Sphere& s) const {
    model->getWorldSpaceBoundingSphere(s);
}


Sphere PosedModelWrapper::worldSpaceBoundingSphere() const {
    return model->worldSpaceBoundingSphere();
}


void PosedModelWrapper::getObjectSpaceBoundingBox(Box& box) const {
    model->getObjectSpaceBoundingBox(box);
}


Box PosedModelWrapper::objectSpaceBoundingBox() const {
    return model->objectSpaceBoundingBox();
}


void PosedModelWrapper::getWorldSpaceBoundingBox(Box& box) const {
    model->getWorldSpaceBoundingBox(box);
}


Box PosedModelWrapper::worldSpaceBoundingBox() const {
    return model->worldSpaceBoundingBox();
}


void PosedModelWrapper::render(class RenderDevice* renderDevice) const { 
    model->render(renderDevice);
}


int PosedModelWrapper::numBoundaryEdges() const {
    return model->numBoundaryEdges();
}


int PosedModelWrapper::numWeldedBoundaryEdges() const {
    return model->numWeldedBoundaryEdges();
}

////////////////////////////////////////////////////

static bool depthGreaterThan(const PosedModel2DRef& a, const PosedModel2DRef& b) {
    return a->depth() > b->depth();
}

void PosedModel2D::sort(Array<PosedModel2DRef>& array) {
    array.sort(depthGreaterThan);
}

}
