// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native Ogre::RbxAdornState (inactive): SGI GLU quad.c (gluCylinder/gluPartialDisk/gluDisk/gluSphere) on
// Ogre::ManualObject. Bodies follow the server-exact analog of each address; upstream: mesa glu src/libutil/quad.c.
// >>> native-status (generated) -- do not edit >>>
// OgreRbxAdornState | 2008-06 | 30 byte-exact, inactive (not link-selected)
// 30/30 mapped addresses byte-exact | named 5 | 0 unproved | no mapped strings | by auto (+3) (mixed 3)
// <<< native-status | src b8efe9b1 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/RbxAdornState2008.h"
#include <OgreManualObject.h>
#include <OgreSceneManager.h>
#include <OgreMath.h>
#include <vector>
#include <cmath>

namespace Ogre
{
	RbxAdornState::RbxAdornState()
	{
		normals = Smooth;
		textureCoords = false;
		orientation = Outside;
		drawStyle = Fill;
		colour = ColourValue(-1.0f, -1.0f, -1.0f, -1.0f);
		offset = Vector3(0.0f, 0.0f, 0.0f);
	}

// quad.c's GL_QUAD_STRIP vertices as an indexed triangle list.
#define VTX(R,Z) {int count=positions.size();if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);\
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);\
\
object->position(R * sinCache[i]+off.x,R * cosCache[i]+off.y,Z+off.z);\
object->index(index++);\
object->normal(currentNormal);\
positions.push_back(Ogre::Vector3(R * sinCache[i] + off.x,R * cosCache[i] + off.y,Z+off.z));\
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);\
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);\
\
object->position(R * sinCache[i]+off.x,R * cosCache[i]+off.y,Z+off.z);\
object->index(index++);\
object->normal(currentNormal);\
positions.push_back(Ogre::Vector3(R * sinCache[i] + off.x,R * cosCache[i] + off.y,Z+off.z));\
normalsCache.push_back(currentNormal);}}\
else{positions.push_back(Ogre::Vector3(R * sinCache[i] + off.x, R * cosCache[i] + off.y, Z + off.z));normalsCache.push_back(currentNormal);}}
ManualObject* RbxAdornState::cylinder(SceneManager*manager,const String&name,ManualObject*object,float baseRadius,float topRadius,float height,int slices,int stacks){
if(!object)object=manager->createManualObject(name);
const Ogre::Vector3& off=offset;

    int i,j;
    float sinCache[240];
    float cosCache[240];
    float sinCache2[240];
    float cosCache2[240];
    float sinCache3[240];
    float cosCache3[240];
    float angle;
    float zLow, zHigh;
    float sintemp, costemp;
    float length;
    float deltaRadius;
    float zNormal;
    float xyNormalRatio;
    float radiusLow, radiusHigh;
    int needCache2, needCache3;

    if (slices >= 240) slices = 240-1;

    if (slices < 2 || stacks < 1 || baseRadius < 0.0 || topRadius < 0.0 ||
	    height < 0.0) {
	
	return 0;
    }

    
    deltaRadius = baseRadius - topRadius;
    length = sqrt(deltaRadius*deltaRadius + height*height);
    if (length == 0.0) {
	
	return 0;
    }

    
    
    
    needCache2 = needCache3 = 0;
    if (normals == Smooth) {
	needCache2 = 1;
    }

    if (normals == Flat) {
	if (drawStyle != Point) {
	    needCache3 = 1;
	}
	if (drawStyle == Line) {
	    needCache2 = 1;
	}
    }

    zNormal = deltaRadius / length;
    xyNormalRatio = height / length;

    for (i = 0; i < slices; i++) {
	angle = 2 * Ogre::Math::PI * i / slices;
	if (needCache2) {
	    if (orientation == Outside) {
		sinCache2[i] = xyNormalRatio * sin(angle);
		cosCache2[i] = xyNormalRatio * cos(angle);
	    } else {
		sinCache2[i] = -xyNormalRatio * sin(angle);
		cosCache2[i] = -xyNormalRatio * cos(angle);
	    }
	}
	sinCache[i] = sin(angle);
	cosCache[i] = cos(angle);
    }

    if (needCache3) {
	for (i = 0; i < slices; i++) {
	    angle = 2 * Ogre::Math::PI * (i-0.5) / slices;
	    if (orientation == Outside) {
		sinCache3[i] = xyNormalRatio * sin(angle);
		cosCache3[i] = xyNormalRatio * cos(angle);
	    } else {
		sinCache3[i] = -xyNormalRatio * sin(angle);
		cosCache3[i] = -xyNormalRatio * cos(angle);
	    }
	}
    }

    sinCache[slices] = sinCache[0];
    cosCache[slices] = cosCache[0];
    if (needCache2) {
	sinCache2[slices] = sinCache2[0];
	cosCache2[slices] = cosCache2[0];
    }
    if (needCache3) {
	sinCache3[slices] = sinCache3[0];
	cosCache3[slices] = cosCache3[0];
    }

    switch (drawStyle) {
      case Fill:
	
	for (j = 0; j < stacks; j++) {
	    zLow = j * height / stacks;
	    zHigh = (j + 1) * height / stacks;
	    radiusLow = baseRadius - deltaRadius * ((float) j / stacks);
	    radiusHigh = baseRadius - deltaRadius * ((float) (j + 1) / stacks);

	    std::vector<Ogre::Vector3> positions;
int index=0;
std::vector<Ogre::Vector3> normalsCache;
Ogre::Vector3 currentNormal;
object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
if(colour.r>=0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		switch(normals) {
		  case Flat:
		    currentNormal=Ogre::Vector3(sinCache3[i], cosCache3[i], zNormal);
		    break;
		  case Smooth:
		    currentNormal=Ogre::Vector3(sinCache2[i], cosCache2[i], zNormal);
		    break;
		  case None:
		  default:
		    break;
		}
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				(float) j / stacks);
		    }
VTX(radiusLow,zLow);
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				(float) (j+1) / stacks);
		    }
