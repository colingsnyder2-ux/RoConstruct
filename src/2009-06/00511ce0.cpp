// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <intrin.h>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    T* operator->()const{return px;}
};
}
namespace G3D {
template<class T> class Array {
public:
    T* data; int num; int numAllocated;
    void resize(int n, bool shrinkIfNecessary = true);
    T& operator[](int n) { return data[n]; }
};
}
namespace RakNet { class BitStream { int x; }; }
RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& v);
namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
namespace Network {
class NetworkSettings {
public:
    char pad[0x8c];
    bool printPhysicsErrors;
    static NetworkSettings* singleton();
};
float decodeAngle(unsigned char value);
struct Item {
    char pad[0x50];
    G3D::Array<float> motorAngles;
};
class PhysicsReceiver {
public:
    void readMotors(RakNet::BitStream& stream, Item& item);
};
void PhysicsReceiver::readMotors(RakNet::BitStream& stream, Item& item)
{
    unsigned char numMotors;
    stream >> numMotors;
    if (numMotors > 50 && NetworkSettings::singleton()->printPhysicsErrors)
        StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in has %d motors", numMotors);

    int n = numMotors;
    item.motorAngles.resize(n);
    for (int i = 0; i < n; i++)
    {
        unsigned char value;
        stream >> value;
        float angle = decodeAngle(value);
        item.motorAngles[i] = angle;
    }
}
}
}
