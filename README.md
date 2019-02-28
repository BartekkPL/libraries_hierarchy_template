# Build multiple libraries and set dependiencies between them

### Test

Go to each directory and follow below instructions:
 - `mkdir build`
 - `cd build`
 - `cmake -DCMAKE_INSTALL_PREFIX=<some_directory>`
 - `make`
 - `[sudo] make install`

**In each directory should be set the same `CMAKE_INSTALL_PREFIX`.**

Add libraries install path to directories list where libraries should be
searched for first, before the standard set of directories:
 - `export LD_LIBRARY_PATH=<some_directory>/lib`

Check if everything is working:
 - `./<some_directory>/bin/exec_ab`

Predicted output is: `ab`.

**There should be no error shown.**
