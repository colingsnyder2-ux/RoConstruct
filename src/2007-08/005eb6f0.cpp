// from server: 100% by EspClaude
// from server: 93% by EspClaude
// roc 2007-08 005eb6f0  unit: RBX::BodyMover  size: 992 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005eb6f0
//
// 005eb6f0  83ec58               sub esp, 0x58
// 005eb6f3  53                   push ebx
// 005eb6f4  55                   push ebp
// 005eb6f5  56                   push esi
// 005eb6f6  57                   push edi
// 005eb6f7  8b7c2470             mov edi, dword ptr [esp + 0x70]
// 005eb6fb  8be9                 mov ebp, ecx
// 005eb6fd  8bcf                 mov ecx, edi
// 005eb6ff  e8fc49f4ff           call 0x530100
// 005eb704  8b442474             mov eax, dword ptr [esp + 0x74]
// 005eb708  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 005eb70c  50                   push eax
// 005eb70d  51                   push ecx
// 005eb70e  8d54244c             lea edx, [esp + 0x4c]
// 005eb712  8db784000000         lea esi, [edi + 0x84]
// 005eb718  52                   push edx
// 005eb719  8bce                 mov ecx, esi
// 005eb71b  e880e2f1ff           call 0x5099a0
// 005eb720  8bc8                 mov ecx, eax
// 005eb722  e85979e8ff           call 0x473080
// 005eb727  8b5f04               mov ebx, dword ptr [edi + 4]
// 005eb72a  8b4304               mov eax, dword ptr [ebx + 4]
// 005eb72d  8b4020               mov eax, dword ptr [eax + 0x20]
// 005eb730  85c0                 test eax, eax
// 005eb732  7407                 je 0x5eb73b
// 005eb734  058c000000           add eax, 0x8c
// 005eb739  eb2c                 jmp 0x5eb767
// 005eb73b  b801000000           mov eax, 1
// 005eb740  840538d18b00         test byte ptr [0x8bd138], al
// 005eb746  751a                 jne 0x5eb762
// 005eb748  d9ee                 fldz 
// 005eb74a  090538d18b00         or dword ptr [0x8bd138], eax
// 005eb750  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005eb756  d91530d18b00         fst dword ptr [0x8bd130]
// 005eb75c  d91d34d18b00         fstp dword ptr [0x8bd134]
// 005eb762  b82cd18b00           mov eax, 0x8bd12c
// 005eb767  d900                 fld dword ptr [eax]
// 005eb769  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb76c  85c9                 test ecx, ecx
// 005eb76e  d95c2420             fstp dword ptr [esp + 0x20]
// 005eb772  d94004               fld dword ptr [eax + 4]
// 005eb775  d95c2424             fstp dword ptr [esp + 0x24]
// 005eb779  d94008               fld dword ptr [eax + 8]
// 005eb77c  d95c2428             fstp dword ptr [esp + 0x28]
// 005eb780  7407                 je 0x5eb789
// 005eb782  e879990300           call 0x625100
// 005eb787  eb03                 jmp 0x5eb78c
// 005eb789  8d4358               lea eax, [ebx + 0x58]
// 005eb78c  50                   push eax
// 005eb78d  8d4c2448             lea ecx, [esp + 0x48]
// 005eb791  e83adef1ff           call 0x5095d0
// 005eb796  8d4c2444             lea ecx, [esp + 0x44]
// 005eb79a  51                   push ecx
// 005eb79b  8d542430             lea edx, [esp + 0x30]
// 005eb79f  52                   push edx
// 005eb7a0  e89bf5fbff           call 0x5aad40
// 005eb7a5  8b442474             mov eax, dword ptr [esp + 0x74]
// 005eb7a9  d94004               fld dword ptr [eax + 4]
// 005eb7ac  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb7af  d84c2434             fmul dword ptr [esp + 0x34]
// 005eb7b3  83c408               add esp, 8
// 005eb7b6  85c9                 test ecx, ecx
// 005eb7b8  d88d2c010000         fmul dword ptr [ebp + 0x12c]
// 005eb7be  d95c2470             fstp dword ptr [esp + 0x70]
// 005eb7c2  7407                 je 0x5eb7cb
// 005eb7c4  e837990300           call 0x625100
// 005eb7c9  eb03                 jmp 0x5eb7ce
// 005eb7cb  8d4358               lea eax, [ebx + 0x58]
// 005eb7ce  50                   push eax
// 005eb7cf  8d4c2448             lea ecx, [esp + 0x48]
// 005eb7d3  e8f8ddf1ff           call 0x5095d0
// 005eb7d8  8d4c2444             lea ecx, [esp + 0x44]
// 005eb7dc  51                   push ecx
// 005eb7dd  8d542430             lea edx, [esp + 0x30]
// 005eb7e1  52                   push edx
// 005eb7e2  e859f5fbff           call 0x5aad40
// 005eb7e7  8b442474             mov eax, dword ptr [esp + 0x74]
// 005eb7eb  d900                 fld dword ptr [eax]
// 005eb7ed  83c408               add esp, 8
// 005eb7f0  d84c2430             fmul dword ptr [esp + 0x30]
// 005eb7f4  8bcf                 mov ecx, edi
// 005eb7f6  d88d2c010000         fmul dword ptr [ebp + 0x12c]
// 005eb7fc  d9e0                 fchs 
// 005eb7fe  d95c2474             fstp dword ptr [esp + 0x74]
// 005eb802  e8f948f4ff           call 0x530100
// 005eb807  8d4c2444             lea ecx, [esp + 0x44]
// 005eb80b  51                   push ecx
// 005eb80c  8bce                 mov ecx, esi
// 005eb80e  e88de1f1ff           call 0x5099a0
// 005eb813  d94004               fld dword ptr [eax + 4]
// 005eb816  d9442424             fld dword ptr [esp + 0x24]
// 005eb81a  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb81d  85c9                 test ecx, ecx
// 005eb81f  dcc9                 fmul st(1), st(0)
// 005eb821  d94008               fld dword ptr [eax + 8]
// 005eb824  d9442428             fld dword ptr [esp + 0x28]
// 005eb828  dcc9                 fmul st(1), st(0)
// 005eb82a  d9cb                 fxch st(3)
// 005eb82c  dec1                 faddp st(1)
// 005eb82e  d900                 fld dword ptr [eax]
// 005eb830  d9442420             fld dword ptr [esp + 0x20]
// 005eb834  dcc9                 fmul st(1), st(0)
// 005eb836  d9ca                 fxch st(2)
// 005eb838  dec1                 faddp st(1)
// 005eb83a  d9542414             fst dword ptr [esp + 0x14]
// 005eb83e  d94010               fld dword ptr [eax + 0x10]
// 005eb841  d8cb                 fmul st(3)
// 005eb843  d94014               fld dword ptr [eax + 0x14]
// 005eb846  d8cd                 fmul st(5)
// 005eb848  dec1                 faddp st(1)
// 005eb84a  d9400c               fld dword ptr [eax + 0xc]
// 005eb84d  d8cb                 fmul st(3)
// 005eb84f  dec1                 faddp st(1)
// 005eb851  d95c2418             fstp dword ptr [esp + 0x18]
// 005eb855  d9401c               fld dword ptr [eax + 0x1c]
// 005eb858  decb                 fmulp st(3)
// 005eb85a  d94020               fld dword ptr [eax + 0x20]
// 005eb85d  decc                 fmulp st(4)
// 005eb85f  d9ca                 fxch st(2)
// 005eb861  dec3                 faddp st(3)
// 005eb863  d84818               fmul dword ptr [eax + 0x18]
// 005eb866  dec2                 faddp st(2)
// 005eb868  d9c9                 fxch st(1)
// 005eb86a  d95c241c             fstp dword ptr [esp + 0x1c]
// 005eb86e  d86c2470             fsubr dword ptr [esp + 0x70]
// 005eb872  d9e1                 fabs 
// 005eb874  d95c2410             fstp dword ptr [esp + 0x10]
// 005eb878  7407                 je 0x5eb881
// 005eb87a  e881980300           call 0x625100
// 005eb87f  eb03                 jmp 0x5eb884
// 005eb881  8d4358               lea eax, [ebx + 0x58]
// 005eb884  50                   push eax
// 005eb885  8d4c2448             lea ecx, [esp + 0x48]
// 005eb889  e842ddf1ff           call 0x5095d0
// 005eb88e  8d542444             lea edx, [esp + 0x44]
// 005eb892  52                   push edx
// 005eb893  8d442430             lea eax, [esp + 0x30]
// 005eb897  50                   push eax
// 005eb898  e8a3f4fbff           call 0x5aad40
// 005eb89d  d98534010000         fld dword ptr [ebp + 0x134]
// 005eb8a3  d84c2434             fmul dword ptr [esp + 0x34]
// 005eb8a7  83c408               add esp, 8
// 005eb8aa  d85c2410             fcomp dword ptr [esp + 0x10]
// 005eb8ae  dfe0                 fnstsw ax
// 005eb8b0  f6c441               test ah, 0x41
// 005eb8b3  7506                 jne 0x5eb8bb
// 005eb8b5  d9442470             fld dword ptr [esp + 0x70]
// 005eb8b9  eb08                 jmp 0x5eb8c3
// 005eb8bb  d9442414             fld dword ptr [esp + 0x14]
// 005eb8bf  d8442470             fadd dword ptr [esp + 0x70]
// 005eb8c3  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb8c6  d95c2414             fstp dword ptr [esp + 0x14]
// 005eb8ca  85c9                 test ecx, ecx
// 005eb8cc  d9442474             fld dword ptr [esp + 0x74]
// 005eb8d0  d8642418             fsub dword ptr [esp + 0x18]
// 005eb8d4  d9e1                 fabs 
// 005eb8d6  d95c2470             fstp dword ptr [esp + 0x70]
// 005eb8da  7407                 je 0x5eb8e3
// 005eb8dc  e81f980300           call 0x625100
// 005eb8e1  eb03                 jmp 0x5eb8e6
// 005eb8e3  8d4358               lea eax, [ebx + 0x58]
// 005eb8e6  50                   push eax
// 005eb8e7  8d4c2448             lea ecx, [esp + 0x48]
// 005eb8eb  e8e0dcf1ff           call 0x5095d0
// 005eb8f0  8d4c2444             lea ecx, [esp + 0x44]
// 005eb8f4  51                   push ecx
// 005eb8f5  8d542430             lea edx, [esp + 0x30]
// 005eb8f9  52                   push edx
// 005eb8fa  e841f4fbff           call 0x5aad40
// 005eb8ff  d98538010000         fld dword ptr [ebp + 0x138]
// 005eb905  d84c2438             fmul dword ptr [esp + 0x38]
// 005eb909  83c408               add esp, 8
// 005eb90c  d85c2470             fcomp dword ptr [esp + 0x70]
// 005eb910  dfe0                 fnstsw ax
// 005eb912  f6c441               test ah, 0x41
// 005eb915  7506                 jne 0x5eb91d
// 005eb917  d9442474             fld dword ptr [esp + 0x74]
// 005eb91b  eb08                 jmp 0x5eb925
// 005eb91d  d9442418             fld dword ptr [esp + 0x18]
// 005eb921  d8442474             fadd dword ptr [esp + 0x74]
// 005eb925  8bcf                 mov ecx, edi
// 005eb927  d95c2418             fstp dword ptr [esp + 0x18]
// 005eb92b  e8d047f4ff           call 0x530100
// 005eb930  8bcf                 mov ecx, edi
// 005eb932  e8c947f4ff           call 0x530100
// 005eb937  8d442444             lea eax, [esp + 0x44]
// 005eb93b  50                   push eax
// 005eb93c  8bce                 mov ecx, esi
// 005eb93e  e85de0f1ff           call 0x5099a0
// 005eb943  d94008               fld dword ptr [eax + 8]
// 005eb946  d88fc8000000         fmul dword ptr [edi + 0xc8]
// 005eb94c  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb94f  85c9                 test ecx, ecx
// 005eb951  d94004               fld dword ptr [eax + 4]
// 005eb954  d88fc4000000         fmul dword ptr [edi + 0xc4]
// 005eb95a  dec1                 faddp st(1)
// 005eb95c  d900                 fld dword ptr [eax]
// 005eb95e  d88fc0000000         fmul dword ptr [edi + 0xc0]
// 005eb964  dec1                 faddp st(1)
// 005eb966  d95c242c             fstp dword ptr [esp + 0x2c]
// 005eb96a  d94014               fld dword ptr [eax + 0x14]
// 005eb96d  d88fc8000000         fmul dword ptr [edi + 0xc8]
// 005eb973  d94010               fld dword ptr [eax + 0x10]
// 005eb976  d88fc4000000         fmul dword ptr [edi + 0xc4]
// 005eb97c  dec1                 faddp st(1)
// 005eb97e  d9400c               fld dword ptr [eax + 0xc]
// 005eb981  d88fc0000000         fmul dword ptr [edi + 0xc0]
// 005eb987  dec1                 faddp st(1)
// 005eb989  d95c2430             fstp dword ptr [esp + 0x30]
// 005eb98d  7407                 je 0x5eb996
// 005eb98f  e86c970300           call 0x625100
// 005eb994  eb03                 jmp 0x5eb999
// 005eb996  8d4358               lea eax, [ebx + 0x58]
// 005eb999  50                   push eax
// 005eb99a  8d4c2448             lea ecx, [esp + 0x48]
// 005eb99e  e82ddcf1ff           call 0x5095d0
// 005eb9a3  8d4c2444             lea ecx, [esp + 0x44]
// 005eb9a7  51                   push ecx
// 005eb9a8  8d54243c             lea edx, [esp + 0x3c]
// 005eb9ac  52                   push edx
// 005eb9ad  e88ef3fbff           call 0x5aad40
// 005eb9b2  d9442440             fld dword ptr [esp + 0x40]
// 005eb9b6  d84c2434             fmul dword ptr [esp + 0x34]
// 005eb9ba  8b4b1c               mov ecx, dword ptr [ebx + 0x1c]
// 005eb9bd  83c408               add esp, 8
// 005eb9c0  85c9                 test ecx, ecx
// 005eb9c2  d88d30010000         fmul dword ptr [ebp + 0x130]
// 005eb9c8  d86c2414             fsubr dword ptr [esp + 0x14]
// 005eb9cc  d95c2414             fstp dword ptr [esp + 0x14]
// 005eb9d0  7407                 je 0x5eb9d9
// 005eb9d2  e829970300           call 0x625100
// 005eb9d7  eb03                 jmp 0x5eb9dc
// 005eb9d9  8d4358               lea eax, [ebx + 0x58]
// 005eb9dc  50                   push eax
// 005eb9dd  8d4c2448             lea ecx, [esp + 0x48]
// 005eb9e1  e8eadbf1ff           call 0x5095d0
// 005eb9e6  8d442444             lea eax, [esp + 0x44]
// 005eb9ea  50                   push eax
// 005eb9eb  8d4c243c             lea ecx, [esp + 0x3c]
// 005eb9ef  51                   push ecx
// 005eb9f0  e84bf3fbff           call 0x5aad40
// 005eb9f5  d9442444             fld dword ptr [esp + 0x44]
// 005eb9f9  d84c2438             fmul dword ptr [esp + 0x38]
// 005eb9fd  83c408               add esp, 8
// 005eba00  8bcf                 mov ecx, edi
// 005eba02  d88d30010000         fmul dword ptr [ebp + 0x130]
// 005eba08  d86c2418             fsubr dword ptr [esp + 0x18]
// 005eba0c  d95c2418             fstp dword ptr [esp + 0x18]
// 005eba10  e8eb46f4ff           call 0x530100
// 005eba15  d94608               fld dword ptr [esi + 8]
// 005eba18  8b5304               mov edx, dword ptr [ebx + 4]
// 005eba1b  d944241c             fld dword ptr [esp + 0x1c]
// 005eba1f  dcc9                 fmul st(1), st(0)
// 005eba21  d94604               fld dword ptr [esi + 4]
// 005eba24  d9442418             fld dword ptr [esp + 0x18]
// 005eba28  dcc9                 fmul st(1), st(0)
// 005eba2a  d9cb                 fxch st(3)
// 005eba2c  dec1                 faddp st(1)
// 005eba2e  d906                 fld dword ptr [esi]
// 005eba30  d9442414             fld dword ptr [esp + 0x14]
// 005eba34  dcc9                 fmul st(1), st(0)
// 005eba36  d9ca                 fxch st(2)
// 005eba38  dec1                 faddp st(1)
// 005eba3a  d94614               fld dword ptr [esi + 0x14]
// 005eba3d  d8cb                 fmul st(3)
// 005eba3f  d94610               fld dword ptr [esi + 0x10]
// 005eba42  d8cd                 fmul st(5)
// 005eba44  dec1                 faddp st(1)
// 005eba46  d9460c               fld dword ptr [esi + 0xc]
// 005eba49  d8cb                 fmul st(3)
// 005eba4b  dec1                 faddp st(1)
// 005eba4d  d94620               fld dword ptr [esi + 0x20]
// 005eba50  decc                 fmulp st(4)
// 005eba52  d9461c               fld dword ptr [esi + 0x1c]
// 005eba55  decd                 fmulp st(5)
// 005eba57  d9cb                 fxch st(3)
// 005eba59  dec4                 faddp st(4)
// 005eba5b  d94618               fld dword ptr [esi + 0x18]
// 005eba5e  8b7220               mov esi, dword ptr [edx + 0x20]
// 005eba61  85f6                 test esi, esi
// 005eba63  deca                 fmulp st(2)
// 005eba65  d9cb                 fxch st(3)
// 005eba67  dec1                 faddp st(1)
// 005eba69  d9ca                 fxch st(2)
// 005eba6b  d8642420             fsub dword ptr [esp + 0x20]
// 005eba6f  d95c2414             fstp dword ptr [esp + 0x14]
// 005eba73  d8642424             fsub dword ptr [esp + 0x24]
// 005eba77  d95c2418             fstp dword ptr [esp + 0x18]
// 005eba7b  d8642428             fsub dword ptr [esp + 0x28]
// 005eba7f  d95c241c             fstp dword ptr [esp + 0x1c]
// 005eba83  743d                 je 0x5ebac2
// 005eba85  807e0400             cmp byte ptr [esi + 4], 0
// 005eba89  7407                 je 0x5eba92
// 005eba8b  8bce                 mov ecx, esi
// 005eba8d  e87eea0200           call 0x61a510
// 005eba92  d9868c000000         fld dword ptr [esi + 0x8c]
// 005eba98  d8442414             fadd dword ptr [esp + 0x14]
// 005eba9c  d99e8c000000         fstp dword ptr [esi + 0x8c]
// 005ebaa2  d98690000000         fld dword ptr [esi + 0x90]
// 005ebaa8  d8442418             fadd dword ptr [esp + 0x18]
// 005ebaac  d99e90000000         fstp dword ptr [esi + 0x90]
// 005ebab2  d98694000000         fld dword ptr [esi + 0x94]
// 005ebab8  d844241c             fadd dword ptr [esp + 0x1c]
// 005ebabc  d99e94000000         fstp dword ptr [esi + 0x94]
// 005ebac2  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 005ebac6  5f                   pop edi
// 005ebac7  5e                   pop esi
// 005ebac8  5d                   pop ebp
// 005ebac9  5b                   pop ebx
// 005ebaca  83c458               add esp, 0x58
// 005ebacd  c20c00               ret 0xc

