#include "Part.h"
#include "RbxView/View.h"
#include "v8datamodel/custommesh.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Surfaces.h"

namespace RBX
{
	namespace View
	{
		PartChunk::PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, View* view)
			: Render::Chunk(polygonOffset),
			  partInstance(partInstance),
			  view(view),
			  materialInvalid(true),
			  specialShape(NULL)
		{
			view->sceneManager->addModel(this);

			childAddedConnection = Instance::event_childAdded.connect(partInstance.get(), boost::bind(&PartChunk::onChildAdded, this, _1));
			childRemovedConnection = Instance::event_childRemoved.connect(partInstance.get(), boost::bind(&PartChunk::onChildRemoved, this, _1));
			ancestorChangedConnection = Instance::event_ancestryChanged.connect(partInstance.get(), boost::bind(&PartChunk::onAncestorChanged, this, _1));
			propertyChangedConnection = Instance::event_propertyChanged.connect(partInstance.get(), boost::bind(&PartChunk::onPropertyChanged, this, _1));

			partInstance->visitChildren(boost::bind(&PartChunk::onChildAdded, this, _1));
		}

		PartChunk::~PartChunk() {}

		G3D::ReferenceCountedPointer<Render::Mesh> PartChunk::getMesh()
		{
			if (mesh.isNull())
				updateMesh();

			return mesh;
		}

		const G3D::CoordinateFrame& PartChunk::cframe()
		{
			coordinateFrame = partInstance->getCoordinateFrame();
			return coordinateFrame;
		}

		void PartChunk::invalidateMaterial()
		{
			material = NULL;
			materialInvalid = true;
			view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
		}

		void PartChunk::invalidateMesh()
		{
			mesh = NULL;
			view->sceneManager->invalidateModel(this, partInstance->getCanAggregate());
		}

		void PartChunk::onChildAdded(boost::shared_ptr<Instance> child)
		{
			SpecialShape* mesh = dynamic_cast<SpecialShape*>(child.get());
			if (mesh)
			{
				specialShape = mesh;
				shapePropertyChangedConnection = Instance::event_propertyChanged.connect(mesh, boost::bind(&PartChunk::onSpecialShapeChanged, this));
				invalidateMesh();
			}
		}

		void PartChunk::onChildRemoved(boost::shared_ptr<Instance> child)
		{
			if (child.get() == specialShape)
			{
				shapePropertyChangedConnection.disconnect();
				specialShape = NULL;
				invalidateMesh();
			}
		}

		void PartChunk::onAncestorChanged(boost::shared_ptr<Instance> ancestor)
		{
			Workspace* workspace = Workspace::findWorkspace(partInstance.get());
			if (!workspace || !partInstance->isDescendentOf(workspace))
			{
				view->sceneManager->removeModel(this);
			}
		}

		void PartChunk::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
		{
			if (*descriptor == PartInstance::prop_Size)
			{
				invalidateMesh();
				invalidateMaterial();
			}
			else if (*descriptor == PartInstance::prop_shapeXml)
			{
				invalidateMesh();
			}
			else if (Surfaces::isSurfaceDescriptor(*descriptor))
			{
				invalidateMesh();
			}
		}

		void PartChunk::onSpecialShapeChanged()
		{
			invalidateMesh();
			invalidateMaterial();
		}

		Part::Part(const boost::shared_ptr<PartInstance>& partInstance, View* view)
			: PartChunk(0.0f, partInstance, view)
		{
			if (partInstance->getCanAggregate())
				view->sceneManager->setSleeping(this, true);

			Notifier<PartInstance, CanAggregateChanged>::connect(partInstance, this);
			invalidateMesh();
			invalidateMaterial();
		}

		Part::~Part()
		{
			Notifier<PartInstance, CanAggregateChanged>::disconnect(partInstance, this);
		}

		void Part::onEvent(const PartInstance* source, CanAggregateChanged event)
		{
			view->sceneManager->setSleeping(this, event.canClump);
		}
	}
}
