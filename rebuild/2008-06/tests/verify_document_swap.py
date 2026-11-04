"""Rebuild recent document dependencies and report the diagnostic link honestly."""
import json
from concurrent.futures import ThreadPoolExecutor, as_completed
import subprocess
import sys
import time
from pathlib import Path

root = Path(__file__).resolve().parents[3]
tests = root / 'rebuild/2008-06/tests'
out = root / 'rebuild/2008-06/out/native-layouts/document-swap-link-trial'
out.mkdir(parents=True, exist_ok=True)
steps = [
    'record_native_instance_child_listener.py',
    'record_native_instance_callbacks.py',
    'record_native_instance_serialization.py',
    'record_native_face_lifetime.py',
    'record_native_class_names_trial.py',
    'record_native_group_action_trial.py',
    'record_native_group_helper_trial.py',
    'record_native_model_factory_trial.py',
    'record_native_move_up_constructors_trial.py',
    'record_native_move_up_action_trial.py',
    'record_native_rotate_action_trial.py',
    'record_native_bool_property_actions_trial.py',
    'record_native_bool_property_access_trial.py',
    'record_native_ungroup_action_trial.py',
    'record_native_ungroup_operation_trial.py',
    'record_native_duplicate_action_trial.py',
    'record_native_safearray_trial.py',
    'record_native_value_converter_worker_trial.py',
    'record_native_register_image_worker.py',
    'record_native_gametool_lifetime.py',
    'record_native_change_history_factory.py',
    'record_native_instance_link_profile.py',
    'record_native_content_provider_layout.py',
    'record_native_instance_signal_archive.py',
    'record_native_decal_lifetime.py',
    'record_native_filtered_selection.py',
    'record_native_workspace_base_offsets.py',
    'record_native_model_lifetime_trial.py',
    'record_native_camera_units.py',
    'record_native_camera_history.py',
    'record_native_sound_service_play.py',
    'record_native_exit_command.py',
    'record_native_selection_commands.py',
    'record_native_move_down_trial.py',
    'record_native_insert_service_trial.py',
    'record_native_insert_dialog_trial.py',
    'record_native_class_images_trial.py',
    'record_native_clipboard_trial.py',
    'record_native_workspace_select_all.py',
    'record_native_part_set_locked_compact.py',
    'record_native_surface_visitors.py',
    'record_native_tool_checked_multi_trial.py',
    'record_native_tool_lifetime_evidence.py',
    'record_native_surface_tool_trial.py',
    'record_native_surface_siblings_trial.py',
    'record_native_flat_tool_methods_trial.py',
    'record_native_flat_tool_name_trial.py',
    'record_native_surface_hover_trial.py',
    'record_native_surface_down_trial.py',
    'record_native_surface_render_trial.py',
    'record_native_mouse_get_surface_trial.py',
    'record_native_part_get_surface_trial.py',
    'record_native_surface_flat_trial.py',
    'record_native_surface_changed_trial.py',
    'record_native_glue_tool_factory_trial.py',
    'record_native_glue_tool_methods_trial.py',
    'record_native_weld_tool_factory_trial.py',
    'record_native_weld_tool_methods_trial.py',
    'record_native_studs_tool_factory_trial.py',
    'record_native_studs_tool_methods_trial.py',
    'record_native_inlet_tool_factory_trial.py',
    'record_native_inlet_tool_methods_trial.py',
    'record_native_hinge_tool_factory_trial.py',
    'record_native_hinge_tool_methods_trial.py',
    'record_native_rightmotor_tool_factory_trial.py',
    'record_native_rightmotor_tool_methods_trial.py',
    'record_native_leftmotor_tool_factory_trial.py',
    'record_native_leftmotor_tool_methods_trial.py',
    'record_native_oscillatemotor_tool_factory_trial.py',
    'record_native_oscillatemotor_tool_methods_trial.py',
    'record_native_model_set_front_factory_trial.py',
    'record_native_model_set_front_methods_trial.py',
    'record_native_top_level_pv_parent_trial.py',
    'record_native_part_tool_trial.py',
    'record_native_clone_tool_trial.py',
    'record_native_grab_tool_trial.py',
    'record_native_clear_starter_trial.py',
    'record_native_clear_backpack_trial.py',
    'record_native_stats_commands_trial.py',
    'record_native_engine_stats_evidence.py',
    'record_native_engine_stats_trial.py',
    'record_native_join_command_trial.py',
    'record_native_motor_feature_trial.py',
    'record_native_velocity_set_hole_trial.py',
    'record_native_grab_methods_trial.py',
    'record_native_grab_name_trial.py',
    'record_native_clone_methods_trial.py',
    'record_native_clone_sticky_trial.py',
    'record_native_clone_name_trial.py',
    'record_native_clone_down_trial.py',
    'record_native_part_tools_factories_trial.py',
    'record_native_part_tool_methods_trial.py',
    'record_native_model_primary_action_trial.py',
    'record_native_part_tool_names_trial.py',
    'record_native_fill_dropper_methods_trial.py',
    'record_native_fill_action_trial.py',
    'record_native_dropper_action_trial.py',
    'record_native_fill_color_trial.py',
    'record_native_model_tool_trial.py',
    'record_native_model_hover_trial.py',
    'record_native_lock_methods_trial.py',
    'record_native_model_tool_names_trial.py',
    'record_native_anchor_actions_trial.py',
    'record_native_apply_anchored_trial.py',
    'record_native_anchor_children_trial.py',
    'record_native_find_unanchored_trial.py',
    'record_native_anchor_hover_trial.py',
    'record_native_find_top_instance_trial.py',
    'record_native_anchor_cursor_trial.py',
    'record_native_lock_cursor_trial.py',
    'record_native_tilt_axis_trial.py',
    'record_native_tilt_matrix_trial.py',
    'record_native_tilt_quadrant_trial.py',
    'record_native_tilt_constants_trial.py',
    'record_native_model_tools_trial.py',
    'record_native_camera_first_person_trial.py',
    'record_native_resize_tool_trial.py',
    'record_native_axis_move_tool_trial.py',
    'record_native_resize_tool_methods.py',
    'record_native_part_resize_trial.py',
    'record_native_document_initialize_trial.py',
    'record_native_camera_center_action.py',
    'record_native_camera_zoom_extents_profile.py',
]
log_path = out / 'verification-batch.log'
started = time.monotonic()
def run_check(name):
    check_started = time.monotonic()
    args = [sys.executable, str(tests / name)]
    if name == 'record_native_instance_serialization.py':
        args.append('shared-layouts/instance-serialization-current.json')
    result = subprocess.run(args, cwd=root,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            text=True, errors='replace')
    result.elapsed_seconds = time.monotonic() - check_started
    return name, result

