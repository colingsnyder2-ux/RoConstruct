namespace RBX {
PartInstance::~PartInstance() {}
Primitive::~Primitive() {
    Geometry::GeometryType type = geometry->getGeometryType();
    if (type != Geometry::GEOMETRY_NONE) {
        delete geometry;
        delete body;
    }
    for (int i = 0; i < 6; i++) delete surfaceData[i];
}
template boost::shared_ptr<PartInstance> Creatable<Instance>::create<PartInstance>();
}
