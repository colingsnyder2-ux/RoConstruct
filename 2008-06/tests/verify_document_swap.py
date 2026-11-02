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
    'record_native_face_lifetime.py',
    'record_native_decal_lifetime.py',
    'record_native_filtered_selection.py',
    'record_native_workspace_base_offsets.py',
    'record_native_model_lifetime_trial.py',
    'record_native_camera_units.py',
    'record_native_camera_history.py',
    'record_native_sound_service_play.py',
    'record_native_exit_command.py',
    'record_native_selection_commands.py',
    'record_native_surface_visitors.py',
    'record_native_tool_checked_multi_trial.py',
    'record_native_tool_lifetime_evidence.py',
    'record_native_resize_tool_trial.py',
    'record_native_document_initialize_trial.py',
    'record_native_camera_center_action.py',
    'record_native_camera_zoom_extents_profile.py',
]
log_path = out / 'verification-batch.log'
started = time.monotonic()
def run_check(name):
    return name, subprocess.run([sys.executable, str(tests / name)], cwd=root,
                                stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                text=True, errors='replace')

with log_path.open('w', encoding='utf-8') as log:
    failures = []
    # Each check owns distinct object and receipt paths. Link waits for all checks.
    with ThreadPoolExecutor(max_workers=3) as pool:
        futures = [pool.submit(run_check, name) for name in steps]
        for future in as_completed(futures):
            name, result = future.result()
            log.write(f'\n=== {name} (exit {result.returncode}) ===\n{result.stdout}')
            log.flush()
            if result.returncode:
                failures.append((name, result))
                print(f'FAIL {name} (exit {result.returncode})\n{result.stdout[-3000:]}', flush=True)
            else:
                print(f'PASS {name}', flush=True)
    if failures:
        sys.exit(1)
    result = subprocess.run([sys.executable, str(tests / 'record_native_document_link_trial.py'),
                             '--filtered-donor', '--provider-trial'], cwd=root,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            text=True, errors='replace')
    log.write(f'\n=== diagnostic link (exit {result.returncode}) ===\n{result.stdout}')
    if result.returncode:
        print(f'FAIL diagnostic setup (exit {result.returncode})\n{result.stdout[-3000:]}', flush=True)
        sys.exit(result.returncode or 1)
    receipt = json.loads((root / 'work/2008-06/shared-layouts/document-swap-provider-trial.json').read_text())
    print(f"Diagnostic link: exit={receipt['link_exit']}, errors={len(receipt['errors'])}; "
          f'{len(steps)} checks passed; {time.monotonic() - started:.1f}s.', flush=True)
    print('Recent dependencies rebuilt; remaining trial objects were not rebuilt. Do not run diagnostic.', flush=True)
    if receipt['link_exit']:
        sys.exit(1)
