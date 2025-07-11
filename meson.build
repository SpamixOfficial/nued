project(
  'nued',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

curses = dependency('ncurses')

dependencies = [
  curses
]

subdir('src')

exe = executable(
  'nued',
  sources,
  dependencies : dependencies,
  install : true,
)

test('basic', exe)