VTX(radiusHigh,zHigh);
		} else {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				(float) (j+1) / stacks);
		    }
VTX(radiusHigh,zHigh);
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				(float) j / stacks);
		    }
VTX(radiusLow,zLow);
		}
	    }
	    object->end();
	}
	break;case Point:
	object->begin("",Ogre::RenderOperation::OT_POINT_LIST);
if(colour.r>=0.0f)object->colour(colour);
	for (i = 0; i < slices; i++) {
	    
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    for (j = 0; j <= stacks; j++) {
		zLow = j * height / stacks;
		radiusLow = baseRadius - deltaRadius * ((float) j / stacks);

		
		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, zLow + offset.z);
switch(normals) {
	      case Flat:
	      case Smooth:
		object->normal(sinCache2[i], cosCache2[i], zNormal);
		break;
	      case None:
	      default:
		break;
	    }
if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    (float) j / stacks);
		};
	    }
	}
	object->end();
	break;
      case Line:
	for (j = 1; j < stacks; j++) {
	    zLow = j * height / stacks;
	    radiusLow = baseRadius - deltaRadius * ((float) j / stacks);

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
if(colour.r>=0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, zLow + offset.z);
switch(normals) {
		  case Flat:
		    object->normal(sinCache3[i], cosCache3[i], zNormal);
		    break;
		  case Smooth:
		    object->normal(sinCache2[i], cosCache2[i], zNormal);
		    break;
		  case None:
		  default:
		    break;
		}
		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	
      case Silhouette:
	for (j = 0; j <= stacks; j += stacks) {
	    zLow = j * height / stacks;
	    radiusLow = baseRadius - deltaRadius * ((float) j / stacks);

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
if(colour.r>=0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, zLow + offset.z);
switch(normals) {
		  case Flat:
		    object->normal(sinCache3[i], cosCache3[i], zNormal);
		    break;
		  case Smooth:
		    object->normal(sinCache2[i], cosCache2[i], zNormal);
		    break;
		  case None:
		  default:
		    break;
		}
		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	for (i = 0; i < slices; i++) {
	    switch(normals) {
	      case Flat:
	      case Smooth:
		object->normal(sinCache2[i], cosCache2[i], 0.0);
		break;
	      case None:
	      default:
		break;
	    }
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
if(colour.r>=0.0f)object->colour(colour);
	    for (j = 0; j <= stacks; j++) {
		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, zLow + offset.z);
zLow = j * height / stacks;
		radiusLow = baseRadius - deltaRadius * ((float) j / stacks);

		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	break;
      default:
	break;
    }

return object;
}
#undef VTX

ManualObject* RbxAdornState::partialDisk(SceneManager*manager,const String&name,ManualObject*object,float innerRadius,float outerRadius,int slices,int loops,float startAngle,float sweepAngle){
if(!object)object=manager->createManualObject(name);
int index=0;

    int i,j;
    float sinCache[240];
    float cosCache[240];
    double angle;
    float sintemp, costemp;
    float deltaRadius;
    float radiusLow, radiusHigh;
    float texLow = 0.0f, texHigh = 0.0f;
    float angleOffset;
    int slices2;
    int finish;

    if (slices >= 240) slices = 240-1;
    if (slices < 2 || loops < 1 || outerRadius <= 0.0f || innerRadius < 0.0f ||
	    innerRadius > outerRadius) {
	
	return 0;
    }

    if (sweepAngle < -360.0f) sweepAngle = 360.0f;
    if (sweepAngle > 360.0f) sweepAngle = 360.0f;
    if (sweepAngle < 0) {
	startAngle += sweepAngle;
	sweepAngle = -sweepAngle;
    }

    if (sweepAngle == 360.0f) {
	slices2 = slices;
    } else {
	slices2 = slices + 1;
    }

    
    deltaRadius = outerRadius - innerRadius;

    

    angleOffset = startAngle / 180.0f * Ogre::Math::PI;
    for (i = 0; i <= slices; i++) {
	angle = angleOffset + double((Ogre::Math::PI * sweepAngle) / 180.0f) * i / slices;
	sinCache[i] = sin(angle);
	cosCache[i] = cos(angle);
    }

    if (sweepAngle == 360.0f) {
	sinCache[slices] = sinCache[0];
	cosCache[slices] = cosCache[0];
    }

    

    switch (drawStyle) {
      case Fill:
	if (innerRadius == 0.0f) {
	    finish = loops - 1;
	    
	    object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
index=0;
if(colour.r>=0.0f)object->colour(colour);
	    object->position(0.0f + offset.x, 0.0f + offset.y, 0.0f + offset.z);
object->index(index++);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

if (textureCoords) {
		object->textureCoord(0.5f, 0.5f);
	    }
	    radiusLow = outerRadius -
		    deltaRadius * ((float) (loops-1) / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    if (orientation == Outside) {
		for (i = slices; i >= 0; i--) {
		    object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
	    } else {
		for (i = 0; i <= slices; i++) {
		    object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
	    }
	    object->end();
	} else {
	    finish = loops;
	}
	for (j = 0; j < finish; j++) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    radiusHigh = outerRadius - deltaRadius * ((float) (j + 1) / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
		texHigh = radiusHigh / outerRadius / 2;
	    }

	    std::vector<Ogre::Vector3> positions;
object->begin("",Ogre::RenderOperation::OT_TRIANGLE_LIST);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

	    for (i = 0; i <= slices; i++) {
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}};

		    if (textureCoords) {
			object->textureCoord(texHigh * sinCache[i] + 0.5f,
				texHigh * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}};
		} else {
		    if (textureCoords) {
			object->textureCoord(texHigh * sinCache[i] + 0.5f,
				texHigh * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusHigh * sinCache[i] + offset.x, radiusHigh * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusHigh * sinCache[i], radiusHigh * cosCache[i], 0.0f));}};

		    if (textureCoords) {
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		    {int count=positions.size();
if(positions.size()>=2){if(count%2){object->position(positions[count-1]);object->index(index++);
object->position(positions[count-2]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}else{object->position(positions[count-2]);object->index(index++);
object->position(positions[count-1]);object->index(index++);
object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}}
else{positions.push_back(Ogre::Vector3(radiusLow * sinCache[i], radiusLow * cosCache[i], 0.0f));}};
		}
	    }
	    object->end();
	}
	break;case Point:
	object->begin("",Ogre::RenderOperation::OT_POINT_LIST);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

	for (i = 0; i < slices2; i++) {
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    for (j = 0; j <= loops; j++) {
		radiusLow = outerRadius - deltaRadius * ((float) j / loops);

		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    texLow = radiusLow / outerRadius / 2;

		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	}
	object->end();
	break;
      case Line:
	if (innerRadius == outerRadius) {
	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }


	    for (i = 0; i <= slices; i++) {
		object->position(innerRadius * sinCache[i] + offset.x, innerRadius * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(sinCache[i] / 2 + 0.5f,
			    cosCache[i] / 2 + 0.5f);
		}
	    }
	    object->end();
	    break;
	}
	for (j = 0; j <= loops; j++) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	}
	for (i=0; i < slices2; i++) {
	    sintemp = sinCache[i];
	    costemp = cosCache[i];
	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (j = 0; j <= loops; j++) {
		radiusLow = outerRadius - deltaRadius * ((float) j / loops);
		

		object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
texLow = radiusLow / outerRadius / 2;
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	}
	break;
      case Silhouette:
	if (sweepAngle < 360.0f) {
	    for (i = 0; i <= slices; i+= slices) {
		sintemp = sinCache[i];
		costemp = cosCache[i];
		object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);
switch(normals) {
      case Flat:
      case Smooth:
	if (orientation == Outside) {
	    object->normal(0.0f, 0.0f, 1.0);
	} else {
	    object->normal(0.0f, 0.0f, -1.0);
	}
	break;
      default:
      case None:
	break;
    }

		for (j = 0; j <= loops; j++) {
		    radiusLow = outerRadius - deltaRadius * ((float) j / loops);

		    object->position(radiusLow * sintemp + offset.x, radiusLow * costemp + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
			texLow = radiusLow / outerRadius / 2;
			object->textureCoord(texLow * sinCache[i] + 0.5f,
				texLow * cosCache[i] + 0.5f);
		    }
		}
		object->end();
	    }
	}
	for (j = 0; j <= loops; j += loops) {
	    radiusLow = outerRadius - deltaRadius * ((float) j / loops);
	    if (textureCoords) {
		texLow = radiusLow / outerRadius / 2;
	    }

	    object->begin("",Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r>=0.0f)object->colour(colour);

	    for (i = 0; i <= slices; i++) {
		object->position(radiusLow * sinCache[i] + offset.x, radiusLow * cosCache[i] + offset.y, 0.0f + offset.z);
object->index(index++);
if (textureCoords) {
		    object->textureCoord(texLow * sinCache[i] + 0.5f,
			    texLow * cosCache[i] + 0.5f);
		}
	    }
	    object->end();
	    if (innerRadius == outerRadius) break;
	}
	break;
      default:
	break;
    }

