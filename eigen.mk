ifndef EIGEN_MK
override EIGEN_MK := T

# Dependencies
# ==============
WEB_DEPENDENCY  += \
    eigen => https://bitbucket.org/eigen/eigen/get/3.2.5.tar.gz    \
            extract: mv eigen eigen-3.2.5.tar.gz && tar -xvf eigen-3.2.5.tar.gz && mv eigen-eigen-bdd17ee3b1b3 eigen \
            build: echo eigen installed

# Paths
# =======
CXXLIBS         += -I external/eigen

endif # ifndef EIGEN_MK