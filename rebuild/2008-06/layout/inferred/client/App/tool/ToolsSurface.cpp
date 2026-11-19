#include "tool/ModelTools.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "util/Sound.h"

namespace RBX {
Instance* findUnanchoredPart(Instance* instance)
{
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        if (!part->getAnchored()) return part;
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > children = instance->children.read();
    if (children) {
        std::vector<boost::shared_ptr<Instance> >::const_iterator end = children->end();
        std::vector<boost::shared_ptr<Instance> >::const_iterator it = children->begin();
        for (; it != end; ++it)
            if (findUnanchoredPart(it->get())) return it->get();
    }
    return NULL;
}

void applyAnchored(Instance* instance, const bool& value)
{
    bool local = value;
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        part->setAnchored(local);
    else {
        Instance::AnchorAction action = { local };
        instance->applyAnchoredToChildren(action);
    }
}

void AnchorTool::onMouseHover(const UIEvent& input)
{
    boost::shared_ptr<Instance> previous = target;
    ModelTool::onMouseHover(input);
    if (previous != target) {
        bool value = target ? findUnanchoredPart(target.get()) == NULL : false;
        anchored = value;
    }
}

MouseCommand* AnchorTool::onMouseDown(const UIEvent&)
{
    if (target && !PartInstance::getLocked(target.get())) {
        bool value = findUnanchoredPart(target.get()) != NULL;
        applyAnchored(target.get(), value);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(PING_SOUND);
    }
    return this;
}
}

// Unsplit: combined from AxisMoveToolCore/Bounds/Down/Move/Render/Methods (mew 5fe2214 layout unsplit for native-doc).
#include "v8datamodel/DataModel.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "StandardVerbs.h"
#include "v8datamodel/Selection.h"
#include "tool/Dragger.h"
#include "tool/DragUtilities.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/Extents.h"
#include "util/Math.h"
#include "AppDraw/DrawAdorn.h"
#include <algorithm>

