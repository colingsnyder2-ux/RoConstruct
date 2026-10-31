// Producer body: existing 004e2c80 / roc_espclaude_f7a520dca9a7cb3a.cpp.
// Retargeted declarations only: measured Level and native parallel vertex bank.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerBlockMesh.h"
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstddef>

namespace PlayerBlockMesh {
using namespace G3D;
typedef RBX::View::RenderSurfaceTypes RenderSurfaceTypes;
typedef char LevelSize[sizeof(Level)==0x28?1:-1];
typedef char LevelIndices[offsetof(Level,indexArray)==0x0c?1:-1];
typedef char LevelPrimitive[offsetof(Level,primitive)==0x18?1:-1];
typedef char LevelDirty[offsetof(Level,dirty)==0x1c?1:-1];
typedef char LevelSharedIndex[offsetof(Level,sharedIndex)==0x20?1:-1];
typedef char LevelBackend[offsetof(Level,backend)==0x24?1:-1];
typedef char NativeArray[sizeof(Array<Vector3>)==12?1:-1];
typedef char ShadowSize[sizeof(ShadowSurface)==0x34?1:-1];
typedef char ShadowNormals[offsetof(ShadowSurface,faceNormals)==0x0c?1:-1];
typedef char ShadowFaces[offsetof(ShadowSurface,faces)==0x18?1:-1];
typedef char ShadowGeometry[offsetof(ShadowSurface,geometry)==0x24?1:-1];
typedef char ShadowDrop[offsetof(ShadowSurface,dropShadow)==0x30?1:-1];
typedef char MeshSize[sizeof(Mesh)==0x88?1:-1];
typedef char MeshLevels[offsetof(Mesh,levels)==0x0c?1:-1];
typedef char MeshShadow[offsetof(Mesh,shadow)==0x18?1:-1];
typedef char MeshRadius[offsetof(Mesh,debugBoundingRadius)==0x4c?1:-1];
typedef char MeshIndices[offsetof(Mesh,shadowIndices)==0x50?1:-1];
typedef char MeshVertices[offsetof(Mesh,shadowVertices)==0x68?1:-1];
typedef char MeshBackend[offsetof(Mesh,shadowBackend)==0x80?1:-1];
typedef char MeshKind[offsetof(Mesh,geometryKind)==0x84?1:-1];
typedef char BrickMeshSize[sizeof(BlockMesh)==0x88?1:-1];
namespace {
Array<Vector3> meshPositions,meshNormals,meshTangents;
Array<Vector2> meshUVs;
Array<int> referenceCounts;
Array<unsigned> freeSlots;
int references;
unsigned levelsAlive,builds;
bool bankInitialized;
bool buildingShadowMesh=false;
float meshBevel=0.0f; // Initial flat/no-bevel path, not the separate bevel LOD.
// Original initialized data at 009413c4/c8, read by 004de360.
const Vector2 flatTextureOrigin(0.015625f,0.8888888955116272f);
void initializeBank() { // 00547f60: reserve slot zero.
    if(bankInitialized)return;
    meshPositions.resize(1);meshNormals.resize(1);meshTangents.resize(1);meshUVs.resize(1);
    referenceCounts.resize(1);referenceCounts[0]=1;freeSlots.clear();bankInitialized=true;
}
unsigned allocate(const Vector3& position,const Vector3& normal,const Vector2& uv,bool) { // 00548000
    unsigned index;
    if(freeSlots.size()==0) {
        index=meshPositions.size();meshPositions.append(position);meshNormals.append(normal);
        meshUVs.append(uv);meshTangents.append(Vector3::zero());referenceCounts.append(1);
    } else {
        index=freeSlots.pop(false);meshPositions[index]=position;meshNormals[index]=normal;
        meshUVs[index]=uv;meshTangents[index]=Vector3::zero();referenceCounts[index]=1;
    }
    ++references;return index;
}
unsigned addReferences(unsigned index,unsigned amount) { // 00547fc0
    referenceCounts[index]+=amount;references+=amount;return index;
}
void release(unsigned index) { // 00548640
    --references;
    if(referenceCounts[index]==1){referenceCounts[index]=0;freeSlots.append(index);}
    else --referenceCounts[index];
}
}
unsigned activeReferences(){return references;}
unsigned liveLevels(){return levelsAlive;}
unsigned producerCalls(){return builds;}
Level::Level(RenderDevice::Primitive p):primitive(p),dirty(true),sharedIndex(-1),backend(0){++levelsAlive;}
Level::~Level(){
    for(int i=0;i<indexArray.size();++i)release(indexArray[i]);
    if(backend)PlayerMeshBackend::destroyIndexed(backend);
    --levelsAlive;
}
Mesh::Mesh():debugBoundingRadius(0),shadowBackend(0),geometryKind(0){initializeBank();}
Mesh::~Mesh(){ // 00548a90: shadow backend first, then member/Level destruction.
    if(shadowBackend)PlayerMeshBackend::destroyIndexed(shadowBackend);
}
BlockMesh::BlockMesh(const Vector3& size,RBX::View::RenderSurfaceTypes surfaces,RBX::BrickColor color){
    geometryKind=1;populate(size,surfaces,color);++builds;
}
template<RBX::NormalId id>
static inline G3D::Vector3 faceHalf(const G3D::Vector3& size,float inset){
    const G3D::Vector3& mapped=RBX::uvwToObject<id>(size);
    return G3D::Vector3(fabs(mapped.x),fabs(mapped.y),fabs(mapped.z))-G3D::Vector3(inset,inset,0);
}
template<RBX::NormalId id>
void recoveredMeshFace(const G3D::Vector3& size,float inset,RBX::View::RenderSurfaceTypes surfacesT,float color,
                      LevelRef& level,unsigned* corners) {
    using namespace G3D;
    unsigned surfaces=surfacesT.data;
    unsigned surface=(surfaces>>(3*id))&7;
    Vector3 half=faceHalf<id>(size,inset);
    Vector2 step(0,0),origin(0,0);
    switch(surface) {
    case 0: origin=flatTextureOrigin;step=half.xy()*2.0f;break;
    case 1: step=Vector2(2,4);break;
    case 2: step=Vector2(2,4);origin.y=1.0f/3.0f;break;
    case 3: step=Vector2(2,2);origin.y=2.0f/3.0f;break;
    case 4: step=Vector2(2,2);origin.y=5.0f/6.0f;break;
    }
    origin.x+=color*(1.0f/32.0f);
    static Vector2 first(0,0);
    static Vector2 last(0,0);
    Vector2 faceFirst,faceLast;
    if(!buildingShadowMesh) {
        faceFirst.x=rand()*(0.1f/32767)-0.05f;
        faceFirst.y=rand()*(0.1f/32767)-0.05f;
        faceLast.x=rand()*(1.0f/32767)>0.5f?faceFirst.x:-faceFirst.x;
        faceLast.y=rand()*(1.0f/32767)>0.5f?faceFirst.y:-faceFirst.y;
        first=faceFirst;last=faceLast;
    } else {
        faceFirst=first;faceLast=last;
    }
    if(surface==0) {
        Vector3 n0(faceFirst.x,faceFirst.y,1),n3(faceFirst.x,faceLast.y,1),n1(faceLast.x,faceFirst.y,1),n2(faceLast.x,faceLast.y,1);
        unsigned a;
        {
            Vector3 tn=RBX::uvwToObject<id>(n0);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(-half.x,-half.y,half.z));
            a=allocate(tp,tn,origin,true);
        }
        unsigned b;
        {
            Vector3 tn=RBX::uvwToObject<id>(n1);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(half.x,-half.y,half.z));
            b=allocate(tp,tn,origin,true);
        }
        unsigned c;
        {
            Vector3 tn=RBX::uvwToObject<id>(n2);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(half.x,half.y,half.z));
            c=allocate(tp,tn,origin,true);
        }
        unsigned d;
        {
            Vector3 tn=RBX::uvwToObject<id>(n3);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(-half.x,half.y,half.z));
            d=allocate(tp,tn,origin,true);
        }
        level->indexArray.append(a,b,c,d);
        corners[0]=a;corners[1]=b;corners[2]=c;corners[3]=d;
        return;
    }
    Vector2 p;
    p.x=-half.x;
    Vector2 delta=(faceLast-faceFirst)*0.5f/half.xy();
    unsigned rows=0;
    Vector2 normal;
    normal.x=faceFirst.x;
    static std::vector<int> indices;
    indices.erase(indices.begin(),indices.end());
    unsigned columns;
    for(;p.x<half.x;++rows) {
        Vector2 q;
        q.x=std::min(p.x+step.x,half.x);
        columns=0;
        Vector2 nextNormal;
        nextNormal.x=normal.x+delta.x;
        p.y=-half.y;
        normal.y=faceFirst.y;
        for(;p.y<half.y;++columns) {
            q.y=std::min(p.y+step.y,half.y);
            nextNormal.y=normal.y+delta.y;
            Vector2 t0(origin.x+1.0f/1024.0f,origin.y+(q.y-p.y)*(1.0f/12.0f));
            Vector2 t1(origin.x-1.0f/1024.0f+(q.x-p.x)*(1.0f/64.0f),origin.y+(q.y-p.y)*(1.0f/12.0f));
            Vector2 t2(origin.x-1.0f/1024.0f+(q.x-p.x)*(1.0f/64.0f),origin.y);
            Vector2 t3(origin.x+1.0f/1024.0f,origin.y);
            Vector3 tn0=RBX::uvwToObject<id>(Vector3(normal.x,normal.y,1));
            Vector3 tp0=RBX::uvwToObject<id>(Vector3(p.x,p.y,half.z));
            unsigned a=allocate(tp0,tn0,t0,true);
            Vector3 tn1=RBX::uvwToObject<id>(Vector3(nextNormal.x,normal.y,1));
            Vector3 tp1=RBX::uvwToObject<id>(Vector3(q.x,p.y,half.z));
            unsigned b=allocate(tp1,tn1,t1,true);
            Vector3 tn2=RBX::uvwToObject<id>(Vector3(nextNormal.x,nextNormal.y,1));
            Vector3 tp2=RBX::uvwToObject<id>(Vector3(q.x,q.y,half.z));
            unsigned c=allocate(tp2,tn2,t2,true);
            Vector3 tn3=RBX::uvwToObject<id>(Vector3(normal.x,nextNormal.y,1));
            Vector3 tp3=RBX::uvwToObject<id>(Vector3(p.x,q.y,half.z));
            unsigned d=allocate(tp3,tn3,t3,true);
            indices.push_back(a);indices.push_back(b);indices.push_back(c);indices.push_back(d);
            level->indexArray.append(a,b,c,d);
            p.y=q.y;normal.y=nextNormal.y;
        }
        p.x=q.x;normal.x=nextNormal.x;
    }
    corners[0]=indices[0];
    corners[1]=indices[(rows-1)*columns*4+1];
    corners[2]=indices[rows*columns*4-2];
    corners[3]=indices[columns*4-1];
}
template void recoveredMeshFace<RBX::NORM_X>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);
template void recoveredMeshFace<RBX::NORM_X_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,LevelRef&,unsigned*);

