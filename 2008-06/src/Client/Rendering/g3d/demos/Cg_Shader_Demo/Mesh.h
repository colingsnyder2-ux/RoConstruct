#ifndef MESH_H
#define MESH_H

#include <G3DAll.h>

class Mesh {
public:

    Array<Vector3>          vertexArray;
    Array<Vector2>          texCoordArray;

    Array<Vector3>          normalArray;
    Array<Vector3>          tangentArray;
    Array<Vector3>          binormalArray;

    Array<int>              indexArray;
    Array<MeshAlg::Face>    faceArray;

    Array<MeshAlg::Edge>    edgeArray;

    Array< Array<int> >     adjacentFaceArray;
    Array<Vector3>          faceNormalArray;

    Mesh() {
        vertexArray.resize(4);
        texCoordArray.resize(4);
        
        vertexArray[0]   = Vector3(-2, 1, -2);
        texCoordArray[0] = Vector2(0, 0); 

        vertexArray[1]   = Vector3(-2, 1,  2);
        texCoordArray[1] = Vector2(0, 1); 

        vertexArray[2]   = Vector3( 2, 1,  2);
        texCoordArray[2] = Vector2(1, 1); 

        vertexArray[3]   = Vector3( 2, 1, -2);
        texCoordArray[3] = Vector2(1, 0); 

        indexArray.append(0, 1, 2);
        indexArray.append(0, 2, 3);

        MeshAlg::computeAdjacency(vertexArray, indexArray,
            faceArray, edgeArray, adjacentFaceArray);

        MeshAlg::computeNormals(vertexArray, faceArray,
            adjacentFaceArray, normalArray, faceNormalArray);

        MeshAlg::computeTangentSpaceBasis(vertexArray, texCoordArray,
            normalArray, faceArray, tangentArray, binormalArray);
    }


    void render(RenderDevice* rd) {
        rd->beginPrimitive(RenderDevice::TRIANGLES);
            for (int i = 0; i < indexArray.size(); ++i) {
                int v = indexArray[i];
                rd->setTexCoord(0, texCoordArray[v]);
                rd->setNormal(normalArray[v]);
                rd->setTexCoord(1, tangentArray[v]);
                rd->setTexCoord(2, binormalArray[v]);
                rd->sendVertex(vertexArray[v]);
            }
        rd->endPrimitive();

        /*
        for (int v = 0; v < vertexArray.size(); ++v) {
            CoordinateFrame cframe(vertexArray[v]);
            cframe.rotation.setColumn(0, tangentArray[v]);
            cframe.rotation.setColumn(1, normalArray[v]);
            cframe.rotation.setColumn(2, binormalArray[v]);
            Draw::axes(cframe, rd, Color3::RED, Color3::GREEN, Color3::BLUE, 0.5);
        }
        */
    }
};

#endif