with log_path.open('w', encoding='utf-8') as log:
    failures = []
    name, result = run_check('refresh_workspace_vector_headers.py')
    log.write(f'\n=== {name} (exit {result.returncode}, {result.elapsed_seconds:.2f}s) ===\n{result.stdout}')
    if result.returncode:
        print(f'FAIL {name}: {result.stdout[-3000:]}', flush=True)
        sys.exit(result.returncode)
    print(f'PASS {name} ({result.elapsed_seconds:.1f}s)', flush=True)
    # Each check owns distinct object and receipt paths. Link waits for all checks.
    with ThreadPoolExecutor(max_workers=3) as pool:
        futures = [pool.submit(run_check, name) for name in steps]
        for future in as_completed(futures):
            name, result = future.result()
            log.write(f'\n=== {name} (exit {result.returncode}, {result.elapsed_seconds:.2f}s) ===\n{result.stdout}')
            log.flush()
            if result.returncode:
                failures.append((name, result))
                print(f'FAIL {name} (exit {result.returncode}, {result.elapsed_seconds:.1f}s)\n{result.stdout[-3000:]}', flush=True)
            else:
                print(f'PASS {name} ({result.elapsed_seconds:.1f}s)', flush=True)
    if failures:
        sys.exit(1)
    # Drag trials share generated headers, so rebuild them sequentially.
    serial_checks = ['record_native_group_drag_lifetime_trial.py', 'record_native_group_drag_methods_trial.py',
                 'record_native_group_drag_name_trial.py', 'record_native_part_drag_lifetime_trial.py',
                 'record_native_part_drag_methods_trial.py', 'record_native_part_drag_name_trial.py',
                 'record_native_collect_drag_parts_trial.py', 'record_native_drag_factory_worker_trial.py',
                 'record_native_insert_decal_action_worker.py', 'record_native_decal_texture_worker.py',
                 'record_native_mime_type_worker.py', 'record_native_decal_property_barrier_worker.py',
                 'record_native_getset_slots_worker_trial.py', 'record_native_hammer_worker_trial.py',
                 'record_native_hammer_methods_worker_trial.py', 'record_native_adorn_sparkle_slot_worker.py', 'record_native_laser_trial.py',
                 'record_native_laser_click_trial.py', 'record_native_insert_object_action_worker.py',
                 'record_native_slingshot_worker_trial.py', 'record_native_slingshot_methods_worker_trial.py',
                 'record_native_shoot_worker_trial.py', 'record_native_slingshot_pellet_worker_trial.py',
                 'record_native_slingshot_dependencies_worker_trial.py', 'record_native_rocket_worker_trial.py',
                 'record_native_rocket_launch_worker_trial.py']
    for name in serial_checks:
        name, result = run_check(name)
        log.write(f'\n=== {name} (exit {result.returncode}, {result.elapsed_seconds:.2f}s) ===\n{result.stdout}')
        if result.returncode:
            print(f'FAIL {name}: {result.stdout[-3000:]}', flush=True)
            sys.exit(result.returncode)
        print(f'PASS {name} ({result.elapsed_seconds:.1f}s)', flush=True)
    name, result = run_check('record_native_test_move_bool_trial.py')
    log.write(f'\n=== {name} (exit {result.returncode}, {result.elapsed_seconds:.2f}s) ===\n{result.stdout}')
    if result.returncode:
        print(f'FAIL {name}: {result.stdout[-3000:]}', flush=True)
        sys.exit(result.returncode)
    print(f'PASS {name} ({result.elapsed_seconds:.1f}s)', flush=True)
    check_started = time.monotonic()
    result = subprocess.run([sys.executable, str(tests / 'record_native_document_link_trial.py'),
                             '--filtered-donor', '--provider-trial'], cwd=root,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            text=True, errors='replace')
    log.write(f'\n=== diagnostic link (exit {result.returncode}) ===\n{result.stdout}')
    print(f'Diagnostic link time: {time.monotonic() - check_started:.1f}s', flush=True)
    if result.returncode:
        print(f'FAIL diagnostic setup (exit {result.returncode})\n{result.stdout[-3000:]}', flush=True)
        sys.exit(result.returncode or 1)
    receipt = json.loads((root / 'work/2008-06/shared-layouts/document-swap-provider-trial.json').read_text())
    print(f"Diagnostic link: exit={receipt['link_exit']}, errors={len(receipt['errors'])}; "
          f'{len(steps) + len(serial_checks) + 2} checks passed; {time.monotonic() - started:.1f}s.', flush=True)
    print('Recent dependencies rebuilt; remaining trial objects were not rebuilt. Do not run diagnostic.', flush=True)
    check_started = time.monotonic()
    probe = subprocess.run([sys.executable, str(tests / 'record_native_resize_document_probe.py')], cwd=root,
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors='replace')
    log.write(f'\n=== resize diagnostic (exit {probe.returncode}) ===\n{probe.stdout}')
    print(probe.stdout.strip(), flush=True)
    print(f'Resize probe time: {time.monotonic() - check_started:.1f}s', flush=True)
    check_started = time.monotonic()
    axis_probe = subprocess.run([sys.executable, str(tests / 'record_native_resize_document_probe.py'), '--axis'], cwd=root,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, errors='replace')
    log.write(f'\n=== axis diagnostic (exit {axis_probe.returncode}) ===\n{axis_probe.stdout}')
    print(axis_probe.stdout.strip(), flush=True)
    print(f'Axis probe time: {time.monotonic() - check_started:.1f}s', flush=True)
    if axis_probe.returncode or probe.returncode or receipt['link_exit']:
        sys.exit(1)
