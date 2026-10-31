// from server: 100% by EspClaude
// from server: 100% by coldek
// roc 2008-06 00658fb0  unit: RBX::ArrowButton  size: 687 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00658fb0
//
// 00658fb0  83ec20               sub esp, 0x20
// 00658fb3  53                   push ebx
// 00658fb4  55                   push ebp
// 00658fb5  56                   push esi
// 00658fb6  b801000000           mov eax, 1
// 00658fbb  57                   push edi
// 00658fbc  8bf1                 mov esi, ecx
// 00658fbe  840558d99700         test byte ptr [0x97d958], al
// 00658fc4  751e                 jne 0x658fe4
// 00658fc6  d90524c28400         fld dword ptr [0x84c224]
// 00658fcc  090558d99700         or dword ptr [0x97d958], eax
// 00658fd2  d9154cd99700         fst dword ptr [0x97d94c]
// 00658fd8  d91550d99700         fst dword ptr [0x97d950]
// 00658fde  d91d54d99700         fstp dword ptr [0x97d954]
// 00658fe4  807e0800             cmp byte ptr [esi + 8], 0
// 00658fe8  7405                 je 0x658fef
// 00658fea  e831fdffff           call 0x658d20
// 00658fef  d94664               fld dword ptr [esi + 0x64]
// 00658ff2  8d5e64               lea ebx, [esi + 0x64]
// 00658ff5  d90520c28400         fld dword ptr [0x84c220]
// 00658ffb  53                   push ebx
// 00658ffc  dcc9                 fmul st(1), st(0)
// 00658ffe  8d4670               lea eax, [esi + 0x70]
// 00659001  d9c9                 fxch st(1)
// 00659003  50                   push eax
// 00659004  8d6e0c               lea ebp, [esi + 0xc]
// 00659007  d91b                 fstp dword ptr [ebx]
// 00659009  8d4c2418             lea ecx, [esp + 0x18]
// 0065900d  d94304               fld dword ptr [ebx + 4]
// 00659010  55                   push ebp
// 00659011  d8c9                 fmul st(1)
// 00659013  51                   push ecx
// 00659014  d95b04               fstp dword ptr [ebx + 4]
// 00659017  d84b08               fmul dword ptr [ebx + 8]
// 0065901a  d95b08               fstp dword ptr [ebx + 8]
// 0065901d  d94604               fld dword ptr [esi + 4]
// 00659020  d98690000000         fld dword ptr [esi + 0x90]
// 00659026  d8c9                 fmul st(1)
// 00659028  d98694000000         fld dword ptr [esi + 0x94]
// 0065902e  d8ca                 fmul st(2)
// 00659030  d98698000000         fld dword ptr [esi + 0x98]
// 00659036  decb                 fmulp st(3)
// 00659038  d986a8000000         fld dword ptr [esi + 0xa8]
// 0065903e  dec2                 faddp st(2)
// 00659040  d886ac000000         fadd dword ptr [esi + 0xac]
// 00659046  d986b0000000         fld dword ptr [esi + 0xb0]
// 0065904c  dec3                 faddp st(3)
// 0065904e  d903                 fld dword ptr [ebx]
// 00659050  dec2                 faddp st(2)
// 00659052  d9c9                 fxch st(1)
// 00659054  d91b                 fstp dword ptr [ebx]
// 00659056  d84304               fadd dword ptr [ebx + 4]
// 00659059  d95b04               fstp dword ptr [ebx + 4]
// 0065905c  d84308               fadd dword ptr [ebx + 8]
// 0065905f  d95b08               fstp dword ptr [ebx + 8]
// 00659062  e8b9f8ffff           call 0x658920
// 00659067  d900                 fld dword ptr [eax]
// 00659069  83c410               add esp, 0x10
// 0065906c  d8054cd99700         fadd dword ptr [0x97d94c]
// 00659072  8d7e54               lea edi, [esi + 0x54]
// 00659075  d94004               fld dword ptr [eax + 4]
// 00659078  57                   push edi
// 00659079  d80550d99700         fadd dword ptr [0x97d950]
// 0065907f  8d542424             lea edx, [esp + 0x24]
// 00659083  d94008               fld dword ptr [eax + 8]
// 00659086  52                   push edx
// 00659087  d80554d99700         fadd dword ptr [0x97d954]
// 0065908d  8d4c2418             lea ecx, [esp + 0x18]
// 00659091  d9ca                 fxch st(2)
// 00659093  d95e48               fstp dword ptr [esi + 0x48]
// 00659096  d95e4c               fstp dword ptr [esi + 0x4c]
// 00659099  d95e50               fstp dword ptr [esi + 0x50]
// 0065909c  d94648               fld dword ptr [esi + 0x48]
// 0065909f  d95c2418             fstp dword ptr [esp + 0x18]
// 006590a3  d9464c               fld dword ptr [esi + 0x4c]
// 006590a6  d95c241c             fstp dword ptr [esp + 0x1c]
// 006590aa  d94650               fld dword ptr [esi + 0x50]
// 006590ad  d95c2420             fstp dword ptr [esp + 0x20]
// 006590b1  d9ee                 fldz 
// 006590b3  d95c2424             fstp dword ptr [esp + 0x24]
// 006590b7  e874f9ffff           call 0x658a30
// 006590bc  d900                 fld dword ptr [eax]
// 006590be  d905ac9b8100         fld dword ptr [0x819bac]
// 006590c4  dcc9                 fmul st(1), st(0)
// 006590c6  d94004               fld dword ptr [eax + 4]
// 006590c9  d8c9                 fmul st(1)
// 006590cb  d94008               fld dword ptr [eax + 8]
// 006590ce  d8ca                 fmul st(2)
// 006590d0  d9400c               fld dword ptr [eax + 0xc]
// 006590d3  decb                 fmulp st(3)
// 006590d5  d94604               fld dword ptr [esi + 4]
// 006590d8  dccc                 fmul st(4), st(0)
// 006590da  dcca                 fmul st(2), st(0)
// 006590dc  dcc9                 fmul st(1), st(0)
// 006590de  decb                 fmulp st(3)
// 006590e0  d907                 fld dword ptr [edi]
// 006590e2  dec4                 faddp st(4)
// 006590e4  d9cb                 fxch st(3)
// 006590e6  d91f                 fstp dword ptr [edi]
// 006590e8  55                   push ebp
// 006590e9  8bcf                 mov ecx, edi
// 006590eb  d84704               fadd dword ptr [edi + 4]
// 006590ee  d95f04               fstp dword ptr [edi + 4]
// 006590f1  d94708               fld dword ptr [edi + 8]
// 006590f4  dec2                 faddp st(2)
// 006590f6  d9c9                 fxch st(1)
// 006590f8  d95f08               fstp dword ptr [edi + 8]
// 006590fb  d8470c               fadd dword ptr [edi + 0xc]
// 006590fe  d95f0c               fstp dword ptr [edi + 0xc]
// 00659101  d9470c               fld dword ptr [edi + 0xc]
// 00659104  d94708               fld dword ptr [edi + 8]
// 00659107  d94704               fld dword ptr [edi + 4]
// 0065910a  d907                 fld dword ptr [edi]
// 0065910c  dcc8                 fmul st(0), st(0)
// 0065910e  d9c1                 fld st(1)
// 00659110  deca                 fmulp st(2)
// 00659112  dec1                 faddp st(1)
// 00659114  d9c1                 fld st(1)
// 00659116  deca                 fmulp st(2)
// 00659118  dec1                 faddp st(1)
// 0065911a  d9c1                 fld st(1)
// 0065911c  deca                 fmulp st(2)
// 0065911e  dec1                 faddp st(1)
// 00659120  d9fa                 fsqrt 
// 00659122  d9e8                 fld1 
// 00659124  def1                 fdivrp st(1)
// 00659126  d907                 fld dword ptr [edi]
// 00659128  d8c9                 fmul st(1)
// 0065912a  d91f                 fstp dword ptr [edi]
// 0065912c  d9c0                 fld st(0)
// 0065912e  d84f04               fmul dword ptr [edi + 4]
// 00659131  d95f04               fstp dword ptr [edi + 4]
// 00659134  d94708               fld dword ptr [edi + 8]
// 00659137  d8c9                 fmul st(1)
// 00659139  d95f08               fstp dword ptr [edi + 8]
// 0065913c  d84f0c               fmul dword ptr [edi + 0xc]
// 0065913f  d95f0c               fstp dword ptr [edi + 0xc]
// 00659142  e88945f8ff           call 0x5dd6d0
// 00659147  d94604               fld dword ptr [esi + 4]
// 0065914a  d98684000000         fld dword ptr [esi + 0x84]
// 00659150  d8c9                 fmul st(1)
// 00659152  d98688000000         fld dword ptr [esi + 0x88]
// 00659158  d8ca                 fmul st(2)
// 0065915a  d9868c000000         fld dword ptr [esi + 0x8c]
// 00659160  decb                 fmulp st(3)
// 00659162  d9869c000000         fld dword ptr [esi + 0x9c]
// 00659168  dec2                 faddp st(2)
// 0065916a  d886a0000000         fadd dword ptr [esi + 0xa0]
// 00659170  d986a4000000         fld dword ptr [esi + 0xa4]
// 00659176  dec3                 faddp st(3)
// 00659178  d9467c               fld dword ptr [esi + 0x7c]
// 0065917b  dcca                 fmul st(2), st(0)
// 0065917d  dcc9                 fmul st(1), st(0)
// 0065917f  decb                 fmulp st(3)
// 00659181  d9463c               fld dword ptr [esi + 0x3c]
// 00659184  dec2                 faddp st(2)
// 00659186  d9c9                 fxch st(1)
// 00659188  d95e3c               fstp dword ptr [esi + 0x3c]
// 0065918b  d84640               fadd dword ptr [esi + 0x40]
// 0065918e  d95e40               fstp dword ptr [esi + 0x40]
// 00659191  d84644               fadd dword ptr [esi + 0x44]
// 00659194  d95e44               fstp dword ptr [esi + 0x44]
// 00659197  d94604               fld dword ptr [esi + 4]
// 0065919a  d9463c               fld dword ptr [esi + 0x3c]
// 0065919d  d8c9                 fmul st(1)
// 0065919f  d94640               fld dword ptr [esi + 0x40]
// 006591a2  d8ca                 fmul st(2)
// 006591a4  d94644               fld dword ptr [esi + 0x44]
// 006591a7  decb                 fmulp st(3)
// 006591a9  d94630               fld dword ptr [esi + 0x30]
// 006591ac  dec2                 faddp st(2)
// 006591ae  d9c9                 fxch st(1)
// 006591b0  d95e30               fstp dword ptr [esi + 0x30]
// 006591b3  d84634               fadd dword ptr [esi + 0x34]
// 006591b6  d95e34               fstp dword ptr [esi + 0x34]
// 006591b9  d84638               fadd dword ptr [esi + 0x38]
// 006591bc  d95e38               fstp dword ptr [esi + 0x38]
// 006591bf  d98680000000         fld dword ptr [esi + 0x80]
// 006591c5  d9ee                 fldz 
// 006591c7  d99684000000         fst dword ptr [esi + 0x84]
// 006591cd  5f                   pop edi
// 006591ce  d9968c000000         fst dword ptr [esi + 0x8c]
// 006591d4  d9c9                 fxch st(1)
// 006591d6  d99e88000000         fstp dword ptr [esi + 0x88]
// 006591dc  d99690000000         fst dword ptr [esi + 0x90]
// 006591e2  d99694000000         fst dword ptr [esi + 0x94]
// 006591e8  d99698000000         fst dword ptr [esi + 0x98]
// 006591ee  d9969c000000         fst dword ptr [esi + 0x9c]
// 006591f4  d996a0000000         fst dword ptr [esi + 0xa0]
// 006591fa  d996a4000000         fst dword ptr [esi + 0xa4]
// 00659200  d996a8000000         fst dword ptr [esi + 0xa8]
// 00659206  d996ac000000         fst dword ptr [esi + 0xac]
// 0065920c  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 00659212  d903                 fld dword ptr [ebx]
// 00659214  d8054cd99700         fadd dword ptr [0x97d94c]
// 0065921a  d91b                 fstp dword ptr [ebx]
// 0065921c  d90550d99700         fld dword ptr [0x97d950]
// 00659222  d84304               fadd dword ptr [ebx + 4]
// 00659225  d95b04               fstp dword ptr [ebx + 4]
// 00659228  d90554d99700         fld dword ptr [0x97d954]
// 0065922e  d84308               fadd dword ptr [ebx + 8]
// 00659231  d95b08               fstp dword ptr [ebx + 8]
// 00659234  d9463c               fld dword ptr [esi + 0x3c]
// 00659237  d8054cd99700         fadd dword ptr [0x97d94c]
// 0065923d  d95e3c               fstp dword ptr [esi + 0x3c]
// 00659240  d94640               fld dword ptr [esi + 0x40]
// 00659243  d80550d99700         fadd dword ptr [0x97d950]
// 00659249  d95e40               fstp dword ptr [esi + 0x40]
// 0065924c  d94644               fld dword ptr [esi + 0x44]
// 0065924f  d80554d99700         fadd dword ptr [0x97d954]
// 00659255  d95e44               fstp dword ptr [esi + 0x44]
// 00659258  5e                   pop esi
// 00659259  5d                   pop ebp
// 0065925a  5b                   pop ebx
// 0065925b  83c420               add esp, 0x20
// 0065925e  c3                   ret 

