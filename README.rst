Boost.Build Toolset Tester
==========================

The project contains a Boost.Build project intended to test a
Boost.Build toolset.  To do this, it attempts to build components of C
and C++ programs (libraries, programs, object files, etc.) in all the
ways that a toolset must to satisfy the Boost.Build architecture.

It is intended to be useful for bare metal cross-compilers as well as
normal toolsets.

Overview
--------

Running the following command will run all tests against each compiler
known.  Note that using the ``--test-config`` option ensures that the
user's configuration does not interfere with the testing.

.. code:: sh

   $ b2 --test-config=user-config.jam

Requirements
------------

* Boost.Build
* All desired compilers

Adding Toolsets
---------------

To add a cross-compiler to the test suite, configure the toolset in
``project-config.jam`` and add it to the ``toolsets`` variable,
ensuring that the toolset is only configured for platforms that
actually have it.
