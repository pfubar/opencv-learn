# install opencv
## from source
https://www.pyimagesearch.com/2015/06/15/install-opencv-3-0-and-python-2-7-on-osx/
https://docs.opencv.org/3.4.1/d7/d9f/tutorial_linux_install.html

download opencv source file and uncompress

```bash
mv opencv-3.4.1
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
make -j7
sudo make install
```

## from brew
https://www.pyimagesearch.com/2016/12/19/install-opencv-3-on-macos-with-homebrew-the-easy-way/

```bash
brew update
brew install python
pip install virtualenv virtualenvwrapper
source virtualenvwrapper.sh
mkvirtualenv opencv-learn
pip install numpy
```

### cmake utility
```bash
brew install cmake pkg-config
```

### image IO
```bash
brew install jpeg libpng libtiff openexr
```

### opencv helper
```bash
brew install eigen tbb
```

## Install for python
```bash
pip install opencv-python
python
import cv2
cv2.__version__
```

### Make opencv-python availble on other virtualenvs
### from brew installed opencv
```bash
ln -s /usr/local/Cellar/opencv/3.4.1_2/lib/python2.7/site-packages/cv2.so $HOME/.virtualenvs/opencv-learn/lib/python2.7/site-packages/
```
### from source built opencv
```bash
ln -s $HOME/dev/opencv-3.4.1/build/lib/cv2.so $HOME/.virtualenvs/opencv-learn/lib/python2.7/site-packages/
```

## Intall for C++
### Using Eclipse
After source build is complete...  
Eclipse properties -> C/C++ Build -> Settings  
C++ Linker -> Libraries  
-L/usr/local/Cellar/opencv/3.4.1_2/lib  
-lopencv_core -lopencv_highgui -lopencv_imgproc

C++ Compiler -> Includes  
-I/usr/local/Cellar/opencv/3.4.1_2/include/opencv

### Using cmake
```bash
brew install cmake
cmake .
make
./opencv-learn
```

## Install for Java
http://opencv-java-tutorials.readthedocs.io/en/latest/01-installing-opencv-for-java.html#introduction-to-opencv-for-java
https://www.pyimagesearch.com/2016/12/19/install-opencv-3-on-macos-with-homebrew-the-easy-way/

```bash
sudo xcode-select --install
brew edit opencv
-DBUILD_opencv_java=ON
brew install --build-from-source opencv
```

### Add as external jar:
/usr/local/Cellar/opencv/3.3.1_1/share/OpenCV/java/opencv-330.jar

### Add as native library location in build path:
/usr/local/Cellar/opencv/3.3.1_1/share/OpenCV/java/

### Setup eclipse
```bash
mvn eclipse:eclipse
```


# Tutorials
https://docs.opencv.org/3.4.1/
https://docs.opencv.org/3.4.1/d6/d00/tutorial_py_root.html
