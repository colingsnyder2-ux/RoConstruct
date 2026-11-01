#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "humanoid/Freefall.h"
#include "v8xml/SerializerV2.h"
#include "script/ScriptContext.h"
#include "script/LuaArguments.h"
#include "security/SecurityContext.h"
#include "util/ContentProvider.h"
#include "util/Sound.h"
#include "../PlayerNativeInput.h"
#include "Network/Players.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Camera.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8kernel/Body.h"
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"
#include "util/Utilities.h"
#include <G3D/Vector3.h>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <new>

static boost::shared_ptr<RBX::DataModel> g_dataModel;
static boost::shared_ptr<RBX::PartInstance> g_brickRef;
static RBX::PartInstance* g_brick = NULL;
static bool g_playing = false;
static PlayerNativeInput* g_input = NULL;
static RBX::ModelInstance* g_actor = NULL;

extern "C" int ConfigureContentRoot(const char* path)
{
    try { RBX::ContentProvider::singleton().setAssetFolder(path); }
    catch(std::exception& e){std::printf("content root: %s\n",e.what());return 1;}
    return 0;
}

struct Echo : RBX::Listener<RBX::StandardOut, RBX::StandardOutMessage>
{
    virtual void onEvent(const RBX::StandardOut*, RBX::StandardOutMessage message) { std::printf("[output] %s\n", message.message.c_str()); }
} g_echo;

extern "C" int LoadPlace(const char* text)
{
    RBX::StandardOut::singleton()->addListener(&g_echo);
    boost::shared_ptr<RBX::Soundscape::SoundChannel> soundFactoryLink = RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundChannel>();
    soundFactoryLink.reset();
    g_dataModel = RBX::DataModel::createDataModel();
    RBX::DataModel::Lock lock(g_dataModel);
    std::istringstream stream(text ? text : "");
    SerializerV2 serializer;
    try { serializer.loadXML(stream, g_dataModel.get()); }
    catch (std::exception& e) { std::printf("load: %s\n", e.what()); return 1; }
    RBX::Workspace* workspace = g_dataModel->getWorkspace();

    g_brick = dynamic_cast<RBX::PartInstance*>(workspace->findFirstChildByNameRecursive("Brick"));
    if (!g_brick && workspace->getChildren()) {
        const std::vector<boost::shared_ptr<RBX::Instance> >& children = *workspace->getChildren();
        for (size_t i = 0; i < children.size(); ++i) {
            g_brick = dynamic_cast<RBX::PartInstance*>(children[i].get());
            if (g_brick) break;
        }
    }
    if (!g_brick) { std::printf("no Part in place (empty control)\n"); g_brickRef.reset(); }
    else {
        g_brickRef = boost::static_pointer_cast<RBX::PartInstance>(g_brick->shared_from_this());
        const G3D::Vector3& size = g_brick->getPartSizeXml();
        G3D::Color3 color = g_brick->getColor3();
        const G3D::Vector3& pos = g_brick->getCoordinateFrame().translation;
        std::printf("loaded part '%s' pos=(%g,%g,%g) size=(%g,%g,%g) color=(%g,%g,%g)\n",
            g_brick->getName().c_str(), pos.x, pos.y, pos.z, size.x, size.y, size.z,
            color.r, color.g, color.b);
    }
    return 0;
}

RBX::DataModel* EngineDataModel()
{
    return g_dataModel.get();
}

extern "C" int CountHumanoids()
{
    if(!g_dataModel)return 0;
    RBX::DataModel::Lock lock(g_dataModel);
    std::vector<RBX::Instance*> pending(1,g_dataModel->getWorkspace());
    int count=0;
    while(!pending.empty()){
        RBX::Instance* item=pending.back();pending.pop_back();
        if(dynamic_cast<RBX::Humanoid*>(item))++count;
        if(item->getChildren()){
            boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > children=item->getChildren().read();
            for(size_t i=0;i<children->size();++i)pending.push_back((*children)[i].get());
        }
    }
    return count;
}

