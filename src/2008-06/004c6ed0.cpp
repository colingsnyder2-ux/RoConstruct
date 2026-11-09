// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_part_interpolation_39321dab6a1be6aa.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
#include <G3D/Vector3.h>
#include <vector>

namespace RBX {

class MotorJoint {
public:
    void setCurrentAngle(float value);
};

class Assembly {
public:
    unsigned int getMotorCount();
    MotorJoint* getMotor(unsigned int index);
};

class Primitive {
public:
    Assembly* getAssembly();
};

class PartInstance {
public:
    char padding[0x228];
    Primitive primitive;

    bool getAnchored() const;
    void setCoordinateFrame(const G3D::CoordinateFrame& value);
};

struct MovementRecord {
    unsigned int time;
    G3D::CoordinateFrame coordinateFrame;
    std::vector<float> motorAngles;
};

class PartInterpolationHistory {
public:
    PartInstance* part;
    char padding[12];
    double interpolationDelay;
    int currentIndex;
    int recordCount;
    MovementRecord records[8];

    void apply(const MovementRecord& record);
    void interpolate(
        const MovementRecord& first,
        const MovementRecord& second,
        float alpha);
    bool sample(unsigned int currentTime);
};

void PartInterpolationHistory::apply(const MovementRecord& record)
{
    part->setCoordinateFrame(record.coordinateFrame);

    PartInstance* targetPart = part;
    Assembly* assembly = targetPart->primitive.getAssembly();
    if (assembly && assembly->getMotorCount() == record.motorAngles.size())
    {
        for (unsigned int i = 0; i < record.motorAngles.size(); ++i)
            assembly->getMotor(i)->setCurrentAngle(record.motorAngles[i]);
    }
}

void PartInterpolationHistory::interpolate(
    const MovementRecord& first,
    const MovementRecord& second,
    float alpha)
{
    PartInstance* targetPart = part;
    targetPart->setCoordinateFrame(
        first.coordinateFrame.lerp(second.coordinateFrame, alpha));

    if (first.motorAngles.size() == second.motorAngles.size())
    {
        PartInstance* assemblyPart = part;
        Assembly* assembly = assemblyPart->primitive.getAssembly();
        if (assembly &&
            assembly->getMotorCount() == first.motorAngles.size())
        {
            for (unsigned int i = 0; i < first.motorAngles.size(); ++i)
            {
                assembly->getMotor(i)->setCurrentAngle(
                    G3D::lerp(
                        first.motorAngles[i],
                        second.motorAngles[i],
                        alpha));
            }
        }
    }
}

bool PartInterpolationHistory::sample(unsigned int currentTime)
{
    if (part->getAnchored())
        return false;

    PartInstance* targetPart = part;
    if (!targetPart->primitive.getAssembly())
        return false;

    if (recordCount == 0)
        return true;

    if (recordCount == 1)
    {
        apply(records[currentIndex]);
        return true;
    }

    double targetTime = static_cast<double>(currentTime) - interpolationDelay;
    MovementRecord* later = 0;
    for (int i = 0; i < recordCount; ++i)
    {
        MovementRecord* record =
            &records[(currentIndex + 8 - i) % 8];
        if (static_cast<double>(record->time) > targetTime)
        {
            later = record;
            continue;
        }

        if (later)
        {
            float alpha = static_cast<float>(
                (targetTime - static_cast<double>(record->time)) /
                static_cast<float>(later->time - record->time));
            interpolate(*record, *later, alpha);
            return true;
        }

        later = record;
        break;
    }

    apply(*later);
    return true;
}

}
