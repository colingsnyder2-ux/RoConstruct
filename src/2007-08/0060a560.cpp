// from server: 100% by EspClaude
// roc 2007-08 0060a560  unit: RBX::MultiJoint  size: 272 bytes
// MultiJoint::removeFromKernel (rbxgs v8world/MutilJoint.cpp) with the 2007 Kernel::removeConnector
// inlined: realTimeConnectors (G3D::Array @+0x10) resize(0,false) + IndexArray connectors @+0x34 fastRemove.
// Offsets from the target.
// roc-flags: /O2 /GS /EHsc /MD
namespace G3D {
template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    void resize(int n, bool shrinkIfNecessary = true);
    int size() const { return num; }
    T& operator[](int n) { return data[n]; }
};
}
namespace RBX {
class Point;
class Connector {
public:
    virtual ~Connector();
    int& getKernelIndex();
};
template <typename tInstance, int& (tInstance::*getIndex)()>
class IndexArray {
private:
    G3D::Array<tInstance*> array;
    int& indexOf(tInstance* instance) const { return (instance->*getIndex)(); }
public:
    int size() const { return array.size(); }
    void fastRemove(tInstance* item)
    {
        int removeIndex = indexOf(item);
        tInstance* movedItem = array[size() - 1];
        array[removeIndex] = movedItem;
        indexOf(movedItem) = removeIndex;
        array.resize(array.size() - 1, false);
        indexOf(item) = -1;
    }
};
class Kernel {
    char pad0[0x10];
    G3D::Array<Connector*> realTimeConnectors;
    char pad1[0x34 - 0x1c];
    IndexArray<Connector, &Connector::getKernelIndex> connectors;
public:
    void deletePoint(Point* p);
    void removeConnector(Connector* c)
    {
        realTimeConnectors.resize(0, false);
        connectors.fastRemove(c);
    }
};
class IPipelined {
    char pad[0x88];
public:
    Kernel* getKernel();
    void removeFromKernel();
};
class MultiJoint : public IPipelined {
    int numConnector;
    Point* point[8];
    Connector* connector[4];
    int numBreakingConnectors;
public:
    void removeFromKernel();
};

void MultiJoint::removeFromKernel()
{
    for (int i = 0; i < numConnector; i++)
    {
        getKernel()->deletePoint(point[(i*2)]);
        getKernel()->deletePoint(point[(i*2)+1]);
        point[(i*2)] = 0;
        point[(i*2)+1] = 0;

        getKernel()->removeConnector(connector[i]);
        delete connector[i];
        connector[i] = 0;
    }

    numConnector = 0;

    IPipelined::removeFromKernel();
}
}
