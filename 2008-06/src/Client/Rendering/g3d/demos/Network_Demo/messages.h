/**
  @file Network_Demo/messages.h

  Messages sent between client and server.

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2004-03-29
  @edited  2005-01-22
 */

#ifndef MESSAGES_H
#define MESSAGES_H

#include <G3DAll.h>
#include "Entity.h"

enum MessageType {
    NO_MSG                  = 0,
    SignOnMessage_MSG       = 2000,
    CreateEntityMessage_MSG = 2001,
    EntityStateMessage_MSG  = 2002,
};


/**
 Sent from the server to the client to tell them their ID.
 */
class SignOnMessage {
public:
    /**
     The ID assigned to the player.
     */
    Entity::ID                               id;

    SignOnMessage() : id(Entity::NO_ID) {}
    SignOnMessage(Entity::ID _id) : id(_id) {}
    virtual ~SignOnMessage() {}

    virtual void serialize(BinaryOutput& b) const {
        b.writeInt32(id);
    }

    virtual void deserialize(BinaryInput& b) {
        id = b.readInt32();
    }
};



/**
 Sent from the client to the server to indicate
 new control settings, and from the server back
 to the clients to distribute that information.
 */
class EntityStateMessage {
public:

    /** ID of the object for which these controls apply */
    Entity::ID                  id;
    Controls                    controls;
    PhysicsFrame                frame;
    Vector3                     velocity;

    virtual ~EntityStateMessage() {}

    virtual void serialize(BinaryOutput& b) const;

    virtual void deserialize(BinaryInput& b);

};

#endif
