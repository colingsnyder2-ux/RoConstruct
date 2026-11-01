// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view-dll roc_claude_meshface22e769980f77f3e44.cpp

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
void recoveredMeshFace(const G3D::Vector3& size,float inset,unsigned surfaces,float color,
                      G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>& level,unsigned* corners) {
    using namespace G3D;
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
template void recoveredMeshFace<RBX::NORM_X>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_X_NEG>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Y_NEG>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
template void recoveredMeshFace<RBX::NORM_Z_NEG>(const G3D::Vector3&,float,unsigned,float,G3D::ReferenceCountedPointer<RBX::Render::Mesh::Level>&,unsigned*);