void BlockMesh::populate(const Vector3& size,RenderSurfaceTypes surfaces,RBX::BrickColor color) {
 LevelRef level=new Level(RenderDevice::QUADS);
 Level* nativeLevel=level.getPointer();
 levels.append(level);
 Vector3 half=size*0.5f;
 float palette=static_cast<float>(color.getClosestPaletteIndex());
 unsigned face[24];
 recoveredMeshFace<RBX::NORM_X>(half,meshBevel,surfaces,palette,level,face);
 recoveredMeshFace<RBX::NORM_Y>(half,meshBevel,surfaces,palette,level,face+4);
 recoveredMeshFace<RBX::NORM_Z>(half,meshBevel,surfaces,palette,level,face+8);
 recoveredMeshFace<RBX::NORM_X_NEG>(half,meshBevel,surfaces,palette,level,face+12);
 recoveredMeshFace<RBX::NORM_Y_NEG>(half,meshBevel,surfaces,palette,level,face+16);
 recoveredMeshFace<RBX::NORM_Z_NEG>(half,meshBevel,surfaces,palette,level,face+20);
 if(!(meshBevel>0)) goto done;
  Vector2 uv;
  uv.y=flatTextureOrigin.y;
  uv.x=palette*(1.0f/32.0f)+flatTextureOrigin.x;
  unsigned copies[24];
  for(int i=0;i<24;++i)copies[i]=allocate(meshPositions[face[i]],meshNormals[face[i]],uv,true);
  nativeLevel->indexArray.append(copies[3],copies[2],copies[4],copies[7]);
  nativeLevel->indexArray.append(copies[11],copies[10],copies[7],copies[6]);
  nativeLevel->indexArray.append(copies[6],copies[5],copies[15],copies[14]);
  nativeLevel->indexArray.append(copies[5],copies[4],copies[23],copies[22]);
  nativeLevel->indexArray.append(copies[10],copies[9],copies[0],copies[3]);
  nativeLevel->indexArray.append(copies[2],copies[1],copies[20],copies[23]);
  nativeLevel->indexArray.append(copies[12],copies[15],copies[22],copies[21]);
  nativeLevel->indexArray.append(copies[14],copies[13],copies[8],copies[11]);
  nativeLevel->indexArray.append(copies[17],copies[16],copies[21],copies[20]);
  nativeLevel->indexArray.append(copies[13],copies[12],copies[16],copies[19]);
  nativeLevel->indexArray.append(copies[9],copies[8],copies[19],copies[18]);
  nativeLevel->indexArray.append(copies[1],copies[0],copies[18],copies[17]);
  nativeLevel->indexArray.append(copies[7],copies[10],copies[3],copies[3]);
  nativeLevel->indexArray.append(copies[4],copies[2],copies[23],copies[23]);
  nativeLevel->indexArray.append(copies[5],copies[22],copies[15],copies[15]);
  nativeLevel->indexArray.append(copies[11],copies[6],copies[14],copies[14]);
  nativeLevel->indexArray.append(copies[16],copies[12],copies[21],copies[21]);
  nativeLevel->indexArray.append(copies[13],copies[19],copies[8],copies[8]);
  nativeLevel->indexArray.append(copies[0],copies[9],copies[18],copies[18]);
  nativeLevel->indexArray.append(copies[17],copies[20],copies[1],copies[1]);
  addReferences(copies[3],1);
  addReferences(copies[2],1);
  addReferences(copies[4],1);
  addReferences(copies[7],1);
  addReferences(copies[11],1);
  addReferences(copies[10],1);
  addReferences(copies[7],1);
  addReferences(copies[6],1);
  addReferences(copies[6],1);
  addReferences(copies[5],1);
  addReferences(copies[15],1);
  addReferences(copies[14],1);
  addReferences(copies[5],1);
  addReferences(copies[4],1);
  addReferences(copies[23],1);
  addReferences(copies[22],1);
  addReferences(copies[10],1);
  addReferences(copies[9],1);
  addReferences(copies[0],1);
  addReferences(copies[3],1);
  addReferences(copies[2],1);
  addReferences(copies[1],1);
  addReferences(copies[20],1);
  addReferences(copies[23],1);
  addReferences(copies[12],1);
  addReferences(copies[15],1);
  addReferences(copies[22],1);
  addReferences(copies[21],1);
  addReferences(copies[14],1);
  addReferences(copies[13],1);
  addReferences(copies[8],1);
  addReferences(copies[11],1);
  addReferences(copies[17],1);
  addReferences(copies[16],1);
  addReferences(copies[21],1);
  addReferences(copies[20],1);
  addReferences(copies[13],1);
  addReferences(copies[12],1);
  addReferences(copies[16],1);
  addReferences(copies[19],1);
  addReferences(copies[9],1);
  addReferences(copies[8],1);
  addReferences(copies[19],1);
  addReferences(copies[18],1);
  addReferences(copies[1],1);
  addReferences(copies[0],1);
  addReferences(copies[18],1);
  addReferences(copies[17],1);
  addReferences(copies[7],1);
  addReferences(copies[10],1);
  addReferences(copies[3],1);
  addReferences(copies[3],1);
  addReferences(copies[4],1);
  addReferences(copies[2],1);
  addReferences(copies[23],1);
  addReferences(copies[23],1);
  addReferences(copies[5],1);
  addReferences(copies[22],1);
  addReferences(copies[15],1);
  addReferences(copies[15],1);
  addReferences(copies[11],1);
  addReferences(copies[6],1);
  addReferences(copies[14],1);
  addReferences(copies[14],1);
  addReferences(copies[16],1);
  addReferences(copies[12],1);
  addReferences(copies[21],1);
  addReferences(copies[21],1);
  addReferences(copies[13],1);
  addReferences(copies[19],1);
  addReferences(copies[8],1);
  addReferences(copies[8],1);
  addReferences(copies[0],1);
  addReferences(copies[9],1);
  addReferences(copies[18],1);
  addReferences(copies[18],1);
  addReferences(copies[17],1);
  addReferences(copies[20],1);
  addReferences(copies[1],1);
  addReferences(copies[1],1);
  for(int i=0;i<24;++i)addReferences(copies[i],static_cast<unsigned>(-1));
 done:;
}


