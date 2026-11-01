// from server: 91% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3& operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3 operator*(float s)const{return Vector3(x*s,y*s,z*s);}
 float&operator[](int i){return (&x)[i];}
};
struct Matrix3 {
 float cells[9];
 Matrix3(const Matrix3&v);
 Vector3 operator*(const Vector3&)const;
};
struct Frame {
 Matrix3 rotation;Vector3 translation;
 Frame(const Matrix3&r,const Vector3&t):rotation(r),translation(t){}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
struct Geometry {void*vtable;Vector3 size;const Vector3&getSize()const{return size;}};
struct Primitive {char opaque[0xe0];Geometry*geometry;const Frame&getCoordinateFrame()const;const Vector3&getSize()const{return geometry->getSize();}};
struct PartInstance {
 virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
 virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
 virtual bool hasSingleAxisResize() const;
 virtual void v23(); virtual void v24(); virtual void v25();
 virtual void setPartSizeXml(const Vector3&);
 char prefix[0x118-4];
 Primitive* primitive;
 const Vector3&getPartSizeXml()const{return primitive->getSize();}
 const Frame&getCoordinateFrame()const{return primitive->getCoordinateFrame();}
 Vector3 xmlToUiSize(const Vector3&)const;
 Vector3 uiToXmlSize(const Vector3&)const;
 void setCoordinateFrame(const Frame&);void join();
 bool resize(int normal,int amount);
};
bool __cdecl fuzzyEq(const Frame&,const Frame&,float,float);
bool PartInstance::resize(int normal,int amount){
 if(amount==0)return false;
 Vector3 oldSize=getPartSizeXml();
 Frame oldFrame=getCoordinateFrame();
 Vector3 delta;
 float sign=normal<3?1.0f:-1.0f;
 if(hasSingleAxisResize())delta[normal%3]=static_cast<float>(amount);
 else delta=Vector3(static_cast<float>(amount),static_cast<float>(amount),static_cast<float>(amount));
 Vector3 newUiSize=xmlToUiSize(oldSize)+delta;
 Vector3 t;
 {
 Vector3 xmlDelta=uiToXmlSize(newUiSize)-oldSize;
 t=oldFrame.vectorToWorldSpace(xmlDelta)*0.5f*sign+oldFrame.translation;
 }
 Frame desired(oldFrame.rotation,t);
 setCoordinateFrame(desired);
 {
 Vector3 finalSize=uiToXmlSize(newUiSize);
 setPartSizeXml(finalSize);
 }
 join();
 if(fuzzyEq(getCoordinateFrame(),desired,0.00001f,0.00001f))return true;
 setCoordinateFrame(oldFrame);
 setPartSizeXml(oldSize);
 return false;
}
