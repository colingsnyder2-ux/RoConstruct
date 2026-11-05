// from server: 100% by coldek
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
