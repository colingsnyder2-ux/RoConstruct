#include "tool/ModelTool.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
ModelTool::ModelTool(Workspace* workspace) : MouseCommand(workspace) {}

void ModelTool::onMouseHover(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL))
        target = shared_from(Workspace::findTopInstance(part));
    else
        target.reset();
}

void ModelTool::render3dAdorn(Adorn* adorn)
{
    // Rejected: the dynamic_cast alone (no explicit target test) drops the original's leading null check (49 of 53 B).
    if (target)
        if (IRenderable* renderable = dynamic_cast<IRenderable*>(target.get()))
            renderable->render3dSelect(adorn, SELECT_NORMAL);
}
}

#include "v8datamodel/DataModel.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "tool/Dragger.h"
#include "util/Math.h"
#include "util/Extents.h"

namespace RBX {
bool hitMoveHandles(const Extents&, const G3D::Ray&, G3D::Vector3&, NormalId&);
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
}

#include "StandardVerbs.h"

namespace RBX {
void recordCameraHistory(const char*, const Instance*);
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

#include "v8datamodel/Selection.h"

namespace RBX {
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
}

#include "tool/BasicMouseTools.h"
#include "v8datamodel/Explosion.h"
#include "util/Sound.h"

namespace RBX {
char sHammerTool[] = "Hammer";
void HammerTool::onMouseIdle(const UIEvent& input)
{
    partInstance = shared_from(getUnlockedPartByLocalCharacter(input));
}

void HammerTool::render3dAdorn(Adorn* adorn)
{
    if (partInstance) partInstance->render3dSelect(adorn, static_cast<SelectState>(1));
}

const std::string HammerTool::getCursorName() const
{
    return partInstance ? "HammerOverCursor" : "HammerCursor";
}

MouseCommand* HammerTool::isSticky() const { return new HammerTool(workspace); }

MouseCommand* HammerTool::onMouseDown(const UIEvent&)
{
    if (partInstance) {
        boost::shared_ptr<Explosion> explosion = Creatable<Instance>::create<Explosion>();
        Explosion::propPosition.setValue(explosion.get(), partInstance->getCoordinateFrame().translation);
        Explosion::propBlastPressure.setValue(explosion.get(), 0.0f);
        explosion->setParent(workspace);
        partInstance->setParent(NULL);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(BOMB_SOUND);
    }
    return NULL;
}

template<> const Name& Named<MouseCommand, sHammerTool>::getName() const
{
    return NativeToolName<HammerTool>::get();
}
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand()
{
    return new HammerTool(dataModel->getWorkspace());
}
}

template class RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>;
template class RBX::Reflection::TypedPropertyDescriptor<float>;
template class boost::shared_ptr<RBX::Explosion>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>::GetSet>;
template class std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<float>::GetSet>;

#include "tool/ModelTools.h"

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

#include "AppDraw/DrawAdorn.h"

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
