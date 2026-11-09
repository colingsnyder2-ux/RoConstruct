/**
@file bsp/q3bsp.cpp
	
@maintainer Morgan McGuire, matrix@graphics3d.com

@created 2003-05-22
@edited  2003-09-04
*/ 

#include "BSPMAP.h"

extern Log*   debugLog;
extern GFont* font;

namespace BSPMAP {

Map::Map(): 
	lightVolumesCount(0),
	lightVolumes(NULL) {

	visData.clustersCount      = 0;
	visData.bytesPerCluster    = 0;
	visData.bitsets            = NULL;

	static const uint8 half[]  = {128, 128, 128, 128}; 
	static const uint8* arry[] = {half};

	defaultLightmap =
		Texture::fromMemory("Default Light Map", arry, TextureFormat::RGB8, 1, 1, 1,
		TextureFormat::RGB8, Texture::CLAMP, Texture::NO_INTERPOLATION, Texture::DIM_2D);
}


Map::~Map() {
	delete lightVolumes;
	delete visData.bitsets;

	faceArray.deleteAll();
}


int Map::findLeaf(const Vector3& pt) const {
	
	double distance = 0;
	int    index    = 0;

	while (index >= 0) {
		const BSPNode& node   = nodeArray[index];
		const BSPPlane& plane = planeArray[node.plane];

		// Distance from point to a plane
		distance = plane.normal.dot(pt) - plane.distance;

		if (distance >= 0) {
			index = node.front;
		} else {
			index = node.back;
		}
	}

	return -(index + 1);
}


bool Map::isClusterVisible(int visCluster, int testCluster) const {

	if ((visData.bitsets == NULL) || (visCluster < 0)) {
		return true;
	}

	// Note: testCluster >> 3 == testCluster / 8
	int i = (visCluster * visData.bytesPerCluster) + (testCluster >> 3);
	uint8 visSet = visData.bitsets[i];

	return (visSet & (1 << (testCluster & 7))) != 0;
}


void Map::initRender(GCamera& camera) {

	for (int ct = 1; ct < 8; ++ct) {
		glDisable(GL_LIGHT0 + ct);
	}

	glEnable(GL_LIGHT0);
	glLighti(GL_LIGHT0,GL_SPOT_CUTOFF,180);
	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,0);
}


void Map::render(RenderDevice* renderDevice, const GCamera& camera) {
    // Adjust intensity for tone mapping
    float adjustBrightness = 1;//0.4; // TODO

	Array<FaceSet*> opaqueFaceArray;
	Array<FaceSet*> translucentFaceArray;

	getVisibleFaces(renderDevice, camera, translucentFaceArray, opaqueFaceArray);

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

		// Opaque
		glCullFace(GL_FRONT);
		glDisable(GL_BLEND);
		glDisable(GL_LIGHTING);
		glEnableClientState(GL_VERTEX_ARRAY);
		
		glClientActiveTextureARB(GL_TEXTURE1_ARB);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glClientActiveTextureARB(GL_TEXTURE0_ARB);        
		glEnable(GL_TEXTURE_2D);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glColor(Color3::white() * adjustBrightness);
		renderFaces(renderDevice, camera, opaqueFaceArray);

		// Translucent
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glAlphaFunc(GL_GREATER, 0.2f);
		glEnable(GL_ALPHA_TEST);
		glDisable(GL_CULL_FACE);

        glColor(Color3::white() * adjustBrightness);
		renderFaces(renderDevice, camera, translucentFaceArray);

	glPopClientAttrib();
	glPopAttrib();

#if 0
	
	// Draw debugging data
	renderDevice->pushState();
		renderDevice->setColor(Color3::WHITE);
		renderDevice->setBlendFunc(RenderDevice::BLEND_SRC_ALPHA, RenderDevice::BLEND_ONE_MINUS_SRC_ALPHA);
		renderDevice->setLineWidth(0.5);
		glColor(Color3::WHITE);
		glBegin(GL_LINES);
		for (int i = 0; i < debugLine.size(); ++i) {
			glVertex(debugLine[i].start);
			glVertex(debugLine[i].stop);
		}
		glEnd();


		renderDevice->debugDrawBox(leafArray[2802].bounds);

	renderDevice->popState();

	
/*
	renderDevice->push2D();

	for (i = 0; i < debugString.size(); ++i) {
		Vector3 pos = camera.project(debugString[i].pos, renderDevice->getWidth(), renderDevice->getHeight());
		font->draw2DString(debugString[i].s, pos.x, pos.y, 15, Color3::WHITE, Color3::BLACK);
	}

	font->draw2DString(format("%g %g %g", camera.getCoordinateFrame().translation.x, camera.getCoordinateFrame().translation.y, camera.getCoordinateFrame().translation.z),
		200, 10, 15, Color3::WHITE, Color3::BLACK);

	renderDevice->pop2D();
    */
#endif
}


