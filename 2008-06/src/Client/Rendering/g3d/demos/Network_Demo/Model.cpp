#include "Model.h"

void PositionOverride::beforePrimitive(RenderDevice* renderDevice) {
    renderDevice->setObjectToWorldMatrix(cframe);
    material.configure(renderDevice);
}


void PositionOverride::afterPrimitive(RenderDevice* renderDevice) {
}


Pose::Pose() : rotorAngle(0) {}

Helicopter::Helicopter(const std::string& dataDir) {
    IFSModelRef bodyModel  = IFSModel::create(dataDir + "ifs/ah64-body.ifs", 8.5);
    IFSModelRef rotorModel = IFSModel::create(dataDir + "ifs/ah64-rotor.ifs", 8.5);

    body  = bodyModel->pose();
    rotor = rotorModel->pose();
    positionShader = PositionOverrideRef(new PositionOverride());
}


HelicopterRef Helicopter::create(const std::string& dataDir) {
    return new Helicopter(dataDir);
}


void Helicopter::render(
    RenderDevice*           rd,
    const CoordinateFrame&  cframe, 
    const Pose&             pose, 
    const GMaterial&        material) const {

    rd->setShader(positionShader);

    positionShader->material = material;
    positionShader->cframe = cframe;
    body->render(rd);

    positionShader->material.color = Color3::black();

    Matrix3 rot1 = Matrix3::fromAxisAngle(Vector3::UNIT_Z, pose.rotorAngle);
    Matrix3 rot2 = Matrix3::fromAxisAngle(Vector3::UNIT_X, toRadians(-90));

    positionShader->cframe.rotation = positionShader->cframe.rotation * rot2 * rot1;
    positionShader->cframe.translation += 
        cframe.rotation.getColumn(1) * 0.85f +
        cframe.rotation.getColumn(2) * -2.25f;

    rotor->render(rd);

    rd->setShader(NULL);
}

