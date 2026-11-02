project(
  'gaskpass',
  'c',
  version: '1.0.0',
  default_options: [
    'warning_level=3',
    'c_std=c17',
  ],
)

executable(
  'gaskpass',
  'main.c',
  dependencies: [
    dependency('gtk4'),
  ],
  install: true,
)

install_data(
  'gaskpass-sudo',
  install_dir: get_option('bindir'),
  install_mode: 'rwxr-xr-x',
)
