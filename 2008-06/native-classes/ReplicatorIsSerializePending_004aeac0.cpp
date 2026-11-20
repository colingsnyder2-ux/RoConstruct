// NOT COMPILABLE YET - header row is owned by another lease (RBX queue 23-nw04, EspClaude,
// rebuild/2008-06/native-headers/Network/Replicator2008.h until 2026-11-19 14:09). Do not bind.
//
// 004aeac0  RBX::Network::Replicator::isSerializePending(const Instance*) const - INFERRED identity:
//   donor tools/rbxgs/Client/Network/Replicator.cpp:284 (verbatim body, below) and the provisional the
//   native-headers/Replicator.h:270 declaration `bool isSerializePending(const Instance*) const;`
//   (native Network/Replicator2008.h does NOT declare it).
//
// Evidence for ownership (all read from the 2008-06 binary):
//   * 74 bytes, ret 4, one stack parameter, this in ecx, no writes - a const member taking a 4-byte pointer.
//   * this reads [ecx+0x2c90] / [ecx+0x2ca8] = RBX::Network::Replicator::pendingNewInstances:
//     native-headers/Network/Replicator2008.h declares
//       std::set<const Instance*> pendingNewInstances;  // +0x2c90 (004b9d30 / 0064b230)
//     and pendingDeleteInstances at +0x2cb0, so the set spans 0x20 bytes: { _Mycont/owner at +0,
//     padding, _Myhead/sentinel node at +0x18 } (binary-proven; not a donor value).
//   * 004ae060 is the set's find: it reads [this+0x18] as the head sentinel, walks left/right from
//     *key, emits the _SECURE_SCL _invalid_parameter_noinfo calls (0x802890) exactly like the
//     byte-exact Ogre matches (hasAnimation 00695cd0 etc., same 74-byte count and shape).
//   * callers: 004b0540 (Replicator::sendTop? family), 004ca980 and 004caaf0
//     (RoundRobinPhysicsSender rows; this = [sender+0x3c] = Replicator* per PhysicsSenders2008.h).
//     Each passes one Instance*/Item* pointer on the stack.
//   * mangled-name identity: no symbol evidence in the binary; 004aeac0 is a placeholder in the
//     identity registry. isSerializePending is a donor name, not a proven 2008 name.
//
// Proposed binding for the network owner (queue 23-nw04):
//   1. native-headers/Network/Replicator2008.h, in the public block after the constructor rows:
//        bool isSerializePending(const Instance* instance) const;  // 004aeac0 ?isSerializePending@Replicator@Network@RBX@@QBE_NABVIInstance@3@@Z ???
//      (mangled form must be re-read from the binary after the declaration lands - it is not proven yet)
//   2. native-classes/NetworkReplicator2008Items.cpp (or the unit that claims Replicator rows):
//        bool Replicator::isSerializePending(const Instance* instance) const
//        {
//            return pendingNewInstances.find(instance) != pendingNewInstances.end();
//        }
//      with // 004aeac0 and the body verbatim from the donor source above.
//   3. prove with: python work/native-client/agent_prove.py <unit>.cpp 004aeac0=isSerializePending
//      (expect EXACT under /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS, the flags the
//      Replicator family units already use).
//
// Do not copy this file into native-classes/ or submit it; the header lease must release first.
// INFERRED: class identity, function name and const-ness are donor-sourced, not binary-proven.
//
// Proposed body (verbatim donor tools/rbxgs/Client/Network/Replicator.cpp:284):
//
//     bool Replicator::isSerializePending(const Instance* instance) const
//     {
//         return pendingNewInstances.find(instance) != pendingNewInstances.end();
//     }
