// from server: 100% by EspClaude
// from server: 68% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view-dll roc_espclaude_f7a520dca9a7cb3a.cpp

// Candidate translation unit (score above; library headers required).
#include "BrickMesh.cpp"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
extern bool buildingShadowMesh;
extern const G3D::Vector2 flatTextureOrigin;
template<RBX::NormalId id>
static inline G3D::Vector3 faceHalf(const G3D::Vector3& size,float inset){
    const G3D::Vector3& mapped=RBX::uvwToObject<id>(size);
    return G3D::Vector3(fabs(mapped.x),fabs(mapped.y),fabs(mapped.z))-G3D::Vector3(inset,inset,0);
}
template<RBX::NormalId id>
void recoveredMeshFace(const G3D::Vector3& size,float inset,RBX::View::RenderSurfaceTypes surfacesT,float color,
                      G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level,unsigned* corners) {
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
            a=RBX::Render::Mesh::allocVertex(tp,tn,origin,true);
        }
        unsigned b;
        {
            Vector3 tn=RBX::uvwToObject<id>(n1);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(half.x,-half.y,half.z));
            b=RBX::Render::Mesh::allocVertex(tp,tn,origin,true);
        }
        unsigned c;
        {
            Vector3 tn=RBX::uvwToObject<id>(n2);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(half.x,half.y,half.z));
            c=RBX::Render::Mesh::allocVertex(tp,tn,origin,true);
        }
        unsigned d;
        {
            Vector3 tn=RBX::uvwToObject<id>(n3);
            Vector3 tp=RBX::uvwToObject<id>(Vector3(-half.x,half.y,half.z));
            d=RBX::Render::Mesh::allocVertex(tp,tn,origin,true);
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
            unsigned a=RBX::Render::Mesh::allocVertex(tp0,tn0,t0,true);
            Vector3 tn1=RBX::uvwToObject<id>(Vector3(nextNormal.x,normal.y,1));
            Vector3 tp1=RBX::uvwToObject<id>(Vector3(q.x,p.y,half.z));
            unsigned b=RBX::Render::Mesh::allocVertex(tp1,tn1,t1,true);
            Vector3 tn2=RBX::uvwToObject<id>(Vector3(nextNormal.x,nextNormal.y,1));
            Vector3 tp2=RBX::uvwToObject<id>(Vector3(q.x,q.y,half.z));
            unsigned c=RBX::Render::Mesh::allocVertex(tp2,tn2,t2,true);
            Vector3 tn3=RBX::uvwToObject<id>(Vector3(normal.x,nextNormal.y,1));
            Vector3 tp3=RBX::uvwToObject<id>(Vector3(p.x,q.y,half.z));
            unsigned d=RBX::Render::Mesh::allocVertex(tp3,tn3,t3,true);
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
template void recoveredMeshFace<RBX::NORM_X>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_X_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z_NEG>(const G3D::Vector3&,float,RBX::View::RenderSurfaceTypes,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);

using namespace G3D;
typedef RBX::Render::Mesh Mesh;
typedef ReferenceCountedPointer<Mesh::Level> LevelRef;
// 004dd2e0 initializes the native 40-byte Level. The older authentic header
// describes its first 28 bytes; byte 1c and words 20/24 are observed extra storage.
// Their original names/meaning are unknown. Constructor/destructor remain native.
class Level2008 : public Mesh::Level {
    bool state;
    int slot;
    unsigned count;
public:
    Level2008(RenderDevice::Primitive);
    virtual ~Level2008();
};
typedef char LevelSizeProof[sizeof(Level2008)==0x28?1:-1];
typedef RBX::View::RenderSurfaceTypes RenderSurfaceTypes;
extern float meshBevel;
extern Array<Vector3> meshPositions;
extern Array<Vector3> meshNormals;
extern void __stdcall cloneMeshQuad(LevelRef&,unsigned,unsigned,unsigned,unsigned,unsigned*);

// Plain 004e2c80 sibling: same faces, flat UVs on bevel joins.
class BrickMeshPlainRecovery:public Mesh {public:void populate(const Vector3&,RenderSurfaceTypes,RBX::BrickColor);};
void BrickMeshPlainRecovery::populate(const Vector3& size,RenderSurfaceTypes surfaces,RBX::BrickColor color) {
 LevelRef level=new Level2008(RenderDevice::QUADS);
 Mesh::Level* nativeLevel=level.getPointer();
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
  for(int i=0;i<24;++i)copies[i]=Mesh::allocVertex(meshPositions[face[i]],meshNormals[face[i]],uv,true);
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
  Mesh::allocVertex(copies[3],1);
  Mesh::allocVertex(copies[2],1);
  Mesh::allocVertex(copies[4],1);
  Mesh::allocVertex(copies[7],1);
  Mesh::allocVertex(copies[11],1);
  Mesh::allocVertex(copies[10],1);
  Mesh::allocVertex(copies[7],1);
  Mesh::allocVertex(copies[6],1);
  Mesh::allocVertex(copies[6],1);
  Mesh::allocVertex(copies[5],1);
  Mesh::allocVertex(copies[15],1);
  Mesh::allocVertex(copies[14],1);
  Mesh::allocVertex(copies[5],1);
  Mesh::allocVertex(copies[4],1);
  Mesh::allocVertex(copies[23],1);
  Mesh::allocVertex(copies[22],1);
  Mesh::allocVertex(copies[10],1);
  Mesh::allocVertex(copies[9],1);
  Mesh::allocVertex(copies[0],1);
  Mesh::allocVertex(copies[3],1);
  Mesh::allocVertex(copies[2],1);
  Mesh::allocVertex(copies[1],1);
  Mesh::allocVertex(copies[20],1);
  Mesh::allocVertex(copies[23],1);
  Mesh::allocVertex(copies[12],1);
  Mesh::allocVertex(copies[15],1);
  Mesh::allocVertex(copies[22],1);
  Mesh::allocVertex(copies[21],1);
  Mesh::allocVertex(copies[14],1);
  Mesh::allocVertex(copies[13],1);
  Mesh::allocVertex(copies[8],1);
  Mesh::allocVertex(copies[11],1);
  Mesh::allocVertex(copies[17],1);
  Mesh::allocVertex(copies[16],1);
  Mesh::allocVertex(copies[21],1);
  Mesh::allocVertex(copies[20],1);
  Mesh::allocVertex(copies[13],1);
  Mesh::allocVertex(copies[12],1);
  Mesh::allocVertex(copies[16],1);
  Mesh::allocVertex(copies[19],1);
  Mesh::allocVertex(copies[9],1);
  Mesh::allocVertex(copies[8],1);
  Mesh::allocVertex(copies[19],1);
  Mesh::allocVertex(copies[18],1);
  Mesh::allocVertex(copies[1],1);
  Mesh::allocVertex(copies[0],1);
  Mesh::allocVertex(copies[18],1);
  Mesh::allocVertex(copies[17],1);
  Mesh::allocVertex(copies[7],1);
  Mesh::allocVertex(copies[10],1);
  Mesh::allocVertex(copies[3],1);
  Mesh::allocVertex(copies[3],1);
  Mesh::allocVertex(copies[4],1);
  Mesh::allocVertex(copies[2],1);
  Mesh::allocVertex(copies[23],1);
  Mesh::allocVertex(copies[23],1);
  Mesh::allocVertex(copies[5],1);
  Mesh::allocVertex(copies[22],1);
  Mesh::allocVertex(copies[15],1);
  Mesh::allocVertex(copies[15],1);
  Mesh::allocVertex(copies[11],1);
  Mesh::allocVertex(copies[6],1);
  Mesh::allocVertex(copies[14],1);
  Mesh::allocVertex(copies[14],1);
  Mesh::allocVertex(copies[16],1);
  Mesh::allocVertex(copies[12],1);
  Mesh::allocVertex(copies[21],1);
  Mesh::allocVertex(copies[21],1);
  Mesh::allocVertex(copies[13],1);
  Mesh::allocVertex(copies[19],1);
  Mesh::allocVertex(copies[8],1);
  Mesh::allocVertex(copies[8],1);
  Mesh::allocVertex(copies[0],1);
  Mesh::allocVertex(copies[9],1);
  Mesh::allocVertex(copies[18],1);
  Mesh::allocVertex(copies[18],1);
  Mesh::allocVertex(copies[17],1);
  Mesh::allocVertex(copies[20],1);
  Mesh::allocVertex(copies[1],1);
  Mesh::allocVertex(copies[1],1);
  for(int i=0;i<24;++i)Mesh::allocVertex(copies[i],static_cast<unsigned>(-1));
 done:;
}