class DebugLine {
public:
	Vector3     start;
	Vector3     stop;
};

class DebugString {
public:
	Vector3     pos;
	std::string s;
};

Array<DebugLine>    debugLine;
Array<DebugString>  debugString;


void Map::getVisibleFaces(
	RenderDevice*               renderDevice,
	const GCamera&              camera,
	Array<FaceSet*>&            translucentFaceArray,
	Array<FaceSet*>&            opaqueFaceArray) {

	debugLine.clear();
	debugString.clear();

	// Find the camera's cluster
	int leafIndex = findLeaf(camera.getCoordinateFrame().translation);
	int visCluster = leafArray[leafIndex].cluster;
		
	Array<Plane> frustum;
	camera.getClipPlanes(renderDevice->getViewport(), frustum);

	facesDrawn.clearAll();

	Vector3 zAxis, origin;
	{
		CoordinateFrame cframe;
		camera.getCoordinateFrame(cframe);
		zAxis  = cframe.getLookVector();
		origin = cframe.translation;
	}

	for (int ct = 0; ct < leafArray.size(); ++ct) {
		const BSPLeaf& leaf = leafArray[ct];
	
		// Try to cull this leaf

		// Cluster-cluster visibility cull
		if (! isClusterVisible(visCluster, leaf.cluster)) {
			continue;
		}

		// Frustum cull
		if (leaf.bounds.culledBy(frustum)) {
			continue;
		}

		Vector3 center = leaf.bounds.getCenter();

		// Draw all of the faceArray in the leaf
		for (int f = leaf.facesCount - 1; f >= 0; --f) {

			int faceIndex = leafFaceArray[leaf.firstFace + f];

			if (! facesDrawn.isOn(faceIndex)) {

				facesDrawn.set(faceIndex);

				FaceSet* face = faceArray[faceIndex];

				// Ignore untextured faces
				TextureRef texture = textures[face->textureID];
				if ((face->lightmapID < 0) && texture.isNull()) {
					continue;
				}

				face->updateSortKey(this, zAxis, origin);
				if ((texture.isNull()) || texture->opaque()) {
					opaqueFaceArray.append(face);
				} else {
					translucentFaceArray.append(face);
				}

				/*
				// Connect the faceArray to the center of their leaf for debugging purposes.
				if (face->getType() == FaceSet::POLYGON) {
					DebugLine line;
					GLBSPPolygon* polygon = dynamic_cast<GLBSPPolygon*>(face);

					line.start = vertexArray[polygon->firstVertex].position;
					line.stop  = center;

					debugLine.append(line);

					// Label the center of each poly with its index
					if ((camera.getCoordinateFrame().translation - vertexArray[polygon->firstVertex].position).length() < 250) {
						DebugString s;
						// Find the center of the polygon
						for (int v = 0; v < polygon->vertexesCount; ++v) {
							s.pos += vertexArray[polygon->firstVertex + v].position;
						}
						s.s = format("%d", faceIndex);
						s.pos /= polygon->vertexesCount;
						debugString.append(s);
					}

				}
				*/
			}
		}
	}

	//get faces of dynamic models
	//models are not in the BSP tree, so it's not worth it to do visibility testing on so few faces
	for (int i = 0; i < dynamicModels.size(); ++i) {
		BSPModel currentModel = dynamicModels[i];
		for(int f = 0; f < currentModel.numOfFaces; ++f){
			FaceSet* face = faceArray[currentModel.faceIndex + f];
			// Ignore untextured faces
			TextureRef texture = textures[face->textureID];
			if ((face->lightmapID < 0) && texture.isNull()) {
				continue;
			}
			face->updateSortKey(this, zAxis, origin);
			if (texture.isNull() || texture->opaque()) {
				opaqueFaceArray.append(face);
			} else {
				translucentFaceArray.append(face);
			}
		}
	}
}