namespace RBX {

char sAxisMoveTool[] = "AxisMove";

bool hitMoveHandles(const Extents&, const G3D::Ray&, G3D::Vector3&, NormalId&);
void recordCameraHistory(const char*, const Instance*);

AxisMoveTool::AxisMoveTool(Workspace* w)
	: Named<ArrowToolBase, sAxisMoveTool>(w), cursor("ArrowCursor"), dragging(false) {}

template<> MouseCommand* TToolVerb<AxisMoveTool, RunStateVerb>::newMouseCommand() {
	return new AxisMoveTool(dataModel->getWorkspace());
}
template<> const Name& Named<ArrowToolBase, sAxisMoveTool>::getName() const {
	return NativeToolName<AxisMoveTool>::get();
}

void __cdecl collectPart(boost::shared_ptr<Instance> value, std::vector<Primitive*>* parts) {
	DragUtilities::getPrimitives(value.get(), *parts);
}
struct AxisBoundsCallback {
	void (__cdecl* function)(boost::shared_ptr<Instance>, std::vector<Primitive*>*);
	std::vector<Primitive*>* parts;
	AxisBoundsCallback(void (__cdecl* f)(boost::shared_ptr<Instance>, std::vector<Primitive*>*), std::vector<Primitive*>* p)
		: function(f), parts(p) {}
	void operator()(const boost::shared_ptr<Instance>& p) { function(p, parts); }
};
bool AxisMoveTool::bounds(Extents& out) {
	ServiceClient<Selection> selection(workspace);
	std::vector<Primitive*> parts;
	std::for_each(selection->selection->begin(), selection->selection->end(), AxisBoundsCallback(collectPart, &parts));
	if (parts.size() > 0) { out = Dragger::computeExtents(parts); return true; }
	return false;
}

bool AxisMoveTool::hitHandle(const UIEvent& event, G3D::Vector3& point, NormalId& face) {
	Extents box;
	if (bounds(box)) {
		if (hitMoveHandles(box, getUnitMouseRay(event), point, face)) return true;
	}
	return false;
}
MouseCommand* AxisMoveTool::onMouseDown(const UIEvent& event) {
	G3D::Vector3 point;
	NormalId face;
	if (hitHandle(event, point, face)) {
		mouseDownView = event.mousePosition;
		axis = face % 3;
		dragPoint = Math::toGrid(point, axisMoveGrid());
		dragRay = G3D::Ray::fromOriginAndDirection(dragPoint, normalIdToVector3(face));
		capture();
		return this;
	}
	return ArrowToolBase::onMouseDown(event);
}

void AxisMoveTool::onMouseMove(const UIEvent& event) {
	if (!dragging && (G3D::Vector2(event.mousePosition) - G3D::Vector2(mouseDownView)).length() > 4.0f) {
		ServiceClient<FilteredSelection<PVInstance> > selection(workspace);
		megaDragger.reset(new MegaDragger(0, selection->items(), workspace));
		megaDragger->startDragging(); megaDragger->alignAndCleanParts(); dragging = true;
	}
	if (dragging && megaDragger->anyDragPartAlive()) {
		G3D::Vector3 hit = Math::closestPointOnRay(dragRay, getUnitMouseRay(event));
		hit = Math::toGrid(hit, axisMoveGrid());
		G3D::Vector3 delta = Math::toGrid(hit - dragPoint, axisMoveGrid());
		if (delta != G3D::Vector3::zero()) {
			megaDragger->continueDragging();
			G3D::Vector3 moved = megaDragger->safeMoveAlongLine(delta);
			if (moved != G3D::Vector3::zero()) dragPoint = Math::toGrid(dragPoint + moved, axisMoveGrid());
		}
	}
}

void AxisMoveTool::render2d(Adorn* adorn) {
	Extents box;
	if (bounds(box)) {
		G3D::CoordinateFrame frame(box.center());
		G3D::Vector3 size = box.size();
		DrawAdorn::handles2d(size, frame, workspace->getGCamera(), adorn, G3D::Color3::orange());
	}
}
void AxisMoveTool::render3dAdorn(Adorn* adorn) {
	Extents box;
	if (bounds(box)) {
		G3D::CoordinateFrame frame(box.center());
		G3D::Vector3 size = box.size();
		DrawAdorn::handles3d(size, frame, adorn, HANDLE_MOVE,
			workspace->getGCamera().getCoordinateFrame().translation);
	}
}

MouseCommand* AxisMoveTool::isSticky() const { return new AxisMoveTool(workspace); }
MouseCommand* AxisMoveTool::onMouseUp(const UIEvent&) {
	if (dragging) {
		megaDragger->finishDragging();
		megaDragger.release();
		dragging = false;
		recordCameraHistory(getName().c_str(), workspace);
	}
	releaseCapture();
	return NULL;
}
void AxisMoveTool::onMouseIdle(const UIEvent& event) {
	ArrowToolBase::onMouseIdle(event);
	if (captured()) cursor = "DragCursor";
	else {
		G3D::Vector3 point;
		NormalId face;
		if (hitHandle(event, point, face)) cursor = "ResizeCursor";
		else cursor = ArrowToolBase::getCursorName();
	}
}

}

template class RBX::ServiceClient<RBX::FilteredSelection<RBX::PVInstance> >;
template class RBX::ServiceClient<RBX::Selection>;
template class boost::function0<unsigned int,std::allocator<boost::function_base> >;
template class boost::shared_ptr<RBX::FilteredSelection<RBX::PVInstance> >;
template class boost::shared_ptr<RBX::Selection>;
template class boost::shared_ptr<RBX::Workspace>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Primitive *> >;
template class std::auto_ptr<RBX::MegaDragger>;
template class std::vector<RBX::Primitive *,std::allocator<RBX::Primitive *> >;

#include "tool/ModelTool.h"

namespace RBX {
ModelTool::ModelTool(Workspace* workspace) : MouseCommand(workspace) {}

void ModelTool::onMouseHover(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL))
        target = shared_from(Workspace::findTopInstance(part));
    else
        target.reset();
}
}

namespace RBX {
const std::string AnchorTool::getCursorName() const
{
    if (target) {
        if (anchored) return "UnAnchorCursor";
        return "AnchorCursor";
    }
    return "AnchorCursor";
}

const std::string LockTool::getCursorName() const
{
    if (target) {
        bool locked = PartInstance::getLocked(target.get());
        if (locked) return "UnlockCursor";
        return "LockCursor";
    }
    return "LockCursor";
}

MouseCommand* LockTool::onMouseDown(const UIEvent&)
{
    if (target) {
        bool value = PartInstance::getLocked(target.get());
        PartInstance::setLocked(target.get(), !value);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(PING_SOUND);
    }
    return this;
}
}

