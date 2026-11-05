// from server: 100% by tajop
#pragma optimize("", off)

struct Vector3 {
    float x, y, z;
};

struct Vertex {
    const Vector3& getOffset() const;
};

struct Face {
    int findEdge(const Vector3& v0, const Vector3& v1) const;
};

struct CoordinateFrame {
    Vector3 pointToObjectSpace(const Vector3& v) const;
};

struct Connector;

struct ConnectorArray {
    void push_back(Connector* const& c);
};

struct CellFaceFacePair {
    char pad0[0x20];
    const Face* mainFace;
    Connector* newFaceEdgeConnector(int edgeId, const Vertex* v0, const Vertex* v1);
    void checkOneSideIntersection(const Vertex* v0, const Vertex* v1, const CoordinateFrame& otherInMe, ConnectorArray& newConnectors);
};

void CellFaceFacePair::checkOneSideIntersection(const Vertex* v0, const Vertex* v1, const CoordinateFrame& otherInMe, ConnectorArray& newConnectors)
{
    Vector3 v0InMe = otherInMe.pointToObjectSpace(v0->getOffset());
    Vector3 v1InMe = otherInMe.pointToObjectSpace(v1->getOffset());
    int edgeId = mainFace->findEdge(v0InMe, v1InMe);
    if (edgeId >= 0) {
        newConnectors.push_back(newFaceEdgeConnector(edgeId, v0, v1));
    }
}
