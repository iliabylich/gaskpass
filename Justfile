setup profile:
    meson setup build --buildtype={{profile}}

dev:
    meson compile -C build
    ./build/gaskpass "Enter your password:"

test-install:
    meson setup build --buildtype=release --prefix=$(pwd)/test-install/usr
    meson compile -C build
    meson install -C build

clean:
    rm -rf build
