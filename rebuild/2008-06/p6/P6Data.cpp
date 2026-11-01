// DataModel access for the client, compiled with the player engine layer's headers.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlSerializer.h"
#include <boost/scoped_ptr.hpp>
#include <fstream>
#include "P6Engine.h"

RBX::DataModel* EngineDataModel();

static void walk(RBX::Instance* item, int depth, P6TreeVisitor visitor, void* context)
{
    visitor(depth, item->getClassName().toString().c_str(), item->getName().c_str(), item, context);
    if (!item->getChildren()) return;
    boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > children = item->getChildren().read();
    for (size_t i = 0; i < children->size(); ++i) walk((*children)[i].get(), depth + 1, visitor, context);
}

extern "C" void P6DataWalk(P6TreeVisitor visitor, void* context)
{
    RBX::DataModel* model = EngineDataModel();
    if (!model) return;
    RBX::DataModel::Lock lock(model);
    walk(model, 0, visitor, context);
}

// Tree items can outlive their instance, so resolve them against the live model.
static bool contains(RBX::Instance* item, const void* wanted)
{
    if (item == wanted) return true;
    if (!item->getChildren()) return false;
    boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > children = item->getChildren().read();
    for (size_t i = 0; i < children->size(); ++i)
        if (contains((*children)[i].get(), wanted)) return true;
    return false;
}

extern "C" int P6DataProperties(void* handle, P6PropertyVisitor visitor, void* context)
{
    RBX::DataModel* model = EngineDataModel();
    if (!model) return 1;
    RBX::DataModel::Lock lock(model);
    if (!contains(model, handle)) return 2;
    RBX::Instance* item = static_cast<RBX::Instance*>(handle);
    int count = 0;
    const RBX::Reflection::ClassDescriptor& type = item->getDescriptor();
    for (RBX::Reflection::PropertyContainer::CollectionType::const_iterator iter = type.RBX::Reflection::PropertyContainer::descriptors_begin();
         iter != type.RBX::Reflection::PropertyContainer::descriptors_end(); ++iter) {
        const RBX::Reflection::PropertyDescriptor& descriptor = **iter;
        if (!descriptor.hasStringValue() || descriptor.name == "CoordinateFrame") continue; // ponytail: its string conversion hangs; CFrame shows the same value
        visitor(descriptor.category.c_str(), descriptor.name.c_str(), descriptor.getStringValue(item).c_str(), descriptor.isReadOnly(), context);
        ++count;
    }
    return -count;
}

extern "C" int P6DataSetProperty(void* handle, const char* name, const char* value)
{
    RBX::DataModel* model = EngineDataModel();
    if (!model) return 1;
    RBX::DataModel::Lock lock(model);
    if (!contains(model, handle)) return 2;
    RBX::Instance* item = static_cast<RBX::Instance*>(handle);
    RBX::Reflection::PropertyIterator iter = item->findProperty(RBX::Name::declare(name, -1));
    if (iter == item->properties_end()) return 3;
    return (*iter).getDescriptor().setStringValue(item, value) ? 0 : 4;
}

// Rotation rows, translation, then horizontal field of view. Edit mode has no character subject.
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
    values[12] = float(camera->getGCamera().getFieldOfView());
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
