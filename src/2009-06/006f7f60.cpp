// from server: 100% by EspClaude
// from server: 100% by king_originala_sol_native
// roc 2008-06 0066ccc0  unit: RBX::GroupDragTool  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ccc0
//
// 0066ccc0  83ec24               sub esp, 0x24
// 0066ccc3  53                   push ebx
// 0066ccc4  55                   push ebp
// 0066ccc5  57                   push edi
// 0066ccc6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0066ccca  8be9                 mov ebp, ecx
// 0066cccc  896c240c             mov dword ptr [esp + 0xc], ebp
// 0066ccd0  c70700000000         mov dword ptr [edi], 0
// 0066ccd6  c7470406000000       mov dword ptr [edi + 4], 6
// 0066ccdd  e87e3ceaff           call 0x510960
// 0066cce2  d900                 fld dword ptr [eax]
// 0066cce4  d95f08               fstp dword ptr [edi + 8]
// 0066cce7  d94004               fld dword ptr [eax + 4]
// 0066ccea  d95f0c               fstp dword ptr [edi + 0xc]
// 0066cced  d94008               fld dword ptr [eax + 8]
// 0066ccf0  d95f10               fstp dword ptr [edi + 0x10]
// 0066ccf3  e8683ceaff           call 0x510960
// 0066ccf8  d900                 fld dword ptr [eax]
// 0066ccfa  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0066ccfd  d95f14               fstp dword ptr [edi + 0x14]
// 0066cd00  d94004               fld dword ptr [eax + 4]
// 0066cd03  d95f18               fstp dword ptr [edi + 0x18]
// 0066cd06  d94008               fld dword ptr [eax + 8]
// 0066cd09  d95f1c               fstp dword ptr [edi + 0x1c]
// 0066cd0c  e8bfaef7ff           call 0x5e7bd0
// 0066cd11  8bd8                 mov ebx, eax
// 0066cd13  85db                 test ebx, ebx
// 0066cd15  0f84e8000000         je 0x66ce03
// 0066cd1b  56                   push esi
// 0066cd1c  8d642400             lea esp, [esp]
// 0066cd20  d9058c748200         fld dword ptr [0x82748c]
// 0066cd26  51                   push ecx
// 0066cd27  8bcb                 mov ecx, ebx
// 0066cd29  d91c24               fstp dword ptr [esp]
// 0066cd2c  ff542444             call dword ptr [esp + 0x44]
// 0066cd30  84c0                 test al, al
// 0066cd32  0f84b7000000         je 0x66cdef
// 0066cd38  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0066cd3b  394514               cmp dword ptr [ebp + 0x14], eax
// 0066cd3e  7503                 jne 0x66cd43
// 0066cd40  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0066cd43  89442438             mov dword ptr [esp + 0x38], eax
// 0066cd47  85c0                 test eax, eax
// 0066cd49  0f84a0000000         je 0x66cdef
// 0066cd4f  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0066cd53  8b4a04               mov ecx, dword ptr [edx + 4]
// 0066cd56  33c0                 xor eax, eax
// 0066cd58  85c9                 test ecx, ecx
// 0066cd5a  7e20                 jle 0x66cd7c
// 0066cd5c  8b32                 mov esi, dword ptr [edx]
// 0066cd5e  8bd6                 mov edx, esi
// 0066cd60  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 0066cd64  392a                 cmp dword ptr [edx], ebp
// 0066cd66  0f84a2000000         je 0x66ce0e
// 0066cd6c  40                   inc eax
// 0066cd6d  83c204               add edx, 4
// 0066cd70  3bc1                 cmp eax, ecx
// 0066cd72  7cec                 jl 0x66cd60
// 0066cd74  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0066cd78  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0066cd7c  8b32                 mov esi, dword ptr [edx]
// 0066cd7e  8d048e               lea eax, [esi + ecx*4]
// 0066cd81  8d0c8e               lea ecx, [esi + ecx*4]
// 0066cd84  3bc1                 cmp eax, ecx
// 0066cd86  7567                 jne 0x66cdef
// 0066cd88  8b542438             mov edx, dword ptr [esp + 0x38]
// 0066cd8c  6a00                 push 0
// 0066cd8e  52                   push edx
// 0066cd8f  8d44241c             lea eax, [esp + 0x1c]
// 0066cd93  50                   push eax
// 0066cd94  8bcd                 mov ecx, ebp
// 0066cd96  e8d5fbffff           call 0x66c970
// 0066cd9b  837c241400           cmp dword ptr [esp + 0x14], 0
// 0066cda0  744d                 je 0x66cdef
// 0066cda2  8d4c2414             lea ecx, [esp + 0x14]
// 0066cda6  e865faffff           call 0x66c810
// 0066cdab  d81d4cb08400         fcomp dword ptr [0x84b04c]
// 0066cdb1  dfe0                 fnstsw ax
// 0066cdb3  f6c405               test ah, 5
// 0066cdb6  7a37                 jp 0x66cdef
// 0066cdb8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0066cdbc  d944241c             fld dword ptr [esp + 0x1c]
// 0066cdc0  8b542418             mov edx, dword ptr [esp + 0x18]
// 0066cdc4  890f                 mov dword ptr [edi], ecx
// 0066cdc6  895704               mov dword ptr [edi + 4], edx
// 0066cdc9  d95f08               fstp dword ptr [edi + 8]
// 0066cdcc  d9442420             fld dword ptr [esp + 0x20]
// 0066cdd0  d95f0c               fstp dword ptr [edi + 0xc]
// 0066cdd3  d9442424             fld dword ptr [esp + 0x24]
// 0066cdd7  d95f10               fstp dword ptr [edi + 0x10]
// 0066cdda  d9442428             fld dword ptr [esp + 0x28]
// 0066cdde  d95f14               fstp dword ptr [edi + 0x14]
// 0066cde1  d944242c             fld dword ptr [esp + 0x2c]
// 0066cde5  d95f18               fstp dword ptr [edi + 0x18]
// 0066cde8  d9442430             fld dword ptr [esp + 0x30]
// 0066cdec  d95f1c               fstp dword ptr [edi + 0x1c]
// 0066cdef  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0066cdf2  53                   push ebx
// 0066cdf3  e8e8adf7ff           call 0x5e7be0
// 0066cdf8  8bd8                 mov ebx, eax
// 0066cdfa  85db                 test ebx, ebx
// 0066cdfc  0f851effffff         jne 0x66cd20
// 0066ce02  5e                   pop esi
// 0066ce03  8bc7                 mov eax, edi
// 0066ce05  5f                   pop edi
// 0066ce06  5d                   pop ebp
// 0066ce07  5b                   pop ebx
// 0066ce08  83c424               add esp, 0x24
// 0066ce0b  c20c00               ret 0xc
// 0066ce0e  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0066ce12  8d0486               lea eax, [esi + eax*4]
// 0066ce15  e967ffffff           jmp 0x66cd81

