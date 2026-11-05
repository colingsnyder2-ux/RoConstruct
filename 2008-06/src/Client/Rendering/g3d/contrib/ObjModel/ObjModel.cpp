/**

  @file ObjModel.h

  @author Corey Taylor, corey@acz.org

 */

#include "ObjModel.h"

#include "G3DAll.h"

ObjModel::ObjModel()
{
	modelExists=false;
}

ObjModel::~ObjModel()
{
}

VARAreaRef ObjModel::varArea = NULL;
TextureManager ObjModel::textureManager;

void ObjModel::render(RenderDevice* renderDevice, const GMaterial& mat, bool useMat) const
{
	if(!modelExists)
		return;
    renderDevice->pushState();
	renderDevice->setCullFace(RenderDevice::CULL_NONE);
	renderDevice->setShadeMode(RenderDevice::SHADE_SMOOTH);

	if(useMat)
		mat.configure(renderDevice);
/*
	const size_t varSize = 2048 * 1024;
    if (ObjModel::varArea.isNull()) {
        // Initialize VAR
        ObjModel::varArea = VARArea::create(varSize);
    }

	if (ObjModel::varArea && (varArea->totalSize() <= sizeof(Vector3) * 2 * objects[0].verticies.size())) {

		// Can use VAR

		varArea->reset();

		VAR vertex(objects[0].verticies, ObjModel::varArea);
		VAR normal(objects[0].vertexNormals, ObjModel::varArea);

		renderDevice->beginIndexedPrimitives();
			renderDevice->setNormalArray(normal);
			renderDevice->setVertexArray(vertex);
			renderDevice->sendIndices(RenderDevice::TRIANGLES, objects[0].vertexIndicies);
		renderDevice->endIndexedPrimitives();

    }
*/
    const int* indexArray = vertexIndices.getCArray();
    const Vector3* vertexArray = geometry.vertexArray.getCArray();
    const Vector3* normalArray = geometry.normalArray.getCArray();
	const int* texArray = textureIndices.getCArray();
	const Vector2* uvArray = textureCoordinates.getCArray();
    int n = vertexIndices.size();
	int objfaces = objects.size();
	
	int starti=0, endi=0;

	if(objfaces > 0){
	for(int idx=0; idx<objfaces; ++idx)
	{
		bool useTexture;
		if(objects[idx].texture != -1){
			renderDevice->setTexture(0, textures[objects[idx].texture]);
			useTexture = true;
		}
		else{
			useTexture = false;
			renderDevice->setTexture(0, NULL);
		}

//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, objects[idx].ambient);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, objects[idx].diffuse);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, objects[idx].specular);
//		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, objects[idx].shininess);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, objects[idx].emission);
		renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
		starti = objects[idx].index;
		if(objects.size() == idx+1)
			endi = n;
		else
			endi = objects[idx+1].index;
		for (int i = starti; i < endi; ++i)
		{
			const int v = indexArray[i];      
			if(useTexture)
				renderDevice->setTexCoord(0, uvArray[texArray[i]]);
			renderDevice->setNormal(normalArray[i]);
			renderDevice->sendVertex(vertexArray[v]);
		}
		renderDevice->endPrimitive();
	}
	}else{
		renderDevice->beginPrimitive(RenderDevice::TRIANGLES);
		for (int i = 0; i < n; ++i)
		{
			const int v = indexArray[i];            
//			renderDevice->setTexCoord(0, uvArray[texArray[i]]);
			renderDevice->setNormal(normalArray[i]);
			renderDevice->sendVertex(vertexArray[v]);
		}
		renderDevice->endPrimitive();
	}
	renderDevice->popState();
}




//PosedObjModel class methods

ObjModel::PosedObjModel::PosedObjModel(ObjModelRef modelref, const CoordinateFrame& pframe, const GMaterial& mat, bool _useMat):
model(modelref), frame(pframe), material(mat), useMat(_useMat)
{
}

string ObjModel::PosedObjModel::name() const
{
	return model->modelName;
}

void ObjModel::PosedObjModel::getCoordinateFrame(CoordinateFrame& c) const
{
	c=frame;
}

