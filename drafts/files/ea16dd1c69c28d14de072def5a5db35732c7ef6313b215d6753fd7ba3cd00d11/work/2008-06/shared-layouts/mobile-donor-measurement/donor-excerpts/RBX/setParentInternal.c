// setParentInternal
// address: 00729e64
// namespace: RBX/Instance
// size: 1951


/* RBX::Instance::setParentInternal(RBX::Instance*, bool) */

undefined4 __thiscall
RBX::Instance::setParentInternal(Instance *this,Instance *param_1,bool param_2)

{
  Instance *pIVar1;
  bool bVar2;
  Instance *pIVar3;
  uint uVar4;
  int iVar5;
  allocator *paVar6;
  shared_ptr<RBX::Instance> *this_00;
  undefined4 *puVar7;
  undefined *puVar8;
  int *piVar9;
  int *extraout_r1;
  int *extraout_r1_00;
  int *extraout_r1_01;
  Instance *pIVar10;
  shared_ptr *psVar11;
  undefined4 uVar12;
  shared_ptr<RBX::Instance> *psVar13;
  Instance *local_144;
  Instance *local_140;
  Instance *local_13c;
  undefined *local_138;
  undefined4 local_134;
  int local_130;
  undefined *local_12c;
  undefined4 local_128;
  int local_124;
  undefined4 local_120;
  int local_11c;
  Instance *local_118;
  int local_114;
  undefined4 local_110;
  int local_10c;
  int local_108;
  allocator aaStack_104 [4];
  int local_100;
  allocator aaStack_fc [4];
  int local_f8;
  int local_f4;
  int *local_f0;
  string asStack_ec [4];
  int *local_e8;
  string asStack_e4 [4];
  int *local_e0;
  string asStack_dc [52];
  Instance *local_a8;
  runtime_error *local_a4;
  runtime_error *local_a0;
  runtime_error *local_9c;
  char *local_98;
  undefined1 auStack_94 [4];
  undefined4 local_90;
  undefined *local_7c;
  int local_78;
  undefined1 *local_74;
  int local_70;
  undefined1 *local_6c;
  
  local_74 = &stack0xfffffff8;
  local_6c = &stack0xfffffea0;
  pIVar10 = *(Instance **)(this + 0x34);
  local_78 = DAT_0072aa30 + 0x729e9e;
  local_7c = PTR____gxx_personality_sj0_0123c4c0;
  local_70 = (DAT_0072aa34 | 1) + 0x729eb4;
  local_a8 = this;
  __Unwind_SjLj_Register(auStack_94);
  puVar8 = PTR_Asserts_0123c1e0;
  uVar12 = 1;
  if (pIVar10 != param_1) {
    if ((!param_2) && (*(char *)(*(int *)(local_a8 + 0x44) + 0x15) != '\0')) {
      local_90 = 0xffffffff;
      getFullName();
      local_90 = 1;
      format((char *)asStack_dc,"The Parent property of %s is locked",local_e0);
      paVar6 = (allocator *)(local_e0 + -3);
      if (paVar6 != (allocator *)PTR__S_empty_rep_storage_0123c274) {
        local_e0 = local_e0 + -1;
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(local_e0);
          iVar5 = *local_e0;
          bVar2 = (bool)hasExclusiveAccess(local_e0);
        } while (!bVar2);
        *local_e0 = iVar5 + -1;
        DataMemoryBarrier(0x1b);
        if (iVar5 < 1) {
          std::string::_Rep::_M_destroy(paVar6);
          local_e0 = extraout_r1_00;
        }
      }
      local_a4 = (runtime_error *)___cxa_allocate_exception(8,local_e0);
      local_90 = 2;
      std::runtime_error::runtime_error(local_a4,asStack_dc);
      local_90 = 3;
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(local_a4,PTR_typeinfo_0123c2c4,PTR__runtime_error_0123c278);
    }
    pIVar3 = param_1;
    if (local_a8 == param_1) {
      local_90 = 0xffffffff;
      getFullName();
      local_90 = 4;
      format((char *)asStack_e4,"Attempt to set %s as its own parent",local_e8);
      paVar6 = (allocator *)(local_e8 + -3);
      if (paVar6 != (allocator *)PTR__S_empty_rep_storage_0123c274) {
        local_e8 = local_e8 + -1;
        DataMemoryBarrier(0x1b);
        do {
          ExclusiveAccess(local_e8);
          iVar5 = *local_e8;
          bVar2 = (bool)hasExclusiveAccess(local_e8);
        } while (!bVar2);
        *local_e8 = iVar5 + -1;
        DataMemoryBarrier(0x1b);
        if (iVar5 < 1) {
          std::string::_Rep::_M_destroy(paVar6);
          local_e8 = extraout_r1_01;
        }
      }
      local_a0 = (runtime_error *)___cxa_allocate_exception(8,local_e8);
      local_90 = 5;
      std::runtime_error::runtime_error(local_a0,asStack_e4);
      local_90 = 6;
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(local_a0,PTR_typeinfo_0123c2c4,PTR__runtime_error_0123c278);
    }
    do {
      if (pIVar3 == (Instance *)0x0) {
        if (FLog::InstanceTreeManipulation != '\0') {
          local_90 = 0xffffffff;
          FLog::FastLog(FLog::InstanceTreeManipulation,
                        "Instance %p: Setting parent to: %p. Old parent: %p",local_a8,param_1,
                        pIVar10);
          pIVar10 = *(Instance **)(local_a8 + 0x34);
        }
        if (local_a8[0x40] != (Instance)0x0) {
          uVar12 = 1;
          if (pIVar10 != param_1) {
            if (pIVar10 == (Instance *)0x0) {
              local_90 = 0xb;
              std::string::string((string *)&local_f8,"NULL",aaStack_fc);
            }
            else {
              local_90 = 0xffffffff;
              std::string::string((string *)&local_f8,(string *)(*(int *)(pIVar10 + 0x44) + 0x18));
            }
            if (param_1 == (Instance *)0x0) {
              local_90 = 0xd;
              std::string::string((string *)&local_100,"NULL",aaStack_104);
            }
            else {
              local_90 = 0xc;
              std::string::string((string *)&local_100,(string *)(*(int *)(param_1 + 0x44) + 0x18));
            }
            local_90 = 0xe;
            format((char *)&local_108,
                   "Something unexpectedly tried to set the parent of %s to %s while trying to set the parent of %s. Current parent is %s."
                   ,*(undefined4 *)(*(int *)(local_a8 + 0x44) + 0x18),local_100);
            local_90 = 0xf;
            StandardOut::singleton((StandardOut *)&local_110);
            local_90 = 0x10;
            StandardOut::printf(local_110,3,local_108);
            if (local_10c != 0) {
              local_90 = 0x11;
              boost::detail::sp_counted_base::release();
            }
            puVar8 = PTR__S_empty_rep_storage_0123c274;
            if (*PTR_NoThrowOnReparenting_012450c4 == '\0') {
              local_98 = (char *)___cxa_allocate_exception(8);
              local_90 = 0x12;
              runtime_error(local_98,
                            "Something unexpectedly tried to set the parent of %s to %s while trying to set the parent of %s. Current parent is %s."
                            ,*(undefined4 *)(*(int *)(local_a8 + 0x44) + 0x18),local_100);
              local_90 = 0x13;
                    /* WARNING: Subroutine does not return */
              ___cxa_throw(local_98,PTR_typeinfo_0123c2c4,PTR__runtime_error_0123c278);
            }
            if ((allocator *)(local_108 + -0xc) != (allocator *)PTR__S_empty_rep_storage_0123c274) {
              piVar9 = (int *)(local_108 + -4);
              DataMemoryBarrier(0x1b);
              do {
                ExclusiveAccess(piVar9);
                iVar5 = *piVar9;
                bVar2 = (bool)hasExclusiveAccess(piVar9);
              } while (!bVar2);
              *piVar9 = iVar5 + -1;
              DataMemoryBarrier(0x1b);
              if (iVar5 < 1) {
                std::string::_Rep::_M_destroy((allocator *)(local_108 + -0xc));
              }
            }
            if ((allocator *)(local_100 + -0xc) != (allocator *)puVar8) {
              piVar9 = (int *)(local_100 + -4);
              DataMemoryBarrier(0x1b);
              do {
                ExclusiveAccess(piVar9);
                iVar5 = *piVar9;
                bVar2 = (bool)hasExclusiveAccess(piVar9);
              } while (!bVar2);
              *piVar9 = iVar5 + -1;
              DataMemoryBarrier(0x1b);
              if (iVar5 < 1) {
                std::string::_Rep::_M_destroy((allocator *)(local_100 + -0xc));
              }
            }
            uVar12 = 0;
            if ((allocator *)(local_f8 + -0xc) != (allocator *)puVar8) {
              piVar9 = (int *)(local_f8 + -4);
              DataMemoryBarrier(0x1b);
              do {
                ExclusiveAccess(piVar9);
                iVar5 = *piVar9;
                bVar2 = (bool)hasExclusiveAccess(piVar9);
              } while (!bVar2);
              *piVar9 = iVar5 + -1;
              uVar12 = 0;
              DataMemoryBarrier(0x1b);
              if (iVar5 < 1) {
                std::string::_Rep::_M_destroy((allocator *)(local_f8 + -0xc));
                uVar12 = 0;
              }
            }
          }
          goto LAB_0072a418;
        }
        local_90 = 0xffffffff;
        RBX::shared_from<RBX::Instance>((Instance *)&local_118);
        local_90 = 0x15;
        RBX::shared_from<RBX::Instance>((Instance *)&local_120);
        local_a8[0x40] = (Instance)0x1;
        local_90 = 0x16;
        (**(code **)(*(int *)local_a8 + 0x38))(local_a8,param_1);
        local_90 = 0x17;
        (**(code **)(*(int *)local_a8 + 0x3c))(local_a8,param_1,local_a8);
        if (param_1 != (Instance *)0x0) {
          local_90 = 0x18;
          (**(code **)(*(int *)param_1 + 0x40))(param_1,local_a8);
          local_90 = 0x19;
          (**(code **)(*(int *)param_1 + 0x44))(param_1,param_1,local_a8);
        }
        if (local_118 == (Instance *)0x0) goto LAB_0072a2ae;
        pIVar10 = param_1;
        if (param_1 == (Instance *)0x0) goto LAB_0072a0fc;
        goto LAB_0072a0f2;
      }
      pIVar1 = pIVar3 + 0x34;
      pIVar3 = *(Instance **)pIVar1;
    } while (*(Instance **)pIVar1 != local_a8);
    uVar4 = (uint)(byte)*PTR_Asserts_0123c1e0;
    if ((uVar4 != 0) && (param_1 == (Instance *)0x0)) {
      if (*(code **)PTR__debugHook_0123c178 != (code *)0x0) {
        local_90 = 0xffffffff;
        iVar5 = (**(code **)PTR__debugHook_0123c178)
                          ("newParent",
                           "/Volumes/MacintoshHD2/Developer/buildAgent/work/565213a28ede2fde/Client/App/v8tree/Instance.cpp"
                           ,0x1c6);
        if (iVar5 != 0) goto LAB_00729f46;
        uVar4 = (uint)(byte)*puVar8;
      }
      local_90 = 0xffffffff;
      ReleaseAssert(uVar4,
                    "newParent file: /Volumes/MacintoshHD2/Developer/buildAgent/work/565213a28ede2fde/Client/App/v8tree/Instance.cpp line: 454"
                   );
    }
LAB_00729f46:
    local_90 = 0xffffffff;
    getFullName();
    piVar9 = local_f0;
    local_90 = 7;
    getFullName();
    local_90 = 8;
    format((char *)asStack_ec,"Attempt to set parent of %s to %s would result in circular reference"
           ,piVar9,local_f4);
    puVar8 = PTR__S_empty_rep_storage_0123c274;
    if ((allocator *)(local_f4 + -0xc) != (allocator *)PTR__S_empty_rep_storage_0123c274) {
      piVar9 = (int *)(local_f4 + -4);
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(piVar9);
        iVar5 = *piVar9;
        bVar2 = (bool)hasExclusiveAccess(piVar9);
      } while (!bVar2);
      *piVar9 = iVar5 + -1;
      DataMemoryBarrier(0x1b);
      if (iVar5 < 1) {
        std::string::_Rep::_M_destroy((allocator *)(local_f4 + -0xc));
      }
    }
    paVar6 = (allocator *)(local_f0 + -3);
    if (paVar6 != (allocator *)puVar8) {
      local_f0 = local_f0 + -1;
      DataMemoryBarrier(0x1b);
      do {
        ExclusiveAccess(local_f0);
        iVar5 = *local_f0;
        bVar2 = (bool)hasExclusiveAccess(local_f0);
      } while (!bVar2);
      *local_f0 = iVar5 + -1;
      DataMemoryBarrier(0x1b);
      if (iVar5 < 1) {
        std::string::_Rep::_M_destroy(paVar6);
        local_f0 = extraout_r1;
      }
    }
    local_9c = (runtime_error *)___cxa_allocate_exception(8,local_f0);
    local_90 = 9;
    std::runtime_error::runtime_error(local_9c,asStack_ec);
    local_90 = 10;
                    /* WARNING: Subroutine does not return */
    ___cxa_throw(local_9c,PTR_typeinfo_0123c2c4,PTR__runtime_error_0123c278);
  }
  goto LAB_0072a418;
  while (pIVar3 = pIVar10 + 0x34, pIVar10 = *(Instance **)pIVar3,
        *(Instance **)pIVar3 != (Instance *)0x0) {
LAB_0072a0f2:
    if (pIVar10 == local_118) goto LAB_0072a10a;
  }