void Map::renderFaces(
	RenderDevice*               renderDevice,
	const GCamera&              camera,
	const Array<FaceSet*>&      visibleFaceArray) {

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

		int lastTextureID = -1;
		int lastLightmapID = -1;

		TextureRef texture;
		for (int i = 0; i < visibleFaceArray.size(); ++i) {
			FaceSet* theFace = visibleFaceArray[i];
		
			if (lastTextureID != theFace->textureID) {
				glActiveTextureARB(GL_TEXTURE0_ARB);
				texture = textures[theFace->textureID];

				if (texture.isNull()) {
					texture = defaultTexture;
				}

				if (texture.notNull()) {
					glEnable(GL_TEXTURE_2D);
					glClientActiveTextureARB(GL_TEXTURE0_ARB);
					glBindTexture(GL_TEXTURE_2D, texture->getOpenGLID());
					glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);  
				} else {
					glDisable(GL_TEXTURE_2D);
				}

				lastTextureID = theFace->textureID;
			}

			if (lastLightmapID != theFace->lightmapID) {
				glActiveTextureARB(GL_TEXTURE1_ARB);
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_EXT, GL_PREVIOUS_EXT);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB_EXT, GL_SRC_COLOR);
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_EXT, GL_MODULATE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_EXT, GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB_EXT, GL_SRC_COLOR);
				glTexEnvf(GL_TEXTURE_ENV, GL_RGB_SCALE_EXT, 2.0f);
				glEnable(GL_TEXTURE_2D);

				if (theFace->lightmapID >= 0) {
					glBindTexture(GL_TEXTURE_2D, lightmaps[theFace->lightmapID]->getOpenGLID());
				} else {
					if (defaultLightmap.notNull()) {
						glBindTexture(GL_TEXTURE_2D, defaultLightmap->getOpenGLID());
					}
				}
				lastLightmapID = theFace->lightmapID;
			}

			theFace->render(this);
		}


	glPopClientAttrib();
	glPopAttrib();

}




void Map::render(GCamera& camera, void* obj) {
/*
	int objectCluster = 
		leafArray[findLeaf(obj->getPositionX(),
						obj->getPositionY(),
						obj->getPositionZ())].cluster;
	
	if (!isClusterVisible(camera.getIntValue(),objectCluster)) {
		return;
	}

	int idxX = int((obj->getPositionX()-staticModel.min[0])*lightVolumesInvSizes.x);
	int idxY = int((obj->getPositionY()-staticModel.min[2])*lightVolumesInvSizes.y+0.5);
	int idxZ = int((-obj->getPositionZ()-staticModel.min[1])*lightVolumesInvSizes.z);
	int index =
		idxX+idxZ*(lightVolumesGrid.x)+idxY*(lightVolumesGrid.x*lightVolumesGrid.z);
	BSPLightVolume* lgh = &lightVolumes[index];
	float ambient[] =
	{lgh->ambient[0]/255.0f,lgh->ambient[1]/255.0f,lgh->ambient[2]/255.0f,1};
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	float diffuse[] = {
		lgh->directional[0]/255.0f,
			lgh->directional[1]/255.0f,
			lgh->directional[2]/255.0f,
			1
	};
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,diffuse);
	int dirA = lgh->direction[0];
	int dirB = lgh->direction[1];
	GLfloat direction[] = {
		MTNormals2D::getNormal(dirA,dirB,0),
			MTNormals2D::getNormal(dirA,dirB,2),
			-MTNormals2D::getNormal(dirA,dirB,1),
			0
	};
	glLightfv(GL_LIGHT0,GL_POSITION,direction);
	obj->render(camera);
*/  
}

