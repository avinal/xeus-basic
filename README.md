
```scala
                `7MM***Yy.     db       .M***by. `7MMF'  .g8***bg.
                  MM    Yb    ;MM:     ,MI    `Y   MM  .dP'     `M
     `7M'   `MF'  MM    .P   ,V^MM.    `MMb.       MM  dM'       `
       `VA ,V'    MMooon*   ,M  `MM      `YMMNq.   MM  MM
         XMX      MM    `Y. AbmmmqMA   .     `MM   MM  MM.        
       ,V' VA.    MM    ,9 A'     VML  Mb     dM   MM  `Mb.     .'
     .AM.   .MA..JMMonald'AMA.   .AMMA.`*Ybmmd*  .JMML.  `*bMond^
                                                                  
```

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/avinal/xeus-basic/HEAD) [![GitHub license](https://img.shields.io/github/license/avinal/xeus-basic)](https://github.com/avinal/xeus-basic/blob/master/LICENSE)

Jupyter Kernel for BASIC language


## Steps to run the project:
**You can directly click on *launch binder* badge above to use this kernel right in your browser.***

* Clone this repository.

* Download miniconda [link](https://conda.io/projects/conda/en/latest/user-guide/install/linux.html#installing-on-linux)

* Create a virual env 
``` bash
   conda create -n vbasic
```
* Activate virtual environment that you created

```bash
  conda activate vbasic
```
* Install dependencies

```bash
  conda install -c conda-forge jupyter xeus xtl nlohmann_json cppzmq
```
* Make a build directory to store all the build files
 
```bash
  mkdir build && cd build
```

* Configure CMake

```bash
  cmake .. -DCMAKE_INSTALL_PREFIX=$CONDA_PREFIX
```

* Build the project

```bash
  make
```

* Install application

```bash
  make install
```

* Launch Jupyter Notebook in the browser

```bash
  jupyter notebook
```

* Launch Jupyter Notebook in the terminal

```bash
  jupyter console --kernel=xbasic
```

## Created By

- [Sarita Singh](https://github.com/itssingh)
- [Avinal Kumar](https://github.com/avinal)

## Acknowledgement 

The BASIC language parser used in this project is a modified version of the [basic](https://github.com/nanoflite/basic) project created by [Johan Van den Brande](https://github.com/nanoflite). 
