
############################################################
##     UNCOMMENT ANY TARGET TO OVERWRITE THE DEFAULT!     ##
############################################################

# Project info
# ===============
# PROJECT         := Optimus
# VERSION         := 1.0.0
# STD_NAMESPACE   := optimus
# GIT_REMOTE_PATH := https://github.com/topsframework/optimus.git
# MAINTEINER_NAME := Ígor Bonadio
# MAINTEINER_MAIL := igorbonadio@gmail.com
# COPYRIGHT       := Optimus
# SYNOPSIS        := Nonlinear optimization library
# DESCRIPTION     := Optimus is a library of nonlinear optimization algorithms written in C++.

# Program settings
# ==================
TESTBIN         := test
BENCHBIN        := bench
SHRLIB          := optimus

# Dependencies
# ==============
# GIT_DEPENDENCY  := # List of git dependencies in the form:
#                    # DEP_NAME => dep_path build_cmd

# Paths
# =======
# ASLIBS          := # Assembly paths
# CLIBS           := # C paths
# CXXLIBS         :=
# LDLIBS          := # Linker paths

# Flags
# =======
# CPPFLAGS        := # Precompiler Flags
# ASFLAGS         := # Assembly Flags
# CFLAGS          := # C Flags
CXXFLAGS        := -ansi -Wall -O2 -std=c++11
# LDFLAGS         := # Linker flags

# Documentation
# ===============
# LICENSE         := # File with a License (def: LICENSE)
# NOTICE          := # Notice of the License, to be put in
#                    # the top of any file (def: NOTICE).
# DOXYFILE        := # Dxygen config file (def: Doxyfile)

# Makeball list
# ===============
# 'include conf/makeball.mk' for pre-configured options
# to use the library 'makeball'
include conf/googletest.mk
include conf/googlebenchmark.mk
include conf/eigen.mk