// from server: 100% by king_originala
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native Gyro.cpp Rocket::turn, with target-observed Body/SimBody/Rocket offsets.
#include <math.h>
#include <stddef.h>
#include <intrin.h>
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 float&operator[](int i){return ((float*)this)[i];}
 const float&operator[](int i)const{return ((const float*)this)[i];}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3&operator+=(const Vector3&v){float oldX=x;_ReadWriteBarrier();x=oldX+v.x;y+=v.y;z+=v.z;return *this;}
 static const Vector3&zero(){static Vector3 v(0,0,0);return v;}
};
struct Matrix3 {
 float elt[3][3];
 Matrix3(){}Matrix3(const Matrix3&);
 Matrix3 transpose()const;
 Vector3 operator*(const Vector3&v)const{
  Vector3 kProd;
  for(int r=0;r<3;++r){double p0=elt[r][0]*v[0];double p1=elt[r][1]*v[1];double p2=elt[r][2]*v[2];kProd[r]=static_cast<float>((p2+p1)+p0);}
  return kProd;
 }
};
struct CoordinateFrame {
 Matrix3 rotation;Vector3 translation;
 Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct PV {G3D::CoordinateFrame position;Velocity velocity;};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);};
struct Cofm {const G3D::Matrix3&getMoment()const;};
struct Body;
struct SimBody {
 Body*body;bool dirty;char unused[0x8c-5];G3D::Vector3 torque;
 void update();
 void accumulateTorque(const G3D::Vector3&v){if(dirty)update();torque+=v;}
};
struct Body {
 char prefix[0x4];Body*root;
 char unused[0x1c-0x8];Cofm*cofm;SimBody*simBody;
 char unused2[0x58-0x24];G3D::Matrix3 moment;float mass;int stateIndex;PV pv;
 void updatePV()const;
 Body*getRoot(){return root;}
 const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return pv.position;}
 const Velocity&getVelocity()const{updatePV();return pv.velocity;}
 const G3D::Vector3&getBranchTorque()const{return root->simBody?root->simBody->torque:G3D::Vector3::zero();}
 G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}
 G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&v){if(root->simBody)root->simBody->accumulateTorque(v);}
};
struct Rocket {
 char unused[0x12c];float kTurnP,kTurnD;G3D::Vector3 maxTorque;
 G3D::Vector3 turn(Body*,const G3D::Vector3&);
};
G3D::Vector3 Rocket::turn(Body*body,const G3D::Vector3&targetDir){
 G3D::Vector3 targetObjectSpace=body->getCoordinateFrame().vectorToObjectSpace(targetDir);
 Body*root=body->getRoot();
 G3D::Vector3 oldTorqueWorld=root->getBranchTorque();
 float desiredTorqueX=targetObjectSpace.y*root->getBranchIBodyV3().x*kTurnP;
 float desiredTorqueY=-(targetObjectSpace.x*root->getBranchIBodyV3().y*kTurnP);
 G3D::Vector3 torqueBody=body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);
 if(fabs(desiredTorqueX-torqueBody.x)<root->getBranchIBodyV3().x*maxTorque.x)torqueBody.x=desiredTorqueX;
 else torqueBody.x+=desiredTorqueX;
 if(fabs(desiredTorqueY-torqueBody.y)<root->getBranchIBodyV3().y*maxTorque.y)torqueBody.y=desiredTorqueY;
 else torqueBody.y+=desiredTorqueY;
 G3D::Vector3 angVelBody=body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
 torqueBody.x-=(root->getBranchIBodyV3().x*angVelBody.x)*kTurnD;
 torqueBody.y-=(root->getBranchIBodyV3().y*angVelBody.y)*kTurnD;
 G3D::Vector3 addedTorque=body->getCoordinateFrame().vectorToWorldSpace(torqueBody)-oldTorqueWorld;
 root->accumulateTorque(addedTorque);
 return targetObjectSpace;
}
}
typedef char body_pv_offset[offsetof(RBX::Body,pv)==0x84?1:-1];
typedef char simbody_torque_offset[offsetof(RBX::SimBody,torque)==0x8c?1:-1];
typedef char rocket_gain_offset[offsetof(RBX::Rocket,kTurnP)==0x12c?1:-1];
