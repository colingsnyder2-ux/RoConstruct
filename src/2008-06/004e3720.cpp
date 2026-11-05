// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view-dll roc_espclaude_2b8ffc226453802c.cpp

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

#include <G3D/Vector4.h>
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
extern Array<Vector2> meshTextures;
static __forceinline void atlasFace(unsigned* corners,const Vector4* rectangles,const unsigned* atlasIndices,const unsigned* flagArray,int side,float margin) {
    const Vector4& rectangle=rectangles[atlasIndices[side]];
    const unsigned& flags=flagArray[side];
    Vector2 border(rectangle.z*6.0f,rectangle.w*6.0f);
    border*=margin;
    Vector2 a,b,c,d;
    a=Vector2(rectangle.x+border.x,rectangle.y+border.y);
    b=Vector2(rectangle.x+rectangle.z-border.x,rectangle.y+border.y);
    c=Vector2(rectangle.x+rectangle.z-border.x,rectangle.y+rectangle.w-border.y);
    d=Vector2(rectangle.x+border.x,rectangle.y+rectangle.w-border.y);
    if(flags&1) {std::swap(a,b);std::swap(c,d);}
    if(flags&2) {std::swap(a,d);std::swap(b,c);}
    if(flags&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    unsigned i0=corners[0],i1=corners[1],i2=corners[2],i3=corners[3];
    meshTextures[i0]=a;
    meshTextures[i1]=b;
    meshTextures[i2]=c;
    meshTextures[i3]=d;
}
#define ATLAS(C,S) { Vector2 border,a,b,c,d; \
    border=Vector2(rectangles[atlasIndices[S]].z*6.0f,rectangles[atlasIndices[S]].w*6.0f); \
    border*=margin; \
    a=Vector2(rectangles[atlasIndices[S]].x+border.x,rectangles[atlasIndices[S]].y+border.y); \
    b=Vector2(rectangles[atlasIndices[S]].x+rectangles[atlasIndices[S]].z-border.x,rectangles[atlasIndices[S]].y+border.y); \
    c=Vector2(rectangles[atlasIndices[S]].x+rectangles[atlasIndices[S]].z-border.x,rectangles[atlasIndices[S]].y+rectangles[atlasIndices[S]].w-border.y); \
    d=Vector2(rectangles[atlasIndices[S]].x+border.x,rectangles[atlasIndices[S]].y+rectangles[atlasIndices[S]].w-border.y); \
    if(flags[S]&1) {std::swap(a,b);std::swap(c,d);} \
    if(flags[S]&2) {std::swap(a,d);std::swap(b,c);} \
    if(flags[S]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;} \
    meshTextures[(C)[0]]=a; \
    meshTextures[(C)[1]]=b; \
    meshTextures[(C)[2]]=c; \
    meshTextures[(C)[3]]=d; }
