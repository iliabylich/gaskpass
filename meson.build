project('gaskpass', 'c',
  version : '1.0.0',
  default_options : [
    'warning_level=3',
    'c_std=c23',
  ]
)

gtk4_dep = dependency('gtk4')

gaskpass_exe = executable('gaskpass',
  'main.c',
  dependencies : [gtk4_dep],
  install : true,
)

install_data('gaskpass-sudo',
  install_dir : get_option('bindir'),
  install_mode : 'rwxr-xr-x'
)