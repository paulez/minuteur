## Minuteur

Minuteur is a simple kitcher timer.

## Dependencies

It uses the notify-send command to notify when the timer has expired.

It uses cmake to build and Qt5 as GUI library.

## Installing

### Dependencies

#### Ubuntu

```
apt install build-essential git cmake qtbase5-dev
```

#### Fedora

```
dnf install git cmake gcc-c++ qt5-qtbase-devel
```

### Building

```
git clone https://github.com/paulez/minuteur.git
cd minuteur
cmake .
make
sudo make install
```
