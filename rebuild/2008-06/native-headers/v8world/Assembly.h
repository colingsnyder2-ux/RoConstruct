#pragma once
// Forwarding header (batch 28). This path used to hold a global-scope stub `class Assembly {};` (added for the
// Replicator::JobSender `const Assembly*` in native-headers/Replicator.h) that shadowed the donor v8world/Assembly.h
// for every unit including it (World / Seat / Mechanism units: Assembly::PrimIterator undeclared). Replicator.h now
// forward-declares RBX::Assembly itself, so this path forwards to the donor header, as native-headers/BitStream.h does.
#include "../../../../tools/rbxgs/Client/App/include/v8world/Assembly.h"
