# Project Name

TODO

## Installation

### Binary

Binary packages for Debian, Ubuntu, RaspberryPi and other Debian-based
distributions can be installed from the [CCCP Linux Package
Archive](https://github.com/cccp-linux/archive). Follow their instructions to
set up the archive and be sure to add the _???_ component. Then, run:

```shell
sudo apt install lib???
```

Install the development package, if you are planning to develop applications
with **???**:
```shell
sudo apt install lib???-dev
```

### From source

Latest release (requires [CMake](https://cmake.org/) >= 3.22, and
[GoogleTest](https://github.com/google/googletest) to run tests):

```shell
o=dimitry-ishenko-??? p=???

url=https://api.github.com/repos/${o}/${p}/releases/latest
curl -Lo ${p}.tar.gz $(curl -sL $url | jq -r .tarball_url)

mkdir -p ${p}/build
tar -xvf ${p}.tar.gz -C ${p} --strip-components=1

cd ${p}/build
cmake ..
make all test
sudo make install
```

## Usage

TODO

## Authors

* **Dimitry Ishenko** - dimitry (dot) ishenko (at) (gee) mail (dot) com

## License

This project is distributed under the GNU GPL license. See the
[LICENSE.md](LICENSE.md) file for details.
