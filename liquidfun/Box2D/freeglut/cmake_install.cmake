# Install script for directory: /home/surender/Downloads/liquidfun-1.1.0/freeglut

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so.3.9.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/surender/Downloads/liquidfun-1.1.0/liquidfun/Box2D/freeglut/Release/libglut.so.3.9.0"
    "/home/surender/Downloads/liquidfun-1.1.0/liquidfun/Box2D/freeglut/Release/libglut.so.3"
    "/home/surender/Downloads/liquidfun-1.1.0/liquidfun/Box2D/freeglut/Release/libglut.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so.3.9.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libglut.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/surender/Downloads/liquidfun-1.1.0/liquidfun/Box2D/freeglut/Release/libglut.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GL" TYPE FILE FILES
    "/home/surender/Downloads/liquidfun-1.1.0/freeglut/include/GL/freeglut.h"
    "/home/surender/Downloads/liquidfun-1.1.0/freeglut/include/GL/freeglut_ext.h"
    "/home/surender/Downloads/liquidfun-1.1.0/freeglut/include/GL/freeglut_std.h"
    "/home/surender/Downloads/liquidfun-1.1.0/freeglut/include/GL/glut.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pkgconfig" TYPE FILE RENAME "freeglut.pc" FILES "/home/surender/Downloads/liquidfun-1.1.0/liquidfun/Box2D/freeglut.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

