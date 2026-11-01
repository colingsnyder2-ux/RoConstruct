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
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <G3D/Table.h>
#include <G3D/Vector2int16.h>
#include <G3D/Vector3int16.h>
#include <exception>
#include "util/MeshId.h"

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
float meshBevel=0.0f;
bool useBevels=true; // Original initialized byte 009413c0.
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

namespace {
// 00500d80/00500d30 and six native face instantiations. Genuine members from
// QuadVolume.h; LevelRef is retargeted to the measured shared native bank.
class SphereLevelBuilder {
public:
    enum Purpose { Surface,Decal,Shadow };
    const Vector3 halfSize;
    const RenderSurfaceTypes surfaceTypes;
    const LevelRef level;
    Vector2 textureScale;
    SphereLevelBuilder(LevelRef& value,Vector3 size,RenderSurfaceTypes surfaces):
        halfSize(size*.5f),surfaceTypes(surfaces),level(value),textureScale(2,2){}
    virtual void build(Purpose purpose){
        buildTop(purpose);buildBottom(purpose);buildLeft(purpose);
        buildRight(purpose);buildFront(purpose);buildBack(purpose);
    }
    virtual void buildTop(Purpose)=0;
    virtual void buildBottom(Purpose)=0;
    virtual void buildLeft(Purpose)=0;
    virtual void buildRight(Purpose)=0;
    virtual void buildFront(Purpose)=0;
    virtual void buildBack(Purpose)=0;

