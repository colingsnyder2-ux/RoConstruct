// DataModel access for the client, compiled with the player engine layer's headers.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlSerializer.h"
#include <boost/scoped_ptr.hpp>
#include <fstream>

RBX::DataModel* EngineDataModel();

// Rotation rows, then translation. Edit mode has no character subject.
extern "C" int P6DataCamera(float* values)
{
    RBX::DataModel* model = EngineDataModel();
    if (!model) return 1;
    RBX::DataModel::Lock lock(model);
    RBX::Camera* camera = model->getWorkspace()->getCamera();
    if (!camera) return 2;
    const G3D::CoordinateFrame frame = camera->getCameraCoordinateFrame();
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c) values[r * 3 + c] = frame.rotation[r][c];
    values[9] = frame.translation.x;
    values[10] = frame.translation.y;
    values[11] = frame.translation.z;
    return 0;
}

// rbxgs DataModel::save builds this XML and posts it; the client writes a file.
extern "C" int P6DataSave(const char* path)
{
    RBX::DataModel* model = EngineDataModel();
    if (!model) return 1;
    std::ofstream stream(path, std::ios::binary);
    if (!stream) return 2;
    RBX::DataModel::Lock lock(model);
    boost::scoped_ptr<XmlElement> root(SerializerV2::newRootElement());
    model->writeChildren(root.get());
    TextXmlWriterWithEmbeddedContent writer(stream);
    writer.serialize(root.get());
    stream.flush();
    return stream ? 0 : 3;
}
