// from server: 100% by EspClaude
// roc 2008-06 004c8150  unit: RBX::Network
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <vector>
#include <stdexcept>

namespace boost {
template<class T>
class shared_ptr {
public:
    T* px;
    void* pn;
    T* operator->() const { return px; }
    ~shared_ptr();
};
}

namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 { public: float elt[3][3]; };
class Quat {
public:
    float x, y, z, w;
    Quat() : x(0), y(0), z(0), w(1) {}
    void toRotationMatrix(Matrix3& rot) const;
};
}

namespace RakNet {
class BitStream {
public:
    bool ReadNormQuat(float& w, float& x, float& y, float& z);
};
}
RakNet::BitStream& operator>>(RakNet::BitStream& stream, G3D::Vector3& v);
RakNet::BitStream& operator>>(RakNet::BitStream& stream, unsigned char& v);

namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
class Instance {
public:
    bool isAncestorOf(const Instance* descendant) const;
};
class PVInstance;
namespace Network {
class NetworkSettings {
public:
    char pad[0x130];
    bool printPhysicsErrors;
    static NetworkSettings* singleton();
};
float decodeAngle(unsigned char value);

class PhysicsReceiver {
public:
    struct Item {
        unsigned int time;
        G3D::Matrix3 rotation;
        G3D::Vector3 position;
        std::vector<float> motorAngles;
    };
    struct Owner { char pad[0x104]; Instance* character; };
    Owner* owner;
    char pad[0xc];
    double averageInterval;
    int index;
    int count;
    Item items[8];

    void readItem(RakNet::BitStream* stream, unsigned int time, Instance* part);
};

void PhysicsReceiver::readItem(RakNet::BitStream* stream, unsigned int time, Instance* part)
{
    index = (index + 9) % 8;
    if (count < 8)
        count++;

    Item& item = items[index];
    item.time = time;

    *stream >> item.position;

    G3D::Quat q;
    if (!stream->ReadNormQuat(q.w, q.x, q.y, q.z))
        throw std::runtime_error("Failed to read Quaternion");
    q.toRotationMatrix(item.rotation);

    unsigned char numMotors;
    *stream >> numMotors;
    if (numMotors > 50 && NetworkSettings::singleton()->printPhysicsErrors)
        StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in has %d motors", numMotors);

    int n = numMotors;
    item.motorAngles.resize(n, 0.0f);
    for (int i = 0; i < n; i++)
    {
        unsigned char value;
        *stream >> value;
        float angle = decodeAngle(value);
        item.motorAngles[i] = angle;
    }

    if (part && owner && (part == owner->character || (owner->character && owner->character->isAncestorOf(part))))
    {
        averageInterval = 0.0;
    }
    else if (count >= 2)
    {
        const Item& previous = items[(index + 7) % 8];
        double interval = (unsigned int)(item.time - previous.time);
        if (interval > averageInterval)
            averageInterval = averageInterval * 0.2 + interval * 0.8;
        else
            averageInterval = averageInterval * 0.8 + interval * 0.2;
    }
}
}
}
