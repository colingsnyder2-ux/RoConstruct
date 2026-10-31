// from server: 85% by EspClaude
// from server: 100% by coldek
// roc 2008-06 00644a30  unit: RBX::HUMAN::Climbing  size: 585 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00644a30
//
// 00644a30  83ec5c               sub esp, 0x5c
// 00644a33  53                   push ebx
// 00644a34  55                   push ebp
// 00644a35  56                   push esi
// 00644a36  8bf1                 mov esi, ecx
// 00644a38  8b4e08               mov ecx, dword ptr [esi + 8]
// 00644a3b  57                   push edi
// 00644a3c  e81f47f9ff           call 0x5d9160
// 00644a41  8bf8                 mov edi, eax
// 00644a43  8bcf                 mov ecx, edi
// 00644a45  e81649f5ff           call 0x599360
// 00644a4a  8b4608               mov eax, dword ptr [esi + 8]
// 00644a4d  50                   push eax
// 00644a4e  81c794000000         add edi, 0x94
// 00644a54  e887ffffff           call 0x6449e0
// 00644a59  d905608b8200         fld dword ptr [0x828b60]
// 00644a5f  83c404               add esp, 4
// 00644a62  d95c2410             fstp dword ptr [esp + 0x10]
// 00644a66  6a02                 push 2
// 00644a68  8d4c2418             lea ecx, [esp + 0x18]
// 00644a6c  51                   push ecx
// 00644a6d  8bcf                 mov ecx, edi
// 00644a6f  8bd8                 mov ebx, eax
// 00644a71  e8cae7ecff           call 0x513240
// 00644a76  d900                 fld dword ptr [eax]
// 00644a78  d9442410             fld dword ptr [esp + 0x10]
// 00644a7c  6a00                 push 0
// 00644a7e  dcc9                 fmul st(1), st(0)
// 00644a80  6a00                 push 0
// 00644a82  d94004               fld dword ptr [eax + 4]
// 00644a85  d8c9                 fmul st(1)
// 00644a87  d94008               fld dword ptr [eax + 8]
// 00644a8a  deca                 fmulp st(2)
// 00644a8c  d90534c48100         fld dword ptr [0x81c434]
// 00644a92  dccb                 fmul st(3), st(0)
// 00644a94  dcc9                 fmul st(1), st(0)
// 00644a96  deca                 fmulp st(2)
// 00644a98  d905ac9b8100         fld dword ptr [0x819bac]
// 00644a9e  dccb                 fmul st(3), st(0)
// 00644aa0  dcc9                 fmul st(1), st(0)
// 00644aa2  deca                 fmulp st(2)
// 00644aa4  d94724               fld dword ptr [edi + 0x24]
// 00644aa7  dec3                 faddp st(3)
// 00644aa9  d84728               fadd dword ptr [edi + 0x28]
// 00644aac  d9472c               fld dword ptr [edi + 0x2c]
// 00644aaf  8d7e14               lea edi, [esi + 0x14]
// 00644ab2  dec2                 faddp st(2)
// 00644ab4  8bcf                 mov ecx, edi
// 00644ab6  d9c2                 fld st(2)
// 00644ab8  d9e8                 fld1 
// 00644aba  dcc1                 fadd st(1), st(0)
// 00644abc  d9c2                 fld st(2)
// 00644abe  d9c4                 fld st(4)
// 00644ac0  d8c2                 fadd st(2)
// 00644ac2  d9ce                 fxch st(6)
// 00644ac4  d8e2                 fsub st(2)
// 00644ac6  d9cc                 fxch st(4)
// 00644ac8  d825b8788300         fsub dword ptr [0x8378b8]
// 00644ace  d9cd                 fxch st(5)
// 00644ad0  dee2                 fsubrp st(2)
// 00644ad2  d9cb                 fxch st(3)
// 00644ad4  d95c242c             fstp dword ptr [esp + 0x2c]
// 00644ad8  d9cb                 fxch st(3)
// 00644ada  d95c2430             fstp dword ptr [esp + 0x30]
// 00644ade  d9ca                 fxch st(2)
// 00644ae0  d95c2434             fstp dword ptr [esp + 0x34]
// 00644ae4  d9c9                 fxch st(1)
// 00644ae6  d95c2438             fstp dword ptr [esp + 0x38]
// 00644aea  d95c243c             fstp dword ptr [esp + 0x3c]
// 00644aee  d95c2440             fstp dword ptr [esp + 0x40]
// 00644af2  e8e98efeff           call 0x62d9e0
// 00644af7  57                   push edi
// 00644af8  6a00                 push 0
// 00644afa  8d54242c             lea edx, [esp + 0x2c]
// 00644afe  52                   push edx
// 00644aff  8bcb                 mov ecx, ebx
// 00644b01  e85a90feff           call 0x62db60
// 00644b06  8b4608               mov eax, dword ptr [esi + 8]
// 00644b09  8b7618               mov esi, dword ptr [esi + 0x18]
// 00644b0c  8ba804010000         mov ebp, dword ptr [eax + 0x104]
// 00644b12  33db                 xor ebx, ebx
// 00644b14  85f6                 test esi, esi
// 00644b16  7e36                 jle 0x644b4e
// 00644b18  8b3f                 mov edi, dword ptr [edi]
// 00644b1a  8d9b00000000         lea ebx, [ebx]
// 00644b20  8b07                 mov eax, dword ptr [edi]
// 00644b22  8b8804010000         mov ecx, dword ptr [eax + 0x104]
// 00644b28  89442410             mov dword ptr [esp + 0x10], eax
// 00644b2c  3be9                 cmp ebp, ecx
// 00644b2e  7416                 je 0x644b46
// 00644b30  85c9                 test ecx, ecx
// 00644b32  0f84f6000000         je 0x644c2e
// 00644b38  55                   push ebp
// 00644b39  e8a2dfddff           call 0x422ae0
// 00644b3e  84c0                 test al, al
// 00644b40  0f84e8000000         je 0x644c2e
// 00644b46  43                   inc ebx
// 00644b47  83c704               add edi, 4
// 00644b4a  3bde                 cmp ebx, esi
// 00644b4c  7cd2                 jl 0x644b20
// 00644b4e  8b7c2470             mov edi, dword ptr [esp + 0x70]
// 00644b52  85ff                 test edi, edi
// 00644b54  0f84c8000000         je 0x644c22
// 00644b5a  e8c1f2ecff           call 0x513e20
// 00644b5f  50                   push eax
// 00644b60  8d4c2440             lea ecx, [esp + 0x40]
// 00644b64  e8b7e6ecff           call 0x513220
// 00644b69  f60550f0960001       test byte ptr [0x96f050], 1
// 00644b70  751b                 jne 0x644b8d
// 00644b72  d9ee                 fldz 
// 00644b74  830d50f0960001       or dword ptr [0x96f050], 1
// 00644b7b  d91544f09600         fst dword ptr [0x96f044]
// 00644b81  d91548f09600         fst dword ptr [0x96f048]
// 00644b87  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00644b8d  d90544f09600         fld dword ptr [0x96f044]
// 00644b93  8b17                 mov edx, dword ptr [edi]
// 00644b95  8b5238               mov edx, dword ptr [edx + 0x38]
// 00644b98  d95c2460             fstp dword ptr [esp + 0x60]
// 00644b9c  d90548f09600         fld dword ptr [0x96f048]
// 00644ba2  8d44243c             lea eax, [esp + 0x3c]
// 00644ba6  d95c2464             fstp dword ptr [esp + 0x64]
// 00644baa  50                   push eax
// 00644bab  d9054cf09600         fld dword ptr [0x96f04c]
// 00644bb1  8bcf                 mov ecx, edi
// 00644bb3  d95c246c             fstp dword ptr [esp + 0x6c]
// 00644bb7  ffd2                 call edx
// 00644bb9  d9e8                 fld1 
// 00644bbb  8b37                 mov esi, dword ptr [edi]
// 00644bbd  d95c2414             fstp dword ptr [esp + 0x14]
// 00644bc1  83c640               add esi, 0x40
// 00644bc4  d905f8498200         fld dword ptr [0x8249f8]
// 00644bca  d9542418             fst dword ptr [esp + 0x18]
// 00644bce  d95c241c             fstp dword ptr [esp + 0x1c]
// 00644bd2  d905ac9b8100         fld dword ptr [0x819bac]
// 00644bd8  d95c2420             fstp dword ptr [esp + 0x20]
// 00644bdc  d9442424             fld dword ptr [esp + 0x24]
// 00644be0  d95c243c             fstp dword ptr [esp + 0x3c]
// 00644be4  d9442428             fld dword ptr [esp + 0x28]
// 00644be8  d95c2440             fstp dword ptr [esp + 0x40]
// 00644bec  d944242c             fld dword ptr [esp + 0x2c]
// 00644bf0  d95c2444             fstp dword ptr [esp + 0x44]
// 00644bf4  d9442430             fld dword ptr [esp + 0x30]
// 00644bf8  d95c2448             fstp dword ptr [esp + 0x48]
// 00644bfc  d9442434             fld dword ptr [esp + 0x34]
// 00644c00  d95c244c             fstp dword ptr [esp + 0x4c]
// 00644c04  d9442438             fld dword ptr [esp + 0x38]
// 00644c08  d95c2450             fstp dword ptr [esp + 0x50]
// 00644c0c  e8ff621700           call 0x7baf10
// 00644c11  8b16                 mov edx, dword ptr [esi]
// 00644c13  50                   push eax
// 00644c14  8d442418             lea eax, [esp + 0x18]
// 00644c18  50                   push eax
// 00644c19  8d4c2444             lea ecx, [esp + 0x44]
// 00644c1d  51                   push ecx
// 00644c1e  8bcf                 mov ecx, edi
// 00644c20  ffd2                 call edx
// 00644c22  5f                   pop edi
// 00644c23  5e                   pop esi
// 00644c24  5d                   pop ebp
// 00644c25  32c0                 xor al, al
// 00644c27  5b                   pop ebx
// 00644c28  83c45c               add esp, 0x5c
// 00644c2b  c20400               ret 4
// 00644c2e  8b742470             mov esi, dword ptr [esp + 0x70]
// 00644c32  85f6                 test esi, esi
// 00644c34  7437                 je 0x644c6d
// 00644c36  e875fcecff           call 0x5148b0
// 00644c3b  d900                 fld dword ptr [eax]
// 00644c3d  d95c2414             fstp dword ptr [esp + 0x14]
// 00644c41  8d4c2414             lea ecx, [esp + 0x14]
// 00644c45  d94004               fld dword ptr [eax + 4]
// 00644c48  51                   push ecx
// 00644c49  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00644c4d  d95c241c             fstp dword ptr [esp + 0x1c]
// 00644c51  d94008               fld dword ptr [eax + 8]
// 00644c54  56                   push esi
// 00644c55  d95c2424             fstp dword ptr [esp + 0x24]
// 00644c59  d9e8                 fld1 
// 00644c5b  d95c2428             fstp dword ptr [esp + 0x28]
// 00644c5f  e82c5ef5ff           call 0x59aa90
// 00644c64  50                   push eax
// 00644c65  e896210300           call 0x676e00
// 00644c6a  83c40c               add esp, 0xc
// 00644c6d  5f                   pop edi
// 00644c6e  5e                   pop esi
// 00644c6f  5d                   pop ebp
// 00644c70  b001                 mov al, 1
// 00644c72  5b                   pop ebx
// 00644c73  83c45c               add esp, 0x5c
// 00644c76  c20400               ret 4

