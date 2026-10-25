// G3D core: vector/matrix/quaternion math, containers and binary serialization.
#include "G3D/Vector3.h"
#include "G3D/Matrix3.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Quat.h"
#include "G3D/Array.h"
#include "G3D/Table.h"
#include "G3D/BinaryOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/format.h"
#include <stdio.h>
#include <math.h>
using namespace G3D;

int main()
{
    int failures = 0;
    Vector3 x(1, 0, 0), y(0, 1, 0);
    if (x.cross(y) != Vector3(0, 0, 1)) ++failures;
    Matrix3 rot = Matrix3::fromAxisAngle(Vector3(0, 0, 1), (float)G3D_PI / 2);
    Vector3 r = rot * x;
    if (fabs(r.x) > 1e-5 || fabs(r.y - 1) > 1e-5) ++failures;
    CoordinateFrame frame(rot, Vector3(10, 0, 0));
    if ((frame.pointToWorldSpace(x) - Vector3(10, 1, 0)).length() > 1e-4) ++failures;
    Quat q(rot);
    if ((q.toRotationMatrix() * x - r).length() > 1e-4) ++failures;

    Array<int> values;
    for (int i = 0; i < 100; ++i) values.append(i * i);
    if (values.size() != 100 || values.last() != 9801) ++failures;
    Table<std::string, int> table;
    table.set("a", 1); table.set("b", 2);
    if (!table.containsKey("b") || table["a"] != 1) ++failures;

    BinaryOutput out("<memory>", G3D_LITTLE_ENDIAN);
    out.writeInt32(0x12345678); out.writeFloat32(2.5f); out.writeString("roc");
    BinaryInput in(out.getCArray(), out.size(), G3D_LITTLE_ENDIAN, false, true);
    if (in.readInt32() != 0x12345678 || in.readFloat32() != 2.5f || in.readString() != "roc") ++failures;

    printf("%s failures=%d\n", format("g3d %d.%02d", G3D_VER / 10000, (G3D_VER / 100) % 100).c_str(), failures);
    return failures;
}