const MeshAlg::Geometry& ObjModel::PosedObjModel::objectSpaceGeometry() const
{
	return model->geometry;
}

const Array<MeshAlg::Face>& ObjModel::PosedObjModel::faces() const
{
	return model->faces;
}

const Array<MeshAlg::Edge>& ObjModel::PosedObjModel::edges() const
{
	return model->edges;
}

const Array<MeshAlg::Vertex>& ObjModel::PosedObjModel::vertices() const
{
	return model->vertexArray;
}

const Array<MeshAlg::Face>& ObjModel::PosedObjModel::weldedFaces() const
{
	if( model->weldedFaces.size() == 0 ){
	    MeshAlg::weldAdjacency(model->geometry.vertexArray, model->weldedFaces, model->weldedEdges, model->weldedVertices);
	    model->numBoundaryEdges = MeshAlg::countBoundaryEdges(model->edges);
	    model->numWeldedBoundaryEdges = MeshAlg::countBoundaryEdges(model->weldedEdges);
	}
	return model->weldedFaces;
}
const Array<MeshAlg::Edge>& ObjModel::PosedObjModel::weldedEdges() const
{
	if( model->weldedEdges.size() == 0 ){
	    MeshAlg::weldAdjacency(model->geometry.vertexArray, model->weldedFaces, model->weldedEdges, model->weldedVertices);
	    model->numBoundaryEdges = MeshAlg::countBoundaryEdges(model->edges);
	    model->numWeldedBoundaryEdges = MeshAlg::countBoundaryEdges(model->weldedEdges);
	}
	return model->weldedEdges;
}
const Array<MeshAlg::Vertex>& ObjModel::PosedObjModel::weldedVertices() const
{
	if( model->weldedVertices.size() == 0 ){
	    MeshAlg::weldAdjacency(model->geometry.vertexArray, model->weldedFaces, model->weldedEdges, model->weldedVertices);
	    model->numBoundaryEdges = MeshAlg::countBoundaryEdges(model->edges);
	    model->numWeldedBoundaryEdges = MeshAlg::countBoundaryEdges(model->weldedEdges);
	}
	return model->weldedVertices;
}

const Array<int>& ObjModel::PosedObjModel::triangleIndices() const
{
	if( model->renderMode == ObjModel::OBJ_TRIANGLES )
		return model->vertexIndices;
	else
		return model->triangleIndices;

}

void ObjModel::PosedObjModel::getObjectSpaceBoundingSphere(Sphere& _sphere) const
{
	_sphere = model->boundingSphere;
}

void ObjModel::PosedObjModel::getObjectSpaceBoundingBox(Box& _box) const
{
	_box = model->boundingBox;
}

void ObjModel::PosedObjModel::render(RenderDevice* renderDevice) const
{
	//do more here?
	renderDevice->pushState();
	renderDevice->setObjectToWorldMatrix(coordinateFrame());
	model->render(renderDevice, material, useMat);
	renderDevice->popState();
}

int ObjModel::PosedObjModel::numBoundaryEdges() const
{
	if( model->edges.size() == 0){
	    MeshAlg::weldAdjacency(model->geometry.vertexArray, model->weldedFaces, model->weldedEdges, model->weldedVertices);
	    model->numBoundaryEdges = MeshAlg::countBoundaryEdges(model->edges);
	    model->numWeldedBoundaryEdges = MeshAlg::countBoundaryEdges(model->weldedEdges);
	}
	return model->numBoundaryEdges;
}

int ObjModel::PosedObjModel::numWeldedBoundaryEdges() const
{
	if( model->weldedEdges.size() == 0){
	    MeshAlg::weldAdjacency(model->geometry.vertexArray, model->weldedFaces, model->weldedEdges, model->weldedVertices);
	    model->numBoundaryEdges = MeshAlg::countBoundaryEdges(model->edges);
	    model->numWeldedBoundaryEdges = MeshAlg::countBoundaryEdges(model->weldedEdges);
	}

	return model->numWeldedBoundaryEdges;
}


