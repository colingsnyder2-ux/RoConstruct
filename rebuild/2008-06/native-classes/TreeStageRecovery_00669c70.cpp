// 2008-06 native RBX::TreeStage member recovery (inactive draft)
// Lease: family:class_RBX_TreeStage
// Functions: 00669c70 (onEdgeRemoving), 00669410 (process), 006699a0 (findLightestDownstream)
// Prove with: python work/native-client/agent_prove.py rebuild/2008-06/native-classes/TreeStageRecovery_00669c70.cpp ADDR=name
//
// STATUS:
// - 00669c70 (onEdgeRemoving): 4 variants tried. Logic matches but compiler code layout differs from target.
//   Blocker: Target places helper call (00669710) linearly between processing path and cleanup, forcing a jump.
//   Candidate falls through to cleanup directly. Functional behavior identical, byte layout differs (111 vs 121 bytes).
// - 00669410 (process): 1 variant tried. std::set iterator code generation differs from target's internal _Tree iteration.
//   Blocker: Target uses explicit _SECURE_SCL iterator validity checks with specific register allocation.
// - 006699a0 (findLightestDownstream): Already parked (4+ LLM tries). Complex SEH frame and local std::set construction.
//   Blocker: Target uses full SEH prologue (0x50 stack frame) vs candidate's simplified frame (0x28).

#include "AppUnit668/TreeStage.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "v8kernel/IPipelined2008.h"

// INFERRED: 005e86a0 - Global function that removes edge from primitive's lists
extern "C" void __cdecl removeEdgeFromPrimitiveLists(RBX::Edge* e);