// from server: 98% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3 operator*(float s)const{return Vector3(x*s,y*s,z*s);}
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 static const Vector3&zero(){static const Vector3 v(0,0,0);return v;}
 static const Vector3&unitX();
};
struct Matrix3 {
 float cells[9];Matrix3(){}Matrix3(const Matrix3&v){*this=v;}
 Matrix3&operator=(const Matrix3&);
 Vector3 getColumn(int)const;static const Matrix3&identity();
};
extern const float zLookDirection;
struct Frame {
 Matrix3 rotation;Vector3 translation;
 Frame():rotation(Matrix3::identity()),translation(Vector3::zero()){}
 Vector3 lookVector()const{return rotation.getColumn(2)*zLookDirection;}
};
struct Extents {Vector3 low,high;Extents(const Vector3&l,const Vector3&h):low(l),high(h){}};
struct AABox {Vector3 low,high;AABox(const Vector3&l,const Vector3&h){low=l;high=h;}};
struct Color4 {float r,g,b,a;Color4(float x,float y,float z,float w):r(x),g(y),b(z),a(w){}Color4(const Vector3&v,float w):r(v.x),g(v.y),b(v.z),a(w){}static const Color4&zero();};
struct Adorn {
 virtual ~Adorn();
 virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();
 virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();
 virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();
 virtual void setObjectToWorldMatrix(const Frame&)=0;
 virtual void setColor(const Color4&)=0;
 virtual void box(const AABox&,const Color4&,const Color4&)=0;
};
struct Part;
struct Instance {char prefix[0x104];Instance*parent;bool isDescendantOf(const Instance*ancestor)const{if(ancestor==parent)return true;if(!parent)return false;return parent->isDescendantOf(ancestor);}};
struct PartInstance:public Instance {const Part&getPart()const;};
struct Body {char prefix[0x94];Frame frame;void updatePV()const;const Frame&getFrame()const{updatePV();return frame;}};
struct Humanoid:public Instance {Body*getTorsoBody()const;};
struct PartArray {PartInstance**data;int count,capacity;void resize(int,bool);int size()const{return count;}PartInstance**getCArray(){return data;}PartInstance*const&operator[](int i)const{return data[i];}};
struct Query {void collect(const Extents&,PartInstance*,PartArray*);};
Query* __cdecl findQuery(Instance*);
void __cdecl selectionBox(const Part&,Adorn*,const Color4&);
struct Climbing {char prefix[8];Humanoid*humanoid;char reserved[8];PartArray parts;bool check(Adorn*);};
bool Climbing::check(Adorn*adorn){
 const Frame&frame=humanoid->getTorsoBody()->getFrame();
 Query*query=findQuery(humanoid);
 Vector3 center=frame.translation+frame.lookVector()*2.0f*0.5f;
 Extents bounds(center-Vector3(1,2.7f,1),center+Vector3(1,0,1));
 parts.resize(0,false);
 query->collect(bounds,0,&parts);
 Instance*character=humanoid->parent;
 int count=parts.size();
 for(int i=0;i<count;++i){
  PartInstance*part=parts.getCArray()[i];
  if(!part->isDescendantOf(character)){
   if(adorn)selectionBox(part->getPart(),adorn,Color4(Vector3::unitX(),1));
   return true;
  }
 }
 if(adorn){
  adorn->setObjectToWorldMatrix(Frame());
  adorn->box(AABox(bounds.low,bounds.high),Color4(1,.2f,.2f,.5f),Color4::zero());
 }
 return false;
}
