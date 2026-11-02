"""Batch independent native source checks; this is not a player or swap gate."""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time

root = Path(__file__).resolve().parents[3]
tests = root / 'rebuild/2008-06/tests'
network_checks = (
    'record_native_rakpeer_layout_integrated.py',
    'record_native_rakpeer_lifetime_integrated.py',
    'record_native_rakpeer_bandwidth_integrated.py',
    'record_native_rakpeer_compression_integrated.py',
    'record_native_rakpeer_loop_integrated.py',
    'record_native_rakpeer_update_integrated.py',
    'record_native_rakpeer_bitstream_rpc_integrated.py',
    'record_native_rakpeer_raw_rpc_integrated.py',
    'record_native_profiled_rakpeer_integrated.py',
    'record_native_peer_constructor_integrated.py',
    'record_native_peer_lifetime_integrated.py',
    'record_native_peer_update_integrated.py',
    'record_native_peer_classname_integrated.py',
    'record_native_reliability_lifetime_integrated.py',
    'record_native_remote_system_integrated.py',
)
sound_checks = (
    'record_native_name_whole.py',
    'record_native_sound_classnames_integrated.py',
    'record_native_sound_name_providers_integrated.py',
    'record_native_sound_constructors_integrated.py',
    'record_native_sound_typed_properties_integrated.py',
    'record_native_sound_value_get_integrated.py',
    'record_native_sound_value_convert_float_integrated.py',
    'record_native_sound_value_convert_id_integrated.py',
    'record_native_sound_value_generic_float_integrated.py',
    'record_native_sound_value_generic_id_integrated.py',
    'record_native_sound_string_converter_integrated.py',
    'record_native_sound_service_provider_integrated.py',
    'record_native_stocksound_ctor_integrated.py',
    'record_native_gamesettings_singleton_integrated.py',
    'record_native_gamesettings_storage_integrated.py',
    'record_native_stats_classname_integrated.py',
    'record_native_instance_descendant_integrated.py',
    'record_native_instance_read_property_integrated.py',
    'record_native_service_lookup_integrated.py',
)
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('group', choices=('all', 'network', 'sound'), nargs='?', default='all')
group = parser.parse_args().group
checks = network_checks + sound_checks if group == 'all' else (network_checks if group == 'network' else sound_checks)

def run(name):
    start = time.monotonic()
    script = tests / name
    digest = hashlib.sha256(script.read_bytes()).hexdigest()
    result = subprocess.run([sys.executable, str(script)], cwd=root,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            text=True, errors='replace')
    if hashlib.sha256(script.read_bytes()).hexdigest() != digest:
        result.returncode = 1
        result.stdout += '\nCheck script changed during execution.\n'
    return name, result, time.monotonic() - start, digest

failures = []
results = []
start = time.monotonic()
with ThreadPoolExecutor(max_workers=3) as pool:
    for future in as_completed([pool.submit(run, name) for name in checks]):
        name, result, elapsed, digest = future.result()
        results.append({'check': name, 'exit': result.returncode,
                        'seconds': round(elapsed, 3),
                        'script_sha256': digest,
                        'error_tail': result.stdout[-2500:] if result.returncode else ''})
        if result.returncode:
            failures.append(name)
            print(f'FAIL {name} ({elapsed:.1f}s)\n{result.stdout[-2500:]}', flush=True)
        else:
            print(f'PASS {name} ({elapsed:.1f}s)', flush=True)
total = len(checks)
if group in ('all', 'sound') and 'record_native_name_whole.py' not in failures:
    name, result, elapsed, digest = run('record_native_name_cross_abi.py')
    total += 1
    results.append({'check': name, 'exit': result.returncode, 'seconds': round(elapsed, 3),
                    'script_sha256': digest, 'error_tail': result.stdout[-2500:] if result.returncode else ''})
    if result.returncode:
        failures.append(name)
        print(f'FAIL {name} ({elapsed:.1f}s)\n{result.stdout[-2500:]}', flush=True)
    else:
        print(f'PASS {name} ({elapsed:.1f}s)', flush=True)
print(f'{total-len(failures)}/{total} checks passed in {time.monotonic()-start:.1f}s. '
      'No client ABI, P5/P6 or server claim.', flush=True)
summary = {'scope': 'Source checks and scoped standalone tests only; no client ABI, P5/P6 or server claim.',
           'group': group, 'finished_utc': datetime.now(timezone.utc).isoformat(),
           'seconds': round(time.monotonic()-start, 3), 'results': sorted(results, key=lambda x: x['check'])}
receipt = root / 'work/2008-06/shared-layouts/native-checkpoint-summary.json'
receipt.parent.mkdir(parents=True, exist_ok=True)
encoded = json.dumps(summary, indent=2) + '\n'
receipt.write_text(encoded, encoding='utf-8')
(receipt.parent / f'native-checkpoint-{group}.json').write_text(encoded, encoding='utf-8')
sys.exit(bool(failures))