void Map::checkCollision(Vector3& pos, Vector3& vel, Vector3& extent) {
	if (vel.squaredLength() > 0) {
		collide(pos, vel, extent);
	}
}


void Map::slideCollision(Vector3& pos, Vector3& vel, Vector3& extent) {

	if (vel.squaredLength() == 0) {
		return;
	}
	
	Vector3 startPos = pos;
	Vector3 startVel = vel;
	Vector3 normalPos = pos;
	Vector3 normalVel = vel;

	slide(normalPos, normalVel, extent);
	
	Vector3 up = startPos;

	// For going up stairs
	const double STEP_SIZE = 22 * LOAD_SCALE;
	up.y += STEP_SIZE;
	Vector3 up2 = up;
	BSPCollision collision = checkMove(up, up2, extent);
	
	if (collision.isSolid)  {
		pos = normalPos;
		return;
	}

	Vector3 upVel = startVel;
	collide(up, upVel, extent);
	Vector3 tmp = up;
	Vector3 down = up;
	down.y -= STEP_SIZE;
	collision = checkMove(up, down, extent);

	if (!collision.isSolid) {
		tmp = collision.end;
	}

	up = tmp;
	float diff;
	float downStep =
		(diff = normalPos.x-startPos.x)*diff +
		(diff = normalPos.z-startPos.z)*diff;
	float upStep =
		(diff = up.x-startPos.x)*diff+
		(diff = up.z-startPos.z)*diff;
	const float MIN_STEP_NORMAL = 0.7f;
	
	if ((downStep > upStep) || (collision.normal.y < MIN_STEP_NORMAL)) {
		vel = normalVel;
		pos = normalPos;
	} else {
		pos = up;
	}
}


void Map::collide(Vector3& pos, Vector3& vel, Vector3& extent) {
	BSPCollision collision;
	collision.fraction = 0;
	Vector3 initPos = pos;
	Vector3 initVel = vel;
	Vector3 planeArray[5];
	float fractionLeft = 1;
	Vector3 dir;
	int planesCount = 0;
	
	for (int plane = 0; plane < 4; plane++) {
		fractionLeft -= collision.fraction;
		Vector3 startPoint = pos;
		Vector3 endPoint = startPoint+vel;
		collision = checkMove(startPoint,endPoint,extent);
		
		if (collision.isSolid) {
			vel.y = 0;
			return;
		}

		if (collision.fraction > 0) {
			pos = collision.end;
			planesCount = 0;
			if (collision.fraction == 1) {
				break;
			}
		}

		if (planesCount >= 5) {
			break;
		}

		planeArray[planesCount] = collision.normal.direction();
		planesCount++;
	}
}


