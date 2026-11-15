#include <G3D/Table.h>

class HashableProbe : public G3D::Hashable {
public:
    HashableProbe();
    virtual unsigned int hashCode() const { return 0; }
};

HashableProbe::HashableProbe() {}
