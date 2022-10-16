#
# src/CMakeLists.txt
# HRVO Library
#
# Copyright (c) 2009-2014 University of North Carolina at Chapel Hill.
# All rights reserved.
#
# Permission to use, copy, modify, and distribute this software and its
# documentation for educational, non-commercial research, and non-profit
# purposes, without fee, and without a written agreement is hereby granted,
# provided that the above copyright notice, this paragraph, and the following
# four paragraphs appear in all copies.
#
# Permission to incorporate this software into commercial products may be
# obtained by contacting the authors <geom@cs.unc.edu> or the Office of
# Technology Development at the University of North Carolina at Chapel Hill
# <otd@unc.edu>.
#
# This software program and documentation are copyrighted by the University of
# North Carolina at Chapel Hill. The software program and documentation are
# supplied as is, without any accompanying services from the University of
# North Carolina at Chapel Hill or the authors. The University of North Carolina
# at Chapel Hill and the authors do not warrant that the operation of the
# program will be uninterrupted or error-free. The end-user understands that the
# program was developed for research purposes and is advised not to rely
# exclusively on the program for any reason.
#
# IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE
# AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR
# CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS
# SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF NORTH CAROLINA AT
# CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
# DAMAGE.
#
# THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
# DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY STATUTORY
# WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS ON AN AS IS
# BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS
# HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
# MODIFICATIONS.
#
# Please send all bug reports to <geom@cs.unc.edu>.
#
# The authors may be contacted via:
#
# Jamie Snape, Jur van den Berg, Stephen J. Guy, and Dinesh Manocha
# Dept. of Computer Science
# 201 S. Columbia St.
# Frederick P. Brooks, Jr. Computer Science Bldg.
# Chapel Hill, N.C. 27599-3175
# United States of America
#
# <http://gamma.cs.unc.edu/HRVO/>
#

set(HRVO_HEADERS
	HRVO.h
	Simulator.h
	Vector2.h
	Agent.h
	Definitions.h
	KdTree.h
	Goal.h
	)

set(HRVO_SOURCES
	Agent.cpp
	Goal.cpp
	KdTree.cpp
	Simulator.cpp
	Vector2.cpp)

find_package(PythonLibs 3.8 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_library(HRVO SHARED ${HRVO_SOURCES})

add_library(pyhrvo MODULE pyhrvo_module.cpp)
target_link_libraries(pyhrvo HRVO ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(pyhrvo PRIVATE ${PYTHON_INCLUDE_DIRS})

install(FILES ${HRVO_HEADERS} DESTINATION include)
install(TARGETS HRVO DESTINATION lib)
