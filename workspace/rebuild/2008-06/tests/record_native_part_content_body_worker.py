# Compatibility entry point; implementation is in matching/.
__file__ = str(__import__('pathlib').Path(__file__).parent / 'matching' / 'record_native_part_content_body_worker.py')
exec(compile(open(__file__, 'rb').read(), __file__, 'exec'))