LAB_0072a0fc:
  local_90 = 0x1a;
  signalDescendantRemoving((shared_ptr *)&local_120,local_118,param_1);
LAB_0072a10a:
  local_90 = 0x1b;
  (**(code **)(*(int *)local_118 + 0x68))(local_118,local_a8);
  local_90 = 0x1c;
  piVar9 = (int *)RBX::
                  copy_on_write_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>>
                  ::write();
  psVar11 = (shared_ptr *)*piVar9;
  psVar13 = *(shared_ptr<RBX::Instance> **)(psVar11 + 4);
  uVar4 = (int)psVar13 - *(int *)psVar11 >> 3;
  if (uVar4 == 1) {
    local_90 = 0x1d;
    std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>::
    _M_erase_at_end(psVar11);
    *(int *)(local_118 + 0x38) = 0;
    iVar5 = *(int *)(local_118 + 0x3c);
    *(int *)(local_118 + 0x3c) = 0;
    if (iVar5 != 0) {
      local_90 = 0x1e;
      boost::detail::sp_counted_base::release();
    }
  }
  else {
    this_00 = (shared_ptr<RBX::Instance> *)
              std::
              __find<__gnu_cxx::__normal_iterator<boost::shared_ptr<RBX::Instance>*,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>>,boost::shared_ptr<RBX::Instance>>
                        (*(int *)psVar11,psVar13,&local_120);
    if (this_00 != psVar13) {
      if (uVar4 < 0x15) {
        local_90 = 0x21;
        std::
        vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>::
        erase(psVar11,this_00);
      }
      else {
        local_90 = 0x1f;
        boost::shared_ptr<RBX::Instance>::operator=(this_00,(shared_ptr *)(psVar13 + -8));
        iVar5 = *(int *)(*piVar9 + 4);
        *(int *)(*piVar9 + 4) = iVar5 + -8;
        if (*(int *)(iVar5 + -4) != 0) {
          local_90 = 0x20;
          boost::detail::sp_counted_base::release();
        }
      }
    }
  }
  *(undefined4 *)(local_a8 + 0x34) = 0;