// from server: 95% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// RunDragger contact search: actual SDK SnapInfo/Array/member-pointer contracts.
#include <stddef.h>
#include <intrin.h>
namespace G3D {
class Vector3 {public:float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return*this;}static const Vector3&inf();};
// Borrowed array: only original12-byte layout/find/end are consumed.
// No allocation, container ownership operation, or by-value Array API is used.
template<class T>class Array {T*data;int num,numAllocated;public:typedef const T*ConstIterator;ConstIterator end()const{return data+num;}ConstIterator find(const T&value)const{for(int i=0;i<num;++i)if(data[i]==value)return data+i;return end();}};
}
namespace RBX {
class Primitive;class Contact;class Kernel;class IStage;
enum NormalId {NORM_X=0,NORM_Y=1,NORM_Z=2,NORM_X_NEG=3,NORM_Y_NEG=4,NORM_Z_NEG=5,NORM_UNDEFINED=6};
class __declspec(novtable) IPipelined {IStage*currentStage;public:virtual~IPipelined(){}virtual void putInKernel(Kernel*);virtual void removeFromKernel();};
namespace Sim {enum EdgeState {UNDEFINED,STEPPING,SLEEPING,TOUCHING,TOUCHING_SLEEPING};}
class __declspec(novtable) Edge:public IPipelined {Sim::EdgeState edgeState;int exePad;Primitive*prim0;Primitive*prim1;Edge*next0;Edge*next1;bool inEdgeList;public:enum EdgeType {JOINT,CONTACT};virtual~Edge(){}virtual EdgeType getEdgeType()const=0;virtual void setPrimitive(int,Primitive*);Primitive*otherPrimitive(const Primitive*p)const{return p==prim0?prim1:prim0;}};
class __declspec(novtable) Contact:public Edge {int lastContactStep,steppingIndex;float jointK,elasticJointK,kFriction;private:virtual void putInKernel(Kernel*);virtual void removeFromKernel();virtual EdgeType getEdgeType()const{return CONTACT;}protected:virtual void deleteAllConnectors()=0;virtual bool stepContact()=0;public:virtual~Contact(){}virtual bool computeIsColliding(float)=0;bool computeIsAdjacent(float);};
class Primitive {public:Contact*getFirstContact();Contact*getNextContact(Contact*);};
class RunDragger {public:class SnapInfo {public:Primitive*snap;NormalId surface;G3D::Vector3 hitWorld,lastDragSnap;SnapInfo():surface(NORM_UNDEFINED),hitWorld(G3D::Vector3::inf()),lastDragSnap(G3D::Vector3::inf()),snap(NULL){}float hitOutsideExtents();};
private:// Borrowed existing owner prefix; no construction or whole native-size claim.
 char beforeDrag[0x14];Primitive*drag;
 SnapInfo createSnapSurface(Primitive*,G3D::Array<NormalId>*);
 bool notTried(Primitive*,const G3D::Array<Primitive*>&);
 SnapInfo bestProximatePart(const G3D::Array<Primitive*>&,bool(Contact::*)(float));
};
}
namespace RBX {
bool RunDragger::notTried(Primitive*check,const G3D::Array<Primitive*>&tried){return check&&tried.find(check)==tried.end();}
RunDragger::SnapInfo RunDragger::bestProximatePart(const G3D::Array<Primitive*>&triedSnap,bool(Contact::*proximityTest)(float)){
 SnapInfo answer;
 for(Contact*current=drag->getFirstContact();current!=NULL;current=drag->getNextContact(current)){
  if((current->*proximityTest)(0.01f)){
   Primitive*otherPrimitive=current->otherPrimitive(drag);
   _ReadWriteBarrier();
   if(notTried(otherPrimitive,triedSnap)){
    SnapInfo testInfo=createSnapSurface(otherPrimitive,NULL);
    if(testInfo.snap&&testInfo.hitOutsideExtents()<1e+10)answer=testInfo;
   }
  }
 }
 return answer;
}
}
