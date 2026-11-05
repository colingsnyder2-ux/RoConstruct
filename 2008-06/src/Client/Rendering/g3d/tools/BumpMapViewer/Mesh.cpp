#include "header.h"

VARAreaRef Mesh::varArea = NULL;

MeshRef Mesh::quad() {
	Array<Vector3> vertex;
	Array<Vector3> normal;
	Array<Vector2> tex;
	Array<int>	   index;

	double s = 2;
	vertex.append(Vector3(-s, -s, 0));
	vertex.append(Vector3( s, -s, 0));
	vertex.append(Vector3( s,  s, 0));
	vertex.append(Vector3(-s,  s, 0));

	normal.append(Vector3::UNIT_Z);
	normal.append(Vector3::UNIT_Z);
	normal.append(Vector3::UNIT_Z);
	normal.append(Vector3::UNIT_Z);

	tex.append(Vector2(0, 1));
	tex.append(Vector2(1, 1));
	tex.append(Vector2(1, 0));
	tex.append(Vector2(0, 0));

	index.append(0, 1, 2);
	index.append(0, 2, 3);

	return new Mesh(index, vertex, normal, tex);
}


Mesh::Mesh(
	const Array<int>& index,
	const Array<Vector3>&	vertex,
	const Array<Vector3>&	normal,
	const Array<Vector2>&	tex) {

	if (varArea.isNull()) {
		varArea = VARArea::create(1024 * 1024, VARArea::WRITE_ONCE);
	}

	indexArray = index;

	Array<Vector3> binormal;
	Array<Vector3> tangent;
	Array<MeshAlg::Face> face;
	MeshAlg::computeAdjacency(vertex, index, face, Array<MeshAlg::Edge>(), Array<MeshAlg::Vertex>()); 
	MeshAlg::computeTangentSpaceBasis(vertex, tex, normal, face, tangent, binormal);

    // Negate the binormal
    for (int i = 0; i < binormal.length(); ++i) {
        binormal[i] = -binormal[i];
    }
    
    
    // TODO: remove
    // Force the TBN space to be identity for testing
    for (int i = 0; i < binormal.length(); ++i) {
        tangent[i]  = Vector3(1,0,0);
        binormal[i] = Vector3(0,1,0);
    }
    
    
    for (int i = 0; i < binormal.length(); ++i) {
        debugPrintf("%s %s %s\n", 
            tangent[i].toString().c_str(),
            binormal[i].toString().c_str(),
            normal[i].toString().c_str());
    }
    

	vertexArray		= VAR(vertex,   varArea);
	texCoordArray	= VAR(tex,      varArea);
	normalArray		= VAR(normal,   varArea);
	binormalArray	= VAR(binormal, varArea);
	tangentArray	= VAR(tangent,  varArea);
}


void Mesh::render(RenderDevice* rd) {
	rd->beginIndexedPrimitives();
        // The mapping from properties to texture coordinates is implicit in the bump shader
		rd->setVertexArray(vertexArray);
		rd->setTexCoordArray(0, texCoordArray);
		rd->setTexCoordArray(1, tangentArray);
		rd->setTexCoordArray(2, binormalArray);
		rd->setNormalArray(normalArray);
		rd->sendIndices(RenderDevice::TRIANGLES, indexArray);
	rd->endIndexedPrimitives();
}