void Map::slide(Vector3& pos, Vector3& vel, Vector3& extent) {
	BSPCollision collision;
	collision.fraction = 0;
	Vector3 initPos = pos;
	Vector3 initVel = vel;
	Vector3 planeArray[5];
	float fractionLeft = 1;
	Vector3 dir;
	int planesCount = 0;
	
	for (int plane = 0; plane < 4; plane++) {
		
		fractionLeft -= collision.fraction;
		Vector3 startPoint = pos;
		Vector3 endPoint = startPoint+vel;
		collision = checkMove(startPoint,endPoint,extent);

		if (collision.isSolid) {
			vel.y = 0;
			return;
		}

		if (collision.fraction > 0) {
			pos = collision.end;
			planesCount = 0;
			if (collision.fraction == 1) {
				break;
			}
		}

		if (planesCount >= 5) {
			break;
		}

		planeArray[planesCount] = collision.normal.direction();
		planesCount++;

		int i,j;
		for (i = 0; i < planesCount; i++) {
		    
			clipVelocity(vel,planeArray[i],vel,1.01f);
		    
			for (j = 0; j < planesCount; j++) {
				if (j != i) {
					if (vel.dot(planeArray[j]) < 0) {
						break;
					}
				}
			}

			if (j == planesCount) {
				break;
			}
		}

		if (i != planesCount) {

			Vector3 dir = vel.direction();
			clipVelocity(vel, planeArray[0], vel, 1.01f);

		} else {

			if (planesCount != 2) {
				vel = Vector3::ZERO;
				break;
			}

			dir = planeArray[0].cross(planeArray[1]);
			vel = dir * dir.dot(vel);
		}

		if (vel.dot(initVel) <= 0) {
			// We've run into a corner and are trying to slide away from
			// the intended movement direction; force velocity to zero.
			vel = Vector3::ZERO;
			break;
		}
	}
}

BSPCollision Map::checkMove(Vector3& start, Vector3& end, Vector3& extent) {

	BSPCollision moveCollision;
	moveCollision.size      = extent;
	moveCollision.start     = start;
	moveCollision.end       = end;
	moveCollision.normal    = Vector3::ZERO;
	moveCollision.fraction  = 1;
	moveCollision.isSolid   = false;

	checkMoveNode(0, 1, start, end, 0, &moveCollision);

	if (moveCollision.fraction < 1.0f) {
		moveCollision.end = (start + (end - start) * (moveCollision.fraction));
	} else {
		moveCollision.end = end;
	}

	return moveCollision;
}


void Map::checkMoveNode(
	float               start,
	float               end,
	Vector3             startPos,
	Vector3             endPos,
	int                 node,
	BSPCollision*       moveCollision) const {
	
	if (moveCollision->fraction <= start) {
		return;
	}

	if (node < 0) {
		// The node index is really a leaf index
		checkMoveLeaf(~node, moveCollision);
		return;
	}

	int plane = nodeArray[node].plane;
	float t1 = planeArray[plane].normal.dot(startPos) - planeArray[plane].distance;
	float t2 = planeArray[plane].normal.dot(endPos) - planeArray[plane].distance;
	float offset =
		fabs(moveCollision->size.x*planeArray[plane].normal.x)+
		fabs(moveCollision->size.y*planeArray[plane].normal.y)+
		fabs(moveCollision->size.z*planeArray[plane].normal.z);

	if ((t1 >= offset) && (t2 >= offset)) {

		checkMoveNode(start, end, startPos, endPos, nodeArray[node].front, moveCollision);
		return;

	} else if ((t1 < -offset) && (t2 < -offset)) {
		
		checkMoveNode(start, end, startPos, endPos, nodeArray[node].back, moveCollision);
		return;
	}

	float frac;
	float frac2;
	const float DIST_EPSILON = 1.0f / 32;
	int frontNode, backNode;

	if (t1 < t2) {
		float invDist = 1 / (t1 - t2);

		backNode    = nodeArray[node].front;
		frontNode   = nodeArray[node].back;
		frac        = (t1 - offset - DIST_EPSILON) * invDist;
		frac2       = (t1 + offset + DIST_EPSILON) * invDist;

	} else if (t1 > t2) {
		float invDist = 1 / (t1 - t2);

		backNode    = nodeArray[node].back;
		frontNode   = nodeArray[node].front;
		frac        = (t1 + offset + DIST_EPSILON) * invDist;
		frac2       = (t1 - offset - DIST_EPSILON) * invDist;

	} else {

		backNode    = nodeArray[node].back;
		frontNode   = nodeArray[node].front;
		frac        = 1;
		frac2       = 0;
	}

	frac  = clamp(frac, 0,  1);
	frac2 = clamp(frac2, 0, 1);

	float mid = start + (end - start) * frac;
	Vector3 midPos = startPos + (endPos - startPos) * frac;

	checkMoveNode(start, mid, startPos, midPos, frontNode, moveCollision);

	mid    = start + (end - start) * frac2;
	midPos = startPos + (endPos - startPos) * frac2;

	checkMoveNode(mid, end, midPos, endPos, backNode, moveCollision);
}


