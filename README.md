# Gaskpass

This tool can be used in a combination with sudo:

```sh
$ SUDO_ASKPASS=gaskpass sudo --prompt "Your text" --askpass ls -l
```

Which results in

![screenshot](./screenshot.png)

Basically it's a sudo-friendly replacement of `zenity --password`.

It's used with (or rather by) `sudo` and so of course it respects `/etc/sudoers`.

# Building

Make sure to install `gtk4`, clone the repo and run `make`.
