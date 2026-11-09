/**
  @file FirstPersonManipulator.cpp

  @maintainer Morgan McGuire, morgan@cs.brown.edu

  @created 2002-07-28
  @edited  2006-04-22
*/

#include "G3D/platform.h"

#include "G3D/Rect2D.h"
#include "GLG3D/ManualCameraController.h"
#include "GLG3D/GWindow.h"
#include "GLG3D/UserInput.h"

namespace G3D {

FirstPersonManipulatorRef FirstPersonManipulator::create() {
    return new FirstPersonManipulator();
}

FirstPersonManipulator::FirstPersonManipulator() : m_mouseMode(MOUSE_DIRECT), _active(false) {}


FirstPersonManipulator::FirstPersonManipulator(
    RenderDevice* rd, UserInput* ui) : m_mouseMode(MOUSE_DIRECT), _active(false) {
    init(rd, ui);
}


CoordinateFrame FirstPersonManipulator::getCoordinateFrame() const {
    return frame();
}


void FirstPersonManipulator::getCoordinateFrame(CoordinateFrame& c) const {
    getFrame(c);
}


void FirstPersonManipulator::getFrame(CoordinateFrame& c) const {
	c.translation = translation;
    c.rotation = Matrix3::fromEulerAnglesZYX(0, -yaw, -pitch);
}


CoordinateFrame FirstPersonManipulator::frame() const {
	CoordinateFrame c;
	getFrame(c);
	return c;
}


void FirstPersonManipulator::init(class RenderDevice* device, class UserInput* input) {
    userInput    = input;
    reset();
}


FirstPersonManipulator::~FirstPersonManipulator() {
}


FirstPersonManipulator::MouseMode FirstPersonManipulator::mouseMode() const {
    return m_mouseMode;
}


void FirstPersonManipulator::setMouseMode(FirstPersonManipulator::MouseMode m) {
    if (m_mouseMode != m) {
        bool wasActive = active();

        if (wasActive) {
            // Toggle activity to let the cursor and 
            // state variables reset.
            setActive(false);

        }

        m_mouseMode = m;

        if (wasActive) {
            setActive(true);
        }
    }
}

bool FirstPersonManipulator::active() const {
    return _active;
}


void FirstPersonManipulator::reset() {
    _active      = false;
    yaw         = -G3D_PI/2;
    pitch       = 0;
	translation = Vector3::zero();
    setMoveRate(10);
	setTurnRate(G3D_PI * 5);
}


void FirstPersonManipulator::setActive(bool a) {
    if (_active == a) {
        return;
    }
    _active = a;

    switch (m_mouseMode) {
    case MOUSE_DIRECT:
        userInput->setPureDeltaMouse(_active);
        break;

    case MOUSE_DIRECT_RIGHT_BUTTON:
        // Only turn on when activeand the right mouse button is down
        userInput->setPureDeltaMouse(_active && userInput->keyDown(SDL_RIGHT_MOUSE_KEY));
        break;

    case MOUSE_SCROLL_AT_EDGE:
    case MOUSE_PUSH_AT_EDGE:        
        userInput->setPureDeltaMouse(false);
        if (_active) {
            userInput->window()->incInputCaptureCount();
        } else {
            userInput->window()->decInputCaptureCount();
        }
        break;

    default:
        debugAssert(false);
    }
}


void FirstPersonManipulator::setMoveRate(double metersPerSecond) {
    maxMoveRate = metersPerSecond;
}


void FirstPersonManipulator::setTurnRate(double radiansPerSecond) {
    maxTurnRate = radiansPerSecond;
}


void FirstPersonManipulator::lookAt(
    const Vector3&      position) {

    const Vector3 look = (position - translation);

    yaw   = aTan2(look.x, -look.z);
    pitch = -aTan2(look.y, distance(look.x, look.z));
}


void FirstPersonManipulator::doSimulation(
    double              elapsedTime) {

    onSimulation(elapsedTime, elapsedTime, elapsedTime);
}


void FirstPersonManipulator::setFrame(const CoordinateFrame& c) {
    Vector3 look = c.getLookVector();

    setPosition(c.translation);

    // this is work towards a patch for bug #1022341
    /*
    if (fuzzyEq(abs(look.dot(Vector3::unitY())), 1.0)) {
        // Looking straight up or down; lookAt won't work
        float dummy;
        float y, p;
        c.rotation.toEulerAnglesZYX(dummy, y, p);
        yaw = -y;
        pitch = -p;

    } else {
    */
        lookAt(c.translation + look);
//    }
}


void FirstPersonManipulator::setCoordinateFrame(const CoordinateFrame& c) {
    setFrame(c);
}


void FirstPersonManipulator::getPosedModel(Array<PosedModelRef>& p3d, Array<PosedModel2DRef>& p2d) {
}


void FirstPersonManipulator::onNetwork() {
}


void FirstPersonManipulator::onLogic() {
}


void FirstPersonManipulator::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    if (! _active) {
        return;
    }