// Existing 00549a50 upload body; only typed receiver/backend bindings changed.
void Level::upload(bool indices32,Ogre::AxisAlignedBox& bounds){
    if(backend){bounds=backend->bounds;return;}
    const G3D::Array<unsigned>& vertexIndices = indexArray;
    std::vector<unsigned> indices3286;
    std::vector<unsigned short> ind16;
    std::vector<float> verts;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::map<unsigned, unsigned> vmap;
    unsigned c = 0;
    for (int k = 0; k < vertexIndices.size(); ++k) {
        if (vmap.find(vertexIndices[k]) == vmap.end()) {
            vmap[vertexIndices[k]] = c;
            ++c;
        }
    }
    std::vector<unsigned> unique(vmap.size());
    for (int k = 0; k < vertexIndices.size(); ++k)
        unique[vmap[vertexIndices[k]]] = vertexIndices[k];

    int k;
    if (indices32) {
        if (static_cast<int>(primitive) == 5) {
            indices3286.resize(vertexIndices.size() / 4 * 6);
            for (k = 0; k < vertexIndices.size(); k += 4) {
                int quad = k / 4;
                indices3286[quad*6] = vmap[vertexIndices[quad*4]];
                indices3286[quad*6+1] = vmap[vertexIndices[quad*4+1]];
                indices3286[quad*6+2] = vmap[vertexIndices[quad*4+3]];
                indices3286[quad*6+3] = vmap[vertexIndices[quad*4+3]];
                indices3286[quad*6+4] = vmap[vertexIndices[quad*4+1]];
                indices3286[quad*6+5] = vmap[vertexIndices[quad*4+2]];
            }
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = meshPositions[unique[k]][j];
                    normals[k*3+j] = meshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = meshUVs[unique[k]][j];
            }
        } else if (static_cast<int>(primitive) == 2) {
            indices3286.resize(vertexIndices.size());
            for (k = 0; k < vertexIndices.size(); ++k)
                indices3286[k] = vmap[vertexIndices[k]];
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = meshPositions[unique[k]][j];
                    normals[k*3+j] = meshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = meshUVs[unique[k]][j];
            }
        }
    } else {
        if (static_cast<int>(primitive) == 5) {
            ind16.resize(vertexIndices.size() / 4 * 6);
            for (k = 0; k < vertexIndices.size(); k += 4) {
                int quad = k / 4;
                ind16[quad*6] = vmap[vertexIndices[quad*4]];
                ind16[quad*6+1] = vmap[vertexIndices[quad*4+1]];
                ind16[quad*6+2] = vmap[vertexIndices[quad*4+3]];
                ind16[quad*6+3] = vmap[vertexIndices[quad*4+3]];
                ind16[quad*6+4] = vmap[vertexIndices[quad*4+1]];
                ind16[quad*6+5] = vmap[vertexIndices[quad*4+2]];
            }
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = meshPositions[unique[k]][j];
                    normals[k*3+j] = meshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = meshUVs[unique[k]][j];
            }
        } else if (static_cast<int>(primitive) == 2) {
            ind16.resize(vertexIndices.size());
            for (k = 0; k < vertexIndices.size(); ++k)
                ind16[k] = vmap[vertexIndices[k]];
            verts.resize(unique.size() * 3);
            normals.resize(unique.size() * 3);
            texCoords.resize(unique.size() * 2);
            for (k = 0; k < static_cast<int>(unique.size()); ++k) {
                int j;
                for (j = 0; j < 3; ++j) {
                    verts[k*3+j] = meshPositions[unique[k]][j];
                    normals[k*3+j] = meshNormals[unique[k]][j];
                }
                for (j = 0; j < 2; ++j)
                    texCoords[k*2+j] = meshUVs[unique[k]][j];
            }
        }
    }
    Ogre::Vector3 min, max;
    backend = PlayerMeshBackend::createIndexed(
        &verts[0], unique.size(), &normals[0], 0, &texCoords[0],
        indices32 ? 0 : &ind16[0],
        indices32 ? &indices3286[0] : 0,
        indices32 ? indices3286.size()/3 : ind16.size()/3,
        min, max);
    bounds.setMinimum(min.x, min.y, min.z);
    bounds.setMaximum(max.x, max.y, max.z);
    dirty = false;
}
}