#include "tool/ResizeTool.h"

namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* ResizeTool::isSticky() const { return new ResizeTool(workspace); }
const std::string ResizeTool::getCursorName() const {
    return overHandle ? "ResizeCursor" : ArrowToolBase::getCursorName();
}
void ResizeTool::onMouseHover(const UIEvent& inputObject) {
    findTargetPV(inputObject);
    overHandle = !targetPV.expired();
    ArrowToolBase::onMouseHover(inputObject);
}
MouseCommand* ResizeTool::onMouseDown(const UIEvent& inputObject) {
    findTargetPV(inputObject);
    if (targetPV.expired()) return ArrowToolBase::onMouseDown(inputObject);
    down = inputObject.mousePosition;
    moveAxis = 0;
    movePerp = 0;
    overHandle = true;
    capture();
    return this;
}
MouseCommand* ResizeTool::onMouseUp(const UIEvent&) {
    if (captured()) {
        releaseCapture();
        if (!targetPV.expired()) {
            recordCameraHistory(getName().c_str(), workspace);
            workspace->getDataState().setDirty(true);
        }
    }
    return NULL;
}
}

#include <cmath>

namespace RBX {
static inline G3D::Vector3 directNormal(NormalId id, const G3D::CoordinateFrame& f) {
    const G3D::Matrix3& m = f.rotation;
    int c = id % 3;
    int sign = 1 - (id / 3) * 2;
    return sign * G3D::Vector3(m[0][c], m[1][c], m[2][c]);
}
void ResizeTool::onMouseMove(const UIEvent& event) {
    if (targetPV.expired()) return;
    G3D::Vector3 direction = directNormal(localNormalId, targetPV.lock()->getLocation());
    G3D::Ray axis = G3D::Ray::fromOriginAndDirection(hitPointGrid, direction);
    G3D::Ray mouse = getUnitMouseRay(event);
    G3D::Vector3 hit = Math::closestPointOnRay(axis, mouse);
    float dot = (hit - hitPointGrid).dot(axis.direction);
    float delta = dot - moveAxis;
    if (delta > 1.0f) {
        int steps = G3D::iRound((float)std::floor(delta));
        moveAxis += steps;
        capturedDrag(steps);
    }
    if (delta < -1.0f) {
        int steps = -G3D::iRound((float)std::floor(-delta));
        moveAxis += steps;
        capturedDrag(steps);
    }
}
}

#include "tool/ShootTools.h"

namespace RBX {
MouseCommand* ShootTool::onMouseDown(const UIEvent& input) { capture(); if (!remaining) shoot(input); return this; }
void ShootTool::onMouseIdle(const UIEvent& input) { if (remaining>0) --remaining; if (captured()) onMouseMove(input); }
void ShootTool::onMouseMove(const UIEvent& input) { if (enabled && !remaining) shoot(input); }
MouseCommand* ShootTool::onMouseUp(const UIEvent&) { releaseCapture(); return this; }
const std::string ShootTool::getCursorName() const { if (remaining && delay>10) return "GunWaitCursor"; return "GunCursor"; }
MouseCommand* SlingshotTool::isSticky() const { return new SlingshotTool(workspace); }
}

#include "tool/SurfaceTool.h"

namespace RBX {
SurfaceTool::SurfaceTool(Workspace* workspace) : MouseCommand(workspace), surface(NULL) {}
}

namespace RBX {
void recordCameraHistory(const char*, const Instance*);
MouseCommand* SurfaceTool::onMouseDown(const UIEvent& input) {
    onMouseHover(input);
    if (surface) {
        applyToSurface(surface);
        ServiceProvider::create<Soundscape::SoundService>(reinterpret_cast<Instance*>(workspace))->playSound(PING_SOUND);
        recordCameraHistory(cursor.c_str(), reinterpret_cast<Instance*>(workspace));
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}
void SurfaceTool::onMouseHover(const UIEvent& input) {
    PartInstance* part;
    surface = getSurface(input, part, surfaceId);
    partInstance = shared_from(surface ? part : NULL);
}
void SurfaceTool::render3dAdorn(Adorn* adorn) {
    if (partInstance)
        DrawAdorn::partSurface(partInstance->getPart(), surfaceId, adorn, G3D::Color4(G3D::Color3::orange(), 1.0f));
}
}