    typedef void (*Function)(Vector3&,Vector3&,Vector2&,const Vector3&,const Vector2int16&);
    template<RBX::NormalId id,class Deformation>
    void emit(Deformation function,Vector2 minimum,Vector2 maximum,float depth,
        Vector2 origin,Vector2 extent,int axis,Vector2int16 divisions){
        Vector3 mapped=RBX::uvwToObject<id>(halfSize);
        Vector3 radius(fabs(mapped.x),fabs(mapped.y),fabs(mapped.z));
        Vector2 positionStep=(maximum-minimum)/Vector2(divisions.x,divisions.y);
        Vector2 textureStep=extent/Vector2(divisions.x,divisions.y);
        unsigned count=(divisions.x+1)*(divisions.y+1);
        unsigned* vertices=new unsigned[count];
        float x=minimum.x,u=origin.x;
        for(int i=0;i<=divisions.x;++i){
            float y=minimum.y,v=origin.y;
            for(int j=0;j<=divisions.y;++j){
                Vector3 position(x,y,depth),normal(0,0,1);
                Vector2 texture;texture[1-axis]=u;texture[axis]=v;
                function(position,normal,texture,radius,Vector2int16(i,j));
                if(extent==Vector2::zero())texture=origin; // 00509ba0 zero vector.
                vertices[i*(divisions.y+1)+j]=allocate(RBX::uvwToObject<id>(position),
                    RBX::uvwToObject<id>(normal),texture*.5f,true); // 00819bac.
                y+=positionStep.y;v+=textureStep.y;
            }
            x+=positionStep.x;u+=textureStep.x;
        }
        for(int i=0;i<divisions.x;++i)for(int j=0;j<divisions.y;++j){
            int index=(divisions.y+1)*i+j,next=index+divisions.y;
            unsigned a=vertices[index+1],b=vertices[index],c=vertices[next+1],d=vertices[next+2];
            // 00500eb0 QUADS branch retains each appended bank index.
            level->indexArray.append(addReferences(a,1),addReferences(b,1),addReferences(c,1),addReferences(d,1));
        }
        for(unsigned i=0;i<count;++i)release(vertices[i]);
        delete[] vertices;
    }
    template<RBX::NormalId id,class Deformation>
    void buildFace(Deformation function,Vector2int16 grid,Purpose purpose){
        unsigned surface=(surfaceTypes.data>>(3*id))&7;
        Vector3 mapped=RBX::uvwToObject<id>(halfSize);
        Vector3 size(fabs(mapped.x),fabs(mapped.y),fabs(mapped.z));
        int axis=!(purpose==Surface && size.x<size.y);
        int steps=purpose==Surface && surface ? G3D::iRound(static_cast<float>(ceil(size[axis]*.5))):1;
        Vector2int16 divisions;
        short n=grid[1-axis];
        divisions[axis]=std::max<short>(1,static_cast<short>(n/steps));divisions[1-axis]=n;
        Vector2 begin=-size.xy(),end=size.xy(),origin,extent;
        switch(purpose){
        case Surface:
            if(!surface){origin=Vector2(.25f,.5f);extent=Vector2::zero();}
            else{
                origin[1-axis]=0;origin[axis]=surface==RBX::View::INLET?.5f:surface==RBX::View::WELD?1:surface==RBX::View::GLUE?1.5f:0;
                extent[1-axis]=size[1-axis]*2;extent[axis]=.5f;
                if(axis==1)extent.x=-extent.x;
            }
            break;
        case Decal:origin=Vector2(0,textureScale.y);extent=Vector2(textureScale.x,-textureScale.y);break;
        case Shadow:origin=extent=Vector2::zero();break;
        }
        for(int i=0;i<steps;++i){
            if(i==steps-1){end[axis]=size[axis];if(purpose==Surface && surface)extent[axis]=(end[axis]-begin[axis])*extent[axis]*.25f;}
            else end[axis]=begin[axis]+4;
            emit<id>(function,begin,end,size.z,origin,extent,axis,divisions);
            begin[axis]=end[axis];
        }
    }
};
// 004fabb0: preserve target normal before component radius scaling.
void sphereTransform(Vector3& vertex,Vector3& normal,Vector2&,const Vector3& radius,const Vector2int16&){
    float inverseLength=1.0f/static_cast<float>(sqrt(vertex.x*vertex.x+vertex.y*vertex.y+vertex.z*vertex.z));
    normal=vertex*inverseLength;vertex=normal*radius;
}
class SphereBuilder : public SphereLevelBuilder {
public:
    const int elements;
    SphereBuilder(LevelRef& level,Vector3 size,RenderSurfaceTypes surfaces):SphereLevelBuilder(level,size,surfaces),elements(6){}
    void buildTop(Purpose p){buildFace<RBX::NORM_Y>(sphereTransform,Vector2int16(elements,elements),p);}
    void buildBottom(Purpose p){buildFace<RBX::NORM_Y_NEG>(sphereTransform,Vector2int16(elements,elements),p);}
    void buildLeft(Purpose p){buildFace<RBX::NORM_X_NEG>(sphereTransform,Vector2int16(elements,elements),p);}
    void buildRight(Purpose p){buildFace<RBX::NORM_X>(sphereTransform,Vector2int16(elements,elements),p);}
    void buildFront(Purpose p){buildFace<RBX::NORM_Z_NEG>(sphereTransform,Vector2int16(elements,elements),p);}
    void buildBack(Purpose p){buildFace<RBX::NORM_Z>(sphereTransform,Vector2int16(elements,elements),p);}
};
// 004f2030 and 004f2110..004f35cf: per-face normal perturbation.
struct PBBFace {
    Vector2 perturbation;
    bool bulge[2];
    PBBFace(){
        perturbation.x=-.05f+.1f*rand()*(1.0f/32767.0f);
        perturbation.y=-.05f+.1f*rand()*(1.0f/32767.0f);
        bulge[0]=rand()*(1.0f/32767.0f)>.5f;
        bulge[1]=rand()*(1.0f/32767.0f)>.5f;
    }
    void operator()(Vector3& vertex,Vector3& normal,Vector2&,const Vector3& size,const Vector2int16&) const {
        for(int k=0;k<2;++k)normal[k]=bulge[k]?vertex[k]/size[k]*perturbation[k]:perturbation[k];
    }
};
// The face and side inset global at 00826e38 is zero in the original image.
class PBBBuilder : public SphereLevelBuilder {
public:
    Vector3int16 strips;
    PBBBuilder(LevelRef& level,Vector3 size,RenderSurfaceTypes surfaces):SphereLevelBuilder(level,size,surfaces){
        strips.x=std::max<int>(1,static_cast<int>(size.x/6.0f));
        strips.y=std::max<int>(1,static_cast<int>(size.y/6.0f));
        strips.z=std::max<int>(1,static_cast<int>(size.z/6.0f));
        strips.x=std::min<int>(4,strips.x);strips.y=std::min<int>(4,strips.y);strips.z=std::min<int>(4,strips.z);
    }
    void buildTop(Purpose p){buildFace<RBX::NORM_Y>(PBBFace(),Vector2int16(1,1),p);}
    void buildBottom(Purpose p){buildFace<RBX::NORM_Y_NEG>(PBBFace(),Vector2int16(1,1),p);}
    void buildLeft(Purpose p){buildFace<RBX::NORM_X_NEG>(PBBFace(),Vector2int16(1,1),p);}
    void buildRight(Purpose p){buildFace<RBX::NORM_X>(PBBFace(),Vector2int16(1,1),p);}
    void buildFront(Purpose p){buildFace<RBX::NORM_Z_NEG>(PBBFace(),Vector2int16(1,1),p);}
    void buildBack(Purpose p){buildFace<RBX::NORM_Z>(PBBFace(),Vector2int16(1,1),p);}
};
// 004fd4a0 and 004fd530: native cylinder endcap and side callbacks.
void cylinderEndcap(Vector3& vertex,Vector3&,Vector2&,const Vector3&,const Vector2int16&){
    float dominant=std::max(static_cast<float>(fabs(vertex.x)),static_cast<float>(fabs(vertex.y)));
    float scale=dominant==0?0:dominant/static_cast<float>(sqrt(vertex.x*vertex.x+vertex.y*vertex.y));
    vertex.x*=scale;vertex.y*=scale;
}
void cylinderSide(Vector3& vertex,Vector3& normal,Vector2&,const Vector3& radius,const Vector2int16&){
    float inverseLength=1.0f/static_cast<float>(sqrt(vertex.y*vertex.y+vertex.z*vertex.z));
    float y=vertex.y*inverseLength,z=vertex.z*inverseLength;
    vertex.y=radius.x*y;vertex.z=radius.y*z;normal=Vector3(0,y,z);
}
class CylinderBuilder : public SphereLevelBuilder {
public:
    const size_t elements;
    CylinderBuilder(LevelRef& level,Vector3 size,RenderSurfaceTypes surfaces,size_t slices):
        SphereLevelBuilder(level,size,surfaces),elements(std::max<size_t>(slices/4,1)){}
    void buildTop(Purpose p){buildFace<RBX::NORM_Y>(cylinderSide,Vector2int16(elements,1),p);}
    void buildBottom(Purpose p){buildFace<RBX::NORM_Y_NEG>(cylinderSide,Vector2int16(elements,1),p);}
    void buildLeft(Purpose p){buildFace<RBX::NORM_X_NEG>(cylinderEndcap,Vector2int16(elements,elements),p);}
    void buildRight(Purpose p){buildFace<RBX::NORM_X>(cylinderEndcap,Vector2int16(elements,elements),p);}
    void buildFront(Purpose p){buildFace<RBX::NORM_Z_NEG>(cylinderSide,Vector2int16(elements,1),p);}
    void buildBack(Purpose p){buildFace<RBX::NORM_Z>(cylinderSide,Vector2int16(elements,1),p);}
};
typedef char NativeBuilderSize[sizeof(SphereLevelBuilder)==0x20?1:-1];
typedef char NativeBuilderHalf[offsetof(SphereLevelBuilder,halfSize)==4?1:-1];
typedef char NativeBuilderSurfaces[offsetof(SphereLevelBuilder,surfaceTypes)==0x10?1:-1];
typedef char NativeBuilderLevel[offsetof(SphereLevelBuilder,level)==0x14?1:-1];
typedef char NativeBuilderTexture[offsetof(SphereLevelBuilder,textureScale)==0x18?1:-1];
typedef char NativeSphereBuilder[sizeof(SphereBuilder)==0x24?1:-1];
typedef char NativeSphereElements[offsetof(SphereBuilder,elements)==0x20?1:-1];
typedef char NativePBBFace[sizeof(PBBFace)==12?1:-1];
typedef char NativePBBBuilder[sizeof(PBBBuilder)==0x28?1:-1];
typedef char NativePBBStrips[offsetof(PBBBuilder,strips)==0x20?1:-1];
typedef char NativeCylinderBuilder[sizeof(CylinderBuilder)==0x24?1:-1];
typedef char NativeCylinderElements[offsetof(CylinderBuilder,elements)==0x20?1:-1];

struct SphereVariations { MeshRef meshes[1]; };
// Genuine unused decal/texture key members from MeshFactory.h. These paths are
// not implemented or credited here; their maps remain empty for ordinary balls.
struct SphereDecalKey { Vector3 size;RBX::NormalId face;bool operator<(const SphereDecalKey&)const; };
struct SphereTextureKey : SphereDecalKey { Vector2 studsPerTile;bool operator<(const SphereTextureKey&)const; };
typedef G3D::Table<Vector3,SphereVariations> SphereSizes;
// RenderSurfaceTypes is one unsigned key with identity hash/equality in target.
typedef G3D::Table<unsigned,SphereSizes> SphereSurfaces;
struct SphereCache {
    SphereSurfaces cache1;
    boost::recursive_mutex mutex;
    std::map<SphereDecalKey,MeshRef> decalCache;
    std::map<SphereTextureKey,MeshRef> textureCache;
    int count;
    SphereCache():count(0){}
};
typedef char NativeSphereSize[sizeof(SphereMesh)==0x8c?1:-1];
typedef char NativeSphereCache[sizeof(SphereCache)==0x60?1:-1];
typedef char NativeSphereMutex[offsetof(SphereCache,mutex)==0x10?1:-1];
typedef char NativeSphereCounter[offsetof(SphereCache,count)==0x5c?1:-1];
SphereCache* sphereCache;
boost::once_flag sphereOnce=BOOST_ONCE_INIT;
void initializeSphereCache(){sphereCache=new SphereCache;} // 004d97b0; persistent singleton.
SphereCache* cylinderCache;
boost::once_flag cylinderOnce=BOOST_ONCE_INIT;
void initializeCylinderCache(){cylinderCache=new SphereCache;}
typedef char NativeCylinderMesh[sizeof(CylinderMesh)==0x8c?1:-1];
struct PBBVariations { MeshRef meshes[4]; };
typedef G3D::Table<Vector3,PBBVariations> PBBSizes;
typedef G3D::Table<unsigned,PBBSizes> PBBSurfaces;
struct PBBCache {
    PBBSurfaces cache1;
    boost::recursive_mutex mutex;
    std::map<SphereDecalKey,MeshRef> decalCache;
    std::map<SphereTextureKey,MeshRef> textureCache;
    int count;
    PBBCache():count(0){}
};
typedef char NativePBBMesh[sizeof(PBBMesh)==0x8c?1:-1];
typedef char NativePBBCache[sizeof(PBBCache)==0x60?1:-1];
PBBCache* pbbCache;
boost::once_flag pbbOnce=BOOST_ONCE_INIT;
void initializePBBCache(){pbbCache=new PBBCache;}
}

