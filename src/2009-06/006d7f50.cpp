// from server: 100% by EspClaude
// roc 2009-06 006d7f50  RBX::MultiJoint::addToMultiJoint (2009 MultiJoint +0x10)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Point;
class Connector;
class Kernel { public: void insertConnector(Connector*); };
class MultiJoint {
    unsigned char padding[0x98];
    int numConnector;
    Point* point[8];
    Connector* connector[4];
    Kernel* getKernel();
protected:
    void addToMultiJoint(Point* point0, Point* point1, Connector* _connector);
};
void MultiJoint::addToMultiJoint(Point* point0, Point* point1, Connector* _connector)
{
    point[numConnector * 2] = point0;
    point[numConnector * 2 + 1] = point1;
    this->connector[numConnector] = _connector;
    getKernel()->insertConnector(_connector);
    ++numConnector;
}
}
