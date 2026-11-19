#pragma once

#include "G3D/ReferenceCount.h"
#include "G3D/Color3.h"

namespace RBX
{
    class Controller : public G3D::ReferenceCountedObject
    {
    public:
        enum ControllerType
        {
            NO_CONTROLLER = 0,
            PRIMARY_CONTROLLER = 1,
            SECONDARY_CONTROLLER = 2,
            PAD_ONE_CONTROLLER = 3,
            PAD_TWO_CONTROLLER = 4,
            AI_CHASE_CONTROLLER = 5,
            AI_FLEE_CONTROLLER = 6,
            PLAYER_CONTROLLER = 7,
            NUM_CONTROLLER_TYPES = 8
        };

        enum InputType
        {
            NO_INPUT = 0,
            LEFT_TRACK_INPUT = 1,
            RIGHT_TRACK_INPUT = 2,
            RIGHT_LEFT_INPUT = 3,
            BACK_FORWARD_INPUT = 4,
            STRAFE_INPUT = 5,
            UP_DOWN_INPUT = 6,
            BUTTON_1_INPUT = 7,
            BUTTON_2_INPUT = 8,
            BUTTON_3_INPUT = 9,
            BUTTON_4_INPUT = 10,
            BUTTON_3_4_INPUT = 11,
            CONSTANT_INPUT = 12,
            SIN_INPUT = 13,
            NUM_INPUT_TYPES = 14
        };

        virtual ~Controller();
        virtual float getValue(InputType inputType) const = 0;
        virtual ControllerType getControllerType() const = 0;
        virtual bool hasIntelligence() const = 0;
        virtual bool isUserController() const = 0;
        bool isNullController();
        static bool isControllableInput(InputType inputType);
        static G3D::Color3 controllerTypeToColor(ControllerType controllerType);
    };
}