SphereMesh::SphereMesh(const Vector3& size,RenderSurfaceTypes surfaces){
    geometryKind=2;levels.push_back(new Level(RenderDevice::QUADS));
    SphereBuilder builder(levels.last(),size,surfaces);builder.build(SphereLevelBuilder::Surface);
}
// 004f4cb0 surface branch; factory, shadow and scene dispatch remain separate.
PBBMesh::PBBMesh(const Vector3& size,RenderSurfaceTypes surfaces){
    levels.push_back(new Level(RenderDevice::QUADS));
    PBBBuilder builder(levels.last(),size,surfaces);builder.build(SphereLevelBuilder::Surface);
}
// 004fd6b0: twelve slices, native QUADS level and geometry kind 3.
CylinderMesh::CylinderMesh(const Vector3& size,RenderSurfaceTypes surfaces){
    geometryKind=3;levels.push_back(new Level(RenderDevice::QUADS));
    CylinderBuilder builder(levels.last(),size,surfaces,12);builder.build(SphereLevelBuilder::Surface);
}
// 004eef30: one cached cylinder variation per size/surface key.
template<> CylinderMesh* MeshFactory<CylinderMesh,1>::create(const Vector3& size,RenderSurfaceTypes surfaces){
    boost::call_once(initializeCylinderCache,cylinderOnce);
    boost::recursive_mutex::scoped_lock lock(cylinderCache->mutex);
    if(!cylinderCache->cache1.containsKey(surfaces.data))cylinderCache->cache1.set(surfaces.data,SphereSizes());
    SphereSizes& sizes=cylinderCache->cache1.get(surfaces.data);
    if(!sizes.containsKey(size))sizes.set(size,SphereVariations());
    SphereVariations& variation=sizes.get(size);
    CylinderMesh* mesh=static_cast<CylinderMesh*>(variation.meshes[0].getPointer());
    if(!mesh){
        mesh=new CylinderMesh(size,surfaces);variation.meshes[0]=mesh;
        if(++cylinderCache->count%100==0){MeshRef keep=variation.meshes[0];PlayerBlockMesh::flushUnused();}
    }
    return mesh;
}
template<> void MeshFactory<CylinderMesh,1>::flushUnused(){
    boost::call_once(initializeCylinderCache,cylinderOnce);
    boost::recursive_mutex::scoped_lock lock(cylinderCache->mutex);
    for(SphereSurfaces::Iterator i=cylinderCache->cache1.begin();i!=cylinderCache->cache1.end();++i)
        for(SphereSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            if(j->value.meshes[0].notNull() && j->value.meshes[0].isLastReference())j->value.meshes[0]=MeshRef();
}
template<> unsigned MeshFactory<CylinderMesh,1>::cachedMeshes(){
    boost::call_once(initializeCylinderCache,cylinderOnce);
    boost::recursive_mutex::scoped_lock lock(cylinderCache->mutex);
    unsigned count=0;
    for(SphereSurfaces::Iterator i=cylinderCache->cache1.begin();i!=cylinderCache->cache1.end();++i)
        for(SphereSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            if(j->value.meshes[0].notNull())++count;
    return count;
}
// 004edb20: four independently generated variations for each size/surface key.
template<> PBBMesh* MeshFactory<PBBMesh,4>::create(const Vector3& size,RenderSurfaceTypes surfaces){
    boost::call_once(initializePBBCache,pbbOnce);
    boost::recursive_mutex::scoped_lock lock(pbbCache->mutex);
    if(!pbbCache->cache1.containsKey(surfaces.data))pbbCache->cache1.set(surfaces.data,PBBSizes());
    PBBSizes& sizes=pbbCache->cache1.get(surfaces.data);
    if(!sizes.containsKey(size))sizes.set(size,PBBVariations());
    PBBVariations& variation=sizes.get(size);
    int index=G3D::iRandom(0,3);
    PBBMesh* mesh=static_cast<PBBMesh*>(variation.meshes[index].getPointer());
    if(!mesh){
        mesh=new PBBMesh(size,surfaces);variation.meshes[index]=mesh;
        if(++pbbCache->count%100==0){MeshRef keep=variation.meshes[index];PlayerBlockMesh::flushUnused();}
    }
    return mesh;
}
template<> void MeshFactory<PBBMesh,4>::flushUnused(){
    boost::call_once(initializePBBCache,pbbOnce);
    boost::recursive_mutex::scoped_lock lock(pbbCache->mutex);
    for(PBBSurfaces::Iterator i=pbbCache->cache1.begin();i!=pbbCache->cache1.end();++i)
        for(PBBSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            for(int k=0;k<4;++k)
                if(j->value.meshes[k].notNull() && j->value.meshes[k].isLastReference())j->value.meshes[k]=MeshRef();
}
template<> unsigned MeshFactory<PBBMesh,4>::cachedMeshes(){
    boost::call_once(initializePBBCache,pbbOnce);
    boost::recursive_mutex::scoped_lock lock(pbbCache->mutex);
    unsigned count=0;
    for(PBBSurfaces::Iterator i=pbbCache->cache1.begin();i!=pbbCache->cache1.end();++i)
        for(PBBSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            for(int k=0;k<4;++k)if(j->value.meshes[k].notNull())++count;
    return count;
}
template<> SphereMesh* MeshFactory<SphereMesh,1>::create(const Vector3& size,RenderSurfaceTypes surfaces){
    boost::call_once(initializeSphereCache,sphereOnce);
    boost::recursive_mutex::scoped_lock lock(sphereCache->mutex);
    if(!sphereCache->cache1.containsKey(surfaces.data))sphereCache->cache1.set(surfaces.data,SphereSizes());
    SphereSizes& sizes=sphereCache->cache1.get(surfaces.data);
    if(!sizes.containsKey(size))sizes.set(size,SphereVariations());
    SphereVariations& variation=sizes.get(size);
    SphereMesh* mesh=static_cast<SphereMesh*>(variation.meshes[0].getPointer());
    if(!mesh){
        mesh=new SphereMesh(size,surfaces);variation.meshes[0]=mesh;
        if(++sphereCache->count%100==0){MeshRef keep=variation.meshes[0];flushUnused();}
    }
    return mesh;
}
template<> void MeshFactory<SphereMesh,1>::flushUnused(){
    boost::call_once(initializeSphereCache,sphereOnce);
    boost::recursive_mutex::scoped_lock lock(sphereCache->mutex);
    for(SphereSurfaces::Iterator i=sphereCache->cache1.begin();i!=sphereCache->cache1.end();++i)
        for(SphereSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            if(j->value.meshes[0].notNull() && j->value.meshes[0].isLastReference())j->value.meshes[0]=MeshRef();
}
template<> unsigned MeshFactory<SphereMesh,1>::cachedMeshes(){
    boost::call_once(initializeSphereCache,sphereOnce);
    boost::recursive_mutex::scoped_lock lock(sphereCache->mutex);
    unsigned count=0;
    for(SphereSurfaces::Iterator i=sphereCache->cache1.begin();i!=sphereCache->cache1.end();++i)
        for(SphereSizes::Iterator j=i->value.begin();j!=i->value.end();++j)
            if(j->value.meshes[0].notNull())++count;
    return count;
}
unsigned activeReferences(){return references;}
// Existing00500b90/00500780 bodies with genuine Mesh/Level/bank types.
// Local provider's bool-ready API bridges the native Succeeded status1.
typedef char NativeFileMeshSize[sizeof(FileMesh)==0x88?1:-1];
MeshRef FileMesh::create(RBX::ContentProvider* provider,const Vector3& scale,RBX::MeshId id){
    FileMesh* value=new FileMesh;
    MeshRef mesh=value;
    return value->loadFromMeshFile(provider,scale,id)?mesh:MeshRef();
}
bool FileMesh::loadFromMeshFile(RBX::ContentProvider* provider,const Vector3& scale,RBX::MeshId id){
    try{
        std::string filename;
        if(!provider->requestContentFile(id,filename))return false;
        LevelRef level=new Level(RenderDevice::TRIANGLES);levels.append(level);
        std::vector<unsigned> vertices;
        FILE* file=fopen(filename.c_str(),"r");
        if(!file)return false; // File may disappear after provider resolution.
        fscanf(file,"version 1.00\n");
        int faces;fscanf(file,"%d\n",&faces);
        for(int i=0;i<faces;++i){
            for(int j=0;j<3;++j){
                float x,y,z,nx,ny,nz,u,v,w;
                fscanf(file,"[%f,%f,%f][%f,%f,%f][%f,%f,%f]",&x,&y,&z,&nx,&ny,&nz,&u,&v,&w);
                Vector3 vertex=Vector3(x,y,z)*.5f;
                Vector3 normal=Vector3(nx,ny,nz).direction();
                vertices.push_back(allocate(vertex*scale,normal,Vector2(u,1-v),true));
            }
            level->indexArray.append(addReferences(vertices[0],1),addReferences(vertices[1],1),addReferences(vertices[2],1));
            for(int j=0;j<3;++j)release(vertices[j]);
            vertices.clear();
        }
        fclose(file);
        std::printf("file mesh loaded: id=%s path=%s faces=%d indices=%d\n",id.c_str(),filename.c_str(),faces,level->indexArray.size());
        return true;
    }catch(std::exception&){return false;}
}
unsigned liveLevels(){return levelsAlive;}
unsigned producerCalls(){return builds;}
Level::Level(RenderDevice::Primitive p):primitive(p),dirty(true),sharedIndex(-1),backend(0){++levelsAlive;}
Level::~Level(){
    for(int i=0;i<indexArray.size();++i)release(indexArray[i]);
    if(backend){
        PlayerSphereCache::Key key=reinterpret_cast<PlayerSphereCache::Key>(backend);
        PlayerMeshBackend::destroyIndexed(backend);
        PlayerSphereCache::remove(key); // 005486e0 ->00682150 after backend deletion.
    }
    --levelsAlive;
}
Mesh::Mesh():debugBoundingRadius(0),shadowBackend(0),geometryKind(0){initializeBank();}
Mesh::~Mesh(){ // 00548a90: shadow backend first, then member/Level destruction.
    if(shadowBackend)PlayerMeshBackend::destroyIndexed(shadowBackend);
}
BlockMesh::BlockMesh(const Vector3& size,RBX::View::RenderSurfaceTypes surfaces,RBX::BrickColor color){
    geometryKind=1;populate(size,surfaces,color);
}

namespace {
// Existing Lookup comparator: roc_espclaude_ccb4c01f44e452a8.cpp.
struct Lookup {
    Vector3 size;
    RenderSurfaceTypes surfaces;
    RBX::BrickColor color;
    bool operator<(const Lookup& other) const {
        for(int i=0;i<3;++i){
            if(size[i]<other.size[i])return true;
            if(size[i]>other.size[i])return false;
        }
        if(surfaces.data<other.surfaces.data)return true;
        if(surfaces.data>other.surfaces.data)return false;
        return color.number<other.color.number;
    }
};
struct Variations {
    int count;
    MeshRef meshes[4];
    Variations():count(0){}
};
struct Cache {
    std::map<Lookup,Variations> entries;
    boost::recursive_mutex mutex;
    int count;
    Cache():count(0){}
};
typedef char LookupSize[sizeof(Lookup)==0x14?1:-1];
typedef char VariationsSize[sizeof(Variations)==0x14?1:-1];
typedef char CacheSize[sizeof(Cache)==0x30?1:-1];
typedef char CacheMutex[offsetof(Cache,mutex)==0x20?1:-1];
typedef char CacheCount[offsetof(Cache,count)==0x2c?1:-1];
Cache* cache;
boost::once_flag cacheOnce=BOOST_ONCE_INIT;
void closeCache(){delete cache;}
void initializeCache(){cache=new Cache;std::atexit(closeCache);}
}

// Existing 004e58b0 body; 004e5a40 calls populate again, not the alternate
// 004e3720 producer. Typed Mesh/Level replace the mining unit's padded base.
MeshRef BlockMesh::create(const Vector3& size,RenderSurfaceTypes surfaces,RBX::BrickColor color){
    Lookup lookup={size,surfaces,color};
    boost::call_once(initializeCache,cacheOnce);
    Cache* c=cache;
    boost::recursive_mutex::scoped_lock lock(c->mutex);
    Variations& variation=c->entries[lookup];
    size_t index=variation.count==4 ? G3D::iRandom(0,3) : std::min(3,G3D::iRandom(0,8));
    MeshRef mesh=variation.meshes[index];
    if(mesh.isNull()){
        buildingShadowMesh=false;
        if(useBevels){
            meshBevel=0.065f;
            mesh=new BlockMesh(size,surfaces,color);
            meshBevel=0;
            buildingShadowMesh=true;
            static_cast<BlockMesh*>(mesh.getPointer())->populate(size,surfaces,color);
            buildingShadowMesh=false;
        }else{
            meshBevel=0;
            mesh=new BlockMesh(size,surfaces,color);
        }
        variation.meshes[index]=mesh;
        ++variation.count;
        if(++c->count%100==0){
            MeshRef keep=variation.meshes[index];
            flushUnused();
        }
    }
    return mesh;
}

// 004e5710 drops cache-only references without erasing keys or resetting count.
void flushUnused(){
    SphereMesh::flushUnused();
    PBBMesh::flushUnused();
    CylinderMesh::flushUnused();
    boost::call_once(initializeCache,cacheOnce);
    boost::recursive_mutex::scoped_lock lock(cache->mutex);
    for(std::map<Lookup,Variations>::iterator it=cache->entries.begin();it!=cache->entries.end();++it)
        for(int i=0;i<4;++i)
            if(it->second.meshes[i].notNull() && it->second.meshes[i].isLastReference())
                it->second.meshes[i]=MeshRef();
}
unsigned cachedMeshes(){
    if(!cache)return SphereMesh::cachedMeshes()+PBBMesh::cachedMeshes()+CylinderMesh::cachedMeshes();
    boost::recursive_mutex::scoped_lock lock(cache->mutex);
    unsigned count=0;
    for(std::map<Lookup,Variations>::iterator it=cache->entries.begin();it!=cache->entries.end();++it)
        for(int i=0;i<4;++i)if(it->second.meshes[i].notNull())++count;
    return count+SphereMesh::cachedMeshes()+PBBMesh::cachedMeshes()+CylinderMesh::cachedMeshes();
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
 ++builds;
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
