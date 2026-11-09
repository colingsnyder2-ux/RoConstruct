// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_standard_verbs_native_be96e67eb3737148.cpp

// Candidate translation unit (score above; library headers required).
// Native 005c7ea0 StandardVerbs composition, derived from 0x704 allocation,
// each member receiver offset, MSVC RTTI inheritance and actual command vtables.
// Public base APIs/value types use genuine RBX headers; no padding or fake slots.
#include "v8tree/Verb.h"
#include "v8tree/Service.h"
#include <G3D/Matrix3.h>
#include <boost/thread/once.hpp>
#include <cstddef>
namespace RBX {
class DataModel;
class Workspace;
class Selection;
class RunService;
class MouseCommand;
class PVInstance;

// Commands.h (2016) declarations reconciled with 2008 ctor stores/RTTI.
class RunStateVerb : public Verb {
protected:
    DataModel* dataModel;
    ServiceClient<RunService> runService;
    RunStateVerb(std::string,DataModel*);
    void playActionSound();
public:
    virtual ~RunStateVerb();
};
class EditSelectionVerb : public Verb {
protected:
    boost::shared_ptr<Workspace> workspace;
    ServiceClient<Selection> selection;
    DataModel* dataModel;
    EditSelectionVerb(std::string,DataModel*);
    EditSelectionVerb(VerbContainer*,std::string,DataModel*);
public:
    virtual ~EditSelectionVerb();
    virtual bool isEnabled() const;
};
class BoolPropertyVerb : public EditSelectionVerb {
    const Name& propertyName;
protected:
    BoolPropertyVerb(const std::string&,DataModel*,const char*);
    virtual void doIt(IDataState*);
    virtual bool isChecked() const;
};
class DeleteBase : public EditSelectionVerb {
    bool rewardHopper;
protected:
    DeleteBase(DataModel*,std::string,bool=false);
    DeleteBase(VerbContainer*,DataModel*,std::string);
public:
    virtual void doIt(IDataState*);
};
class PlayDeleteSelectionVerb : public DeleteBase {
public:
    PlayDeleteSelectionVerb(DataModel* dm) : DeleteBase(dm,"PlayDelete",true) {}
};
class DeleteSelectionVerb : public DeleteBase {
public:
    DeleteSelectionVerb(DataModel* dm) : DeleteBase(dm,"Delete") {}
};
class SelectAllCommand : public RunStateVerb {
public:
    SelectAllCommand(DataModel* dm) : RunStateVerb("SelectAll",dm) {}
    virtual void doIt(IDataState*);
};
class GroupSelectionVerb : public EditSelectionVerb {
public:
    GroupSelectionVerb(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class UngroupSelectionVerb : public EditSelectionVerb {
public:
    UngroupSelectionVerb(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class WeldSelectionVerb : public EditSelectionVerb {
public:
    WeldSelectionVerb(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class SnapSelectionVerb : public EditSelectionVerb {
public:
    SnapSelectionVerb(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class DuplicateSelectionVerb : public EditSelectionVerb {
public:
    DuplicateSelectionVerb(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class AttachCameraCommand : public EditSelectionVerb {
public:
    AttachCameraCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class TrackCameraCommand : public EditSelectionVerb {
public:
    TrackCameraCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class FollowCameraCommand : public EditSelectionVerb {
public:
    FollowCameraCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class WatchCameraCommand : public EditSelectionVerb {
public:
    WatchCameraCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class AnchorVerb : public BoolPropertyVerb {
public:
    AnchorVerb(DataModel*);
};
class TranslucentVerb : public BoolPropertyVerb {
public:
    TranslucentVerb(DataModel*);
};
class CanCollideVerb : public BoolPropertyVerb {
public:
    CanCollideVerb(DataModel*);
};

class CanNotSelectCommand : public EditSelectionVerb {
public:
    CanNotSelectCommand(DataModel* dm) : EditSelectionVerb("CanNotSelect",dm) {}
    virtual void doIt(IDataState*);
};
class AllCanSelectCommand : public RunStateVerb {
public:
    AllCanSelectCommand(DataModel* dm) : RunStateVerb("AllCanSelect",dm) {}
    virtual void doIt(IDataState*);
};
class MoveUpSelectionVerb : public EditSelectionVerb {
    float moveUpHeight;
public:
    MoveUpSelectionVerb(DataModel*,const std::string&,float);
    virtual void doIt(IDataState*);
};
class MoveUpPlateVerb : public MoveUpSelectionVerb {
public:
    MoveUpPlateVerb(DataModel*);
};
class MoveUpBrickVerb : public MoveUpSelectionVerb {
public:
    MoveUpBrickVerb(DataModel*);
};
class MoveDownSelectionVerb : public EditSelectionVerb {
public:
    MoveDownSelectionVerb(DataModel*);
    virtual void doIt(IDataState*);
};
class RotateAxisCommand : public EditSelectionVerb {
protected:
    RotateAxisCommand(std::string,DataModel*);
    void rotateAboutAxis(const G3D::Matrix3&,const std::vector<PVInstance*>&);
    virtual G3D::Matrix3 getRotationAxis()=0;
public:
    virtual void doIt(IDataState*);
};
class RotateSelectionVerb : public RotateAxisCommand {
public:
    RotateSelectionVerb(DataModel*);
protected:
    virtual G3D::Matrix3 getRotationAxis();
};
class TiltSelectionVerb : public RotateAxisCommand {
public:
    TiltSelectionVerb(DataModel*);
protected:
    virtual G3D::Matrix3 getRotationAxis();
};
class ControllerCommand : public EditSelectionVerb {
protected:
    ControllerCommand(std::string,DataModel*);
public:
    virtual bool isEnabled() const;
};
class PrimaryControllerCommand : public ControllerCommand {
public:
    PrimaryControllerCommand(DataModel*);
    virtual void doIt(IDataState*);
};
class SecondaryControllerCommand : public ControllerCommand {
public:
    SecondaryControllerCommand(DataModel*);
    virtual void doIt(IDataState*);
};
class ClearStarterpack : public Verb {
    DataModel* dataModel;
public:
    ClearStarterpack(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class ClearBackpack : public Verb {
    DataModel* dataModel;
public:
    ClearBackpack(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class RunCommand : public RunStateVerb {
public:
    RunCommand(DataModel* dm) : RunStateVerb("Run",dm) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class StopCommand : public RunStateVerb {
public:
    StopCommand(DataModel* dm) : RunStateVerb("Stop",dm) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};
class ResetCommand : public RunStateVerb {
public:
    ResetCommand(DataModel* dm) : RunStateVerb("Reset",dm) {}
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};

class FirstPersonCommand : public Verb {
    DataModel* dataModel;
public:
    FirstPersonCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*) {}
};
class StatsCommand : public Verb {
protected:
    DataModel* dataModel;
public:
    StatsCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual bool isChecked() const;
    virtual void doIt(IDataState*);
};
class ForceAssertionCommand : public Verb {
public:
    ForceAssertionCommand(DataModel*);
    virtual bool isEnabled() const {return true;}
    virtual void doIt(IDataState*) {}
};
class EngineStatsCommand : public Verb {
    DataModel* dataModel;
public:
    EngineStatsCommand(DataModel*);
    virtual bool isEnabled() const {return true;}
    virtual void doIt(IDataState*);
};
class JoinCommand : public Verb {
protected:
    DataModel* dataModel;
public:
    JoinCommand(DataModel*);
    virtual bool isEnabled() const;
    virtual void doIt(IDataState*);
};

// Same public Name::declare + Boost once algorithm as genuine Name.h template.
// Reused adapter avoids changing old header's private API or completing tool classes.
template<class Tool> struct NativeToolText;
template<class Tool> struct NativeToolName {
    static const Name& doDeclare() {
        static const Name& name=Name::declare(NativeToolText<Tool>::get(),-1);
        return name;
    }
    static void callDoDeclare() {doDeclare();}
    static const Name& get() {
        static boost::once_flag flag=BOOST_ONCE_INIT;
        boost::call_once(&callDoDeclare,flag);
        return doDeclare();
    }
};
template<class MouseCommandClass,class ParentClass=RunStateVerb>
class TToolVerb : public ParentClass {
public:
    TToolVerb(DataModel* dm)
        : ParentClass(NativeToolName<MouseCommandClass>::get().toString()+"Tool",dm) {}
    virtual void doIt(IDataState*);
    virtual bool isChecked() const;
    virtual boost::shared_ptr<MouseCommand> newMouseCommand();
};
class ArrowTool;
template<> struct NativeToolText<ArrowTool> {static const char* get() {return "Arrow";}};
class ResizeTool;
template<> struct NativeToolText<ResizeTool> {static const char* get() {return "Resize";}};
class AxisMoveTool;
template<> struct NativeToolText<AxisMoveTool> {static const char* get() {return "AxisMove";}};
class FlatTool;
template<> struct NativeToolText<FlatTool> {static const char* get() {return "Flat";}};
class GlueTool;
template<> struct NativeToolText<GlueTool> {static const char* get() {return "Glue";}};
class WeldTool;
template<> struct NativeToolText<WeldTool> {static const char* get() {return "Weld";}};
class StudsTool;
template<> struct NativeToolText<StudsTool> {static const char* get() {return "Studs";}};
class InletTool;
template<> struct NativeToolText<InletTool> {static const char* get() {return "Inlet";}};
class HingeTool;
template<> struct NativeToolText<HingeTool> {static const char* get() {return "Hinge";}};
class RightMotorTool;
template<> struct NativeToolText<RightMotorTool> {static const char* get() {return "RightMotor";}};
class LeftMotorTool;
template<> struct NativeToolText<LeftMotorTool> {static const char* get() {return "LeftMotor";}};
class OscillateMotorTool;
template<> struct NativeToolText<OscillateMotorTool> {static const char* get() {return "OscillateMotor";}};
class ModelSetFrontTool;
template<> struct NativeToolText<ModelSetFrontTool> {static const char* get() {return "ModelSetFront";}};
class ModelSetPrimaryPartTool;
template<> struct NativeToolText<ModelSetPrimaryPartTool> {static const char* get() {return "ModelSetPrimaryPart";}};
class AnchorTool;
template<> struct NativeToolText<AnchorTool> {static const char* get() {return "Anchor";}};
class LockTool;
template<> struct NativeToolText<LockTool> {static const char* get() {return "Lock";}};
class FillTool;
template<> struct NativeToolText<FillTool> {static const char* get() {return "Fill";}};
class DropperTool;
template<> struct NativeToolText<DropperTool> {static const char* get() {return "Dropper";}};
class NullTool;
template<> struct NativeToolText<NullTool> {static const char* get() {return "NullTool";}};
class GameTool;
template<> struct NativeToolText<GameTool> {static const char* get() {return "GameTool";}};
class GrabTool;
template<> struct NativeToolText<GrabTool> {static const char* get() {return "Grab";}};
class CloneTool;
template<> struct NativeToolText<CloneTool> {static const char* get() {return "Clone";}};
class HammerTool;
template<> struct NativeToolText<HammerTool> {static const char* get() {return "Hammer";}};
class SlingshotTool;
template<> struct NativeToolText<SlingshotTool> {static const char* get() {return "Slingshot";}};
class RocketTool;
template<> struct NativeToolText<RocketTool> {static const char* get() {return "Rocket";}};
class LaserTool;
template<> struct NativeToolText<LaserTool> {static const char* get() {return "Laser";}};

struct StandardVerbs {
    PlayDeleteSelectionVerb playDelete; // 0x0
    DeleteSelectionVerb deleteSelection; // 0x28
    SelectAllCommand selectAll; // 0x50
    GroupSelectionVerb group; // 0x6c
    UngroupSelectionVerb ungroup; // 0x90
    WeldSelectionVerb weld; // 0xb4
    SnapSelectionVerb snap; // 0xd8
    DuplicateSelectionVerb duplicate; // 0xfc
    AttachCameraCommand attach; // 0x120
    TrackCameraCommand track; // 0x144
    FollowCameraCommand follow; // 0x168
    WatchCameraCommand watch; // 0x18c
    AnchorVerb anchor; // 0x1b0
    TranslucentVerb translucent; // 0x1d8
    CanCollideVerb canCollide; // 0x200
    CanNotSelectCommand canNotSelect; // 0x228
    AllCanSelectCommand allCanSelect; // 0x24c
    MoveUpPlateVerb moveUpPlate; // 0x268
    MoveUpBrickVerb moveUpBrick; // 0x290
    MoveDownSelectionVerb moveDown; // 0x2b8
    RotateSelectionVerb rotate; // 0x2dc
    TiltSelectionVerb tilt; // 0x300
    PrimaryControllerCommand primaryController; // 0x324
    SecondaryControllerCommand secondaryController; // 0x348
    ClearStarterpack clearStarterpack; // 0x36c
    ClearBackpack clearBackpack; // 0x37c
    RunCommand run; // 0x38c
    StopCommand stop; // 0x3a8
    ResetCommand reset; // 0x3c4
    FirstPersonCommand firstPerson; // 0x3e0
    StatsCommand stats; // 0x3f0
    ForceAssertionCommand forceAssertion; // 0x400
    EngineStatsCommand engineStats; // 0x40c
    JoinCommand join; // 0x41c
    TToolVerb<ArrowTool> toolArrow; // 0x42c
    TToolVerb<ResizeTool> toolResize; // 0x448
    TToolVerb<AxisMoveTool> toolAxisMove; // 0x464
    TToolVerb<FlatTool> toolFlat; // 0x480
    TToolVerb<GlueTool> toolGlue; // 0x49c
    TToolVerb<WeldTool> toolWeld; // 0x4b8
    TToolVerb<StudsTool> toolStuds; // 0x4d4
    TToolVerb<InletTool> toolInlet; // 0x4f0
    TToolVerb<HingeTool> toolHinge; // 0x50c
    TToolVerb<RightMotorTool> toolRightMotor; // 0x528
    TToolVerb<LeftMotorTool> toolLeftMotor; // 0x544
    TToolVerb<OscillateMotorTool> toolOscillateMotor; // 0x560
    TToolVerb<ModelSetFrontTool> toolModelSetFront; // 0x57c
    TToolVerb<ModelSetPrimaryPartTool> toolModelSetPrimaryPart; // 0x598
    TToolVerb<AnchorTool> toolAnchor; // 0x5b4
    TToolVerb<LockTool> toolLock; // 0x5d0
    TToolVerb<FillTool> toolFill; // 0x5ec
    TToolVerb<DropperTool> toolDropper; // 0x608
    TToolVerb<NullTool> toolNull; // 0x624
    TToolVerb<GameTool> toolGame; // 0x640
    TToolVerb<GrabTool> toolGrab; // 0x65c
    TToolVerb<CloneTool> toolClone; // 0x678
    TToolVerb<HammerTool> toolHammer; // 0x694
    TToolVerb<SlingshotTool> toolSlingshot; // 0x6b0
    TToolVerb<RocketTool> toolRocket; // 0x6cc
    TToolVerb<LaserTool> toolLaser; // 0x6e8
    StandardVerbs(DataModel*);
};
typedef char native_Verb_size[(sizeof(Verb)==12)?1:-1];
typedef char native_RunStateVerb_size[(sizeof(RunStateVerb)==28)?1:-1];
typedef char native_EditSelectionVerb_size[(sizeof(EditSelectionVerb)==36)?1:-1];
typedef char native_DeleteBase_size[(sizeof(DeleteBase)==40)?1:-1];
typedef char native_BoolPropertyVerb_size[(sizeof(BoolPropertyVerb)==40)?1:-1];
typedef char native_StandardVerbs_size[(sizeof(StandardVerbs)==1796)?1:-1];
typedef char native_playDelete_offset[(offsetof(StandardVerbs,playDelete)==0x0)?1:-1];
typedef char native_deleteSelection_offset[(offsetof(StandardVerbs,deleteSelection)==0x28)?1:-1];
typedef char native_selectAll_offset[(offsetof(StandardVerbs,selectAll)==0x50)?1:-1];
typedef char native_group_offset[(offsetof(StandardVerbs,group)==0x6c)?1:-1];
typedef char native_ungroup_offset[(offsetof(StandardVerbs,ungroup)==0x90)?1:-1];
typedef char native_weld_offset[(offsetof(StandardVerbs,weld)==0xb4)?1:-1];
typedef char native_snap_offset[(offsetof(StandardVerbs,snap)==0xd8)?1:-1];
typedef char native_duplicate_offset[(offsetof(StandardVerbs,duplicate)==0xfc)?1:-1];
typedef char native_attach_offset[(offsetof(StandardVerbs,attach)==0x120)?1:-1];
typedef char native_track_offset[(offsetof(StandardVerbs,track)==0x144)?1:-1];
typedef char native_follow_offset[(offsetof(StandardVerbs,follow)==0x168)?1:-1];
typedef char native_watch_offset[(offsetof(StandardVerbs,watch)==0x18c)?1:-1];
typedef char native_anchor_offset[(offsetof(StandardVerbs,anchor)==0x1b0)?1:-1];
typedef char native_translucent_offset[(offsetof(StandardVerbs,translucent)==0x1d8)?1:-1];
typedef char native_canCollide_offset[(offsetof(StandardVerbs,canCollide)==0x200)?1:-1];
typedef char native_canNotSelect_offset[(offsetof(StandardVerbs,canNotSelect)==0x228)?1:-1];
typedef char native_allCanSelect_offset[(offsetof(StandardVerbs,allCanSelect)==0x24c)?1:-1];
typedef char native_moveUpPlate_offset[(offsetof(StandardVerbs,moveUpPlate)==0x268)?1:-1];
typedef char native_moveUpBrick_offset[(offsetof(StandardVerbs,moveUpBrick)==0x290)?1:-1];
typedef char native_moveDown_offset[(offsetof(StandardVerbs,moveDown)==0x2b8)?1:-1];
typedef char native_rotate_offset[(offsetof(StandardVerbs,rotate)==0x2dc)?1:-1];
typedef char native_tilt_offset[(offsetof(StandardVerbs,tilt)==0x300)?1:-1];
typedef char native_primaryController_offset[(offsetof(StandardVerbs,primaryController)==0x324)?1:-1];
typedef char native_secondaryController_offset[(offsetof(StandardVerbs,secondaryController)==0x348)?1:-1];
typedef char native_clearStarterpack_offset[(offsetof(StandardVerbs,clearStarterpack)==0x36c)?1:-1];
typedef char native_clearBackpack_offset[(offsetof(StandardVerbs,clearBackpack)==0x37c)?1:-1];
typedef char native_run_offset[(offsetof(StandardVerbs,run)==0x38c)?1:-1];
typedef char native_stop_offset[(offsetof(StandardVerbs,stop)==0x3a8)?1:-1];
typedef char native_reset_offset[(offsetof(StandardVerbs,reset)==0x3c4)?1:-1];
typedef char native_firstPerson_offset[(offsetof(StandardVerbs,firstPerson)==0x3e0)?1:-1];
typedef char native_stats_offset[(offsetof(StandardVerbs,stats)==0x3f0)?1:-1];
typedef char native_forceAssertion_offset[(offsetof(StandardVerbs,forceAssertion)==0x400)?1:-1];
typedef char native_engineStats_offset[(offsetof(StandardVerbs,engineStats)==0x40c)?1:-1];
typedef char native_join_offset[(offsetof(StandardVerbs,join)==0x41c)?1:-1];
typedef char native_toolArrow_offset[(offsetof(StandardVerbs,toolArrow)==0x42c)?1:-1];
typedef char native_toolResize_offset[(offsetof(StandardVerbs,toolResize)==0x448)?1:-1];
typedef char native_toolAxisMove_offset[(offsetof(StandardVerbs,toolAxisMove)==0x464)?1:-1];
typedef char native_toolFlat_offset[(offsetof(StandardVerbs,toolFlat)==0x480)?1:-1];
typedef char native_toolGlue_offset[(offsetof(StandardVerbs,toolGlue)==0x49c)?1:-1];
typedef char native_toolWeld_offset[(offsetof(StandardVerbs,toolWeld)==0x4b8)?1:-1];
typedef char native_toolStuds_offset[(offsetof(StandardVerbs,toolStuds)==0x4d4)?1:-1];
typedef char native_toolInlet_offset[(offsetof(StandardVerbs,toolInlet)==0x4f0)?1:-1];
typedef char native_toolHinge_offset[(offsetof(StandardVerbs,toolHinge)==0x50c)?1:-1];
typedef char native_toolRightMotor_offset[(offsetof(StandardVerbs,toolRightMotor)==0x528)?1:-1];
typedef char native_toolLeftMotor_offset[(offsetof(StandardVerbs,toolLeftMotor)==0x544)?1:-1];
typedef char native_toolOscillateMotor_offset[(offsetof(StandardVerbs,toolOscillateMotor)==0x560)?1:-1];
typedef char native_toolModelSetFront_offset[(offsetof(StandardVerbs,toolModelSetFront)==0x57c)?1:-1];
typedef char native_toolModelSetPrimaryPart_offset[(offsetof(StandardVerbs,toolModelSetPrimaryPart)==0x598)?1:-1];
typedef char native_toolAnchor_offset[(offsetof(StandardVerbs,toolAnchor)==0x5b4)?1:-1];
typedef char native_toolLock_offset[(offsetof(StandardVerbs,toolLock)==0x5d0)?1:-1];
typedef char native_toolFill_offset[(offsetof(StandardVerbs,toolFill)==0x5ec)?1:-1];
typedef char native_toolDropper_offset[(offsetof(StandardVerbs,toolDropper)==0x608)?1:-1];
typedef char native_toolNull_offset[(offsetof(StandardVerbs,toolNull)==0x624)?1:-1];
typedef char native_toolGame_offset[(offsetof(StandardVerbs,toolGame)==0x640)?1:-1];
typedef char native_toolGrab_offset[(offsetof(StandardVerbs,toolGrab)==0x65c)?1:-1];
typedef char native_toolClone_offset[(offsetof(StandardVerbs,toolClone)==0x678)?1:-1];
typedef char native_toolHammer_offset[(offsetof(StandardVerbs,toolHammer)==0x694)?1:-1];
typedef char native_toolSlingshot_offset[(offsetof(StandardVerbs,toolSlingshot)==0x6b0)?1:-1];
typedef char native_toolRocket_offset[(offsetof(StandardVerbs,toolRocket)==0x6cc)?1:-1];
typedef char native_toolLaser_offset[(offsetof(StandardVerbs,toolLaser)==0x6e8)?1:-1];
StandardVerbs::StandardVerbs(DataModel* dm)
    : playDelete(dm),
      deleteSelection(dm),
      selectAll(dm),
      group(dm),
      ungroup(dm),
      weld(dm),
      snap(dm),
      duplicate(dm),
      attach(dm),
      track(dm),
      follow(dm),
      watch(dm),
      anchor(dm),
      translucent(dm),
      canCollide(dm),
      canNotSelect(dm),
      allCanSelect(dm),
      moveUpPlate(dm),
      moveUpBrick(dm),
      moveDown(dm),
      rotate(dm),
      tilt(dm),
      primaryController(dm),
      secondaryController(dm),
      clearStarterpack(dm),
      clearBackpack(dm),
      run(dm),
      stop(dm),
      reset(dm),
      firstPerson(dm),
      stats(dm),
      forceAssertion(dm),
      engineStats(dm),
      join(dm),
      toolArrow(dm),
      toolResize(dm),
      toolAxisMove(dm),
      toolFlat(dm),
      toolGlue(dm),
      toolWeld(dm),
      toolStuds(dm),
      toolInlet(dm),
      toolHinge(dm),
      toolRightMotor(dm),
      toolLeftMotor(dm),
      toolOscillateMotor(dm),
      toolModelSetFront(dm),
      toolModelSetPrimaryPart(dm),
      toolAnchor(dm),
      toolLock(dm),
      toolFill(dm),
      toolDropper(dm),
      toolNull(dm),
      toolGame(dm),
      toolGrab(dm),
      toolClone(dm),
      toolHammer(dm),
      toolSlingshot(dm),
      toolRocket(dm),
      toolLaser(dm) {}
}
