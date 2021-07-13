# Project Name

Project description.

## Installation

### Prerequisites

* Project A
* Project B

### Binary

Debian/Ubuntu/etc:

```shell
$ p=...
$ v=0.0
$ wget https://github.com/dimitry-ishenko/${p}/releases/download/v${v}/${p}_${v}_amd64.deb
$ sudo apt install ./${p}_${v}_amd64.deb
```

RaspberryPi:

```shell
$ p=...
$ v=0.0
$ wget https://github.com/dimitry-ishenko/${p}/releases/download/v${v}/${p}_${v}_armhf.deb
$ sudo apt install ./${p}_${v}_armhf.deb
```

### From source

Stable version (requires [CMake](https://cmake.org/) >= 3.1):

```shell
$ p=...
$ v=0.0
$ wget https://github.com/dimitry-ishenko/${p}/archive/v${v}.tar.gz
$ tar xzf v${v}.tar.gz
$ mkdir ${p}-${ver}/build
$ cd ${p}-${ver}/build
$ cmake ..
$ make
$ sudo make install
```

Latest master (requires [git](https://git-scm.com/) and [CMake](https://cmake.org/) >= 3.1):

```shell
$ p=...
$ git clone https://github.com/dimitry-ishenko/${p}.git
$ mkdir ${p}/build
$ cd ${p}/build
$ cmake ..
$ make
$ sudo make install
```

## Authors

* **Dimitry Ishenko** - dimitry (dot) ishenko (at) (gee) mail (dot) com

## License

This project is distributed under the GNU GPL license. See the
[LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* John Doe