void Map::checkMoveLeaf(int leaf, BSPCollision* moveCollision) const {
	int firstBrush = leafArray[leaf].firstBrush;

	for (int ct = 0; ct < leafArray[leaf].brushesCount; ++ct) {
		int brushIndex = leafBrushArray[firstBrush + ct];
		
		const Brush* brush = &brushArray[brushIndex];
		clipBoxToBrush(brush, moveCollision);
		
		if (! moveCollision->fraction) {
			return;
		}
	}
}


void Map::clipBoxToBrush(
	const Brush*        brush,
	BSPCollision*       moveCollision) const {

	if ((!textureIsHollow.isOn(brush->textureID)) ||
		(brush->brushSidesCount == 0)) {

		return;
	}

	const float DIST_EPSILON = 1.0f/32;
	float enter         = -1;
	float exit          = 1;
	bool startOut       = false;
	bool endOut         = false;
	int firstBrushSide  = brush->firstBrushSide;
	Vector3 hitNormal(0,0,0);
	
	for (int ct = 0; ct < brush->brushSidesCount; ++ct) {
		int planeIndex = brushSideArray[firstBrushSide+ct].plane;
		const BSPPlane& plane = planeArray[planeIndex];
		Vector3 offsets = moveCollision->size*(-1);
		
		if (plane.normal.x < 0) {
			offsets.x = -offsets.x;
		}

		if (plane.normal.y < 0) {
			offsets.y = -offsets.y;
		}

		if (plane.normal.z < 0) {
			offsets.z = -offsets.z;
		}

		float dist = plane.distance-offsets.dot(plane.normal);
		float d1 = moveCollision->start.dot(plane.normal)-dist;
		float d2 = moveCollision->end.dot(plane.normal)-dist;
		
		if (d1 > 0) {
			startOut = true;
		}

		if (d2 > 0) {
			endOut = true;
		}

		if ((d1 > 0) && (d2 >= d1)) {
			return;
		}

		if ((d1 <= 0) && (d2 <= 0)) {
			continue;
		}

		float f;
		if (d1 > d2) {
			f = (d1 - DIST_EPSILON) / (d1 - d2);
			if (f > enter) {
				enter = f;
				hitNormal = plane.normal;
			}
		} else {
			f = (d1 + DIST_EPSILON) / (d1 - d2);
			if (f < exit) {
				exit = f;
			}
		}
	}

	if (!startOut) {
		moveCollision->isSolid = !endOut;
		return;
	}

	if (enter < exit) {
		if ((enter > -1) && (enter < moveCollision->fraction)) {
			if (enter < 0) {
				enter = 0;
			}
			moveCollision->fraction = enter;
			moveCollision->normal = hitNormal;
		}
	}
}


void Map::clipVelocity(
	const Vector3&      in,
	const Vector3&      planeNormal,
	Vector3&            out,
	float               overbounce) const {

	const float STOP_EPSILON = 0.1f;
	
	out = in - planeNormal * (in.dot(planeNormal) * overbounce);
	
	if (fabs(out.x) < STOP_EPSILON) {
		out.x = 0;
	}

	if (fabs(out.y) < STOP_EPSILON) {
		out.y = 0;
	}

	if (fabs(out.z) < STOP_EPSILON) {
		out.z = 0;
	}
}