// claudeSub 2026-10-28: normalize() member + linear ref local + 2 frame locals (fp:fast operand order follows local count)
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
struct Matrix3;
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&a):x(a.x),y(a.y),z(a.z){}
 Vector3& operator=(const Vector3&a){x=a.x;y=a.y;z=a.z;return *this;}
 Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}
 Vector3&operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 Vector3&operator*=(float f){x*=f;y*=f;z*=f;return *this;}
 friend Vector3 operator*(float f,const Vector3&v){return Vector3(f*v.x,f*v.y,f*v.z);}
 static const Vector3& zero(){static Vector3 v(0,0,0);return v;}
};
struct Matrix3 {
 float data[3][3];
 Matrix3(){}
 Matrix3(const Matrix3&);
};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;};
inline Vector3 operator*(const Vector3&v,const Matrix3&m){
 return Vector3(v.x*m.data[0][0]+v.z*m.data[2][0]+v.y*m.data[1][0],
 v.x*m.data[0][1]+v.z*m.data[2][1]+v.y*m.data[1][1],
 v.x*m.data[0][2]+v.z*m.data[2][2]+v.y*m.data[1][2]);
}
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct PV {
 G3D::CoordinateFrame position;Velocity velocity;
 PV pvAtLocalOffset(const G3D::Vector3&)const;
};
struct Quaternion {
 float x,y,z,w;
 Quaternion(const G3D::Matrix3&);
 Quaternion(const G3D::Vector3&v,float f):x(v.x),y(v.y),z(v.z),w(f){}
 Quaternion(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 Quaternion operator*(const Quaternion&)const;
 Quaternion operator*(float f)const{return Quaternion(x*f,y*f,z*f,w*f);}
 Quaternion&operator+=(const Quaternion&q){x+=q.x;y+=q.y;z+=q.z;w+=q.w;return *this;}
 void toRotationMatrix(G3D::Matrix3&)const;
 Quaternion& operator=(const Quaternion&);
 float magnitude()const{return sqrtf(x*x+y*y+z*z+w*w);}
 Quaternion& operator*=(float f){x=f*x;y=f*y;z=f*z;w=f*w;return *this;}
 void normalize(){*this*=1.0f/magnitude();}
};

struct Body;
struct SimBody {
 Body*body;float dt;bool dirty;char padding[3];
 PV pv;Quaternion qOrientation;
 G3D::Vector3 angMomentum,momentRecip;
 float massRecip,constantForceY;
 G3D::Vector3 force,torque,impulse,angularImpulse;
 void update();void updateIfDirty(){if(dirty)update();}
 const PV&getPV()const{return pv;}
 void step();
};
G3D::Vector3 __cdecl computeRotVel(const G3D::Matrix3&,const G3D::Vector3&,const G3D::Vector3&);
void SimBody::step(){
 float dd1 = 0; float dd2 = 0;
 static G3D::Vector3 denormFix(9.9999997e-21f,9.9999997e-21f,9.9999997e-21f);
 updateIfDirty();
 angMomentum*=0.99980003f;
 angMomentum+=angularImpulse+torque*dt;
 pv.velocity.rotational=computeRotVel(getPV().position.rotation,momentRecip,angMomentum)+denormFix;
 Quaternion qDot(Quaternion(pv.velocity.rotational,0)*qOrientation*0.5f);
 qOrientation+=qDot*dt;
 qOrientation.normalize();
 qOrientation.toRotationMatrix(pv.position.rotation);
 const float& dt=this->dt;
 pv.velocity.linear+=massRecip*(impulse+force*dt);
 pv.position.translation+=pv.velocity.linear*dt;
 force=G3D::Vector3(0,constantForceY,0);
 torque=G3D::Vector3(0,0,0);impulse=G3D::Vector3(0,0,0);angularImpulse=G3D::Vector3(0,0,0);
 angMomentum+=denormFix;
 G3D::Vector3& lin=pv.velocity.linear;
 lin+=denormFix;
}
}