static __forceinline void extendTexture(unsigned destination,unsigned base,unsigned other,float margin) {
    Vector2 direction=meshTextures[base]-meshTextures[other];
    direction.unitize(1e-6f);
    float extent=margin*(2.0f/3.0f);
    meshTextures[destination]=meshTextures[base]+Vector2(direction.x*extent,direction.y*extent);
}
class BrickMeshRecovery {
public:
    void populate(const Vector3&,RenderSurfaceTypes,RBX::BrickColor,const unsigned*,const Vector4*,const unsigned*,float);
    template<class T> T& field(unsigned offset) {return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);}
    void cloneMeshQuad(LevelRef& level,unsigned a,unsigned b,unsigned c,unsigned d,unsigned* out);
};
__declspec(noinline) void BrickMeshRecovery::cloneMeshQuad(LevelRef& level,unsigned a,unsigned b,unsigned c,unsigned d,unsigned* out) {
 out[0]=Mesh::allocVertex(meshPositions[a],meshNormals[a],meshTextures[a],true);
 out[1]=Mesh::allocVertex(meshPositions[b],meshNormals[b],meshTextures[b],true);
 out[2]=Mesh::allocVertex(meshPositions[c],meshNormals[c],meshTextures[c],true);
 out[3]=Mesh::allocVertex(meshPositions[d],meshNormals[d],meshTextures[d],true);
 unsigned q0=out[0],q1=out[1],q2=out[2],q3=out[3];
 level->indexArray.append(q0,q1,q2,q3);
}
void BrickMeshRecovery::populate(const Vector3& size,RenderSurfaceTypes surfaces,RBX::BrickColor color,
                               const unsigned* atlasIndices,const Vector4* rectangles,const unsigned* flags,float margin) {
    LevelRef level=new Level2008(RenderDevice::QUADS);
    field<Array<LevelRef> >(0xc).append(level);
    Vector3 half=size*0.5f;
    float palette=static_cast<float>(color.getClosestPaletteIndex());
    unsigned quads[16];
    unsigned face[24];
    recoveredMeshFace<RBX::NORM_X>(half,meshBevel,surfaces,palette,level,face);
    {
    Vector2 border(rectangles[atlasIndices[3]].z*6.0f,rectangles[atlasIndices[3]].w*6.0f); border*=margin; const float& by=border.y;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[3]].x+border.x,rectangles[atlasIndices[3]].y+by);
    b=Vector2(rectangles[atlasIndices[3]].x+rectangles[atlasIndices[3]].z-border.x,rectangles[atlasIndices[3]].y+by);
    c=Vector2(rectangles[atlasIndices[3]].x+rectangles[atlasIndices[3]].z-border.x,rectangles[atlasIndices[3]].y+rectangles[atlasIndices[3]].w-by);
    d=Vector2(rectangles[atlasIndices[3]].x+border.x,rectangles[atlasIndices[3]].y+rectangles[atlasIndices[3]].w-by);
    if(flags[3]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[3]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[3]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face)[0]]=a;
    meshTextures[(face)[1]]=b;
    meshTextures[(face)[2]]=c;
    meshTextures[(face)[3]]=d;
    }
    recoveredMeshFace<RBX::NORM_Y>(half,meshBevel,surfaces,palette,level,face+4);
    {
    Vector2 border(rectangles[atlasIndices[4]].z*6.0f,rectangles[atlasIndices[4]].w*6.0f); border*=margin; const float& bx=border.x; const float& by=border.y;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[4]].x+bx,rectangles[atlasIndices[4]].y+by);
    b=Vector2(rectangles[atlasIndices[4]].x+rectangles[atlasIndices[4]].z-bx,rectangles[atlasIndices[4]].y+by);
    c=Vector2(rectangles[atlasIndices[4]].x+rectangles[atlasIndices[4]].z-bx,rectangles[atlasIndices[4]].y+rectangles[atlasIndices[4]].w-by);
    d=Vector2(rectangles[atlasIndices[4]].x+bx,rectangles[atlasIndices[4]].y+rectangles[atlasIndices[4]].w-by);
    if(flags[4]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[4]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[4]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face+4)[0]]=a;
    meshTextures[(face+4)[1]]=b;
    meshTextures[(face+4)[2]]=c;
    meshTextures[(face+4)[3]]=d;
    }
    recoveredMeshFace<RBX::NORM_Z>(half,meshBevel,surfaces,palette,level,face+8);
    {
    Vector2 border(rectangles[atlasIndices[0]].z*6.0f,rectangles[atlasIndices[0]].w*6.0f); border*=margin; const float& by=border.y;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[0]].x+border.x,rectangles[atlasIndices[0]].y+by);
    b=Vector2(rectangles[atlasIndices[0]].x+rectangles[atlasIndices[0]].z-border.x,rectangles[atlasIndices[0]].y+by);
    c=Vector2(rectangles[atlasIndices[0]].x+rectangles[atlasIndices[0]].z-border.x,rectangles[atlasIndices[0]].y+rectangles[atlasIndices[0]].w-by);
    d=Vector2(rectangles[atlasIndices[0]].x+border.x,rectangles[atlasIndices[0]].y+rectangles[atlasIndices[0]].w-by);
    if(flags[0]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[0]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[0]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face+8)[0]]=a;
    meshTextures[(face+8)[1]]=b;
    meshTextures[(face+8)[2]]=c;
    meshTextures[(face+8)[3]]=d;
    }
    recoveredMeshFace<RBX::NORM_X_NEG>(half,meshBevel,surfaces,palette,level,face+12);
    {const Vector4* rectangles_Cy=rectangles;const Vector4* rectangles_h=rectangles;
    Vector2 border(rectangles_h[atlasIndices[2]].z*6.0f,rectangles_h[atlasIndices[2]].w*6.0f); border*=margin; const float& bx=border.x; const float& by=border.y;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[2]].x+bx,rectangles_Cy[atlasIndices[2]].y+by);
    b=Vector2(rectangles[atlasIndices[2]].x+rectangles[atlasIndices[2]].z-bx,rectangles_Cy[atlasIndices[2]].y+by);
    c=Vector2(rectangles[atlasIndices[2]].x+rectangles[atlasIndices[2]].z-bx,rectangles_Cy[atlasIndices[2]].y+rectangles[atlasIndices[2]].w-by);
    d=Vector2(rectangles[atlasIndices[2]].x+bx,rectangles_Cy[atlasIndices[2]].y+rectangles[atlasIndices[2]].w-by);
    if(flags[2]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[2]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[2]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face+12)[0]]=a;
    meshTextures[(face+12)[1]]=b;
    meshTextures[(face+12)[2]]=c;
    meshTextures[(face+12)[3]]=d;
    }
    recoveredMeshFace<RBX::NORM_Y_NEG>(half,meshBevel,surfaces,palette,level,face+16);
    {const Vector4* rectangles_h=rectangles;
    Vector2 border(rectangles_h[atlasIndices[5]].z*6.0f,rectangles_h[atlasIndices[5]].w*6.0f); border*=margin;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[5]].x+border.x,rectangles[atlasIndices[5]].y+border.y);
    b=Vector2(rectangles[atlasIndices[5]].x+rectangles[atlasIndices[5]].z-border.x,rectangles[atlasIndices[5]].y+border.y);
    c=Vector2(rectangles[atlasIndices[5]].x+rectangles[atlasIndices[5]].z-border.x,rectangles[atlasIndices[5]].y+rectangles[atlasIndices[5]].w-border.y);
    d=Vector2(rectangles[atlasIndices[5]].x+border.x,rectangles[atlasIndices[5]].y+rectangles[atlasIndices[5]].w-border.y);
    if(flags[5]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[5]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[5]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face+16)[0]]=a;
    meshTextures[(face+16)[1]]=b;
    meshTextures[(face+16)[2]]=c;
    meshTextures[(face+16)[3]]=d;
    }
    recoveredMeshFace<RBX::NORM_Z_NEG>(half,meshBevel,surfaces,palette,level,face+20);
    {
    Vector2 border(rectangles[atlasIndices[1]].z*6.0f,rectangles[atlasIndices[1]].w*6.0f); border*=margin; const float& by=border.y;
    Vector2 a,b,c,d;
    a=Vector2(rectangles[atlasIndices[1]].x+border.x,rectangles[atlasIndices[1]].y+by);
    b=Vector2(rectangles[atlasIndices[1]].x+rectangles[atlasIndices[1]].z-border.x,rectangles[atlasIndices[1]].y+by);
    c=Vector2(rectangles[atlasIndices[1]].x+rectangles[atlasIndices[1]].z-border.x,rectangles[atlasIndices[1]].y+rectangles[atlasIndices[1]].w-by);
    d=Vector2(rectangles[atlasIndices[1]].x+border.x,rectangles[atlasIndices[1]].y+rectangles[atlasIndices[1]].w-by);
    if(flags[1]&1) {std::swap(a,b);std::swap(c,d);}
    if(flags[1]&2) {std::swap(a,d);std::swap(b,c);}
    if(flags[1]&4) {Vector2 t=a;a=b;b=c;c=d;d=t;}
    meshTextures[(face+20)[0]]=a;
    meshTextures[(face+20)[1]]=b;
    meshTextures[(face+20)[2]]=c;
    meshTextures[(face+20)[3]]=d;
    }
    if(meshBevel>0) {
        unsigned copies[24];
        for(int i=0;i<24;++i)
            copies[i]=Mesh::allocVertex(meshPositions[face[i]],meshNormals[face[i]],meshTextures[face[i]],true);
        // UV extrapolation and join topology follow the native geometry API trace.
        extendTexture(copies[3],copies[7],copies[6],margin);
        extendTexture(copies[2],copies[4],copies[5],margin);
        extendTexture(copies[23],copies[4],copies[7],margin);
        extendTexture(copies[22],copies[5],copies[6],margin);
        extendTexture(copies[15],copies[5],copies[4],margin);
        extendTexture(copies[14],copies[6],copies[7],margin);
        extendTexture(copies[11],copies[6],copies[5],margin);
        extendTexture(copies[10],copies[7],copies[4],margin);
        extendTexture(copies[1],copies[17],copies[16],margin);
        extendTexture(copies[0],copies[18],copies[19],margin);
        extendTexture(copies[9],copies[18],copies[17],margin);
        extendTexture(copies[8],copies[19],copies[16],margin);
        extendTexture(copies[13],copies[19],copies[18],margin);
        extendTexture(copies[12],copies[16],copies[17],margin);
        extendTexture(copies[21],copies[16],copies[19],margin);
        extendTexture(copies[20],copies[17],copies[18],margin);
        level->indexArray.append(copies[3],copies[2],copies[4],copies[7]);
        level->indexArray.append(copies[11],copies[10],copies[7],copies[6]);
        level->indexArray.append(copies[6],copies[5],copies[15],copies[14]);
        level->indexArray.append(copies[5],copies[4],copies[23],copies[22]);
        cloneMeshQuad(level,face[10],face[9],face[0],face[3],quads+0);
        extendTexture(quads[0+3],face[10],face[11],margin);
        extendTexture(quads[0+2],face[9],face[8],margin);
        cloneMeshQuad(level,face[2],face[1],face[20],face[23],quads+4);
        extendTexture(quads[4+3],face[2],face[3],margin);
        extendTexture(quads[4+2],face[1],face[0],margin);
        cloneMeshQuad(level,face[22],face[21],face[12],face[15],quads+8);
        extendTexture(quads[8+3],face[22],face[23],margin);
        extendTexture(quads[8+2],face[21],face[20],margin);
        cloneMeshQuad(level,face[14],face[13],face[8],face[11],quads+12);
        extendTexture(quads[12+3],face[14],face[15],margin);
        extendTexture(quads[12+2],face[13],face[12],margin);
        level->indexArray.append(copies[17],copies[16],copies[21],copies[20]);
        level->indexArray.append(copies[13],copies[12],copies[16],copies[19]);
        level->indexArray.append(copies[9],copies[8],copies[19],copies[18]);
        level->indexArray.append(copies[1],copies[0],copies[18],copies[17]);
        level->indexArray.append(copies[7],copies[10],copies[3],copies[3]);
        level->indexArray.append(copies[4],copies[2],copies[23],copies[23]);
        level->indexArray.append(copies[5],copies[22],copies[15],copies[15]);
        level->indexArray.append(copies[11],copies[6],copies[14],copies[14]);
        level->indexArray.append(copies[16],copies[12],copies[21],copies[21]);
        level->indexArray.append(copies[13],copies[19],copies[8],copies[8]);
        level->indexArray.append(copies[0],copies[9],copies[18],copies[18]);
        level->indexArray.append(copies[17],copies[20],copies[1],copies[1]);
        // Each retained join index gains one reference; release the 24 temporary clones.
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
        for(int i=0;i<24;++i) Mesh::allocVertex(copies[i],static_cast<unsigned>(-1));
    }
}



