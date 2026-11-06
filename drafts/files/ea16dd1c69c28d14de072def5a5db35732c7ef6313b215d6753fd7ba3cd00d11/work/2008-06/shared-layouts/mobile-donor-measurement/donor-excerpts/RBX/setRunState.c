// setRunState
// address: 0036d920
// namespace: RBX/RunService
// size: 95


/* RBX::RunService::setRunState(RBX::RunState) */

void __thiscall RBX::RunService::setRunState(RunService *this,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    *(undefined4 *)(this + 0x84) = 0;
    *(undefined4 *)(this + 0x88) = 0;
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined4 *)(this + 0x78) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    *(undefined4 *)(this + 0x7c) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    *(undefined4 *)(this + 0x80) = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  }
  else if (param_2 == 2) {
    if (*(int *)(this + 0x70) != 1) {
      return;
    }
  }
  else if (param_2 == 1) {
    if ((*(uint *)(this + 0x70) | 2) != 2) {
      return;
    }
    if (*(int *)(this + 0x60) == 0) {
      start(this);
    }
  }
  iVar1 = *(int *)(this + 0x70);
  if (iVar1 == param_2) {
    return;
  }
  *(int *)(this + 0x70) = param_2;
  rbx::signals::signal_with_args<1,void(RBX::RunTransition)>::
  __ZN3rbx7signals16signal_with_argsILi1EFvN3RBX13RunTransitionEEEclES3__shim
            ((signal_with_args<1,void(RBX::RunTransition)> *)(this + 0x9c),iVar1,param_2);
  return;
}


