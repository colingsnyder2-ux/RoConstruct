# Compatibility entry point; implementation is in build/.
__file__ = str(__import__('pathlib').Path(__file__).parent / 'build' / 'header_catalog.py')
exec(compile(open(__file__, 'rb').read(), __file__, 'exec'))