void Patch::Bezier2D::tessellate(int L) {
	level = L;

	// The number of vertices along a side is 1 + num edges
	const int L1 = L + 1;

	vertex.resize(L1 * L1);

	// Compute the vertices
	int i;

	for (i = 0; i <= L; ++i) {
		double a = (double)i / L;
		double b = 1 - a;

		vertex[i] =
			controls[0] * (b * b) + 
			controls[3] * (2 * b * a) +
			controls[6] * (a * a);
	}

	for (i = 1; i <= L; ++i) {
		double a = (double)i / L;
		double b = 1.0 - a;

		Vertex temp[3];

		int j;
		for (j = 0; j < 3; ++j) {
			int k = 3 * j;
			temp[j] =
				controls[k + 0] * (b * b) + 
				controls[k + 1] * (2 * b * a) +
				controls[k + 2] * (a * a);
		}

		for(j = 0; j <= L; ++j) {
			double a = (double)j / L;
			double b = 1.0 - a;

			vertex[i * L1 + j]=
				temp[0] * (b * b) + 
				temp[1] * (2 * b * a) +
				temp[2] * (a * a);
		}
	}


	// Compute the indices
	int row;
	indexes.resize(L * (L + 1) * 2);

	for (row = 0; row < L; ++row) {
		for(int col = 0; col <= L; ++col)	{
			indexes[(row * (L + 1) + col) * 2 + 1] = row       * L1 + col;
			indexes[(row * (L + 1) + col) * 2]     = (row + 1) * L1 + col;
		}
	}

	trianglesPerRow.resize(L);
	rowIndexes.resize(L);
	for (row = 0; row < L; ++row) {
		trianglesPerRow[row] = 2 * L1;
		rowIndexes[row]      = &indexes[row * 2 * L1];
	}
	
}


void Patch::Bezier2D::render() const {
	glVertexPointer(3, GL_FLOAT,sizeof(Vertex), &vertex[0].position);

	glClientActiveTextureARB(GL_TEXTURE0_ARB);
	glTexCoordPointer(2,GL_FLOAT,sizeof(Vertex), &vertex[0].textureCoord);

	glClientActiveTextureARB(GL_TEXTURE1_ARB);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &vertex[0].lightmapCoord);

	glMultiDrawElementsEXT(GL_TRIANGLE_STRIP, trianglesPerRow.getCArray(),
		GL_UNSIGNED_INT, (const void **)(rowIndexes.getCArray()), level);
}


void Patch::render(class Map* map) const {
	for (int p = 0; p < bezierArray.size(); ++p) {
		bezierArray[p].render();
	}
}


void Patch::updateSortKey(
	class Map*      map,
	const Vector3&  zAxis,
	Vector3&        origin) {

	if (bezierArray.size() > 0) {
		sortKey = (bezierArray[0].controls[0].position - origin).dot(zAxis);
	}
}


void Mesh::render(Map* map) const {

	int offset = firstVertex;

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex),
		&(map->vertexArray[offset].position));

	glClientActiveTextureARB(GL_TEXTURE0_ARB);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex),
		&(map->vertexArray[offset].textureCoord));

	glClientActiveTextureARB(GL_TEXTURE1_ARB);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex),
		&(map->vertexArray[offset].lightmapCoord));

	glDrawElements(GL_TRIANGLES, meshVertexesCount, GL_UNSIGNED_INT,
		&(map->meshVertexArray[firstMeshVertex]));

}


void Mesh::updateSortKey(
	class Map*      map,
	const Vector3&  zAxis,
	Vector3&        origin) {
	sortKey = (map->vertexArray[firstVertex].position - origin).dot(zAxis);
}


