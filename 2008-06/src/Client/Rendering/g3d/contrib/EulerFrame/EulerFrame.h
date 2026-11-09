/**
 @file EulerFrame.h
 @author Morgan McGuire

 An Euler-angle coordinate frame convenient for airplane simulations.
 */

class EulerFrame {
public:

    double              yaw;
    double              roll;
    double              pitch;
    Vector3             translation;

    EulerFrame();

    EulerFrame(double r, double y, double p, const Vector3& t);

    EulerFrame operator-(const EulerFrame& other) const;

    EulerFrame operator+(const EulerFrame& other) const;

    EulerFrame operator*(double s) const;

    CoordinateFrame toCoordinateFrame() const;

    EulerFrame lerp(const EulerFrame& other, double alpha) const;

    void serialize(BinaryOutput&) const;

    void deserialize(BinaryInput&);
};


EulerFrame::EulerFrame() : yaw(0), roll(0), pitch(0), translation(Vector3::ZERO) {
}


EulerFrame::EulerFrame(double r, double y, double p, const Vector3& t) :
    yaw(y), roll(r), pitch(p), translation(t) {
}


void EulerFrame::serialize(BinaryOutput& b) const {
    b.writeFloat32(roll);
    b.writeFloat32(yaw);
    b.writeFloat32(pitch);
    translation.serialize(b);
}


void EulerFrame::deserialize(BinaryInput& b) {
    roll = b.readFloat32();
    yaw  = b.readFloat32();
    pitch = b.readFloat32();
    translation.deserialize(b);
}


EulerFrame EulerFrame::lerp(const EulerFrame& other, double alpha) const {
    return EulerFrame(
        G3D::lerp(roll, other.roll, alpha),
        G3D::lerp(yaw, other.yaw, alpha),
        G3D::lerp(pitch, other.pitch, alpha),
        translation.lerp(other.translation, alpha));
}


CoordinateFrame EulerFrame::toCoordinateFrame() const {
    return CoordinateFrame(
        Matrix3::fromEulerAnglesYXZ(yaw, pitch, roll), translation);
}


EulerFrame EulerFrame::operator-(const EulerFrame& other) const {
    return EulerFrame(roll - other.roll, yaw - other.yaw,
        pitch - other.pitch, translation - other.translation);
}


EulerFrame EulerFrame::operator+(const EulerFrame& other) const {
    return EulerFrame(roll + other.roll, yaw + other.yaw,
        pitch + other.pitch, translation + other.translation);
}


EulerFrame EulerFrame::operator*(double s) const {
    return EulerFrame(roll * s, yaw * s, pitch * s, translation * s);
}
