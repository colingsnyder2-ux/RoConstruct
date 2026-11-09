/**
 @file Collision_Demo/Model.cpp

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created 2003-02-07
 @edited  2003-11-23
 */

#include "Model.h"

extern VARAreaRef           varStatic;
extern GApp*                app;

Table<std::string, Model*>  Model::table;

void Model::freeModels() {
    table.deleteValues();
    table.clear();
}


Model* Model::getModel(const std::string& filename) {
    if (! table.containsKey(filename)) {
        table.set(filename, new Model(filename));
    }

    return table[filename];
}


Model::Model(const std::string& filename) {

    double radius = 0;

	Array<Vector3> vertex;
	Array<Vector3> normal;

    // file := 
    //    fileheader +
    //    vertexheader +
    //    vertex* +
    //    triheader +
    //    tri*
    //
    //  fileheader   := (string32) "IFS" + (float32)1.0 + (string32)modelname
    //  vertexheader := (string32) "VERTICES" + (uint32)numVertices
    //  vertex       := (float32)x + (float32)y + (float32)z
    //  triheader    := (string32)"TRIANGLES" + (uint32)numFaces
    //  tri          := (uint32)v0 + (uint32)v1 + (uint32)v2

    app->debugLog->println(std::string("Loading ") + app->dataDir + "ifs/" + filename);

    BinaryInput b(app->dataDir + "ifs/" + filename, G3D_LITTLE_ENDIAN);

    debugAssertM(b.getLength() > 0, std::string("File not found: \"") + app->dataDir + "ifs/" + filename + "\"");

    Vector3     min(Vector3::inf());
    Vector3     max(-Vector3::inf());

    std::string fmt         = b.readString32();
    float       version     = b.readFloat32();
    (void)version;
    std::string name        = b.readString32();

    debugAssert(fmt     == "IFS");
    debugAssert(version == 1.0);

    std::string vertexHeader = b.readString32();

    // Load the vertices
    vertex.resize(b.readUInt32());

    for (int v = 0; v < vertex.size(); ++v) {
        vertex[v] = b.readVector3() * 5;

        double r = vertex[v].squaredLength();

        if (r > radius * radius) {
            radius = sqrt(r);
        }

        min = min.min(vertex[v]);
        max = max.max(vertex[v]);
    }

    boundingSphere = Sphere(Vector3::zero(), radius);
    boundingBox    = Box(min, max);

    // Per-vertex normals
    normal.resize(vertex.size());

    // Load the triangles
    std::string triHeader   = b.readString32();

    int numTris = b.readUInt32();

    for (int t = 0; t < numTris; ++t) {
        int v0 = b.readUInt32();
        int v1 = b.readUInt32();
        int v2 = b.readUInt32();

        // Compute the non-unit face normal
        Vector3 faceNormal = 
          (vertex[v1] - vertex[v0]).cross( 
           (vertex[v2] - vertex[v0]));

        normal[v0] += faceNormal;
        normal[v1] += faceNormal;
        normal[v2] += faceNormal;

        // Record the indices
        index.append(v0, v1, v2);
    }

    // Rescale the normals to unit length
    for (int n = 0; n < normal.size(); ++n) {
        normal[n] = normal[n].direction();
    }

    varVertex = VAR(vertex, varStatic);
    varNormal = VAR(normal, varStatic);

    for (int i = 0; i < index.size(); i += 3) {
        collisionTriangle.append(Triangle(vertex[index[i]], vertex[index[i + 1]], vertex[index[i + 2]]));
    }
}


void Model::render() const {

    app->renderDevice->pushState();

    // Draw the model
    app->renderDevice->beginIndexedPrimitives();
    {
        app->renderDevice->setNormalArray(varNormal);
        app->renderDevice->setVertexArray(varVertex);
        app->renderDevice->sendIndices(RenderDevice::TRIANGLES, index);
    }
    app->renderDevice->endIndexedPrimitives();

    app->renderDevice->popState();
}


GameTime Model::timeUntilCollisionWithMovingSphere(
    const Sphere&       sphere,
    const Vector3&      velocity,
    GameTime            timeLimit,
    Vector3&            outLocation,
    Vector3&            outNormal) const {

    outLocation = Vector3::inf();

    // First test if the sphere passes near our bounding sphere.  We
    // construct the capsule that contains the sphere's motion, expand it
    // by the radius of our bounding sphere, and see if the center of our
    // bounding sphere is inside.
    if (! Capsule(sphere.center,
                  sphere.center + velocity * timeLimit,
                  sphere.radius + boundingSphere.radius).contains(boundingSphere.center)) {
        // No collision is possible in the given time period.
        return inf();
    }

    // Check intersection with polygons (only return the first intersection)
    GameTime outTime = inf();

    int i;
    for (i = 0; i < collisionTriangle.size(); ++i) {
        Vector3 testLocation, testNormal;
        GameTime testTime;

        Triangle t = collisionTriangle[i];
        testTime = CollisionDetection::collisionTimeForMovingSphereFixedTriangle(sphere, velocity, collisionTriangle[i], testLocation, testNormal);

        if (testTime < outTime) {
            outTime     = testTime;
            outNormal   = testNormal;
            outLocation = testLocation;
        }
    }

    if (outTime > timeLimit) {
        return inf();
    } else {
        return outTime;
    }
}
