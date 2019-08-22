# -*- coding: utf-8 -*-
# https://pythonhosted.org/an_example_pypi_project/setuptools.html
# http://setuptools.readthedocs.io/en/latest/setuptools.html
from setuptools import setup, find_packages

setup(
    name='opencv-learn',
    packages=find_packages(exclude=('tests', 'docs')),
    install_requires=[
        'numpy',
    ],
)