return object;
}

	ManualObject* RbxAdornState::disk(SceneManager* manager, const String& name, ManualObject* object,
	                                  float innerRadius, float outerRadius, int slices, int loops)
	{
		return partialDisk(manager, name, object, innerRadius, outerRadius, slices, loops, 0.0f, 360.0f);
	}

ManualObject* RbxAdornState::sphere(SceneManager* manager,const String& name,ManualObject* object,float radius,int slices,int stacks){
const Ogre::Vector3& off=offset;
if(!object)object=manager->createManualObject(name);
unsigned int index=0;

    int i,j;
    float sinCache1a[240];
    float cosCache1a[240];
    float sinCache2a[240];
    float cosCache2a[240];
    float sinCache3a[240];
    float cosCache3a[240];
    float sinCache1b[240];
    float cosCache1b[240];
    float sinCache2b[240];
    float cosCache2b[240];
    float sinCache3b[240];
    float cosCache3b[240];
    float angle;
    float zLow, zHigh;
    float sintemp1, sintemp2, sintemp3 = 0.0, sintemp4 = 0.0;
    float costemp1, costemp2 = 0.0, costemp3 = 0.0, costemp4 = 0.0;
    bool needCache2, needCache3;
    int start, finish;

    if (slices >= 240) slices = 240-1;
    if (stacks >= 240) stacks = 240-1;
    if (slices < 2 || stacks < 1 || radius < 0.0) {
	
	return 0;
    }

    
    
    
    needCache2 = needCache3 = false;

    if (normals == Smooth) {
	needCache2 = true;
    }

    if (normals == Flat) {
	if (drawStyle != Point) {
	    needCache3 = true;
	}
	if (drawStyle == Line) {
	    needCache2 = true;
	}
    }

    for (i = 0; i < slices; i++) {
	angle = 2 * Ogre::Math::PI * i / slices;
	sinCache1a[i] = sin(angle);
	cosCache1a[i] = cos(angle);
	if (needCache2) {
	    sinCache2a[i] = sinCache1a[i];
	    cosCache2a[i] = cosCache1a[i];
	}
    }

    for (j = 0; j <= stacks; j++) {
	angle = Ogre::Math::PI * j / stacks;
	if (needCache2) {
	    if (orientation == Outside) {
		sinCache2b[j] = sin(angle);
		cosCache2b[j] = cos(angle);
	    } else {
		sinCache2b[j] = -sin(angle);
		cosCache2b[j] = -cos(angle);
	    }
	}
	sinCache1b[j] = radius * sin(angle);
	cosCache1b[j] = radius * cos(angle);
    }
    
    sinCache1b[0] = 0;
    sinCache1b[stacks] = 0;

    if (needCache3) {
	for (i = 0; i < slices; i++) {
	    angle = 2 * Ogre::Math::PI * (i-0.5) / slices;
	    sinCache3a[i] = sin(angle);
	    cosCache3a[i] = cos(angle);
	}
	for (j = 0; j <= stacks; j++) {
	    angle = Ogre::Math::PI * (j - 0.5) / stacks;
	    if (orientation == Outside) {
		sinCache3b[j] = sin(angle);
		cosCache3b[j] = cos(angle);
	    } else {
		sinCache3b[j] = -sin(angle);
		cosCache3b[j] = -cos(angle);
	    }
	}
    }

    sinCache1a[slices] = sinCache1a[0];
    cosCache1a[slices] = cosCache1a[0];
    if (needCache2) {
	sinCache2a[slices] = sinCache2a[0];
	cosCache2a[slices] = cosCache2a[0];
    }
    if (needCache3) {
	sinCache3a[slices] = sinCache3a[0];
	cosCache3a[slices] = cosCache3a[0];
    }

    switch(drawStyle){case Fill:if (!textureCoords) {start=1;finish=stacks-1;
object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
if (colour.r >= 0.0f) object->colour(colour);
index=0;
object->position(0.0 + off.x, 0.0 + off.y, radius + off.z);
object->index(index++);
switch(normals) {
	      case Flat:
		sintemp3 = sinCache3b[1];
		costemp3 = cosCache3b[1];
		break;
	      case Smooth:
		sintemp3 = sinCache2b[1];
		costemp3 = cosCache2b[1];
		object->normal(sinCache2a[0] * sinCache2b[0],
			cosCache2a[0] * sinCache2b[0],
			cosCache2b[0]);
		break;
	      default:
		break;
	    }
sintemp2 = sinCache1b[1];
	    zHigh = cosCache1b[1];
	    
	    if (orientation == Outside) {
		for (i = slices; i >= 0; i--) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			if (i != slices) {
			    object->normal(sinCache3a[i+1] * sintemp3,
				    cosCache3a[i+1] * sintemp3,
				    costemp3);
			}
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    } else {
		for (i = 0; i <= slices; i++) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			object->normal(sinCache3a[i] * sintemp3,
				cosCache3a[i] * sintemp3,
				costemp3);
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    }
	    object->end();

	    
	    object->begin("", Ogre::RenderOperation::OT_TRIANGLE_FAN);
if (colour.r >= 0.0f) object->colour(colour);
index=0;
object->position(0.0 + off.x, 0.0 + off.y, -radius + off.z);
object->index(index++);


	    if (orientation == Outside) {sintemp2 = sinCache1b[stacks-1];
	    zHigh = cosCache1b[stacks-1];
	    switch(normals) {
	      case Flat:
		sintemp3 = sinCache3b[stacks];
		costemp3 = cosCache3b[stacks];
		break;
	      case Smooth:
		sintemp3 = sinCache2b[stacks-1];
		costemp3 = cosCache2b[stacks-1];
		object->normal(sinCache2a[stacks] * sinCache2b[stacks],
			cosCache2a[stacks] * sinCache2b[stacks],
			cosCache2b[stacks]);
		break;
	      default:
		break;
	    }
		for (i = 0; i <= slices; i++) {
		    object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			object->normal(sinCache3a[i] * sintemp3,
				cosCache3a[i] * sintemp3,
				costemp3);
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    } else {
		for (i = slices; i >= 0; i--) {
		    object->position(sinCache1b[1] * sinCache1a[i] + off.x, sinCache1b[1] * cosCache1a[i] + off.y, cosCache1b[1] + off.z);
object->index(index++);
switch(normals) {
		      case Smooth:
			object->normal(sinCache2a[i] * sintemp3,
				cosCache2a[i] * sintemp3,
				costemp3);
			break;
		      case Flat:
			if (i != slices) {
			    object->normal(sinCache3a[i+1] * sintemp3,
				    cosCache3a[i+1] * sintemp3,
				    costemp3);
			}
			break;
		      case None:
		      default:
			break;
		    }
		    
		}
	    }
	    object->end();
	} else {start=0;finish=stacks;}
for (j = start; j < finish; j++) {
	    zLow = cosCache1b[j];
	    zHigh = cosCache1b[j+1];
	    sintemp1 = sinCache1b[j];
	    sintemp2 = sinCache1b[j+1];
	    switch(normals) {
	      case Flat:
		sintemp4 = sinCache3b[j+1];
		costemp4 = cosCache3b[j+1];
		break;
	      case Smooth:
		if (orientation == Outside) {
		    sintemp3 = sinCache2b[j+1];
		    costemp3 = cosCache2b[j+1];
		    sintemp4 = sinCache2b[j];
		    costemp4 = cosCache2b[j];
		} else {
		    sintemp3 = sinCache2b[j];
		    costemp3 = cosCache2b[j];
		    sintemp4 = sinCache2b[j+1];
		    costemp4 = cosCache2b[j+1];
		}
		break;
	      default:
		break;
	    }

	    std::vector<Ogre::Vector3> positions;
std::vector<Ogre::Vector3> normalsCache;
Ogre::Vector3 currentNormal;
if(j==start){object->begin("", Ogre::RenderOperation::OT_TRIANGLE_LIST);index=0;}
if(colour.r >= 0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		switch(normals) {
		  case Smooth:
		    currentNormal = Ogre::Vector3(sinCache2a[i] * sintemp3, cosCache2a[i] * sintemp3, costemp3);
		    break;
		  case Flat:
		  case None:
		  default:
		    break;
		}
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) (j+1) / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));normalsCache.push_back(currentNormal);}};
		} else {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) j / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));normalsCache.push_back(currentNormal);}};
		}
		switch(normals) {
		  case Smooth:
		    currentNormal = Ogre::Vector3(sinCache2a[i] * sintemp4, cosCache2a[i] * sintemp4, costemp4);
		    break;
		  case Flat:
		    currentNormal = Ogre::Vector3(sinCache3a[i] * sintemp4, cosCache3a[i] * sintemp4, costemp4);
		    break;
		  case None:
		  default:
		    break;
		}
		if (orientation == Outside) {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) j / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, zLow + off.z));normalsCache.push_back(currentNormal);}};
		} else {
		    if (textureCoords) {
			object->textureCoord(1 - (float) i / slices,
				1 - (float) (j+1) / stacks);
		    }
		    {int count=positions.size();
if(positions.size()>=2){
if(count%2){object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}else{object->position(positions[count-2]);object->index(index++);object->normal(normalsCache[count-2]);
object->position(positions[count-1]);object->index(index++);object->normal(normalsCache[count-1]);
object->position(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z);
object->index(index++);
object->normal(currentNormal);
positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));
normalsCache.push_back(currentNormal);}
}else{positions.push_back(Ogre::Vector3(sintemp2 * sinCache1a[i] + off.x, sintemp2 * cosCache1a[i] + off.y, zHigh + off.z));normalsCache.push_back(currentNormal);}};
		}
	    }
	    if(j==finish-1)object->end();
	}
	break;case Point:
	object->begin("", Ogre::RenderOperation::OT_POINT_LIST);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	for (j = 0; j <= stacks; j++) {
	    sintemp1 = sinCache1b[j];
	    costemp1 = cosCache1b[j];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2b[j];
		costemp2 = cosCache2b[j];
		break;
	      default:
		break;
	    }
	    for (i = 0; i < slices; i++) {
		object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, costemp1 + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		  case Smooth:
		    object->normal(sinCache2a[i] * sintemp2,
			    cosCache2a[i] * sintemp2,
			    costemp2);
		    break;
		  case None:
		  default:
		    break;
		}

		zLow = j * radius / stacks;

		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	}
	object->end();
	break;
      case Line:
      case Silhouette:
	for (j = 1; j < stacks; j++) {
	    sintemp1 = sinCache1b[j];
	    costemp1 = cosCache1b[j];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2b[j];
		costemp2 = cosCache2b[j];
		break;
	      default:
		break;
	    }

	    object->begin("", Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	    for (i = 0; i <= slices; i++) {
		object->position(sintemp1 * sinCache1a[i] + off.x, sintemp1 * cosCache1a[i] + off.y, costemp1 + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		    object->normal(sinCache3a[i] * sintemp2,
			    cosCache3a[i] * sintemp2,
			    costemp2);
		    break;
		  case Smooth:
		    object->normal(sinCache2a[i] * sintemp2,
			    cosCache2a[i] * sintemp2,
			    costemp2);
		    break;
		  case None:
		  default:
		    break;
		}
		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	for (i = 0; i < slices; i++) {
	    sintemp1 = sinCache1a[i];
	    costemp1 = cosCache1a[i];
	    switch(normals) {
	      case Flat:
	      case Smooth:
		sintemp2 = sinCache2a[i];
		costemp2 = cosCache2a[i];
		break;
	      default:
		break;
	    }

	    object->begin("", Ogre::RenderOperation::OT_LINE_STRIP);
index=0;
if(colour.r >= 0.0f)object->colour(colour);
	    for (j = 0; j <= stacks; j++) {
		object->position(sintemp1 * sinCache1b[j] + off.x, costemp1 * sinCache1b[j] + off.y, cosCache1b[j] + off.z);
object->index(index++);
switch(normals) {
		  case Flat:
		    object->normal(sintemp2 * sinCache3b[j],
			    costemp2 * sinCache3b[j],
			    cosCache3b[j]);
		    break;
		  case Smooth:
		    object->normal(sintemp2 * sinCache2b[j],
			    costemp2 * sinCache2b[j],
			    cosCache2b[j]);
		    break;
		  case None:
		  default:
		    break;
		}

		if (textureCoords) {
		    object->textureCoord(1 - (float) i / slices,
			    1 - (float) j / stacks);
		}
		
	    }
	    object->end();
	}
	break;
      default:
	break;
    }

return object;
}
}
