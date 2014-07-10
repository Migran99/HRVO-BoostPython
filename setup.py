#!/usr/bin/env python
 
from distutils.core import setup
from distutils.extension import Extension
from glob import glob

files=glob('src/*.cpp')

setup(name="pyhrvo",
    ext_modules=[
        Extension("pyhrvo", 
        	files,
        libraries = ["boost_python"]),
    ])

