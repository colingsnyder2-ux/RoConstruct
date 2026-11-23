// =============================================================================
// LocalBackpack.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/LocalBackpack.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8datamodel/Hopper.h"
#include "Network/Player.h"
#include "Network/Players.h"

namespace RBX
{
extern char sLocalBackpackItem[];
class LocalBackpackItem : public DescribedCreatable<LocalBackpackItem, Widget, sLocalBackpackItem> {
    boost::shared_ptr<BackpackItem> myItem;
    GuiDrawImage guiImageDraw;
    virtual bool askSetParent(const Instance*) const { return true; }
    virtual G3D::Vector2 getSize() const;
    virtual void render2d(Adorn*);
    virtual void onClick(const GuiEvent& event);
    int getBinId() const;
public:
    LocalBackpackItem();
    void setItem(BackpackItem* item) { myItem = shared_from(item); }
    BackpackItem* getItem() { return myItem.get(); }
};

extern char sLocalBackpack[];
class LocalBackpack : public DescribedCreatable<LocalBackpack, RelativePanel, sLocalBackpack>, public Service,
    public Listener<Instance, ChildAdded>, public Listener<Instance, ChildRemoved>,
    public Listener<Instance, DescendentAdded>, public Listener<Instance, DescendentRemoving>,
    public Listener<Network::Player, Network::CharacterAdded>, public Listener<Network::Player, Network::CharacterRemoving> {
    boost::shared_ptr<Network::Players> players;
    boost::shared_ptr<Network::Player> localPlayer;
    boost::shared_ptr<Backpack> localBackpack;
    boost::shared_ptr<Instance> localCharacter;
    boost::shared_ptr<BackpackItem> pendingClick;
    int lastRemovedIndex;
    virtual bool askSetParent(const Instance*) const { return true; }
    virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*);
    virtual void onEvent(const Network::Player*, Network::CharacterRemoving);
    virtual void onEvent(const Network::Player*, Network::CharacterAdded);
    virtual void onEvent(const Instance*, DescendentRemoving);
    virtual void onEvent(const Instance*, DescendentAdded);
    virtual void onEvent(const Instance*, ChildRemoved);
    virtual void onEvent(const Instance*, ChildAdded);
    void onLocalCharacterAdded(Instance*);
    void onLocalPlayerAdded(Network::Player*);
    void onLocalBackpackAdded(Backpack*);
    void clearAll(); void clearLocalCharacter(); void clearLocalPlayer(); void clearLocalBackpack();
    void insertBackpackItem(BackpackItem*); void removeBackpackItem(BackpackItem*);
public:
    LocalBackpack(); virtual ~LocalBackpack(); void onHeartbeat(); void onClick(LocalBackpackItem*);
    bool onKey(int); void cycleUp(); void cycleDown(); virtual XmlElement* write() { return NULL; }
};
}
