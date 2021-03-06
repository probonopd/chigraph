FROM centos:6.8

RUN yum -y update && yum -y install wget && yum -y install centos-release-scl epel-release && yum -y update && yum -y install devtoolset-4-gcc devtoolset-4-gcc-c++ devtoolset-4-binutils wget tar bzip2 git libtool which fuse fuse-devel libpng-devel automake cppunit-devel cmake glibc-headers libstdc++-devel gcc-c++ freetype-devel fontconfig-devel libxml2-devel libstdc++-devel libXrender-devel patch xcb-util-keysyms-devel libXi-devel libudev-devel.x86_64 openssl-devel sqlite-devel.x86_64 gperftools.x86_64 gperf.x86_64 libicu-devel.x86_64 boost-devel.x86_64 libxslt-devel.x86_64 docbook-style-xsl.noarch python27.x86_64 cmake3.x86_64 ruby bison flex bison-devel ruby-devel flex-devel xz pcre-devel pcre2-devel pcre pcre2 mesa-libEGL-devel mesa-libGL-devel glib-devel gettext perl-URI.noarch bzip2-devel.x86_64 subversion-devel.x86_64 subversion.x86_64 sqlite2-devel.x86_64 vim sudo
RUN cd /tmp && wget wget http://opensource.wandisco.com/rhel/6/svn-1.9/RPMS/x86_64/subversion-1.9.4-3.x86_64.rpm http://opensource.wandisco.com/rhel/6/svn-1.9/RPMS/x86_64/subversion-devel-1.9.4-3.x86_64.rpm http://opensource.wandisco.com/rhel/6/svn-1.9/RPMS/x86_64/serf-1.3.7-1.x86_64.rpm && yum -y install subversion* serf*; rm subversion* serf*

RUN echo ". /opt/rh/devtoolset-4/enable && chmod +x /opt/rh/python27/enable && . /opt/rh/python27/enable" >> /root/.bashrc

ENV LC_ALL=en_US.UTF-8 LANG=en_us.UTF-8 QTVERSION=5.8.0 QVERSION_SHORT=5.8 LLVM_ROOT=/opt/llvm/ QTV=5.8.0 LD_LIBRARY_PATH=$QTDIR/lib/
ENV QTDIR=/usr/local/Qt-${QTVERSION}/

# Qt!
RUN mkdir -p /qt
RUN bash -c "cd /qt && wget http://download.qt.io/archive/qt/${QVERSION_SHORT}/${QTVERSION}/single/qt-everywhere-opensource-src-${QTVERSION}.tar.xz && tar xvf qt-everywhere-opensource-src-${QTVERSION}.tar.xz"
RUN bash -c "ln -sf /opt/rh/devtoolset-4/root/usr/bin/g++ /usr/bin/g++ && ln -sf /opt/rh/devtoolset-4/root/usr/bin/c++ /usr/bin/c++"
RUN bash -c "cd /qt/qt-everywhere-opensource-src-$QTV && ./configure -v -skip qtgamepad -skip webengine -platform linux-g++ -qt-pcre -qt-xcb -qt-xkbcommon -xkb-config-root /usr/share/X11/xkb -no-pch -confirm-license -opensource && make -j 8 || make -j 1 install; make -j8 install && rm -Rf /qt"

# ninja
RUN yum -y update && yum -y install unzip
RUN cd /usr/bin && wget https://github.com/ninja-build/ninja/releases/download/v1.7.2/ninja-linux.zip && unzip ninja-linux.zip && rm -f ninja-linux.zip

# llvm+clang
RUN mkdir -p /llvm
RUN bash -c "cd /llvm && wget http://llvm.org/releases/3.9.1/llvm-3.9.1.src.tar.xz && tar xvf llvm-3.9.1.src.tar.xz"
RUN bash -c "cd /llvm/llvm-3.9.1.src && cd tools && wget http://llvm.org/releases/3.9.1/cfe-3.9.1.src.tar.xz && tar xvf cfe-3.9.1.src.tar.xz"
RUN bash -c "source /opt/rh/python27/enable && source /opt/rh/devtoolset-4/enable && python --version && cd /llvm/llvm-3.9.1.src && mkdir -p build && cd build && cmake3 .. -DLLVM_TARGETS_TO_BUILD=X86 -DLLVM_ENABLE_RTTI=ON -GNinja -DCMAKE_INSTALL_PREFIX=/opt/llvm/ -DCMAKE_BUILD_TYPE=Release && ninja install && rm -Rf /llvm"

CMD /bin/bash
 