void Map::getTriangles(
    Array<Vector3>&     outVertexArray,
    Array<Vector3>&     outNormalArray,
    Array<int>&         outIndexArray,
    Array<Vector2>&     outTexCoordArray,
    Array<Vector2>&     outLightCoordArray,
    Array<int>&         outLightMapIndexArray,
    Array<int>&         outTexCoordIndexArray,
    Array<TextureRef>&  outTextureMapArray,
    Array<TextureRef>&  outLightMapArray) const {

    // Copy the textures
    outLightMapArray = lightmaps;
    outTextureMapArray = textures;

    // Resize the output arrays
    const int n = vertexArray.size();
    outVertexArray.resize(n);
    outLightCoordArray.resize(n);
    outTexCoordArray.resize(n);
    outNormalArray.resize(n);

    // Spread the input over the output arrays
    for (int i = 0; i < vertexArray.size(); ++i) {
        const Vertex& vertex  = vertexArray[i];

        outVertexArray[i]     = vertex.position;
        outLightCoordArray[i] = vertex.lightmapCoord;
        outTexCoordArray[i]   = vertex.textureCoord;
        outNormalArray[i]     = vertex.normal;
    }

    // Extract the indices
	for (int f = 0; f < faceArray.size(); ++f) {
		// Only render map faces (not entity faces), which have valid light maps
		if (faceArray[f]->lightmapID >= 0) {
			switch (faceArray[f]->type()) {
			case FaceSet::MESH:
				{
					const Mesh* mesh = dynamic_cast<const Mesh*>(faceArray[f]);
					for (int t = 0; t < mesh->meshVertexesCount / 3; ++t) {
                        outLightMapIndexArray.append(mesh->lightmapID);
						debugAssert(mesh->lightmapID >= 0);

						for (int v = 0; v < 3; ++v) {
							// Compute the index into the index array
							// Wind backwards
							int i = mesh->firstMeshVertex + t * 3 + (2 - v);
							// Compute the index into the vertex array
							int index = meshVertexArray[i] + mesh->firstVertex;

                            outIndexArray.append(index);
						}
					}
				}
				break;

			case FaceSet::BILLBOARD:
				break;

			case FaceSet::PATCH:
                // TODO: Morgan add these vertices at the end of the array
				/*
                {
					const Patch* patch = dynamic_cast<const Patch*>(faceArray[f]);
					for (int b = 0; b < patch->bezierArray.size(); ++b) {
						const Patch::Bezier2D& bezier = patch->bezierArray[b];

						for (int row = 0; row < bezier.level; ++row) {
							// This is a triangle strip.  Track every three vertices
							// and alternate winding directions.
							int v0 = bezier.rowIndexes[row][0];
							int v1 = bezier.rowIndexes[row][1];
							for (int v = 2; v < bezier.trianglesPerRow[row]; ++v) {
								int v2 = bezier.rowIndexes[row][v];

								MatrianceTri& tri = triArray.next();
								tri.color = Color3uint8(Color3::WHITE);
								tri.lightMapIndex = patch->lightmapID;

								if (isOdd(v)) {
									tri.vertex[0].position   = bezier.vertex[v0].position;
									tri.vertex[0].lightCoord = bezier.vertex[v0].lightmapCoord;

									tri.vertex[1].position   = bezier.vertex[v1].position;
									tri.vertex[1].lightCoord = bezier.vertex[v1].lightmapCoord;

									tri.vertex[2].position   = bezier.vertex[v2].position;
									tri.vertex[2].lightCoord = bezier.vertex[v2].lightmapCoord;
								} else {
									tri.vertex[2].position   = bezier.vertex[v0].position;
									tri.vertex[2].lightCoord = bezier.vertex[v0].lightmapCoord;

									tri.vertex[1].position   = bezier.vertex[v1].position;
									tri.vertex[1].lightCoord = bezier.vertex[v1].lightmapCoord;

									tri.vertex[0].position   = bezier.vertex[v2].position;
									tri.vertex[0].lightCoord = bezier.vertex[v2].lightmapCoord;
								}

								// Shift
								v0 = v1;
								v1 = v2;
							}
						}
					}
				}
                */
				break;

			default:
				debugAssertM(false, "Fell through switch");
			}
		}
	}

}


}