extern "C" int CountInstancesByClass(const char* name)
{
    if(!g_dataModel)return 0;
    RBX::DataModel::Lock lock(g_dataModel);
    std::vector<RBX::Instance*> pending(1,g_dataModel.get());
    int count=0;
    while(!pending.empty()){
        RBX::Instance* item=pending.back();pending.pop_back();
        if(item->getClassName().toString()==name)++count;
        if(item->getChildren()){
            boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > children=item->getChildren().read();
            for(size_t i=0;i<children->size();++i)pending.push_back((*children)[i].get());
        }
    }
    return count;
}

extern "C" void GetPartPosition(float* x, float* y, float* z)
{
    if (!g_brick) { if (x) *x=0; if (y)*y=0; if (z)*z=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Vector3 t = g_brick->getCoordinateFrame().translation;
    if (x) *x = t.x; if (y) *y = t.y; if (z) *z = t.z;
}

extern "C" void GetPartExtent(float* x, float* y, float* z)
{
    if (!g_brick) { if (x) *x=0; if (y)*y=0; if (z)*z=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Vector3 s = g_brick->getPartSizeXml();
    if (x) *x = s.x; if (y) *y = s.y; if (z) *z = s.z;
}

extern "C" void GetPartColor(float* r, float* g, float* b)
{
    if (!g_brick) { if (r) *r=0; if (g)*g=0; if (b)*b=0; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Color3 c = g_brick->getColor3();
    if (r) *r = c.r; if (g) *g = c.g; if (b) *b = c.b;
}

extern "C" int PartAlive(void)
{
    return g_brick && g_brickRef && g_brick->getParent() != NULL;
}

// Verify the constructor does not inherit a nonzero runDisabled byte.
extern "C" int CheckRunServiceInitialization()
{
    void* storage=::operator new(sizeof(RBX::RunService));
    std::memset(storage,0xff,sizeof(RBX::RunService));
    RBX::RunService* service=::new(storage) RBX::RunService();
    int result=service->runDisabled?1:0;
    service->~RunService();::operator delete(storage);return result;
}

// 0055e320: verify digest buffer, unsigned bytes and zero-padded hex.
extern "C" int CheckNativeMD5()
{
    boost::scoped_ptr<RBX::MD5Hasher> empty(RBX::MD5Hasher::create());
    if(empty->toString()!="d41d8cd98f00b204e9800998ecf8427e")return 1;
    boost::scoped_ptr<RBX::MD5Hasher> text(RBX::MD5Hasher::create());
    text->addData("a",1);text->addData("bc",2);
    if(text->toString()!="900150983cd24fb0d6963f7d28e17f72" || std::strcmp(text->c_str(),"900150983cd24fb0d6963f7d28e17f72"))return 2;
    boost::scoped_ptr<RBX::MD5Hasher> binary(RBX::MD5Hasher::create());
    const char bytes[]={0,static_cast<char>(0xff),0x10};binary->addData(bytes,sizeof(bytes));
    return binary->toString()=="481e4551ec039aada760901cf52b1917"?0:3;
}

// Exercise the actual Lua userdata conversion and stack balance.
extern "C" int CheckLuaObjectConversion()
{
    if(!g_dataModel)return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::Instance* actor=g_dataModel->getWorkspace()->findFirstChildByName("Actor");
    if(!actor)return 2;
    lua_State* state=luaL_newstate();
    RBX::Lua::ObjectBridge::registerClass(state);
    RBX::Lua::ObjectBridge::registerClassLibrary(state);
    RBX::Lua::ObjectBridge::push(state,boost::static_pointer_cast<RBX::Reflection::DescribedBase>(actor->shared_from_this()));
    int top=lua_gettop(state);RBX::Reflection::Value value;
    bool read=RBX::Lua::LuaArguments::get(state,1,value,false);
    bool balanced=lua_gettop(state)==top;
    bool same=read && value.convert<boost::shared_ptr<RBX::Instance> >().get()==actor;
    lua_close(state);
    return same && balanced ? 0 : 3;
}

static void RecordFreefall(std::vector<int>* values,bool active){values->push_back(active?1:0);}
extern "C" int CheckFreefallTransitions()
{
    if(!g_dataModel)return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ModelInstance* actor=dynamic_cast<RBX::ModelInstance*>(g_dataModel->getWorkspace()->findFirstChildByName("Actor"));
    RBX::Humanoid* humanoid=actor?RBX::Humanoid::modelIsCharacter(actor):NULL;
    if(!humanoid || !humanoid->getHead() || !humanoid->getTorso())return 2;
    RBX::PartInstance* head=humanoid->getHead();RBX::PartInstance* torso=humanoid->getTorso();
    head->setFriction(.23f);torso->setFriction(.67f);
    std::vector<int> events;
    boost::signals::connection connection=RBX::Humanoid::event_FreeFalling.connect(humanoid,boost::bind(&RecordFreefall,&events,_1));
    {
        RBX::Freefall falling(humanoid);
        if(events.size()!=1 || events[0]!=1 || head->getFriction()!=0 || torso->getFriction()!=0)return 3;
    }
    connection.disconnect();
    return events.size()==2 && events[1]==0 && fabs(head->getFriction()-.23f)<.0001f && fabs(torso->getFriction()-.67f)<.0001f ? 0 : 4;
}

namespace RBX { bool DetectClimb(Humanoid*); }
static boost::signals::connection g_climbConnection;
static int g_climbEvents;
static float g_climbMaxSpeed;
static void ObserveClimb(float speed){++g_climbEvents;g_climbMaxSpeed=std::max(g_climbMaxSpeed,speed);}
extern "C" int BeginClimbObservation()
{
    if(!g_dataModel)return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ModelInstance* actor=dynamic_cast<RBX::ModelInstance*>(g_dataModel->getWorkspace()->findFirstChildByName("Actor"));
    RBX::Humanoid* humanoid=actor?RBX::Humanoid::modelIsCharacter(actor):NULL;
    if(!humanoid)return 2;
    g_climbEvents=0;g_climbMaxSpeed=0;
    g_climbConnection=RBX::Humanoid::event_Climbing.connect(humanoid,&ObserveClimb);
    return 0;
}
extern "C" int EndClimbObservation(float* maxSpeed)
{
    g_climbConnection.disconnect();*maxSpeed=g_climbMaxSpeed;return g_climbEvents;
}
extern "C" int CheckClimbProbe()
{
    if(!g_dataModel)return -1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ModelInstance* actor=dynamic_cast<RBX::ModelInstance*>(g_dataModel->getWorkspace()->findFirstChildByName("Actor"));
    RBX::Humanoid* humanoid=actor?RBX::Humanoid::modelIsCharacter(actor):NULL;
    return humanoid?int(RBX::DetectClimb(humanoid)):-1;
}

// Diagnostic: use the existing Humanoid joint builder on the authored actor.
extern "C" int BuildPlayerJoints()
{
    if (!g_dataModel) return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::Instance* actor=g_dataModel->getWorkspace()->findFirstChildByName("Actor");
    RBX::Humanoid* humanoid=RBX::Humanoid::modelIsCharacter(actor);
    if (!humanoid || !humanoid->getTorso() || !humanoid->getHead() || !humanoid->getLeftArm() ||
        !humanoid->getRightArm() || !humanoid->getLeftLeg() || !humanoid->getRightLeg()) return 1;
    humanoid->buildJoints();
    return 0;
}

// Diagnostic local-player/controller attachment to the authored Actor.
extern "C" int AttachPlayerController(int spawn)
{
    if (!g_dataModel) return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ModelInstance* actor=dynamic_cast<RBX::ModelInstance*>(g_dataModel->getWorkspace()->findFirstChildByName("Actor"));
    if (!spawn && (!actor || !RBX::Humanoid::modelIsCharacter(actor))) return 2;
    RBX::Network::Players* players=RBX::ServiceProvider::create<RBX::Network::Players>(g_dataModel.get());
    if (!players) {
        try {
            boost::shared_ptr<RBX::Network::Players> service=RBX::Creatable<RBX::Instance>::create<RBX::Network::Players>();
            service->setParent(g_dataModel.get());players=service.get();
        } catch(const std::exception& error) {std::fprintf(stderr,"controller: %s\n",error.what());return 4;}
    }
    RBX::Security::Impersonator trusted(RBX::Security::CmdLine);
    RBX::Network::Player* player=players->getLocalPlayer();
    try { if (!player) player=dynamic_cast<RBX::Network::Player*>(players->createLocalPlayer(1).get()); }
    catch(const std::exception& error){std::fprintf(stderr,"controller: local player %s\n",error.what());std::fflush(stderr);return 5;}
    if (!player) return 3;
    if (spawn) {
        const char* assets[]={"fonts\\character.rbxm","fonts\\humanoidSound.rbxm","fonts\\humanoidHealth.rbxm","fonts\\humanoidAnimate.rbxm"};
        for(int i=0;i<4;++i){
            if(!RBX::ContentProvider::singleton().requestContentString(RBX::ContentId::fromAssets(assets[i]))){
                std::fprintf(stderr,"character asset unavailable: %s\n",assets[i]);return 6;
            }
        }
        try { player->loadCharacter(); }
        catch(const std::exception& error){std::fprintf(stderr,"character spawn: %s\n",error.what());return 6;}
        actor=player->getCharacter();
    } else player->setCharacter(actor);
    if (!actor || !RBX::Humanoid::modelIsCharacter(actor)) return 7;
    g_actor=actor;
    static PlayerNativeInput input;g_input=&input;
    RBX::ServiceProvider::create<RBX::ControllerService>(g_dataModel.get())->setHardwareDevice(g_input);
    actor->setControllerType(RBX::Controller::PLAYER_CONTROLLER);
    actor->getTopPVController();
    return 0;
}
extern "C" int GetActorTorsoPosition(float* x,float* y,float* z)
{
    if (!g_dataModel) return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::Instance* actor=g_actor?g_actor:g_dataModel->getWorkspace()->findFirstChildByName("Actor");
    RBX::Humanoid* humanoid=RBX::Humanoid::modelIsCharacter(actor);
    RBX::PartInstance* torso=humanoid?humanoid->getTorso():NULL;
    if (!torso) return 1;
    G3D::Vector3 position=torso->getCoordinateFrame().translation;
    *x=position.x;*y=position.y;*z=position.z;return 0;
}
extern "C" void SetPlayerTestKey(int down){if(g_input)g_input->setKeyState(SDLK_w,down!=0);}
extern "C" int CheckPlayerController()
{
    if (!g_dataModel || !g_input) return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ModelInstance* actor=RBX::Network::Players::findLocalCharacter(g_dataModel.get());
    RBX::Humanoid* humanoid=RBX::Humanoid::modelIsCharacter(actor);
    RBX::Camera* camera=g_dataModel->getWorkspace()->getCamera();
    RBX::RunService* run=RBX::ServiceProvider::create<RBX::RunService>(g_dataModel.get());
    if (!humanoid || !camera || !run) return 2;
    if (RBX::Network::Players::getPlayerFromCharacter(actor)!=RBX::ServiceProvider::create<RBX::Network::Players>(g_dataModel.get())->getLocalPlayer()) return 9;
    camera->setCameraCoordinateFrameNoLerp(G3D::CoordinateFrame());
    g_input->setKeyState(SDLK_w,true);g_input->setKeyState(SDLK_s,true);
    run->raiseHeartbeat(0,1.0f/60.0f);
    G3D::Vector3 walk=humanoid->getWalkDirection();
    if ((walk-G3D::Vector3(0,0,-1)).squaredLength()>1e-6f) return 3;
    g_input->setKeyState(SDLK_s,false);g_input->setKeyState(SDLK_d,true);
    run->raiseHeartbeat(0,1.0f/60.0f);walk=humanoid->getWalkDirection();
    if (fabs(walk.magnitude()-1.0f)>1e-4f || walk.x<0.6f || walk.z>-0.6f) return 4;
    G3D::Vector3 oldLook=camera->getCameraCoordinateFrame().lookVector();
    g_input->setKeyState(SDLK_LEFT,true);
    run->raiseHeartbeat(0,1.0f/60.0f);
    if (humanoid->getWalkDirection().squaredLength()>1e-6f) return 5;
    camera->goalToCamera();
    if ((camera->getCameraCoordinateFrame().lookVector()-oldLook).squaredLength()<1e-6f) return 8;
    g_input->setKeyState(SDLK_LEFT,false);g_input->setKeyState(SDLK_w,false);g_input->setKeyState(SDLK_d,false);
    g_input->setKeyState(SDLK_SPACE,true);humanoid->setSit(true);
    run->raiseHeartbeat(0,1.0f/60.0f);
    if (!humanoid->getJump() || humanoid->getSit()) return 6;
    g_input->setKeyState(SDLK_SPACE,false);humanoid->setJump(false);
    run->raiseHeartbeat(0,1.0f/60.0f);
    return humanoid->getWalkDirection().squaredLength()>1e-6f ? 7 : 0;
}


static RBX::TimerService* g_clockProbeTimer=NULL;
static int g_clockProbeCalls=0;
static void clockProbeCallback()
{
    ++g_clockProbeCalls;
    if (g_clockProbeCalls<4) g_clockProbeTimer->delay(&clockProbeCallback,0.01);
}
// Exercise a timer that schedules another timer while a heartbeat is running.
extern "C" int CheckShortTimer()
{
    if (!g_dataModel) return -1;
    RBX::DataModel::Lock lock(g_dataModel);
    g_clockProbeTimer=RBX::ServiceProvider::create<RBX::TimerService>(g_dataModel.get());
    RBX::RunService* run=RBX::ServiceProvider::create<RBX::RunService>(g_dataModel.get());
    if (!g_clockProbeTimer || !run) return -1;
    g_clockProbeCalls=0;g_clockProbeTimer->delay(&clockProbeCallback,0.0);
    run->raiseHeartbeat(g_dataModel->getSimTime(),1.0f/60.0f);
    int result=g_clockProbeCalls;g_clockProbeTimer=NULL;return result;
}

// Diagnostic play transition: use the existing RunService state change.
extern "C" void StartPlay()
{
    if (!g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ServiceProvider::create<RBX::RunService>(g_dataModel.get())->run();
    g_playing = true;
}

extern "C" void StepEngine(float dt)
{
    if (!g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    float stepped = g_dataModel->step(dt);
    if (g_playing) {
        RBX::RunService* run = RBX::ServiceProvider::create<RBX::RunService>(g_dataModel.get());
        run->raiseStepped(g_dataModel->getSimTime(), stepped);
        run->raiseHeartbeat(g_dataModel->getSimTime(), dt);
    }
}

extern "C" void MovePartTo(float x, float y, float z)
{
    if (!g_brick || !g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    char command[160];
    _snprintf(command, sizeof(command),
        "game.Workspace.Brick.CFrame = CFrame.new(%g,%g,%g)", x, y, z);
    try { scripts->executeInNewThread(RBX::Security::CmdLine, command, "move"); }
    catch (std::exception& e) { std::printf("script: %s\n", e.what()); }
    g_dataModel->step(1.0f / 30.0f);
}

extern "C" void RemovePart()
{
    if (!g_brick || !g_dataModel) return;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts = RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    try { scripts->executeInNewThread(RBX::Security::CmdLine, "game.Workspace.Brick.Parent = nil", "remove"); }
    catch (std::exception& e) { std::printf("script: %s\n", e.what()); }
    g_dataModel->step(1.0f / 30.0f);
}

extern "C" void SetPartYaw(float yaw)
{
    RBX::DataModel::Lock lock(g_dataModel);
    G3D::Matrix3 rotation=G3D::Matrix3::fromAxisAngle(G3D::Vector3::unitY(),yaw);
    g_brick->setCoordinateFrame(G3D::CoordinateFrame(rotation,g_brick->getCoordinateFrame().translation));
}

// Harness entry: execute genuine model/script property changes for P3 controls.
extern "C" int ExecutePlayerScript(const char* command)
{
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::ScriptContext* scripts=RBX::ServiceProvider::create<RBX::ScriptContext>(g_dataModel.get());
    try { scripts->executeInNewThread(RBX::Security::CmdLine,command,"player-lifetime"); }
    catch(std::exception& e){std::printf("script: %s\n",e.what());return 1;}
    g_dataModel->step(1.0f/30.0f);
    return 0;
}

extern "C" void GetBrickAnchorFlags(int* dragging,int* aggregate)
{
    if (!g_brick || !g_dataModel) { *dragging = *aggregate = -1; return; }
    RBX::DataModel::Lock lock(g_dataModel);
    *dragging = g_brick->getPrimitive()->getDragging() ? 1 : 0;
    *aggregate = g_brick->getPrimitive()->getAnchor() ? 1 : 0;
}

// Exercise all flag combinations while the Part is in Workspace.
extern "C" int CheckBrickAnchorFlags()
{
    if (!g_brick || !g_dataModel) return 1;
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::Primitive* primitive=g_brick->getPrimitive();
    for (int i=0;i<8;++i) {
        int bits=i^(i>>1);
        g_brick->setDragging((bits&1)!=0);
        g_brick->setAnchored((bits&2)!=0);
        primitive->setFlag0xaa((bits&4)!=0);
        bool aggregate=bits!=0;
        if (g_brick->getDragging()!=((bits&1)!=0) || g_brick->getAnchored()!=((bits&2)!=0) ||
            primitive->getAnchor()!=aggregate || (primitive->getAnchorObject()!=NULL)!=aggregate) return 2;
    }
    primitive->setFlag0xaa(false);
    g_brick->setDragging(false);
    g_brick->setAnchored(false);
    return primitive->getAnchorObject() || primitive->getAnchor() ? 3 : 0;
}

extern "C" int GetBrickAnchored()
{
    if (!g_brick || !g_dataModel) return -1;
    RBX::DataModel::Lock lock(g_dataModel);
    return g_brick->getAnchored() ? 1 : 0;
}

extern "C" int GetContactState(float* expectedY,float* floorY,int* anchored)
{
    RBX::DataModel::Lock lock(g_dataModel);
    RBX::PartInstance* floor=dynamic_cast<RBX::PartInstance*>(g_dataModel->getWorkspace()->findFirstChildByName("Floor"));
    if(!g_brick || !floor)return 1;
    *floorY=floor->getCoordinateFrame().translation.y;
    *expectedY=*floorY+(floor->getPartSizeXml().y+g_brick->getPartSizeXml().y)*.5f;
    *anchored=floor->getAnchored();
    return 0;
}

extern "C" void ClosePlace()
{
    g_playing = false;
    if (g_input && g_dataModel) {
        RBX::DataModel::Lock lock(g_dataModel);
        RBX::ControllerService* service=RBX::ServiceProvider::find<RBX::ControllerService>(g_dataModel.get());
        if (service) service->setHardwareDevice(NULL);
        g_input->setKeyState(SDLK_w,false);g_input=NULL;
    }
    g_actor = NULL;
    g_brick = NULL;
    g_brickRef.reset();
    if (g_dataModel) { RBX::DataModel::closeDataModel(g_dataModel, true); g_dataModel.reset(); }
}