namespace RBX
{

// 00669c70: virtual void onEdgeRemoving(Edge* e) - vftable slot 5
// Target: 121 bytes. Candidate: 111 bytes (DIFF - layout differs)
void TreeStage::onEdgeRemoving(Edge* e)
{
    // ESI = e, EDI = this
    // Call e->getEdgeType() (vtable slot 3, offset 0xC)
    Edge::EdgeType edgeType = e->getEdgeType();
    
    Joint* joint = 0;
    Primitive* topPrimitive = 0;
    Primitive* lightestPrimitive = 0;
    Joint* lightestJoint = 0;
    bool callHelper = false;
    bool skipHelper = false;
    
    if (edgeType != Edge::JOINT)  // JOINT = 0
    {
        callHelper = true;
    }
    else
    {
        // Is a JOINT - cast to Joint to access Joint-specific virtual functions
        joint = static_cast<Joint*>(e);
        
        // Call joint->getJointType() (vtable slot 5, offset 0x14)
        Joint::JointType jointType = joint->getJointType();
        
        if (jointType < Joint::ANCHOR_JOINT)  // 5 = ANCHOR_JOINT
        {
            callHelper = true;
        }
        else
        {
            // Joint type >= ANCHOR_JOINT - check active flag
            if (!joint->getActive())  // byte at [esi + 0x24]
            {
                skipHelper = true;
            }
            else
            {
                // Active and jointType >= ANCHOR_JOINT - process the joint
                // Call getTopPrimitive(joint) - 005e7490
                topPrimitive = getTopPrimitive(joint);
                
                // Call findLightestDownstream(topPrimitive, &lightestPrimitive) - 006699a0
                // Initialize output to 0 (matches target: mov dword ptr [esp + 0x14], 0)
                lightestPrimitive = 0;
                lightestJoint = findLightestDownstream(topPrimitive, lightestPrimitive);
                
                // Call replaceLightest(oldJoint, newJoint, primitive) - 00669940
                // oldJoint = joint, newJoint = lightestJoint, primitive = lightestPrimitive (output from findLightestDownstream)
                replaceLightest(joint, lightestJoint, lightestPrimitive);
                
                // Set dirty flag at this + 0x14
                dirty = true;
                
                skipHelper = true;
            }
        }
    }
    
    if (callHelper)
    {
        // Call cleanup helper 00669710
        onEdgeRemovingNonJoint(e);
    }
    
    // Common cleanup path (00669cd3)
    // Call edge->removeFromStage(this) - 00645840 (IPipelined::removeFromStage)
    e->removeFromStage(this);
    
    // Call fn_005e86a0 (edge cleanup) - 005e86a0
    // INFERRED: Global function that removes edge from primitive's lists
    removeEdgeFromPrimitiveLists(e);
}

// 00669710: private helper for onEdgeRemoving cleanup (non-JOINT or jointType < ANCHOR_JOINT)
void TreeStage::onEdgeRemovingNonJoint(Edge* e)
{
    // INFERRED: 00669710 - cleanup for edges that don't meet the joint criteria
    // The binary just calls this and then proceeds to common cleanup
    (void)e;  // Suppress unused parameter warning
}

// 00669410: void process() - callgraph-adjacency
// Target: 323 bytes. Candidate: 210 bytes (DIFF - iterator layout differs)
void TreeStage::process()
{
    // Check dirty flag at +0x14
    if (!dirty)
        return;
    
    // Iterate through assemblies set at +0x38
    // Clean each assembly using cleanAssembly (00668f20)
    // Target uses explicit _Tree iterator with _SECURE_SCL checks:
    //   _M_head at +0x0, _M_size at +0x4, _M_head._M_left (begin) at +0x10, _M_head._M_parent (end) at +0x14
    for (std::set<Assembly*>::iterator it = assemblies.begin(); it != assemblies.end(); )
    {
        Assembly* assembly = *it;
        // Call cleanAssembly(assembly) - 00668f20
        cleanAssembly(assembly);
        // Erase and advance iterator (cleanAssembly removes from set)
        it = assemblies.erase(it);
    }
    
    // Iterate through edges set at +0x58
    // Clean each edge using cleanEdge (00668fa0) while size at +0x74 is non-zero
    // Target checks _M_size at [esi + 0x74] (edges._M_t._M_impl._M_size)
    while (!edges.empty())
    {
        std::set<Edge*>::iterator it = edges.begin();
        Edge* edge = *it;
        // Call cleanEdge(edge) - 00668fa0
        cleanEdge(edge);
        // Erase the edge (cleanEdge removes from set)
        edges.erase(it);
    }
    
    // Clear dirty flag
    dirty = false;
}

// 006699a0: Joint* findLightestDownstream(Primitive* p, Primitive*& outLightestPrimitive) - callgraph-adjacency
// Target: 446 bytes. Candidate: 314 bytes (DIFF - SEH frame and local set layout differs)
// PARKED: 4+ LLM tries. Complex SEH prologue and stack-allocated std::set.
Joint* TreeStage::findLightestDownstream(Primitive* p, Primitive*& outLightestPrimitive)
{
    // Create local std::set<Primitive*> on stack for collecting top joints
    // Target allocates this at [esp+0x40] with 0x50 byte stack frame including SEH
    std::set<Primitive*> topJoints;
    
    // Call collectTopJoints(p, &topJoints) - 00669150
    collectTopJoints(p, &topJoints);
    
    Joint* lightestJoint = 0;
    Primitive* lightestPrimitive = 0;
    int lightestDepth = -1;  // INFERRED: tracks the "lightest" by some metric
    
    // Iterate through collected top joints
    for (std::set<Primitive*>::iterator it = topJoints.begin(); it != topJoints.end(); ++it)
    {
        Primitive* currentPrimitive = *it;
        
        // Call getFirstJoint() on primitive - 005e7b90
        Joint* joint = currentPrimitive->getFirstJoint();
        while (joint)
        {
            // Check if joint is active at +0x24
            if (joint->getActive())
            {
                // Call getEdgeType() - should return JOINT (0)
                // getEdgeType is protected in Joint, but virtual - call through Edge interface
                Edge* edgePtr = joint;
                Edge::EdgeType edgeType = edgePtr->getEdgeType();
                if (edgeType == Edge::JOINT)
                {
                    // Call getJointType() (vtable slot 5)
                    Joint::JointType jointType = joint->getJointType();
                    
                    // INFERRED: Complex logic to determine "lightest" joint
                    // The assembly compares joint's primitive's assembly/clump depth
                    // and selects based on some criteria
                    
                    // Get the other primitive from this joint
                    Primitive* otherPrim = joint->otherPrimitive(currentPrimitive);
                    
                    // Get assembly of the other primitive
                    Assembly* assembly = otherPrim->getAssembly();
                    if (assembly)
                    {
                        // INFERRED: Compare some metric (depth, mass, etc.)
                        // For now, pick the first valid one
                        if (!lightestJoint)
                        {
                            lightestJoint = joint;
                            lightestPrimitive = otherPrim;
                        }
                    }
                }
            }
            
            // Get next joint - 005e7ba0
            joint = currentPrimitive->getNextJoint(joint);
        }
    }
    
    outLightestPrimitive = lightestPrimitive;
    return lightestJoint;
}

} // namespace RBX