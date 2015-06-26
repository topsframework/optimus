
############################################################
##     UNCOMMENT ANY TARGET TO OVERWRITE THE DEFAULT!     ##
############################################################

# Project info
# ===============
# PROJECT         := # Project name (def: Default)
# VERSION         := # Version (def: 1.0.0)
# STD_NAMESPACE   := # Project namespace for C/C++
# GIT_REMOTE_PATH := # Remote path for git repository
# MAINTEINER_NAME := # Your name
# MAINTEINER_MAIL := # your_name@mail.com
# COPYRIGHT       := # Copyright Holder
# SYNOPSIS        := # One-line description of the program
# DESCRIPTION     := # Longer description of the program

# Program settings
# ==================
BIN             := main
TESTBIN         := test
BENCHBIN        := bench
# ARLIB           := # Static/Shared libraries' names. If
# SHRLIB          := # one is a dir, all srcs within will
                     # make the lib

# Dependencies
# ==============
# GIT_DEPENDENCY  := # List of git dependencies in the form:
#                    # DEP_NAME => dep_path build_cmd
# WEB_DEPENDENCY  := # Same as above, but for URL downloads
#                    # with 'curl -o' (default) or 'wget -O'

# Paths
# =======
# ASLIBS          := # Assembly paths
# CLIBS           := # C paths
CXXLIBS         := -I /Users/igorbonadio/Projetos/eigen-eigen-bdd17ee3b1b3
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

CXXLIBS         += -I external/gmock/include/ -I external/gtest/include/
LDLIBS          += -L external/gtest/make/ -L external/gmock/make/