    if (userInput == NULL) {
        return;
    }

    RealTime elapsedTime = sdt;

    {
        // Translation direction
        Vector2 direction(userInput->getX(), userInput->getY());
        direction.unitize();

        // Translate forward
        translation += (getLookVector() * direction.y + 
            getStrafeVector() * direction.x) * elapsedTime * maxMoveRate;
    }
    
    // Desired change in yaw and pitch
    Vector2 delta;
    float maxTurn = maxTurnRate * elapsedTime;

    switch (m_mouseMode) {
    case MOUSE_DIRECT_RIGHT_BUTTON:
        {
            bool mouseDown = userInput->keyDown(SDL_RIGHT_MOUSE_KEY);
            userInput->setPureDeltaMouse(mouseDown);
            if (! mouseDown) {
                // Skip bottom case
                break;
            }
        }
        // Intentionally fall through to MOUSE_DIRECT

    case MOUSE_DIRECT:
        delta = userInput->mouseDXY() / 100.0f;
        break;


    case MOUSE_SCROLL_AT_EDGE:
        {
            Rect2D viewport = Rect2D::xywh(0, 0, userInput->window()->width(), userInput->window()->height());
            Vector2 mouse = userInput->mouseXY();

            Vector2 hotExtent(max(50.0f, viewport.width() / 8), 
                              max(50.0f, viewport.height() / 6));

            // The hot region is outside this rect
            Rect2D hotRegion = Rect2D::xyxy(
                viewport.x0() + hotExtent.x, viewport.y0() + hotExtent.y,
                viewport.x1() - hotExtent.y, viewport.y1() - hotExtent.y);

            // See if the mouse is near an edge
            if (mouse.x <= hotRegion.x0()) {
                delta.x = -square(1.0 - (mouse.x - viewport.x0()) / hotExtent.x);
                // - Yaw
            } else if (mouse.x >= hotRegion.x1()) {
                delta.x = square(1.0 - (viewport.x1() - mouse.x) / hotExtent.x);
                // + Yaw
            }

            if (mouse.y <= hotRegion.y0()) {
                delta.y = -square(1.0 - (mouse.y - viewport.y0()) / hotExtent.y) * 0.6;
                // - pitch
            } else if (mouse.y >= hotRegion.y1()) {
                delta.y = square(1.0 - (viewport.y1() - mouse.y) / hotExtent.y) * 0.6;
                // + pitch
            }

            delta *= maxTurn / 5;
        }
        break;

//    case MOUSE_PUSH_AT_EDGE: 
    default:
        debugAssert(false);
    }


    // Turn rate limiter
    if (G3D::abs(delta.x) > maxTurn) {
        delta.x = maxTurn * G3D::sign(delta.x);
    }

    if (G3D::abs(delta.y) > maxTurn) {
        delta.y = maxTurn * G3D::sign(delta.y);
    }

    yaw   += delta.x;
    pitch += delta.y;

    // As a patch for a setCoordinateFrame bug, we prevent 
    // the camera from looking exactly along the y-axis.
    pitch = clamp(pitch, -G3D_PI / 2 + 0.001, G3D_PI / 2 - 0.001);
}


void FirstPersonManipulator::onUserInput(UserInput* ui) {
    userInput = ui;
}


bool FirstPersonManipulator::onEvent(const GEvent& event) {
    return false;
}


}

