# Compatibility entry point; implementation is in matching/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'matching' / 'audit_native_rakpeer_stale_profiler_worker.py').read_bytes(), __file__, 'exec'))
