// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
class Body;
class IStage { public: virtual ~IStage(); virtual int getStageType() const; };
class Geometry {
public:
    virtual ~Geometry();
    virtual void g1(); virtual void g2(); virtual void g3();
    virtual float getRadius() const;
};
class Ball : public Geometry {};
class Primitive {
public:
    char pad[0x9c];
    Geometry* geometry;
    Body* body;
    Geometry* getGeometry() const { return geometry; }
    Body* getBody() const { return body; }
};
class GeoPair {
public:
    char pad0[8];
    int geoPairType;
    char pad1[0x14];
    float radius0;
    float radiusSum;
    void setBallBall(float r0, float rs) { radius0 = r0; radiusSum = rs; geoPairType = 0; }
};
class ContactConnector : public GeoPair {};
class IPipelined {
public:
    virtual ~IPipelined();
    IStage* currentStage;
    bool inKernel() const { return currentStage->getStageType() == 7; }
};
class Edge : public IPipelined {
public:
    int pad8;
    Primitive* prim0;
    Primitive* prim1;
    Primitive* getPrimitive(int index) const { return (&prim0)[index]; }
};
class Contact : public Edge {
public:
    char pad14[0x20];
protected:
    Body* getBody(int index) const { return getPrimitive(index)->getBody(); }
    ContactConnector* createConnector(Body* b0, Body* b1);
    virtual void x1(); virtual void x2(); virtual void x3(); virtual void x4();
    virtual void deleteAllConnectors() = 0;
    virtual bool stepContact() = 0;
public:
    virtual bool computeIsColliding(float overlapIgnored) = 0;
};
class BallBallContact : public Contact {
public:
    ContactConnector* ballBallConnector;
    Ball* ball(int index) { return static_cast<Ball*>(getPrimitive(index)->getGeometry()); }
    virtual void deleteAllConnectors();
    virtual bool stepContact();
    virtual bool computeIsColliding(float overlapIgnored);
};
bool BallBallContact::stepContact()
{
    if (BallBallContact::computeIsColliding(0.0f)) {
        if (inKernel()) {
            if (ballBallConnector == 0) {
                ballBallConnector = createConnector(getBody(0), getBody(1));
            }
            Ball* ball1 = ball(1);
            Ball* ball0 = ball(0);
            ContactConnector* connector = ballBallConnector;
            float radius0 = ball0->getRadius();
            float radius1 = ball1->getRadius();
            connector->setBallBall(radius0, radius0 + radius1);
        }
        return true;
    }
    deleteAllConnectors();
    return false;
}
}
