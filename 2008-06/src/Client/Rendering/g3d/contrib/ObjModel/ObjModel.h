/**

  @file ObjModel.h

  @author Corey Taylor, corey@acz.org

 */

#ifndef __OBJ_MODEL__H_
#define __OBJ_MODEL__H_

#include "G3DAll.h"
#include <string>
using namespace std;

class ObjModel;

typedef ReferenceCountedPointer<ObjModel> ObjModelRef;

class ObjModel_load{
private:
	enum ObjRender {OBJ_QUADS=0, OBJ_TRIANGLES, OBJ_POLYGONS};
	friend ObjModel;
	class ObjMtl{
	public:
		string name;
		string texture;
		int textureIndex;
		float diffuse[3];
		float ambient[3];
		float specular[3];
		float emission[3];
		float shininess;
	};
	ObjRender refmode;
	void loadModel(ObjModel& ref, const string& file, bool useMtl, ObjRender mode);
	bool ReadObjVerticies(ObjModel& ref, TextInput& in, Token& type);
	bool ReadObjUVs(ObjModel& ref, TextInput& in, Token& type);
	bool ReadObjFaces(ObjModel& ref, TextInput& in, Token& type);
	bool ReadMtl(const string& file, Array<ObjMtl>& mtls);
};


class ObjModel: public ReferenceCountedObject{
public:
	enum ObjRender {OBJ_QUADS=0, OBJ_TRIANGLES, OBJ_POLYGONS};
	ObjModel();
	~ObjModel();

	static ObjModelRef create(const string& file, bool useMtl=false, ObjRender mode=OBJ_TRIANGLES)
	{
		ObjModel* tmp = new ObjModel;
		ObjModel_load loader;
		loader.loadModel(*tmp, file, useMtl, (ObjModel_load::ObjRender)mode);
		return tmp;
	}
	
	static VARAreaRef varArea;
	static TextureManager textureManager;

	void render(RenderDevice* render, const GMaterial& mat, bool useMat) const;

    std::string name() const{
		return modelName;
	}
	
	ObjRender getRenderMode(){
		return renderMode;
	}

	//Reminder to finish defining pose class
	PosedModelRef pose(const CoordinateFrame& cframe){
		return new PosedObjModel(this, cframe, GMaterial(), false);
	}

	bool modelExists;

protected:

	class PosedObjModel: public PosedModel{
	public:
		ObjModelRef model;
		CoordinateFrame frame;
		GMaterial material;
		bool useMat;

		PosedObjModel::PosedObjModel(ObjModelRef modelref, const CoordinateFrame& pframe, const GMaterial& mat, bool useMat);
		string name() const;
		void getCoordinateFrame(CoordinateFrame& c) const;
		const MeshAlg::Geometry& objectSpaceGeometry() const;
		const Array<MeshAlg::Face>& faces() const;
		const Array<MeshAlg::Edge>& edges() const;
		const Array<MeshAlg::Vertex>& vertices() const;
		const Array<MeshAlg::Face>& weldedFaces() const;
		const Array<MeshAlg::Edge>& weldedEdges() const;
		const Array<MeshAlg::Vertex>& weldedVertices() const;
		const Array<int>& triangleIndices() const;
		void getObjectSpaceBoundingSphere(Sphere&) const;
		void getObjectSpaceBoundingBox(Box&) const;
		void render(class RenderDevice* renderDevice) const;
		int numBoundaryEdges() const;
		int numWeldedBoundaryEdges() const;
	};

	friend class PosedObjModel;
	friend class ObjModel_load;

	class ObjModelFace{
	public:
		int index;
		int texture;	
		float diffuse[3];
		float ambient[3];
		float specular[3];
		float emission[3];
		float shininess;
	};

	ObjRender renderMode;

	string modelName;
	Sphere boundingSphere;
	Box boundingBox;
	int numBoundaryEdges;
	
	//Posed Model only
	Array<MeshAlg::Vertex> vertexArray;
	Array<MeshAlg::Face> weldedFaces;
	Array<MeshAlg::Edge> weldedEdges;
	Array<MeshAlg::Vertex> weldedVertices;
	int numWeldedBoundaryEdges;
	Array<MeshAlg::Face> faces;
	Array<Vector3> faceNormals;
	Array<MeshAlg::Edge> edges;

	//All render modes
	MeshAlg::Geometry geometry;
	Array<int> vertexIndices;
	Array<Vector2> textureCoordinates;
	Array<int> textureIndices;


	//Polygon/Quad render mode only
	MeshAlg::Geometry triangleGeometry;
	Array<int> triangleIndices;

	Array<TextureRef> textures;
	Array<ObjModelFace> objects;


	//Override this to use the .mtl material light data
	virtual inline void UseMtlData(const ObjModelFace& data){};

};


#endif // _OBJ_MODEL_H