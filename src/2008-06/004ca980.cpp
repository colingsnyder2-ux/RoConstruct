// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
struct Vec3 {float x,y,z;};
struct Matrix3 {float v[9];};
struct Frame {Matrix3 rotation;Vec3 translation;};
// Quaternion layout and magnitude expression follow native util/Quaternion.h.
struct Quaternion {float x,y,z,w;Quaternion(const Matrix3&);void normalize(){float squared=x*x+y*y+z*z+w*w;float scale=1.0f/sqrtf(squared);x=x*scale;y=y*scale;z=z*scale;w=w*scale;}};
struct BitStream {void WriteNormQuat(float w,float x,float y,float z);};
BitStream& __cdecl writeByte(BitStream&,unsigned char);
void __cdecl writeTranslation(BitStream&,const Vec3&,bool);
unsigned char __cdecl rotationToByte(float);
struct Motor {char prefix[0x8c];float angle;};
struct Assembly {int numMotors()const;Motor* getMotor(int)const;};
struct Primitive {Assembly*getAssembly()const;};
struct Part {char prefix[0x228];Primitive primitive;const Frame& getFrame()const;};
struct Entry {Part* part;char prefix[0x44];float precision;};
struct Replicator {bool test(Part*);bool serializeId(BitStream&,Part*);};

struct Sender {char prefix[0x3c];Replicator*replicator;bool write(BitStream&,const Entry&);};
bool Sender::write(BitStream&stream,const Entry&entry){
 Part*part=entry.part;
 if(replicator->test(part))return false;
 if(!replicator->serializeId(stream,part))return false;
 const Frame&frame=part->getFrame();
 writeTranslation(stream,frame.translation,entry.precision<20.0f);
 Quaternion q(frame.rotation);q.normalize();stream.WriteNormQuat(q.w,q.x,q.y,q.z);
 Assembly*assembly=part->primitive.getAssembly();
 int count=assembly?assembly->numMotors():0;
 writeByte(stream,(unsigned char)count);
 for(int i=0;i<count;++i){
  float angle=0.0f;
  Motor*motor=assembly->getMotor(i);
  if(motor)angle=motor->angle;
  unsigned char value=rotationToByte(angle);
  writeByte(stream,value);
 }
 return true;
}
