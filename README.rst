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
user's configuration does not interfere with the testing and the
``--hash`` option keeps the paths to reasonable lengths with the large
number of properties generated for this project.

.. code:: sh

   $ b2 --test-config=user-config.jam --hash

By default, this tests almost all combination of the standard
features.  These features are defined in Boost.Build and a
non-normative list is given below.  The list of options tested can be
found in the logic within the `Jamroot <Jamroot>`__.

* link
* runtime-link (disabled)
* runtime-debugging (disabled)
* optimization
* profiling
* inlining
* threading
* rtti
* exception-handling
* asynch-exceptions (disabled)
* extern-c-nothrow (disabled)
* debug-symbols
* strip
* define
* undef
* include
* warnings
* warnings-as-errors

This is a lot of tests.  To limit the scale of the tests, add
properties for features to the command line to limit the tests to only
that value of the given property.

For example, to limit to only building for a single toolset,
run the following command.

.. code:: sh

   $ b2 --test-config=user-config.jam \
       --hash \
       toolset=gcc

To limit further to only include static linking, run the following
command.

.. code:: sh

   $ b2 --test-config=user-config.jam \
       --hash \
       toolset=gcc \
       link=static

To limit further to only test for single-threaded programs, run the
following command.

.. code:: sh

   $ b2 --test-config=user-config.jam \
       --hash \
       toolset=gcc \
       link=static \
       threading=single

To test the IAR Systems compilers, limit the properties to
those supported by the toolset to minimize the warnings from
Boost.Build.

* target-os=baremetal
* link=static

To limit tests during development, narrow the properties as much as
possible to test as few variants as desired.  For example, to minimize
the architecture and instruction set, run the following command.

.. code:: sh

   $ b2 --test-config=user-config.jam \
       --hash \
        toolset=iccarm \
        architecture=armv7 \
        instruction-set=armv7 \
        target-os=baremetal \
        link=static

Requirements
------------

* Boost.Build
* All desired compilers

IAR Systems
~~~~~~~~~~~

* IAR Embedded Workbench for ARM 7.5
* IAR Embedded Workbench for AVR32 7.2

Adding Toolsets
---------------

To add a cross-compiler to the test suite, configure the toolset in
``project-config.jam`` and add it to the ``toolsets`` variable,
ensuring that the toolset is only configured for platforms that
actually have it.
