// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vec {float x,y,z;Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}Vec& operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return *this;}Vec clamp(float,float)const;};
extern bool isDenormal(float);
extern bool isInvalid(const Vec&);
extern float low,high;
bool func(const Vec& in,Vec&out){
 Vec v=in;
 if(isDenormal(v.x))v.x=0;
 if(isDenormal(v.y))v.y=0;
 if(isDenormal(v.z))v.z=0;
 if(isInvalid(v))return false;
 v=v.clamp(low,high);
 out=v;
 return true;
}
