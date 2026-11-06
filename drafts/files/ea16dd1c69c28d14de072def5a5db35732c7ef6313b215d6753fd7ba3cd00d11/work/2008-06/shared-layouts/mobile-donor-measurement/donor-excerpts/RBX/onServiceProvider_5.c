// onServiceProvider
// address: 0036d980
// namespace: RBX/RunService
// size: 9


/* RBX::RunService::onServiceProvider(RBX::ServiceProvider*, RBX::ServiceProvider*) */

void RBX::RunService::onServiceProvider(ServiceProvider *param_1,ServiceProvider *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_b0 [8];
  ServiceProvider *pSStack_a8;
  undefined4 uStack_a4;
  int iStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  undefined1 auStack_94 [4];
  undefined4 uStack_90;
  undefined *puStack_7c;
  int iStack_78;
  undefined1 *puStack_74;
  int iStack_70;
  undefined1 *puStack_6c;
  
  if (param_2 != (ServiceProvider *)0x0) {
    puStack_74 = &stack0xfffffff8;
    puStack_6c = auStack_b0;
    iVar2 = *(int *)(param_1 + 0x60);
    iStack_78 = DAT_0036cf5c + 0x36ce34;
    puStack_7c = PTR____gxx_personality_sj0_0123c4c0;
    iStack_70 = (DAT_0036cf60 | 1) + 0x36ce4a;
    __Unwind_SjLj_Register(auStack_94);
    if (iVar2 != 0) {
      uStack_90 = 0xffffffff;
      uVar1 = TaskScheduler::singleton();
      uStack_9c = *(undefined4 *)(param_1 + 0x60);
      uStack_90 = 0xffffffff;
      pSStack_a8 = param_1;
      boost::detail::shared_count::shared_count
                ((shared_count *)&iStack_98,(shared_count *)(param_1 + 100));
      uStack_90 = 1;
      RBX::TaskScheduler::remove(uVar1,&uStack_9c);
      if (iStack_98 != 0) {
        uStack_90 = 0xffffffff;
        boost::detail::sp_counted_base::release();
      }
      param_1 = pSStack_a8;
      *(undefined4 *)(pSStack_a8 + 0x60) = 0;
      iVar2 = *(int *)(pSStack_a8 + 100);
      *(undefined4 *)(pSStack_a8 + 100) = 0;
      if (iVar2 != 0) {
        uStack_90 = 0xffffffff;
        boost::detail::sp_counted_base::release();
      }
    }
    if (*(int *)(param_1 + 0x68) != 0) {
      uStack_90 = 0xffffffff;
      uVar1 = TaskScheduler::singleton();
      uStack_a4 = *(undefined4 *)(param_1 + 0x68);
      uStack_90 = 0xffffffff;
      pSStack_a8 = param_1;
      boost::detail::shared_count::shared_count
                ((shared_count *)&iStack_a0,(shared_count *)(param_1 + 0x6c));
      uStack_90 = 3;
      RBX::TaskScheduler::remove(uVar1,&uStack_a4);
      if (iStack_a0 != 0) {
        uStack_90 = 0xffffffff;
        boost::detail::sp_counted_base::release();
      }
      *(undefined4 *)(pSStack_a8 + 0x68) = 0;
      iVar2 = *(int *)(pSStack_a8 + 0x6c);
      *(undefined4 *)(pSStack_a8 + 0x6c) = 0;
      if (iVar2 != 0) {
        uStack_90 = 0xffffffff;
        boost::detail::sp_counted_base::release();
      }
    }
    __Unwind_SjLj_Unregister(auStack_94);
    return;
  }
  return;
}