LAB_0072a2ae:
  if (param_1 != (Instance *)0x0) {
    local_90 = 0x22;
    puVar7 = (undefined4 *)
             RBX::
             copy_on_write_ptr<std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>>
             ::write();
    local_90 = 0x23;
    std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance>>>::
    push_back((shared_ptr *)*puVar7);
  }
  *(Instance **)(local_a8 + 0x34) = param_1;
  if (local_118 != (Instance *)0x0) {
    puVar8 = PTR_vtable_0124517c + 8;
    local_128 = local_120;
    local_90 = 0x24;
    local_12c = puVar8;
    boost::detail::shared_count::shared_count((shared_count *)&local_124,(shared_count *)&local_11c)
    ;
    local_128 = local_120;
    local_90 = 0x25;
    rbx::signals::
    signal_with_args<2,void(RBX::Instance::CombinedSignalType,RBX::Instance::ICombinedSignalData_const*)>
    ::operator()(local_118 + 0x50,1,&local_12c);
    local_90 = 0x26;
    RBX::Instance::childRemovedSignal((shared_ptr *)local_118);
    local_90 = 0x27;
    (**(code **)(*(int *)local_118 + 0x6c))(local_118,local_a8);
    local_12c = puVar8;
    if (local_124 != 0) {
      local_90 = 0x28;
      boost::detail::sp_counted_base::release();
    }
  }
  if (param_1 != (Instance *)0x0) {
    local_90 = 0x2a;
    (**(code **)(*(int *)param_1 + 100))(param_1,local_a8);
    for (pIVar10 = local_118; pIVar10 != (Instance *)0x0; pIVar10 = *(Instance **)(pIVar10 + 0x34))
    {
      if (pIVar10 == param_1) goto LAB_0072a36c;
    }
    local_90 = 0x2b;
    signalDescendantAdded(local_a8,param_1,local_118);
LAB_0072a36c:
    puVar8 = PTR_vtable_01245178 + 8;
    local_134 = local_120;
    local_90 = 0x2c;
    local_138 = puVar8;
    boost::detail::shared_count::shared_count((shared_count *)&local_130,(shared_count *)&local_11c)
    ;
    local_134 = local_120;
    local_90 = 0x2d;
    rbx::signals::
    signal_with_args<2,void(RBX::Instance::CombinedSignalType,RBX::Instance::ICombinedSignalData_const*)>
    ::operator()(param_1 + 0x50,0,&local_138);
    local_90 = 0x2e;
    RBX::Instance::childAddedSignal((shared_ptr *)param_1);
    local_138 = puVar8;
    if (local_130 != 0) {
      local_90 = 0x2f;
      boost::detail::sp_counted_base::release();
    }
  }
  local_144 = local_a8;
  local_140 = local_118;
  local_90 = 0x31;
  local_13c = param_1;
  (**(code **)(*(int *)local_a8 + 0x58))(local_a8,&local_144);
  local_90 = 0x32;
  raisePropertyChanged(local_a8,(PropertyDescriptor *)&propParent);
  local_a8[0x40] = (Instance)0x0;
  if (local_11c != 0) {
    local_90 = 0x33;
    boost::detail::sp_counted_base::release();
  }
  uVar12 = 1;
  if (local_114 != 0) {
    local_90 = 0xffffffff;
    boost::detail::sp_counted_base::release();
    uVar12 = 1;
  }
LAB_0072a418:
  __Unwind_SjLj_Unregister(auStack_94);
  return uVar12;
}


